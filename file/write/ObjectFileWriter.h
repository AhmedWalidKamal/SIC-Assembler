//
// Created by SalmaAhmed on 01/05/2017.
//

#ifndef SIC_ASSEMBLER_OBJECTFILEWRITER_H
#define SIC_ASSEMBLER_OBJECTFILEWRITER_H

#include <string>
#include <fstream>
#include "../../datatypes/Hexadecimal.h"
#include "../../util/StringUtil.h"

class ObjectFileWriter {

public:
    ObjectFileWriter(const std::string &fileName);

    void writeHeader(std::string sourceName, std::string startAddress, std::string length);

    void startNewRecord(std::string startAddress);

    void writeTextRecord();

    void writeTextRecord(std::string objectCode, std::string locationCounter);

    void writeEndRecord(std::string startAddress);

    void writeModRecord();
    int instructionCounter=0;

private:
    std::ofstream objectFileStream;
    StringUtil *stringUtil;
    const std::string fileName;
    const std::string fileExtension;
    std::string record;
    std::string recordLength;
    int MAX_RECORD_LEN = 30;
    std::string SEPARATOR = "^";
    int FIELD_LENGTH = 6;

    std::string getRecordLength(std::string basic_string);
};


#endif //SIC_ASSEMBLER_OBJECTFILEWRITER_H
