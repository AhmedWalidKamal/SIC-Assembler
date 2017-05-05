//
// Created by SalmaAhmed on 01/05/2017.
//

#ifndef SIC_ASSEMBLER_OBJECTFILEWRITER_H
#define SIC_ASSEMBLER_OBJECTFILEWRITER_H
#include <string>
#include "../../datatypes/Hexadecimal.h"

class ObjectFileWriter {

public:
    //constructor
    ObjectFileWriter(string objectCodeFile);

    void writeHeader(string sourceName,string startAddress,string length);
    //writes the whole text record.
    void writeTextRecord();
    //writes only one instruction to the text record.
    void writeTextRecord(string objectCode,string locationCounter);
    void writeEndRecord(string startAddress);
    void writeModRecord();//still to see what paramters shall it take in order to be able to write the modification record
    bool newRecord=false;
private:
    Hexadecimal *hexadecimalConverter;
    string objectCodeFile;
    string record;
    string recordLength;
    int MAX_RECORD_LEN=60;
    string SEPARATOR="^";
    int FIELD_LENGTH=6;
    //writes the start of a new record
    void startNewRecord(string startAddress);
    std::string fillSpaces(std::string,int length);
    std::string fillZeros(std::string,int length);
};


#endif //SIC_ASSEMBLER_OBJECTFILEWRITER_H
