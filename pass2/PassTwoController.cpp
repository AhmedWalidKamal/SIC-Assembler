//
// Created by SalmaAhmed on 5/1/2017.
//

#include "PassTwoController.h"
#include "../format/Format.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

string label="programName",mnemonic="start",operand="1000"; //TODO replace with fields from the statement.
int size=1; //TODO : replace with the size of the vector of statements from pass1.

string toLower(string word);

PassTwoController::PassTwoController(string intermediateFile, int programLength, string objectFile,unordered_map<std::string, std::pair<int, Format *> > instructionTable,unordered_map<std::string, int> symbolTable) {

    this ->intermediateFile=intermediateFile;
    this ->programLength=programLength;
    this -> outputFile =objectFile;
    this -> objectWriter= new ObjectFileWriter(objectFile);
}
void PassTwoController::executePass2() {
   for(int i=0;i<size;i++){
       /*writes header to objectFile.*/
       if(toLower(mnemonic)=="start"){
           objectWriter->writeHeader(label,operand,programLength);
       }
       /*writes end record to object file with address of first executable instruction*/
       else if(toLower(mnemonic)=="end"){
         objectWriter->writeEndRecord(operand);
       }
       else{

       }
   }

    /* after the loop on the program finishes
     * 1-write modification records.
     * 2-write the end record.*/

}

/*utility method to lower all the characters of a string */
string toLower(string word){
    transform(word.begin(),word.end(),word.begin(),::tolower);
    return word;
}
