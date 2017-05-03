//
// Created by SalmaAhmed on 5/1/2017.
//

#ifndef SIC_ASSEMBLER_PASSTWOCONTROLLER_H
#define SIC_ASSEMBLER_PASSTWOCONTROLLER_H


#include <string>
#include "ObjectCodeWriter.h"

using namespace std;
class PassTwoController {
public:
    PassTwoController(string intermediateFile,string programLength,string objectFile);
    void executePass2();

private:
    ObjectCodeWriter *objectWriter;
    string intermediateFile;
    string outputFile;
    string programLength;






};


#endif //SIC_ASSEMBLER_PASSTWOCONTROLLER_H
