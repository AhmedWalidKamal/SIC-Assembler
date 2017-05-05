//
// Created by SalmaAhmed on 5/1/2017.
//

#include "PassTwoController.h"
#include "../format/Format.h"
#include "../statement/Statement.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

/*constructor*/
PassTwoController::PassTwoController(vector<Statement> statements, int programLength, string objectFile, unordered_map<std::string, std::pair<int, Format *> > &instructionTable, unordered_map<std::string, int> &symbolTable) {

    this->statements=statements;
    this ->programLength=programLength;
    this -> outputFile =objectFile;
    this -> objectWriter= new ObjectFileWriter(objectFile);
    this->hexadecimalConverter=new Hexadecimal();
    this->instructionTable=instructionTable;
    this->symbolTable=symbolTable;
}

/*responsible for execution of pass2*/
void PassTwoController::executePass2() {
    string mnemonic;
    for (int i = 0; i < statements.size() - 1; i++) {
        if (!statements[i].isComment()) {
            mnemonic = statements[i].getMnemonic()->getMnemonicField();

            /*writes header to objectFile.*/
            if (mnemonic == "START") {
                executeStart(statements[i]);
            }else if (mnemonic == "BYTE") {
                executeByte(statements[i]);
            }else if (mnemonic == "WORD") {
               executeWord(statements[i]);
            }else if (mnemonic == "RESW" || mnemonic == "RESB") {
               //has no object code but force the start of a new record.
                string locationCounter=hexadecimalConverter->intToHex(statements[i].getStatementLocationPointer());
                executeRES(locationCounter);
            } else {
                executeInstruction(statements[i]);
            }
        }
    }
    /*writes end record to object file with address of first executable instruction*/
    if (mnemonic == "END") {
        executeEnd(statements[statements.size() - 1]);
    }
}

void PassTwoController::executeStart(Statement statement) {
    string label=statement.getLabel()->getLabelField();
    int operand=statement.getOperand()->getintValue();
     if (label.length() > 6) {
        //error program name does not fit
     } else {
        objectWriter->writeHeader(label, hexadecimalConverter->intToHex(operand), hexadecimalConverter->intToHex(programLength));
        objectWriter->startNewRecord(hexadecimalConverter->intToHex(operand)); //initialize a new record
     }
}
/*typical case of instruction*/
void PassTwoController::executeInstruction(Statement statement) {
    string mnemonic=statement.getMnemonic()->getMnemonicField();
    string objectCode=hexadecimalConverter->intToHex(instructionTable[mnemonic].first);//opCode
    bool isIndexed;//statement.getOperand().isIndexed();TODO after method isIndexed is added to operand class
    if (statement.getOperand()->isLabel()) {
        string label = statement.getOperand()->getValue();
        if(isIndexed){
            //1 is added to leftmost bit of address if indexed which is equal to 32768 in decimal and 8000 in hexa
            objectCode+=hexadecimalConverter->intToHex(symbolTable[label]+INDEXINGVALUE);
        }
        else{
            objectCode+=hexadecimalConverter->intToHex(symbolTable[label]);
        }
    } else{
        objectCode+=hexadecimalConverter->intToHex(statement.getOperand()->getintValue());
    }
    objectWriter->writeTextRecord(objectCode, hexadecimalConverter->intToHex(statement.getStatementLocationPointer()));

}

void PassTwoController::executeRES(string locationCounter) {
    objectWriter->startNewRecord(locationCounter);
}
void PassTwoController::executeWord(Statement statement) {
    string address=hexadecimalConverter->intToHex(statement.getOperand()->getintValue());
    string location=hexadecimalConverter->intToHex(statement.getStatementLocationPointer());
    objectWriter->writeTextRecord(address,location);
}
void PassTwoController::executeByte(Statement statement) {
//two options BYTE C'EOF' for example or BYTE X'F2'
    string address;
    if(statement.getOperand()->isConstant()){ //does is constant indicates it is in form X'..' not C'..'?? TODO check this line
        address=hexadecimalConverter->intToHex(statement.getOperand()->getintValue());
    }
    else {
        address=hexadecimalConverter->stringToHex(statement.getOperand()->getValue());
    }
    objectWriter->writeTextRecord(address,hexadecimalConverter->intToHex(statement.getStatementLocationPointer()));
}
void PassTwoController::executeEnd(Statement statement) {
    if(statements[statements.size()-1].getOperand()->isLabel()){
        string operand=statements[statements.size()-1].getOperand()->getValue();
        objectWriter->writeEndRecord(hexadecimalConverter->intToHex(symbolTable[operand]));
    }
    else{
        int operand=statements[statements.size()-1].getOperand()->getintValue();
        objectWriter->writeEndRecord(hexadecimalConverter->intToHex(operand));
    }
}