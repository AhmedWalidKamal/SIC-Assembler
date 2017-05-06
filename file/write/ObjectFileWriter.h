//
// Created by SalmaAhmed on 01/05/2017.
//

#ifndef SIC_ASSEMBLER_OBJECTFILEWRITER_H
#define SIC_ASSEMBLER_OBJECTFILEWRITER_H
#include <string>
#include "../../datatypes/Hexadecimal.h"
#include "../../util/StringUtil.h"
class ObjectFileWriter {

public:
    //constructor
    ObjectFileWriter(std::string objectCodeFile);

    void writeHeader(std::string sourceName,std::string startAddress,std::string length);
    //writes the whole text record.
    void writeTextRecord();
    //writes only one instruction to the text record.
    void writeTextRecord(std::string objectCode,std::string locationCounter);
    void writeEndRecord(std::string startAddress);
    void writeModRecord();//still to see what paramters shall it take in order to be able to write the modification record
    bool newRecord=false;
private:
    std::string objectCodeFile;
    std::string record;
    std::string recordLength;
    int MAX_RECORD_LEN=60;
    std::string SEPARATOR="^";
    int FIELD_LENGTH=6;
    //writes the start of a new record
    void startNewRecord(std::string startAddress);
};


#endif //SIC_ASSEMBLER_OBJECTFILEWRITER_H
