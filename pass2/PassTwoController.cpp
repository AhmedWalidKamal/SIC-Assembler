//
// Created by SalmaAhmed on 5/1/2017.
//

#include "PassTwoController.h"
#include <iostream>

/*constructor*/
PassTwoController::PassTwoController(std::vector<bool> hasLabel, std::vector<int> operandsValues,
                                     std::vector<Statement> statements, int programLength,
                                     const std::string &objectName, const std::string objectExtension,
                                     const std::string &listingName,
                                     const std::string listingExtension,
                                     std::unordered_map<std::string, int> &instructionTable,
                                     std::unordered_map<std::string, int> &symbolTable)
        : objectName(objectName), objectExtension(objectExtension), listingName(objectName),
          listingExtension(objectExtension) {

    this->hasLabel = hasLabel;
    this->operandsValues = operandsValues;
    this->statements = statements;
    this->programLength = programLength;
    this->objectWriter = new ObjectFileWriter(objectName, objectExtension);
    this->listingWriter = new ListingFileWriter(listingName, listingExtension);
    this->hexadecimalConverter = new Hexadecimal();
    this->instructionTable = instructionTable;
    this->symbolTable = symbolTable;
    this->objectCode = "";
}

/*responsible for execution of pass2*/
void PassTwoController::executePass2() {
    listingWriter->writeInitialLine();
    std::string mnemonic;
    for (int i = 0; i < statements.size() - 1; i++) {
        if (statements[i].isComment()) {
            listingWriter->writeComment(i*5, statements[i].getStatementField());}
        else{
            mnemonic = statements[i].getMnemonic()->getMnemonicField();
            try {
                /*writes header to objectFile.*/
                if (mnemonic == START) {
                    executeStart(statements[i], i);
                } else if (mnemonic == BYTE) {
                    objectCode = executeByte(statements[i]);
                } else if (mnemonic == WORD) {
                    objectCode = executeWord(statements[i], i);
                } else if (mnemonic == RESW || mnemonic == RESB) {
                    //has no object code but force the start of a new record.
                    executeRES();
                } else {
                    objectCode = executeInstruction(statements[i], i);
                }
            } catch (ErrorHandler::Error error) {
                //write the error to listing file.
                listingWriter->writeError(error);
            }
            listingWriter->writeLine(i * 5, statements[i], objectCode);
            objectCode = "";
        }
    }
    mnemonic = statements[statements.size() - 1].getMnemonic()->getMnemonicField();
    /*writes end record to object file with address of first executable instruction*/
    if (mnemonic == END) {
        executeEnd(statements.[statements.size() - 1]);
        listingWriter->writeLine(statements.size() * 5, statements[statements.size() - 1], objectCode);
    }
}

void PassTwoController::executeStart(Statement statement, int i) {
    std::string label = statement.getLabel()->getLabelField();
    int operand = operandsValues[i];
    //int operand=statement.getOperand()->getintValue();
    /*if source name more than 6 characters ..error*/
    if (label.length() > MAX_SOURCENAME_LENGTH)
        throw ErrorHandler::invalid_source_name;

    objectWriter->writeHeader(label, hexadecimalConverter->intToHex(operand),
                              hexadecimalConverter->intToHex(programLength));
}

/*typical case of instruction*/
std::string PassTwoController::executeInstruction(Statement statement, int i) {
    std::string mnemonic;
    mnemonic = statement.getMnemonic()->getMnemonicField();
    std::string objectCode = hexadecimalConverter->intToHex(
            instructionTable[mnemonic]);//TODO opCode//change later b map of string ,instruction msh string int
    bool isIndexed = false;//statement.getOperand().isIndexed();TODO after method isIndexed is added to operand class
    //if (statement.getOperand()->isLabel()) {
    if (hasLabel[i]) {
        std::string operand = statement.getOperand()->getOperandField();
        if (symbolTable[operand] == -1)
            throw ErrorHandler::undeclared_label;
        if (isIndexed) {
            //1 is added to leftmost bit of address if indexed which is equal to 32768 in decimal and 8000 in hexa
            objectCode += hexadecimalConverter->intToHex(symbolTable[operand] + INDEXINGVALUE);
        } else {
            objectCode += hexadecimalConverter->intToHex(symbolTable[operand]);
        }
    } else {
        //objectCode+=hexadecimalConverter->intToHex(statement.getOperand()->getintValue());
        objectCode += hexadecimalConverter->intToHex(operandsValues[i]);
    }
    objectWriter->writeTextRecord(objectCode, hexadecimalConverter->intToHex(statement.getStatementLocationPointer()));
    return objectCode;
}

void PassTwoController::executeRES() {
    objectWriter->newRecord = true;

}

std::string PassTwoController::executeWord(Statement statement, int i) {
    std::string address = hexadecimalConverter->intToHex(operandsValues[i]);
    //string address=hexadecimalConverter->intToHex(statement.getOperand()->getintValue());
    //Error if word length > 3 bytes.
    if (address.length() > MAX_WORD_LENGTH)
        throw ErrorHandler::address_out_of_range;

    std::string location = hexadecimalConverter->intToHex(statement.getStatementLocationPointer());
    objectWriter->writeTextRecord(address, location);
    return address;
}

std::string PassTwoController::executeByte(Statement statement) {
    std::string address;
    bool flag = false;
    if (flag) { //does is constant indicates it is in form X'..' not C'..'?? TODO check this line
        // address=hexadecimalConverter->intToHex(statement.getOperand()->getintValue());
    } else {
        address = hexadecimalConverter->stringToHex(statement.getOperand()->getOperandField());
    }
    //max length for BYTE is 14 hexadecimal digits.
    if (address.length() > MAX_BYTE_LENGTH)
        throw ErrorHandler::address_out_of_range;

    objectWriter->writeTextRecord(address, hexadecimalConverter->intToHex(statement.getStatementLocationPointer()));
    return address;
}

void PassTwoController::executeEnd(Statement statement) {
    if (hasLabel[statements.size() - 1]) {
        //if(statements[statements.size()-1].getOperand()->isLabel()){
        std::string operand = statements[statements.size() - 1].getOperand()->getOperandField();
        if (symbolTable[operand] == -1)
            throw ErrorHandler::undeclared_label;
        objectWriter->writeEndRecord(hexadecimalConverter->intToHex(symbolTable[operand]));
    } else {
        int operand = operandsValues[statements.size() - 1];
        //int operand=statements[statements.size()-1].getOperand()->getintValue();
        objectWriter->writeEndRecord(hexadecimalConverter->intToHex(operand));
    }
}
