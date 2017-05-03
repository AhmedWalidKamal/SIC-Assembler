//
// Created by SalmaAhmed on 01/05/2017.
//

#ifndef SIC_ASSEMBLER_OBJECTCODEWRITER_H
#define SIC_ASSEMBLER_OBJECTCODEWRITER_H
#include <string>
using namespace std;

class ObjectCodeWriter {
public:
    //constructor
    ObjectCodeWriter(string objectCodeFile);

    void writeHeader(string sourceName,string startAddress,string length);

    void writeTextRecord(string startAddress,string opCode , string recordLength);

    void writeModRecord();//still to see what paramters shall it take in order to be able to write the modification record

    void writeEndRecord(string startAddress);
private:
    string objectCodeFile;





};


#endif //SIC_ASSEMBLER_OBJECTCODEWRITER_H
