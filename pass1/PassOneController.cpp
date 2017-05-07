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
        //std::cout << statement->getLabel()->getLabelField() << std::endl;
        //std::cout << statement->getMnemonic()->getMnemonicField() << std::endl;
        //std::cout << statement->getOperand()->getOperandField() << std::endl;
        //std::cout << statement->getComment()->getComment() << std::endl;

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
            /// Updating SymTable
            if (statement->getOperand()->isLabel()) {
                symbolTable[statement->getOperand()->getOperandField()] = -1; // -1 indicating variable not declared yet.
            }
            if (!statement->getLabel()->isEmpty()) {
                std::cout << statement->getLabel()->getLabelField() <<std::endl;
                symbolTable[statement->getLabel()->getLabelField()] = locationCounter;
            }
            /// Updating LC
            statement->execute(startAddress, endAddress, locationCounter, directiveTable, instructionTable);

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
    std::cout<<"sym";
    for (auto curr : symbolTable) {
        //std::cout << "hello darkness my old friend." << std::endl;
        std::cout << curr.first << " " <<  Hexadecimal::intToHex(curr.second) << std::endl;

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

