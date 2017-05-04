//
// Created by SalmaAhmed on 01/05/2017.
//

#ifndef SIC_ASSEMBLER_OBJECTFILEWRITER_H
#define SIC_ASSEMBLER_OBJECTFILEWRITER_H
#include <string>
#include "../../datatypes/Hexadecimal.h"

using namespace std;

class ObjectFileWriter {

public:
    //constructor
    ObjectFileWriter(string objectCodeFile);

    void writeHeader(string sourceName,int startAddress,int length);
    //writes the whole text record.
    void writeTextRecord();
    //writes only one instruction to the text record.
    void writeTextRecord(int objectCode ,bool isIndexed, int address);
    //special case of instructions like WORD,BYTE..;
    void writeTextRecord(string address);
    //writes the start of a new record
    void startNewRecord(int startAddress);

    void writeModRecord();//still to see what paramters shall it take in order to be able to write the modification record

    void writeEndRecord(string startAddress);

private:
    string objectCodeFile;
    Hexadecimal *hexadecimalConverter;
    string record;
    string recordLength;
   // string previousAddress;
    int INDEXINGVALUE=32768; //TODO perform hexadecimal addition for the value of one int the leftmost bot instead of hardcoded.
    int MAXRECORDLEN=60;

    string SEPARATOR="^";
};


#endif //SIC_ASSEMBLER_OBJECTFILEWRITER_H
