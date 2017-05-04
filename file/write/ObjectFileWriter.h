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

    void writeHeader(string sourceName,int startAddress,int length);
    //writes the whole text record.
    void writeTextRecord();
    //writes only one instruction to the text record.
    void writeTextRecord(int opCode ,bool isIndexed, int address,int locationCounter);
    //special case of instructions like WORD,BYTE..;
    void writeTextRecord(int address);
    //writes the start of a new record
    void startNewRecord(int startAddress);
    /*to be implemented for SIC/XE only*/
    void writeModRecord();//still to see what paramters shall it take in order to be able to write the modification record

    void writeEndRecord(int startAddress);

private:
    string objectCodeFile;
    Hexadecimal *hexadecimalConverter;
    string record;
    string recordLength;
    int INDEXINGVALUE=32768; //TODO perform hexadecimal addition for the value of one int the leftmost bot instead of hardcoded.
    int MAXRECORDLEN=60;
    string SEPARATOR="^";
};


#endif //SIC_ASSEMBLER_OBJECTFILEWRITER_H
