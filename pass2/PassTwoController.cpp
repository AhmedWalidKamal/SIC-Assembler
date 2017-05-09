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
    PassTwoController::listingWriter = new ListingFileWriter(fileName);
    listingWriter->writeInitialLine();
    int lineNumber = 1;
    int errorFlag = false;
    for (auto currentStatement : program->getStatements()) {
        if (currentStatement->isComment()) {
            listingWriter->writeComment(lineNumber, currentStatement->getStatementField());
        } else {
            std::string mnemonic = "";
            std::string objectCode = "";
            mnemonic = currentStatement->getMnemonic()->getMnemonicField();
            try {
                if (mnemonic == START) {
                    startCheck(currentStatement);
                } else if (mnemonic == BYTE) {
                    byteCheck(currentStatement);
                } else if (mnemonic == WORD) {
                    wordCheck(currentStatement);
                } else {
                    instructionCheck(currentStatement, symbolTable);
                }
            } catch (ErrorHandler::Error error) {
                listingWriter->writeError(error);
                errorFlag=true;
            }
            listingWriter->writeLine(lineNumber, currentStatement, objectCode);
        }
        lineNumber++;
    }
    if (!errorFlag) {
        PassTwoController::objectWriter = new ObjectFileWriter(fileName);
        for (auto currentStatement : program->getStatements()) {
            if (!currentStatement->isComment()) {
                std::string mnemonic = "";
                std::string objectCode = "";
                mnemonic = currentStatement->getMnemonic()->getMnemonicField();
                if (mnemonic == START) {
                    executeStart(currentStatement, program);
                } else if (mnemonic == END) {
                    executeEnd(currentStatement, symbolTable);
                } else if (mnemonic == RESW || mnemonic == RESB) {
                    executeRES();
                } else if (mnemonic == BYTE) {
                    objectCode = executeByte(currentStatement);
                } else if (mnemonic == WORD) {
                    objectCode = executeWord(currentStatement);
                } else {
                    objectCode = executeInstruction(currentStatement, symbolTable);
                }
            }
        }
    }
}

void PassTwoController::executeStart(Statement *statement, Program *program) {
    objectWriter->writeHeader(statement->getLabel()->getLabelField(),
                              Hexadecimal::intToHex(statement->getOperand()->getLCIncrement()),
                              Hexadecimal::intToHex(program->getProgramLength()));
}

void PassTwoController::executeEnd(Statement *statement, std::map<std::string, int> &symbolTable) {
    int executableAddress = 0;
    if (statement->getOperand()->isLabel()) {
        executableAddress = symbolTable[statement->getOperand()->getOperandField()];
    } else if (statement->getOperand()->isFixedAddress()) {
        executableAddress = statement->getOperand()->getLCIncrement();
    } else {
        objectWriter->writeEndRecord("");
        return;
    }
    objectWriter->writeEndRecord(Hexadecimal::intToHex(executableAddress));
}

void PassTwoController::executeRES() {
    objectWriter->writeCurrentTextRecord();
    objectWriter->startNewTextRecord(-1);
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
            address = symbolTable[statement->getOperand()->getOperandField()];
        } else if (statement->getOperand()->isFixedAddress()) {
            address = statement->getOperand()->getLCIncrement();
        } else {
            address = statement->getStatementLocationPointer();
        }
    }
    objectWriter->addRecordToTextRecord(StringUtil::fillZeros(getSicObjectCode(opCode, indexBit, address),
                                                              MAX_WORD_LENGTH), statement->getStatementLocationPointer());
//    objectWriter->writeTextRecord(getSicObjectCode(opCode, indexBit, address),
//                                  Hexadecimal::intToHex(statement->getStatementLocationPointer()));
    return getSicObjectCode(opCode, indexBit, address);
}

/// Assumption -> Maximum length for WORD directive's operand is 3 bytes.
std::string PassTwoController::executeWord(Statement *statement) {
    std::string operand = Hexadecimal::intToHex(statement->getOperand()->getintValue());
    objectWriter->addRecordToTextRecord(StringUtil::fillZeros(operand, MAX_WORD_LENGTH), statement->getStatementLocationPointer());
    //objectWriter->writeTextRecord(address, location);
    return operand;
}

/// Assumption -> Maximum length for BYTE directive's operand is 15 byte or 14 Hex digits.
std::string PassTwoController::executeByte(Statement *statement) {
    std::string address;
    if (statement->getOperand()->isHexConstant()) {
        address = statement->getOperand()->getOperandField();
    } else {
        address = Hexadecimal::stringToHex(statement->getOperand()->getOperandField());
    }
    // Adding a 0 if the hex length was odd.
    if (address.length() % 2 != 0) {
        address = StringUtil::fillZeros(address, address.length() + 1);
    }
    objectWriter->addRecordToTextRecord(address, statement->getStatementLocationPointer());
  //  objectWriter->writeTextRecord(address, Hexadecimal::intToHex(statement->getStatementLocationPointer()));
    return address;
}

std::string PassTwoController::getSicObjectCode(int opCode, int indexBit, int address) {
    return Hexadecimal::intToHex(((((opCode << 1) | indexBit) << 15) | address));
}

void PassTwoController::startCheck(Statement *statement){
    if (statement->getLabel()->getLabelField().length() > MAX_SOURCENAME_LENGTH) {
        throw ErrorHandler::invalid_source_name;
    }
}
void PassTwoController::wordCheck(Statement *statement){
    std::string operand = Hexadecimal::intToHex(statement->getOperand()->getintValue());
    if (operand.length() > MAX_WORD_LENGTH) {
        throw ErrorHandler::address_out_of_range;
    }
}
void PassTwoController:: byteCheck(Statement *statement){
    std::string address;
    if (statement->getOperand()->isHexConstant()) {
        address = statement->getOperand()->getOperandField();
    } else {
        address = Hexadecimal::stringToHex(statement->getOperand()->getOperandField());
    }
    if (address.length() > MAX_BYTE_LENGTH) {
        throw ErrorHandler::address_out_of_range;
    }
}
void PassTwoController::instructionCheck(Statement *statement,std::map<std::string, int> &symbolTable){
    if (symbolTable[statement->getOperand()->getOperandField()] == -1) {
        throw ErrorHandler::undeclared_label;
    }
}