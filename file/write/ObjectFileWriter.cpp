//
// Created by SalmaAhmed on 01/05/2017.
//

#include <fstream>
#include <iostream>
#include "ObjectFileWriter.h"

ObjectFileWriter::ObjectFileWriter(const std::string &fileName, const std::string fileExtension)
        : fileName(fileName), fileExtension(fileExtension) {

    ObjectFileWriter::objectFileStream.open(std::string(fileName).append(fileExtension));
}

void ObjectFileWriter::writeHeader(std::string sourceName, std::string startAddress, std::string length) {

    objectFileStream << "H" << "^";
    sourceName = StringUtil::fillSpaces(sourceName, FIELD_LENGTH);
    objectFileStream << sourceName << "^";
    startAddress = StringUtil::fillZeros(startAddress, FIELD_LENGTH);
    objectFileStream << startAddress << "^";
    objectFileStream << length << "\n";
    newRecord = true;
    startNewRecord(startAddress);
    newRecord = false;
}

//writes whole text record after concatenating many instructions object code to the string record.
void ObjectFileWriter::writeTextRecord() {
    recordLength = Hexadecimal::intToHex(3 * record.length());
    objectFileStream << recordLength << record << "\n";

}


/*performs writing of typical case of instruction object code*/
void ObjectFileWriter::writeTextRecord(std::string objectCode, std::string locationCounter) {
    objectCode = StringUtil::fillZeros(objectCode, FIELD_LENGTH);
    //check if after adding this instruction object code will fit or i need to start a new record.
    if (objectCode.length() + record.length() > MAX_RECORD_LEN || newRecord) {
        writeTextRecord();
        startNewRecord(locationCounter);//TODO check this line
        newRecord = false;
    }
    record += SEPARATOR + objectCode;


}

void ObjectFileWriter::startNewRecord(std::string startAddress) {
    if (newRecord) {
        record = "";
        objectFileStream << "T" << "^";
        objectFileStream << StringUtil::fillZeros(startAddress, FIELD_LENGTH) << "^";
    }
}

void ObjectFileWriter::writeEndRecord(std::string startAddress) {
    writeTextRecord();
    objectFileStream << "E" << "^";
    startAddress = StringUtil::fillZeros(startAddress, FIELD_LENGTH);
    objectFileStream << startAddress;
    objectFileStream.close();

}

/*to be implemented*/
void ObjectFileWriter::writeModRecord() {

}


