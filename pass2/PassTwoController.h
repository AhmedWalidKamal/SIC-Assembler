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
#include "../statement/Operand.h"
#include "../file/write/ListingFileWriter.h"

class PassTwoController {
public:
    PassTwoController(std::vector<bool> hasLabel,std::vector<int>operandsValues,std::vector<Statement> &lines,int programLength,std::string objectFile,std::string listingFile,std::unordered_map<std::string, int > &instructionTable,std::unordered_map<std::string, int> &symbolTable);
    void executePass2();

private:
    void executeStart(Statement statement,int i);
    std::string executeInstruction(Statement statement,int i);
    void executeRES();
    std::string executeWord(Statement statement,int i);
    std::string executeByte(Statement statement);
    void executeEnd(Statement statement);
    ObjectFileWriter *objectWriter;
    ListingFileWriter *listingWriter;
    Hexadecimal *hexadecimalConverter;
    int programLength;
    std::string objectCode;
    std::unordered_map<std::string, int> instructionTable;
    std::unordered_map<std::string, int> symbolTable;
    std::vector<Statement> statements;
    std::vector<int>operandsValues;
    std::vector<bool> hasLabel;
    int INDEXINGVALUE=32768; //TODO perform hexadecimal addition for the value of one int the leftmost bot instead of hardcoded.
};


#endif //SIC_ASSEMBLER_PASSTWOCONTROLLER_H
