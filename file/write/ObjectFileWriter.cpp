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
void ObjectFileWriter::writeHeader(std::string sourceName, std::string startAddress,std::string length) {

    outFile<<"H"<<"^";
    sourceName=fillSpaces(sourceName,fieldLength);
    //write the program name.
    outFile<<sourceName<<"^";
    startAddress=fillZeros(startAddress,fieldLength);
    //write the hexadecimal start address.
    outFile<<startAddress<<"^";
    //write the program length.
    outFile<<length<<"\n";

}
//writes whole text record after concatenating many instructions object code to the string record.
void ObjectFileWriter::writeTextRecord() {
    recordLength=hexadecimalConverter->intToHex(3*record.length());
    outFile<<recordLength<<record<<"\n";

}


/*performs writing of typical case of instruction object code*/
void ObjectFileWriter::writeTextRecord(string objectCode,string locationCounter) {
    objectCode=fillZeros(objectCode,fieldLength);
    //check if after adding this instruction object code will fit or i need to start a new record.
     if(objectCode.length()+record.length()>MAXRECORDLEN){
         writeTextRecord();
         startNewRecord(locationCounter);//TODO check this line
     }
    record+=objectCode+SEPARATOR;


}

void ObjectFileWriter::startNewRecord(string startAddress) {
    record="";
    outFile<<"T"<<"^";
    outFile<<fillZeros(startAddress,fieldLength)<<"^";
}

void ObjectFileWriter::writeEndRecord(string startAddress) {
    outFile<<"E"<<"^";
    startAddress=fillZeros(startAddress,fieldLength);
    //write address of first executable statement in the program.
    outFile<<startAddress;
    outFile.close();

}

/*to be implemented for SIC/XE later.*/
void ObjectFileWriter::writeModRecord() {

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
