//
// Created by Walid on 5/1/2017.
//

#include <iostream>
#include <cstdlib>
#include "PassOneController.h"
#include "../file/write/FileWriter.h"
#include "../format/FormatThree.h"
#include "../file/write/IntermediateFileWriter.h"
#include "../error/ErrorHandler.h"
#include "../util/Program.h"
#include "../datatypes/Hexadecimal.h"


PassOneController::PassOneController(std::map<std::string, Instruction *> &instructionTable,
                                     std::map<std::string, Directive *> &directiveTable) {
    PassOneController::instructionTable = instructionTable;
    PassOneController::directiveTable = directiveTable;
    PassOneController::lineNumber = 1;
    PassOneController::locationCounter = 0;
    PassOneController::startAddress = -1;
    PassOneController::endAddress = -1; // Modified when END directive is reached.
}

void PassOneController::execute(std::map<std::string, int> &symbolTable,
                                       FileReader *fileReader, Program *program) {
    IntermediateFileWriter *intermediateFileWriter = new IntermediateFileWriter(fileReader->getFileName(),
                                                                                std::string(".int"));
    intermediateFileWriter->writeInitialLine();
    while (!fileReader->finishedReading()) {
        Statement *statement = fileReader->getNextStatement();
        if (statement->isComment()) {
            intermediateFileWriter->writeComment(lineNumber, statement->getStatementField());
        } else {
            try {
                statement->validate(instructionTable, directiveTable, symbolTable,
                                    startAddress, endAddress, locationCounter);

            } catch (ErrorHandler::Error error) {
                intermediateFileWriter->writeError(error);
                std::cout << ErrorHandler::errors[error] << std::endl;
                lineNumber++;
                continue;
            }
            /// If no error logic:

            /// Updating LC
            statement->execute(startAddress, endAddress, locationCounter, directiveTable, instructionTable);

            /// Updating SymTable
            if (statement->getOperand()->isLabel() &&
                symbolTable.find(statement->getOperand()->getOperandField()) == symbolTable.end()) {
                symbolTable[statement->getOperand()->getOperandField()] = -1;// -1 indicating variable not declared yet.
            }
           if (!statement->getLabel()->isEmpty()) {
                symbolTable[statement->getLabel()->getLabelField()] = statement->getStatementLocationPointer();

            }
            /// Writing to file
            intermediateFileWriter->writeStatement(lineNumber*5, statement);
            program->addStatement(statement);
            lineNumber++;
        }
        lineNumber++;
        if (statement->getMnemonic()->getMnemonicField() == "END") {
            break;
        }
    }
    if (!fileReader->finishedReading()) {
        intermediateFileWriter->writeError(ErrorHandler::code_after_end);
    }

    intermediateFileWriter->writeSymbolTable(symbolTable);
    /// Check this agian.
    if (startAddress == -1 && endAddress == -1) {
        program->setProgramLength(locationCounter);
    } else if (endAddress == -1) {
        program->setProgramLength(locationCounter - startAddress);
    } else {
        program->setProgramLength(endAddress - startAddress);
    }
}

