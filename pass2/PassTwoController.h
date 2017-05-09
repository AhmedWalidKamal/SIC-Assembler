//
// Created by SalmaAhmed on 5/1/2017.
//

#ifndef SIC_ASSEMBLER_PASSTWOCONTROLLER_H
#define SIC_ASSEMBLER_PASSTWOCONTROLLER_H


#include <string>
#include <unordered_map>
#include <vector>
#include "../file/write/ObjectFileWriter.h"
#include "../statement/Statement.h"
#include "../statement/Operand.h"
#include "../file/write/ListingFileWriter.h"
#include "../util/Program.h"

class PassTwoController {
public:
    PassTwoController(std::map<std::string, Instruction *> &instructionTable);

    void executePass2(std::map<std::string, int> &symbolTable,
                      Program *program, std::string fileName);

private:
    void executeStart(Statement *statement, Program *program);

    std::string executeInstruction(Statement *statement, std::map<std::string, int> &symbolTable);

    void executeRES(Statement *statement);

    std::string executeWord(Statement *statement);

    std::string executeByte(Statement *statement);

    void executeEnd(Statement *statement, std::map<std::string, int> &symbolTable);

    std::string getSicObjectCode(int opCode, int indexBit, int address);

    ObjectFileWriter *objectWriter;
    ListingFileWriter *listingWriter;
    std::string objectCode;

    std::map<std::string, Instruction *> instructionTable;
    const int INDEXINGVALUE = 32768; //TODO perform hexadecimal addition for the value of one int the leftmost bot instead of hardcoded.
    const int MAX_WORD_LENGTH = 6;
    const int MAX_BYTE_LENGTH = 15;
    const int MAX_SOURCENAME_LENGTH = 6;
    const std::string START="START";
    const std::string END="END";
    const std::string BYTE="BYTE";
    const std::string WORD="WORD";
    const std::string RESW="RESW";
    const std::string RESB="RESB";
    bool checkIn = false;
};


#endif //SIC_ASSEMBLER_PASSTWOCONTROLLER_H
