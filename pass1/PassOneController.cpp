//
// Created by Walid on 5/1/2017.
//

#include <iostream>
#include <cstdlib>
#include "PassOneController.h"
#include "../file/write/IntermediateFileWriter.h"
#include "../error/ErrorHandler.h"
#include "../util/Program.h"
#include "../datatypes/Hexadecimal.h"

PassOneController::PassOneController(std::map<std::string, Instruction *> &instructionTable,
                                     std::map<std::string, Directive *> &directiveTable) {
    PassOneController::instructionTable = instructionTable;
    PassOneController::directiveTable = directiveTable;
    PassOneController::lineNumber = 1;
    /// If no start directive is entered, location counter starts at 0.
    PassOneController::locationCounter = 0;
    /// Assumption -> Program may get assembled without having a START or an END directives.
    PassOneController::startAddress = -1;
    PassOneController::endAddress = -1;
}

bool PassOneController::execute(std::map<std::string, int> &symbolTable,
                                FileReader *fileReader, Program *program,
                                std::map<std::string, std::pair<Operand *, int> > &literalTable) {
    IntermediateFileWriter *intermediateFileWriter = new IntermediateFileWriter(fileReader->getFileName(),
                                                                                std::string(".int"));
    bool validSourceCode = true;
    intermediateFileWriter->writeInitialLine();
    while (!fileReader->finishedReading()) {
        Statement *statement = fileReader->getNextStatement();
        if (statement->isComment()) {
            intermediateFileWriter->writeComment(lineNumber, statement->getStatementField());
            program->addStatement(statement);
        } else {
            try {
                statement->validate(instructionTable, directiveTable, symbolTable,
                                    startAddress, endAddress, locationCounter);

            } catch (ErrorHandler::Error error) {
                validSourceCode = false;
                intermediateFileWriter->writeError(error);
                lineNumber++;
                continue;
            }
            if (statement->getOperand()->isLabel() &&
                symbolTable.find(statement->getOperand()->getOperandField()) == symbolTable.end()) {
                symbolTable[statement->getOperand()->getOperandField()] = -1;
            }
            if (statement->getOperand()->isLiteral() &&
                literalTable.find(statement->getOperand()->getHexValue()) == literalTable.end()) {
                if (statement->getOperand()->isCurrentLocationCounter()) {
                    statement->getOperand()->setHexValue(Hexadecimal::intToHex(locationCounter));
                }
                literalTable[statement->getOperand()->getHexValue()] = std::make_pair(statement->getOperand(), -1);
            }
            if (!statement->getLabel()->isEmpty()) {
                symbolTable[statement->getLabel()->getLabelField()] = statement->getStatementLocationPointer();
            }
            if (statement->getMnemonic()->getMnemonicField() == "EQU") {
                if (statement->getOperand()->isCurrentLocationCounter()) {
                    symbolTable[statement->getLabel()->getLabelField()] = statement->getStatementLocationPointer();
                } else if (statement->getOperand()->isLabel()) {
                    symbolTable[statement->getLabel()->getLabelField()]= symbolTable[statement->getOperand()->getOperandField()];
                } else if (statement->getOperand()->isFixedAddress()) {
                    symbolTable[statement->getLabel()->getLabelField()] = statement->getOperand()->getLCIncrement();
                } else {
                    symbolTable[statement->getLabel()->getLabelField()]= statement->getOperand()->getExpressionValue();
                }
            }
            statement->execute(startAddress, endAddress, locationCounter, directiveTable, instructionTable,
                               symbolTable, literalTable);
            intermediateFileWriter->writeStatement(lineNumber, statement);
            program->addStatement(statement);
        }
        lineNumber++;
        if (statement->getMnemonic()->getMnemonicField() == "END") {
            break;
        }
    }
    if (!fileReader->finishedReading()) {
        intermediateFileWriter->writeError(ErrorHandler::code_after_end);
        return false;
    }

    intermediateFileWriter->writeSymbolTable(symbolTable);
    intermediateFileWriter->writeLiteralTable(literalTable);

    if (startAddress == -1 && endAddress == -1) {
        program->setProgramLength(locationCounter);
    } else if (endAddress == -1) {
        program->setProgramLength(locationCounter - startAddress);
    } else {
        program->setProgramLength(endAddress - startAddress);
    }

    if (locationCounter > MAX_MEMORY_LIMIT) {
        intermediateFileWriter->writeError(ErrorHandler::memory_exceeded);
        return false;
    }
    return validSourceCode;
}

