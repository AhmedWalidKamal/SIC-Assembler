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

    void writeHeader(string sourceName,string startAddress,int length);

    void writeTextRecord(string startAddress,string objectCode , string recordLength);

    void writeModRecord();//still to see what paramters shall it take in order to be able to write the modification record

    void writeEndRecord(string startAddress);
private:
    string objectCodeFile;
    Hexadecimal *hexadecimalConverter;




};


#endif //SIC_ASSEMBLER_OBJECTFILEWRITER_H
