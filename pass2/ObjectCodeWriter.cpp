//
// Created by SalmaAhmed on 01/05/2017.
//

#include <fstream>
#include "ObjectCodeWriter.h"

// string separator="^";

void ObjectCodeWriter::ObjectCodeWriter(string objectCodeFile) {
    this ->objectCodeFile=objectCodeFile;

}
void ObjectCodeWriter::writeHeader( string sourceName, string startAddress,string length) {
    ofstream outFile;
    outFile.open (objectCodeFile);
    outFile<<"H"<<"^";
    while(sourceName.length()<6){
        sourceName+=" ";
    }
    outFile<<sourceName<<"^";
    //convert start address to hexadecimal address then write it to header
    //length is given by hexadecimal from pass1 or is it given binary to be converted here????



}
void ObjectCodeWriter::writeTextRecord(string startAddress, string opCode, string recordLength) {

}
void ObjectCodeWriter::writeModRecord() {

}
void ObjectCodeWriter::writeEndRecord(string startAddress) {

}