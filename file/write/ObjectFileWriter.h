//
// Created by SalmaAhmed on 01/05/2017.
//

#ifndef SIC_ASSEMBLER_OBJECTFILEWRITER_H
#define SIC_ASSEMBLER_OBJECTFILEWRITER_H

#include <string>
#include <fstream>
#include "../../datatypes/Hexadecimal.h"
#include "../../util/StringUtil.h"
#include "TextRecord.h"

class ObjectFileWriter {

public:
    ObjectFileWriter(const std::string &fileName);

    void writeHeader(std::string sourceName, std::string startAddress, std::string length);

    void startNewTextRecord(int address);

    void addRecordToTextRecord(std::string objectCode, int address);

    void writeCurrentTextRecord();

    void writeEndRecord(std::string startAddress);

    void writeModRecord();

private:
    std::ofstream objectFileStream;
    const std::string fileName;
    const std::string fileExtension;
    int MAX_RECORD_LEN = 30;
    std::string SEPARATOR = "^";
    int FIELD_LENGTH = 6;
    TextRecord *textRecord;
};


#endif //SIC_ASSEMBLER_OBJECTFILEWRITER_H
