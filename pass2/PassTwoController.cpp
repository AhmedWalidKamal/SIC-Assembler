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
    listingWriter->writeInitialLine();
    std::string mnemonic;
    for (int i = 0; i < program->getStatements().size() - 1; i++) {
        if (program->getStatements()[i]->isComment()) {
            listingWriter->writeComment(i*5, program->getStatements()[i]->getStatementField());}
        else{
            mnemonic = program->getStatements()[i]->getMnemonic()->getMnemonicField();
            try {
                /*writes header to objectFile.*/
                if (mnemonic == START) {
                    executeStart(program->getStatements()[i], program);
                } else if (mnemonic == BYTE) {
                    objectCode = executeByte(program->getStatements()[i]);
                } else if (mnemonic == WORD) {
                    objectCode = executeWord(program->getStatements()[i]);
                } else if (mnemonic == RESW || mnemonic == RESB) {
                    //has no object code but force the start of a new record.
                    executeRES();
                } else {
                    objectCode = executeInstruction(program->getStatements()[i], symbolTable);
                }
            } catch (ErrorHandler::Error error) {
                //write the error to listing file.
                listingWriter->writeError(error);
            }
            listingWriter->writeLine(i * 5, program->getStatements()[i], objectCode);
            objectCode = "";
        }
    }
    mnemonic = program->getStatements()[program->getStatements().size() - 1]->getMnemonic()->getMnemonicField();
    /*writes end record to object file with address of first executable instruction*/
    if (mnemonic == END) {
        executeEnd(program->getStatements()[program->getStatements().size() - 1], symbolTable);
        listingWriter->writeLine(program->getStatements().size() * 5,
                                 program->getStatements()[program->getStatements().size() - 1], objectCode);
    }
}

void PassTwoController::executeStart(Statement *statement, Program *program) {
    std::string label = statement->getLabel()->getLabelField();
    int operand = statement->getOperand()->getLCIncrement();
    /*if source name more than 6 characters ..error*/
    if (label.length() > MAX_SOURCENAME_LENGTH) {
        throw ErrorHandler::invalid_source_name;
    }
    objectWriter->writeHeader(label, Hexadecimal::intToHex(operand),
                                 Hexadecimal::intToHex(program->getProgramLength()));
}

/*typical case of instruction*/
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
    // Rsub fails here, we need to check for it or sth.
    objectWriter->writeTextRecord(objectCode, Hexadecimal::intToHex(statement->getStatementLocationPointer()));
    return objectCode;
}

void PassTwoController::executeRES() {
    objectWriter->newRecord = true;
}

std::string PassTwoController::executeWord(Statement *statement) {
    std::string address = Hexadecimal::intToHex(statement->getOperand()->getintValue());
    //Error if word length > 3 bytes.
    if (address.length() > MAX_WORD_LENGTH) {
        throw ErrorHandler::address_out_of_range;
    }
    std::string location = Hexadecimal::intToHex(statement->getStatementLocationPointer());
    objectWriter->writeTextRecord(address, location);
    return address;
}

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
