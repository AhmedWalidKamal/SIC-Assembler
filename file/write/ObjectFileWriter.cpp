//
// Created by SalmaAhmed on 01/05/2017.
//

#include <fstream>
#include <iostream>
#include "ObjectFileWriter.h"

ObjectFileWriter::ObjectFileWriter(const std::string &fileName)
        : fileName(fileName), fileExtension(".obj") {
    ObjectFileWriter::objectFileStream.open(std::string(fileName).append(fileExtension));
    stringUtil = new StringUtil();
}

void ObjectFileWriter::writeHeader(std::string sourceName, std::string startAddress, std::string length) {

    objectFileStream << "H" << "^";
    sourceName = stringUtil->fillSpaces(sourceName, FIELD_LENGTH);
    objectFileStream << sourceName << "^";
    startAddress = stringUtil->fillZeros(startAddress, FIELD_LENGTH);
    objectFileStream << startAddress << "^";
    objectFileStream << length << "\n";
    //newRecord = true;
    startNewRecord(startAddress);
    //newRecord = false;
}

//writes whole text record after concatenating many instructions object code to the string record.
void ObjectFileWriter::writeTextRecord() {
    recordLength = Hexadecimal::intToHex(3 * record.length());
    objectFileStream << recordLength <<SEPARATOR<< record << "\n";

}


/*performs writing of typical case of instruction object code*/
void ObjectFileWriter::writeTextRecord(std::string objectCode, std::string locationCounter) {
    objectCode = stringUtil->fillZeros(objectCode, FIELD_LENGTH);
    instructionCounter++;
    //check if after adding this instruction object code will fit or i need to start a new record.
    if(instructionCounter>MAX_RECORD_LEN){
    //if (objectCode.length() + record.length() > MAX_RECORD_LEN /*|| newRecord*/) {
        writeTextRecord();
        startNewRecord(locationCounter);//TODO check this line
        instructionCounter=0;
        //newRecord = false;
    }
    record +=objectCode+SEPARATOR;


}

void ObjectFileWriter::startNewRecord(std::string startAddress) {
    //if (newRecord) {
        record ="";
        objectFileStream << "T" << "^";
        objectFileStream << stringUtil->fillZeros(startAddress, FIELD_LENGTH) << "^";
    //}
}

void ObjectFileWriter::writeEndRecord(std::string startAddress) {
    writeTextRecord();
    objectFileStream << "E" << "^";
    startAddress = stringUtil->fillZeros(startAddress, FIELD_LENGTH);
    objectFileStream << startAddress;
    objectFileStream.close();

}

/*to be implemented*/
void ObjectFileWriter::writeModRecord() {

}


