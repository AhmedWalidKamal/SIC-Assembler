//
// Created by SalmaAhmed on 01/05/2017.
//

#include <fstream>
#include <iostream>
#include "ObjectFileWriter.h"

ObjectFileWriter::ObjectFileWriter(const std::string &fileName)
        : fileName(fileName), fileExtension(".obj") {
    ObjectFileWriter::objectFileStream.open(std::string(fileName).append(fileExtension));
    textRecord = new TextRecord(-1);
}

void ObjectFileWriter::writeHeader(std::string sourceName, std::string startAddress, std::string length) {

    objectFileStream << "H" << "^";
    sourceName = StringUtil::fillSpaces(sourceName, FIELD_LENGTH);
    objectFileStream << sourceName << "^";
    startAddress = StringUtil::fillZeros(startAddress, FIELD_LENGTH);
    objectFileStream << startAddress << "^";
    int offset = FIELD_LENGTH - length.length();
    while (offset--) {
        objectFileStream << "0";
    }
    objectFileStream << length << std::endl;
}

void ObjectFileWriter::writeEndRecord(std::string startAddress) {
    writeCurrentTextRecord();
    objectFileStream << "E";
    if (!startAddress.empty()) {
        startAddress = StringUtil::fillZeros(startAddress, FIELD_LENGTH); // shouldn't this be appending 0s before the address?
        objectFileStream << "^" ;
        objectFileStream<< startAddress;
    }
    objectFileStream.close();
}

void ObjectFileWriter::writeModRecord() {

}

void ObjectFileWriter::writeCurrentTextRecord() {
    if (textRecord->getStartingAddress() != -1) {
        objectFileStream << "T^";
        objectFileStream<< StringUtil::fillZeros(Hexadecimal::intToHex(textRecord->getStartingAddress()), FIELD_LENGTH);
        objectFileStream << "^";
        if (Hexadecimal::intToHex(textRecord->getLength()).length() < 2) {
            objectFileStream << "0" ;
            objectFileStream<< Hexadecimal::intToHex(textRecord->getLength());
        } else {
            objectFileStream << Hexadecimal::intToHex(textRecord->getLength());
        }

        for (auto record : textRecord->getRecords()) {
            objectFileStream << "^" ;
            objectFileStream<< record;
        }
        objectFileStream << std::endl;
    }
}

void ObjectFileWriter::addRecordToTextRecord(std::string objectCode, int address) {
    if ((objectCode.length() / 2) + textRecord->getLength() <= MAX_RECORD_LEN
        && textRecord->getStartingAddress() != -1) {
        textRecord->addRecord(objectCode);
    } else {
        writeCurrentTextRecord();
        startNewTextRecord(address);
        textRecord->addRecord(objectCode);
    }
}

void ObjectFileWriter::startNewTextRecord(int address) {
    textRecord = new TextRecord(address);
}

