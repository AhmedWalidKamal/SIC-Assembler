//
// Created by SalmaAhmed on 01/05/2017.
//

#include <fstream>
#include "ObjectFileWriter.h"

int fieldLength=6;
ofstream outFile;

string fillSpaces(std::string word,int size);

string fillZeros(std::string word,int size);

ObjectFileWriter::ObjectFileWriter(std::string objectCodeFile) {

    this ->objectCodeFile=objectCodeFile;
    outFile.open (objectCodeFile);
    this->hexadecimalConverter=new Hexadecimal();


}
void ObjectFileWriter::writeHeader(std::string sourceName, int startAddress,int length) {

    outFile<<"H"<<"^";
    sourceName=fillSpaces(sourceName,fieldLength);
    //write the program name.
    outFile<<sourceName<<"^";
    std::string start=fillZeros(hexadecimalConverter->intToHex(startAddress),fieldLength);
    //write the hexadecimal start address.
    outFile<<start<<"^";
    //convert the length of the program from integer to hexadecimal.
    outFile<<hexadecimalConverter->intToHex(length)<<"\n";

}
//writes whole text record after concatenating many instructions object code to the string record.
void ObjectFileWriter::writeTextRecord() {
    recordLength=hexadecimalConverter->intToHex(3*record.length());
    outFile<<recordLength<<record<<"\n";

}

/*performs writing of special cases of object code for WORD,BYTE,....*/
void ObjectFileWriter::writeTextRecord(int address) {
    record+=fillZeros(hexadecimalConverter->intToHex(address),fieldLength);
}

/*performs writing of typical case of instruction object code*/
void ObjectFileWriter::writeTextRecord(int opCode,bool isIndexed, int address,int locationCounter) {
    std::string objectCode;
     if(isIndexed){
         objectCode+=hexadecimalConverter->intToHex(opCode);
         //1 is added to leftmost bit of address if indexed which is equal to 32768 in decimal and 8000 in hexa
         objectCode+=hexadecimalConverter->intToHex(address+INDEXINGVALUE);
     }
    else{
         objectCode+=hexadecimalConverter->intToHex(opCode);
         objectCode+=hexadecimalConverter->intToHex(address);
     }
    //check if after adding this instruction object code will fit or i need to start a new record.
     if(objectCode.length()+record.length()>MAXRECORDLEN){
         writeTextRecord();
         startNewRecord(locationCounter);//TODO check this line
     }
    record+=objectCode+SEPARATOR;


}

void ObjectFileWriter::startNewRecord(int startAddress) {
    record="";
    outFile<<"T"<<"^";
    outFile<<fillZeros(hexadecimalConverter->intToHex(startAddress),fieldLength)<<"^";
}
/*to be implemented for SIC/XE later.*/
void ObjectFileWriter::writeModRecord() {

}

void ObjectFileWriter::writeEndRecord(int startAddress) {
    outFile<<"E"<<"^";
    std::string address=fillZeros(hexadecimalConverter->intToHex(startAddress),fieldLength);
    //write address of first executable statement in the program.
    outFile<<address;
    outFile.close();

}

string fillSpaces(std::string word,int size){
    while(word.length()<size) {
        word+=" ";
    }
    return word;
}
string fillZeros(std::string word,int size){
    while(word.length()<size) {
        word="0"+word;
    }
    return word;
}
