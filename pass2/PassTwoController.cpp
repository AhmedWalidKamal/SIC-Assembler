//
// Created by SalmaAhmed on 5/1/2017.
//

#include "PassTwoController.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

/*constructor*/
PassTwoController::PassTwoController(vector<bool> hasLabel,vector<int>operandsValues,vector<Statement> &statements, int programLength, string objectFile ,string listingFile, std::unordered_map<std::string, int> &instructionTable, unordered_map<std::string, int> &symbolTable) {

    this->hasLabel=hasLabel;
    this->operandsValues=operandsValues;
    this->statements=statements;
    this ->programLength=programLength;
    this ->objectWriter= new ObjectFileWriter(objectFile);
    this->listingWriter=new ListingFileWriter(listingFile);
    this->hexadecimalConverter=new Hexadecimal();
    this->instructionTable=instructionTable;
    this->symbolTable=symbolTable;
    this->objectCode="";
}

/*responsible for execution of pass2*/
void PassTwoController::executePass2() {
    listingWriter->writeInitialLine();
    string mnemonic;
    for (int i = 0; i < statements.size() - 1; i++) {
        if (!statements[i].isComment()) {
            mnemonic = statements[i].getMnemonic()->getMnemonicField();
            /*writes header to objectFile.*/
            if (mnemonic == "START") {
                executeStart(statements[i],i);
            }else if (mnemonic == "BYTE") {
                objectCode=executeByte(statements[i]);
            }else if (mnemonic == "WORD") {
               objectCode=executeWord(statements[i],i);
            }else if (mnemonic == "RESW" || mnemonic == "RESB") {
               //has no object code but force the start of a new record.
                executeRES();
            } else {
                objectCode=executeInstruction(statements[i],i);
            }
        }
        listingWriter->writeLine(i*5,statements[i],objectCode);
        objectCode="";
    }
    mnemonic = statements[statements.size()-1].getMnemonic()->getMnemonicField();
    /*writes end record to object file with address of first executable instruction*/
    if (mnemonic == "END") {
        executeEnd(statements[statements.size() - 1]);
        listingWriter->writeLine(statements.size()*5,statements[statements.size()-1],objectCode);
    }
}

void PassTwoController::executeStart(Statement statement,int i) {
    string label=statement.getLabel()->getLabelField();
    int operand=operandsValues[i];
    //int operand=statement.getOperand()->getintValue();
     if (label.length() > 6) {
        //error program name does not fit
     } else {
         objectWriter->writeHeader(label, hexadecimalConverter->intToHex(operand), hexadecimalConverter->intToHex(programLength));
     }
}
/*typical case of instruction*/
std::string PassTwoController::executeInstruction(Statement statement,int i) {
    string mnemonic=statement.getMnemonic()->getMnemonicField();
    string objectCode=hexadecimalConverter->intToHex(instructionTable[mnemonic]);//opCode//change later b map of string ,instruction msh string int
    bool isIndexed=false;//statement.getOperand().isIndexed();TODO after method isIndexed is added to operand class
    //if (statement.getOperand()->isLabel()) {
    if(hasLabel[i]){
        string label = statement.getOperand()->getOperandField();
        if(isIndexed){
            //1 is added to leftmost bit of address if indexed which is equal to 32768 in decimal and 8000 in hexa
            objectCode+=hexadecimalConverter->intToHex(symbolTable[label]+INDEXINGVALUE);
        }
        else{
            objectCode+=hexadecimalConverter->intToHex(symbolTable[label]);
        }
    } else{
        //objectCode+=hexadecimalConverter->intToHex(statement.getOperand()->getintValue());
        objectCode+=hexadecimalConverter->intToHex(operandsValues[i]);
    }
    objectWriter->writeTextRecord(objectCode, hexadecimalConverter->intToHex(statement.getStatementLocationPointer()));
 return objectCode;
}

void PassTwoController::executeRES() {
    objectWriter->newRecord=true;

}
std::string PassTwoController::executeWord(Statement statement,int i) {
    string address=hexadecimalConverter->intToHex(operandsValues[i]);
    //string address=hexadecimalConverter->intToHex(statement.getOperand()->getintValue());
    string location=hexadecimalConverter->intToHex(statement.getStatementLocationPointer());
    objectWriter->writeTextRecord(address,location);
    return address;
}
std::string PassTwoController::executeByte(Statement statement) {
    string address;
    bool flag=false;
    if(flag){ //does is constant indicates it is in form X'..' not C'..'?? TODO check this line
       // address=hexadecimalConverter->intToHex(statement.getOperand()->getintValue());
    }
    else {
        address=hexadecimalConverter->stringToHex(statement.getOperand()->getOperandField());
    }
    objectWriter->writeTextRecord(address,hexadecimalConverter->intToHex(statement.getStatementLocationPointer()));
    return address;
}

void PassTwoController::executeEnd(Statement statement) {
    if(hasLabel[statements.size()-1]){
    //if(statements[statements.size()-1].getOperand()->isLabel()){
        string operand=statements[statements.size()-1].getOperand()->getOperandField();
        objectWriter->writeEndRecord(hexadecimalConverter->intToHex(symbolTable[operand]));
    }
    else{
          int operand=operandsValues[statements.size()-1];
        //int operand=statements[statements.size()-1].getOperand()->getintValue();
        objectWriter->writeEndRecord(hexadecimalConverter->intToHex(operand));
    }
}