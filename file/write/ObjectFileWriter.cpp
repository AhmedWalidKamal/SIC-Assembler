//
// Created by SalmaAhmed on 01/05/2017.
//

#include <fstream>
#include <iostream>
#include "ObjectFileWriter.h"

std::ofstream outFile;

ObjectFileWriter::ObjectFileWriter(std::string objectCodeFile) {

    this ->objectCodeFile=objectCodeFile;
    outFile.open (objectCodeFile);
}
void ObjectFileWriter::writeHeader(std::string sourceName, std::string startAddress,std::string length) {

    outFile<<"H"<<"^";
    sourceName=StringUtil::fillSpaces(sourceName,FIELD_LENGTH);
    outFile<<sourceName<<"^";
    startAddress=StringUtil::fillZeros(startAddress,FIELD_LENGTH);
    outFile<<startAddress<<"^";
    outFile<<length<<"\n";
    newRecord=true;
    startNewRecord(startAddress);
    newRecord=false;
}
//writes whole text record after concatenating many instructions object code to the string record.
void ObjectFileWriter::writeTextRecord() {
    recordLength=Hexadecimal::intToHex(3*record.length());
    outFile<<recordLength<<record<<"\n";

}


/*performs writing of typical case of instruction object code*/
void ObjectFileWriter::writeTextRecord(std::string objectCode,std::string locationCounter) {
    objectCode=StringUtil::fillZeros(objectCode,FIELD_LENGTH);
    //check if after adding this instruction object code will fit or i need to start a new record.
     if(objectCode.length()+record.length()>MAX_RECORD_LEN||newRecord){
         writeTextRecord();
         startNewRecord(locationCounter);//TODO check this line
         newRecord=false;
     }
    record+=SEPARATOR+objectCode;


}

void ObjectFileWriter::startNewRecord(std::string startAddress) {
    if(newRecord){
     record="";
     outFile<<"T"<<"^";
     outFile<<StringUtil::fillZeros(startAddress,FIELD_LENGTH)<<"^";
    }
}

void ObjectFileWriter::writeEndRecord(std::string startAddress) {
    writeTextRecord();
    outFile<<"E"<<"^";
    startAddress=StringUtil::fillZeros(startAddress,FIELD_LENGTH);
    outFile<<startAddress;
    outFile.close();

}

/*to be implemented*/
void ObjectFileWriter::writeModRecord() {

}


