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
    std::string mnemonic;
    for (int i = 0; i < program->getStatements().size(); i++) {
        if (program->getStatements()[i]->isComment()) {
            listingWriter->writeComment(i + 1, program->getStatements()[i]->getStatementField());
        }
        else {
            mnemonic = program->getStatements()[i]->getMnemonic()->getMnemonicField();
            try {
                if (mnemonic == START) {
                    if (checkIn) {
                        objectWriter->
                                startNewRecord(Hexadecimal::intToHex(program->getStatements()[i]->
                                getStatementLocationPointer()));
                    }
                    executeStart(program->getStatements()[i], program);
                    checkIn= false;
                } else if (mnemonic == BYTE) {
                    if (checkIn) {
                        objectWriter->
                                startNewRecord(Hexadecimal::intToHex(program->getStatements()[i]->
                                getStatementLocationPointer()));
                    }
                    objectCode = executeByte(program->getStatements()[i]);
                    checkIn= false;
                } else if (mnemonic == WORD) {
                    if (checkIn) {
                        objectWriter->
                                startNewRecord(Hexadecimal::intToHex(program->getStatements()[i]->
                                getStatementLocationPointer()));
                    }
                    objectCode = executeWord(program->getStatements()[i]);
                    checkIn= false;
                } else if (mnemonic == RESW || mnemonic == RESB) {
                    executeRES(program->getStatements()[i]);
                } else if (mnemonic == END) {
                    if (checkIn) {
                        objectWriter->
                                startNewRecord(Hexadecimal::intToHex(program->getStatements()[i]->
                                getStatementLocationPointer()));
                    }
                    executeEnd(program->getStatements()[i], symbolTable);
                    checkIn = false;
                } else {
                    if (checkIn) {
                        objectWriter->
                                startNewRecord(Hexadecimal::intToHex(program->getStatements()[i]->
                                getStatementLocationPointer()));
                    }
                    objectCode = executeInstruction(program->getStatements()[i], symbolTable);
                    checkIn = false;
                }
            } catch (ErrorHandler::Error error) {
                listingWriter->writeError(error);
            }
            listingWriter->writeLine(i + 1, program->getStatements()[i], objectCode);
            objectCode = "";
        }
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
    std::string mnemonic;
    mnemonic = statement->getMnemonic()->getMnemonicField();
    std::string objectCode = Hexadecimal::intToHex(
            instructionTable[mnemonic]->getOpCode());
    if (!statement->getOperand()->isEmpty()) {
        if (statement->getOperand()->isLabel()) {
            std::string operand = statement->getOperand()->getOperandField();
            if (symbolTable[operand] == -1) {
                throw ErrorHandler::undeclared_label;
            }
            if (statement->getOperand()->isIndexed()) {
                objectCode += Hexadecimal::intToHex(symbolTable[operand] + INDEXINGVALUE);
            } else {
                objectCode += Hexadecimal::intToHex(symbolTable[operand]);
            }
        } else if (statement->getOperand()->isFixedAddress()) {
            if (statement->getOperand()->isIndexed()) {
                objectCode += Hexadecimal::intToHex(statement->getOperand()->getLCIncrement() + INDEXINGVALUE);
            } else {
                objectCode += Hexadecimal::intToHex(statement->getOperand()->getLCIncrement());
            }
        } else {
            if (statement->getOperand()->isIndexed()) {
                objectCode += Hexadecimal::intToHex(statement->getStatementLocationPointer() + INDEXINGVALUE);
            } else {
                objectCode += Hexadecimal::intToHex(statement->getStatementLocationPointer());
            }
        }
    }
    objectWriter->writeTextRecord(objectCode, Hexadecimal::intToHex(statement->getStatementLocationPointer()));
    return objectCode;
}

void PassTwoController::executeRES(Statement *statement) {
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
