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
    void executeStart(Statement statement);
    void executeInstruction(Statement statement);
    void executeRES(string locationCounter);
    void executeWord(Statement statement);
    void executeByte(Statement statement);
    void executeEnd(Statement statement);
    ObjectFileWriter *objectWriter;
    Hexadecimal *hexadecimalConverter;
    string outputFile;
    int programLength;
    unordered_map<std::string, std::pair<int, Format *>> instructionTable;
    unordered_map<std::string, int> symbolTable;
    vector<Statement> statements;
    int INDEXINGVALUE=32768; //TODO perform hexadecimal addition for the value of one int the leftmost bot instead of hardcoded.
};


#endif //SIC_ASSEMBLER_PASSTWOCONTROLLER_H
