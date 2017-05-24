//
// Created by SalmaAhmed on 5/1/2017.
//

#include "PassTwoController.h"
#include <iostream>
#include <set>


PassTwoController::PassTwoController(std::map<std::string, Instruction *> &instructionTable) {
    PassTwoController::instructionTable = instructionTable;

}

void PassTwoController::executePass2(std::map<std::string, int> &symbolTable,
                                     Program *program, std::string fileName,
                                     std::map<std::string, std::pair<Operand *, int> > &literalTable) {
    PassTwoController::listingWriter = new ListingFileWriter(fileName);
    listingWriter->writeInitialLine();
    int lineNumber = 1;
    bool foundError = false;
    std::set<std::string> literalPool;
    for (auto currentStatement : program->getStatements()) {
        if (currentStatement->isComment()) {
            listingWriter->writeComment(lineNumber, currentStatement->getStatementField());
        } else {
            std::string mnemonic = "";
            std::string objectCode = "";
            mnemonic = currentStatement->getMnemonic()->getMnemonicField();
            if (!currentStatement->getOperand()->isEmpty() && currentStatement->getOperand()->isLiteral()) {
                literalPool.insert(currentStatement->getOperand()->getHexValue());
            }
            try {
                if (mnemonic == START) {
                    startCheck(currentStatement);
                } else if (mnemonic == BYTE) {
                    byteCheck(currentStatement);
                    objectCode = getByteObjectCode(currentStatement);
                } else if (mnemonic == WORD) {
                    wordCheck(currentStatement);
                    objectCode = getWordObjectCode(currentStatement);
                } else if (mnemonic != RESB && mnemonic != RESW &&
                        mnemonic != END && mnemonic != ORG && mnemonic != EQU && mnemonic != LTORG) {
                    instructionCheck(currentStatement, symbolTable);
                    objectCode = getInstructionObjectCode(currentStatement, symbolTable, literalTable);
                }
            } catch (ErrorHandler::Error error) {
                listingWriter->writeError(error);
                foundError = true;
            }
            listingWriter->writeLine(lineNumber, currentStatement, objectCode);
            if (mnemonic == LTORG || mnemonic == END) {
                int currentLocCtr = currentStatement->getStatementLocationPointer();
                for (auto literal : literalPool) {
                    Statement *statement = new Statement();
                    statement->setLabel(new Label("*"));
                    statement->setMnemonic(new Mnemonic(literalTable[literal].first->getrawInput()));
                    statement->setStatementLocationPointer(currentLocCtr);
                    listingWriter->writeLine(lineNumber, statement, literal);
                    if (literalTable[literal].first->isHexConstant() ||
                            literalTable[literal].first->isStringConstant()) {
                        currentLocCtr += literalTable[literal].first->getLCIncrement();
                    } else {
                        currentLocCtr += 3;
                    }
                    lineNumber++;
                }
                lineNumber--;
                literalPool.clear();
            }
        }
        lineNumber++;
    }
    if (!foundError) {
        PassTwoController::objectWriter = new ObjectFileWriter(fileName);
        std::set<std::string> literalPool;
        for (auto currentStatement : program->getStatements()) {
            if (!currentStatement->isComment()) {
                std::string mnemonic = "";
                std::string objectCode = "";
                if (!currentStatement->getOperand()->isEmpty() && currentStatement->getOperand()->isLiteral()) {
                    literalPool.insert(currentStatement->getOperand()->getHexValue());
                }
                mnemonic = currentStatement->getMnemonic()->getMnemonicField();
                if (mnemonic == START) {
                    writeStartObjectFile(currentStatement, program);
                } else if (mnemonic == END) {
                    writeLiteralsInObjectFile(literalPool,
                                              currentStatement->getStatementLocationPointer(), literalTable);
                    literalPool.clear();
                    writeEndObjectFile(currentStatement, symbolTable);
                } else if (mnemonic == RESW || mnemonic == RESB) {
                    writeResObjectFile();
                } else if (mnemonic == BYTE) {
                    objectCode = getByteObjectCode(currentStatement);
                    writeByteObjectFile(objectCode, currentStatement);
                } else if (mnemonic == WORD) {
                    objectCode = getWordObjectCode(currentStatement);
                    writeWordObjectFile(objectCode, currentStatement);
                } else if (mnemonic == LTORG) {
                    writeLiteralsInObjectFile(literalPool,
                                              currentStatement->getStatementLocationPointer(), literalTable);
                    literalPool.clear();
                } else if (mnemonic != ORG && mnemonic != EQU){
                    objectCode = getInstructionObjectCode(currentStatement, symbolTable, literalTable);
                    writeInstructionObjectFile(objectCode, currentStatement);
                }
            }
        }
    }
}

void PassTwoController::writeStartObjectFile(Statement *statement, Program *program) {
    objectWriter->writeHeader(statement->getLabel()->getLabelField(),
                              Hexadecimal::intToHex(statement->getOperand()->getLCIncrement()),
                              Hexadecimal::intToHex(program->getProgramLength()));
}

void PassTwoController::writeEndObjectFile(Statement *statement, std::map<std::string, int> &symbolTable) {
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

void PassTwoController::writeResObjectFile() {
    objectWriter->writeCurrentTextRecord();
    objectWriter->startNewTextRecord(-1);
}

std::string PassTwoController::
getInstructionObjectCode(Statement *statement,
                         std::map<std::string, int> &symbolTable,
                         std::map<std::string, std::pair<Operand *, int>> &literalTable) {
    int opCode = instructionTable[statement->getMnemonic()->getMnemonicField()]->getOpCode();
    int indexBit = 0, address = 0;
    if (!statement->getOperand()->isEmpty()) {
        if (statement->getOperand()->isIndexed()) {
            indexBit = 1;
        }
        if (statement->getOperand()->isLabel()) {
            address = symbolTable[statement->getOperand()->getOperandField()];
        } else if (statement->getOperand()->isFixedAddress()) {
            address = statement->getOperand()->getLCIncrement();
        } else if (statement->getOperand()->isLiteral()){
            address = literalTable[statement->getOperand()->getHexValue()].second;
        } else {
            address = statement->getStatementLocationPointer();
        }
    }
    return getSicObjectCode(opCode, indexBit, address);
}

void PassTwoController::writeLiteralsInObjectFile(std::set<std::string> literalPool, int locationCounter,
                                                  std::map<std::string, std::pair<Operand *, int>> &literalTable) {
    for (auto literal : literalPool) {
        if (literalTable[literal].first->isHexConstant() ||
            literalTable[literal].first->isStringConstant()) {
            objectWriter->addRecordToTextRecord(literal, locationCounter);
            locationCounter += literalTable[literal].first->getLCIncrement();

        } else {
            objectWriter->addRecordToTextRecord(StringUtil::fillZeros(literal, MAX_WORD_LENGTH), locationCounter);
            locationCounter += 3;
        }
    }
}

void PassTwoController::writeInstructionObjectFile(std::string objCode, Statement *statement) {
    objectWriter->addRecordToTextRecord(StringUtil::fillZeros(objCode,
                                                              MAX_WORD_LENGTH), statement->getStatementLocationPointer());
}

void PassTwoController::writeWordObjectFile(std::string objCode, Statement *statement) {
    objectWriter->addRecordToTextRecord(StringUtil::fillZeros(objCode, MAX_WORD_LENGTH),
                                        statement->getStatementLocationPointer());
}

/// Assumption -> Maximum length for BYTE directive's operand is 15 byte or 14 Hex digits.
void PassTwoController::writeByteObjectFile(std::string objCode, Statement *statement) {
    objectWriter->addRecordToTextRecord(objCode, statement->getStatementLocationPointer());
}

/// Assumption -> Maximum length for WORD directive's operand is 3 bytes.
std::string PassTwoController::getWordObjectCode(Statement *statement) {
    std::string operand = Hexadecimal::intToHex(statement->getOperand()->getOperandValue());

    //objectWriter->writeTextRecord(address, location);
    return operand;
}

std::string PassTwoController::getByteObjectCode(Statement *statement) {
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
    std::string operand = Hexadecimal::intToHex(statement->getOperand()->getOperandValue());
    if (operand.length() > MAX_WORD_LENGTH) {
        throw ErrorHandler::address_out_of_range;
    }
}
void PassTwoController:: byteCheck(Statement *statement){
    std::string address;
    if (statement->getOperand()->isHexConstant()) {
        address = statement->getOperand()->getOperandField();
        if (address.length() > MAX_BYTE_LENGTH) {
            throw ErrorHandler::address_out_of_range;
        }
    } else {
        address = Hexadecimal::stringToHex(statement->getOperand()->getOperandField());
        if (address.length()/2 > MAX_BYTE_LENGTH) {
            throw ErrorHandler::address_out_of_range;
        }
    }

}
void PassTwoController::instructionCheck(Statement *statement,std::map<std::string, int> &symbolTable){
    if (symbolTable[statement->getOperand()->getOperandField()] == -1) {
        throw ErrorHandler::undeclared_label;
    }
}
