//
// Created by SalmaAhmed on 5/1/2017.
//

#include "PassTwoController.h"
#include <iostream>

PassTwoController::PassTwoController(std::map<std::string, Instruction *> &instructionTable) {
    PassTwoController::instructionTable = instructionTable;

}

void PassTwoController::executePass2(std::map<std::string, int> &symbolTable,
                                     Program *program, std::string fileName) {
    PassTwoController::objectWriter = new ObjectFileWriter(fileName);
    PassTwoController::listingWriter = new ListingFileWriter(fileName);
    listingWriter->writeInitialLine();
    int lineNumber = 1;
    for (auto currentStatement : program->getStatements()) {
        if (currentStatement->isComment()) {
            listingWriter->writeComment(lineNumber, currentStatement->getStatementField());
        }
        else {
            std::string mnemonic;
            mnemonic = currentStatement->getMnemonic()->getMnemonicField();
            try {
                if (mnemonic == START) {
                    if (checkIn) {
                        objectWriter->
                                startNewRecord(Hexadecimal::intToHex(currentStatement->
                                getStatementLocationPointer()));
                    }
                    executeStart(currentStatement, program);
                    checkIn= false;
                } else if (mnemonic == END) {
                    if (checkIn) {
                        objectWriter->
                                startNewRecord(Hexadecimal::intToHex(currentStatement->
                                getStatementLocationPointer()));
                    }
                    executeEnd(currentStatement, symbolTable);
                    checkIn = false;
                } else if (mnemonic == RESW || mnemonic == RESB) {
                    executeRES();
                } else if (mnemonic == BYTE) {
                    if (checkIn) {
                        objectWriter->
                                startNewRecord(Hexadecimal::intToHex(currentStatement->
                                getStatementLocationPointer()));
                    }
                    objectCode = executeByte(currentStatement);
                    checkIn= false;
                } else if (mnemonic == WORD) {
                    if (checkIn) {
                        objectWriter->
                                startNewRecord(Hexadecimal::intToHex(currentStatement->
                                getStatementLocationPointer()));
                    }
                    objectCode = executeWord(currentStatement);
                    checkIn= false;
                } else {
                    if (checkIn) {
                        objectWriter->
                                startNewRecord(Hexadecimal::intToHex(currentStatement->
                                getStatementLocationPointer()));
                    }
                    objectCode = executeInstruction(currentStatement, symbolTable);
                    checkIn = false;
                }
            } catch (ErrorHandler::Error error) {
                listingWriter->writeError(error);
            }
            listingWriter->writeLine(lineNumber, currentStatement, objectCode);
            objectCode = "";
        }
        lineNumber++;
    }
}

void PassTwoController::executeStart(Statement *statement, Program *program) {
    std::string label = statement->getLabel()->getLabelField();
    int operand = statement->getOperand()->getLCIncrement();
    if (label.length() > MAX_SOURCENAME_LENGTH) {
        throw ErrorHandler::invalid_source_name;
    }
    objectWriter->writeHeader(label, Hexadecimal::intToHex(operand),
                                 Hexadecimal::intToHex(program->getProgramLength()));
}

std::string PassTwoController::executeInstruction(Statement *statement,
                                                  std::map<std::string, int> &symbolTable) {
    int opCode = instructionTable[ statement->getMnemonic()->getMnemonicField()]->getOpCode();
    int indexBit = 0, address = 0;
    if (!statement->getOperand()->isEmpty()) {
        if (statement->getOperand()->isIndexed()) {
            indexBit = 1;
        }
        if (statement->getOperand()->isLabel()) {
            if (symbolTable[statement->getOperand()->getOperandField()] == -1) {
                throw ErrorHandler::undeclared_label;
            }
            address = symbolTable[statement->getOperand()->getOperandField()];
        } else if (statement->getOperand()->isFixedAddress()) {
            address = statement->getOperand()->getLCIncrement();
        } else {
            address = statement->getStatementLocationPointer();
        }
    }
    objectWriter->writeTextRecord(getSicObjectCode(opCode, indexBit, address),
                                  Hexadecimal::intToHex(statement->getStatementLocationPointer()));
    return getSicObjectCode(opCode, indexBit, address);
}

void PassTwoController::executeRES() {
    if (!checkIn) {
        objectWriter->writeTextRecord();
        checkIn = true;
    }
}

/// Assumption -> Maximum length for WORD directive's operand is 3 bytes.
std::string PassTwoController::executeWord(Statement *statement) {
    std::string address = Hexadecimal::intToHex(statement->getOperand()->getintValue());
    if (address.length() > MAX_WORD_LENGTH) {
        throw ErrorHandler::address_out_of_range;
    }
    std::string location = Hexadecimal::intToHex(statement->getStatementLocationPointer());
    objectWriter->writeTextRecord(address, location);
    return address;
}

/// Assumption -> Maximum length for BYTE directive's operand is 15 byte or 14 Hex digits.
std::string PassTwoController::executeByte(Statement *statement) {
    std::string address;
    if (statement->getOperand()->isHexConstant()) {
         address = Hexadecimal::intToHex(statement->getOperand()->getintValue());
    } else {
        address = Hexadecimal::stringToHex(statement->getOperand()->getOperandField());
    }
    if (address.length() > MAX_BYTE_LENGTH) {
        throw ErrorHandler::address_out_of_range;
    }
    objectWriter->writeTextRecord(address, Hexadecimal::intToHex(statement->getStatementLocationPointer()));
    return address;
}

void PassTwoController::executeEnd(Statement *statement, std::map<std::string, int> &symbolTable) {
    if (statement->getOperand()->isLabel()) {
        std::string operand = statement->getOperand()->getOperandField();
        if (symbolTable[operand] == -1)
            throw ErrorHandler::undeclared_label;
        objectWriter->writeEndRecord(Hexadecimal::intToHex(symbolTable[operand]));
    } else if (statement->getOperand()->isFixedAddress()) {
        int operand = statement->getOperand()->getLCIncrement();
        objectWriter->writeEndRecord(Hexadecimal::intToHex(operand));
    } else {
        objectWriter->writeEndRecord("");
    }
}

std::string PassTwoController::getSicObjectCode(int opCode, int indexBit, int address) {
    return Hexadecimal::intToHex(((((opCode << 1) | indexBit) << 15) | address));
}
