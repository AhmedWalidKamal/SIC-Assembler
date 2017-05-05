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
    //writes the start of a new record
    void startNewRecord(string startAddress);
    void writeEndRecord(string startAddress);
    /*to be implemented for SIC/XE only*/
    void writeModRecord();//still to see what paramters shall it take in order to be able to write the modification record

private:
    string objectCodeFile;
    Hexadecimal *hexadecimalConverter;
    string record;
    string recordLength;
    int MAXRECORDLEN=60;
    string SEPARATOR="^";
};


#endif //SIC_ASSEMBLER_OBJECTFILEWRITER_H
