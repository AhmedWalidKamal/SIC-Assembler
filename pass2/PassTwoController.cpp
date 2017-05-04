//
// Created by SalmaAhmed on 5/1/2017.
//

#include "PassTwoController.h"
#include "../format/Format.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

string label="Copy",mnemonic="START";int operand=4096; //TODO replace with fields from the statement.
int size=1; //TODO : replace with the size of the vector of statements from pass1.

string toString(int number) ;

/*constructor*/
PassTwoController::PassTwoController(string intermediateFile, int programLength, string objectFile, unordered_map<std::string, std::pair<int, Format *> > &instructionTable, unordered_map<std::string, int> &symbolTable) {

    this ->intermediateFile=intermediateFile;
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
           locationCounter=operand;
           objectWriter->writeHeader(label,operand,programLength);
           objectWriter->startNewRecord(operand); //initialize a new record
           }
       }
       else if(mnemonic=="BYTE"){

       }
       else if(mnemonic=="WORD"){

       }
       else if(mnemonic=="RESW"){
           //has no object code but force the start of a new record.
       }
       else if(mnemonic=="RESB"){
           //has no object code but forces the start of a new record.
       }
       else{
           /*construct object code for the instruction*/
         /*string objectCode=toString(instructionTable[mnemonic].first);//first opcode
           if(operand.isLabel()){
               objectCode+=toString(symbolTable[operand]);

           } /*else operand is not a label but direct number ???is this case available in SIC machines
               objectCode+=*/


       }
   }


    /* after the loop on the program finishes
     * 1-write modification records.
     * 2-write the end record.*/


    /*writes end record to object file with address of first executable instruction*/
    /*if(mnemonic=="END"){
        if(operand.isLabel()){
            string address=toString(symbolTable[operand]);
            objectWriter->writeEndRecord(address);
        }
        else
            objectWriter->writeEndRecord(operand);
    }*/

}
/*utility method convert integer to string*/
string toString(int number) {
    ostringstream stream;
    stream << number;
    return stream.str();;
}
