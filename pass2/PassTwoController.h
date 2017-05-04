//
// Created by SalmaAhmed on 5/1/2017.
//

#ifndef SIC_ASSEMBLER_PASSTWOCONTROLLER_H
#define SIC_ASSEMBLER_PASSTWOCONTROLLER_H


#include <string>
#include <unordered_map>
#include <vector>
#include "../file/write/ObjectFileWriter.h"
#include "../format/Format.h"
#include "../statement/Statement.h"

using namespace std;
class PassTwoController {
public:
    PassTwoController(vector<Statement> lines,int programLength,string objectFile,unordered_map<std::string, std::pair<int, Format *>> &instructionTable,unordered_map<std::string, int> &symbolTable);
    void executePass2();

private:
    ObjectFileWriter *objectWriter;
    string outputFile;
    int programLength;
    unordered_map<std::string, std::pair<int, Format *>> instructionTable;
    unordered_map<std::string, int> symbolTable;

};


#endif //SIC_ASSEMBLER_PASSTWOCONTROLLER_H
