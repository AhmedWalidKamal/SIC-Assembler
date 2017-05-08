//
// Created by SalmaAhmed on 01/05/2017.
//

#include <fstream>
#include <iostream>
#include "ObjectFileWriter.h"

ObjectFileWriter::ObjectFileWriter(const std::string &fileName)
        : fileName(fileName), fileExtension(".obj") {
    ObjectFileWriter::objectFileStream.open(std::string(fileName).append(fileExtension));
}

void ObjectFileWriter::writeHeader(std::string sourceName, std::string startAddress, std::string length) {

    objectFileStream << "H" << "^";
    sourceName = StringUtil::fillSpaces(sourceName, FIELD_LENGTH);
    objectFileStream << sourceName << "^";
    startAddress = StringUtil::fillZeros(startAddress, FIELD_LENGTH);
    objectFileStream << startAddress << "^";
    objectFileStream << length << std::endl;
    startNewRecord(startAddress);
}

void ObjectFileWriter::writeTextRecord() {
    recordLength = getRecordLength(record);
    objectFileStream << recordLength << SEPARATOR << record << std::endl;
}

void ObjectFileWriter::writeTextRecord(std::string objectCode, std::string locationCounter) {
    objectCode = StringUtil::fillZeros(objectCode, FIELD_LENGTH);
    //check if after adding this instruction object code will fit or i need to start a new record.
    instructionCounter++;
    std::string temp = record + objectCode;
    std::string modifiedString = "";
    for (char curr : temp) {
        if (curr != '^') {
            modifiedString.push_back(curr);
        }
    }
    if(modifiedString.length() / 2 > ObjectFileWriter::MAX_RECORD_LEN) {
        writeTextRecord();
        startNewRecord(locationCounter);
    }
    record += objectCode + SEPARATOR;
}

void ObjectFileWriter::startNewRecord(std::string startAddress) {
        record = "";
        instructionCounter = 0;
        objectFileStream << "T" << "^";
        objectFileStream << StringUtil::fillZeros(startAddress, FIELD_LENGTH) << "^";
}

void ObjectFileWriter::writeEndRecord(std::string startAddress) {
    writeTextRecord();
    objectFileStream << "E" << "^";
    startAddress = StringUtil::fillZeros(startAddress, FIELD_LENGTH);
    objectFileStream << startAddress;
    objectFileStream.close();
}

void ObjectFileWriter::writeModRecord() {

}

std::string ObjectFileWriter::getRecordLength(std::string record) {
    std::string modifiedString = "";
    for (char curr : record) {
        if (curr != '^') {
            modifiedString.push_back(curr);
        }
    }
    return Hexadecimal::intToHex(modifiedString.length() / 2);
}

