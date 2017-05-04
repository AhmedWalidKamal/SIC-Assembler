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

string label="Copy",mnemonic="START",operandLabel="Buffer";int operand=4096,locationCounter=1; //TODO replace with fields from the statement.
int size=1; //TODO : replace with the size of the vector of statements from pass1.

string toString(int number) ;

/*constructor*/
PassTwoController::PassTwoController(vector<Statement> statement, int programLength, string objectFile, unordered_map<std::string, std::pair<int, Format *> > &instructionTable, unordered_map<std::string, int> &symbolTable) {
    
    this ->programLength=programLength;
    this -> outputFile =objectFile;
    this -> objectWriter= new ObjectFileWriter(objectFile);
    this->instructionTable=instructionTable;
    this->symbolTable=symbolTable;
}

/*responsible for execution of pass2*/
void PassTwoController::executePass2() {
   for(int i=0;i<size;i++){
       /*writes header to objectFile.*/
       if(mnemonic=="START"){
           if(label.length()>6){
               //error program name does not fit
           }
         else{
           objectWriter->writeHeader(label,operand,programLength);
           objectWriter->startNewRecord(operand); //initialize a new record
           }
       }
       else if(mnemonic=="BYTE"){
           //two options BYTE C'EOF' for example or BYTE X'F2' is there other options ???
       }
       else if(mnemonic=="WORD"){
         objectWriter->writeTextRecord(operand);
       }
       else if(mnemonic=="RESW"||mnemonic=="RESB"){
           //has no object code but force the start of a new record.
           objectWriter->startNewRecord(locationCounter);
       }
       else{
           /*construct object code for typical case of the instruction*/
           if(operand.isLabel()){
               objectWriter->writeTextRecord(instructionTable[mnemonic].first,statement.isIndexed(),symbolTable[operandLabel],statement.getLocationCounter());

           } //else
               //in the lecture it says set address=0 and output an error msg no symbol in operand ??check???
               //objectWriter->writeTextRecord(instructionTable[mnemonic].first,statement.isIndexed(),operand);


       }
   }


    /* after the loop on the program finishes
     * 1-write modification records(IN CASE OF SIC/XE "ONLY").
     * 2-write the end record.*/
    /*writes end record to object file with address of first executable instruction*/
    if(mnemonic=="END"){
        if(operand.isLabel()){
            objectWriter->writeEndRecord(symbolTable[operandLabel]);
        }
        else
            objectWriter->writeEndRecord(operand);
    }

}
/*utility method convert integer to string*/
string toString(int number) {
    ostringstream stream;
    stream << number;
    return stream.str();;
}
