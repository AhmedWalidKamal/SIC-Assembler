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
                      Program *program, std::string fileName,
                      std::map<std::string, std::pair<int, int> > &literalTable);

private:
    void startCheck(Statement *statement);

    void byteCheck(Statement *statement);

    void wordCheck(Statement *statement);

    void instructionCheck(Statement *statement,std::map<std::string, int> &symbolTable);

    std::string getSicObjectCode(int opCode, int indexBit, int address);

    void writeStartObjectFile(Statement *statement, Program *program);

    void writeEndObjectFile(Statement *statement, std::map<std::string, int> &symbolTable);

    void writeResObjectFile();

    std::string getInstructionObjectCode(Statement *statement, std::map<std::string, int> &symbolTable);

    void writeInstructionObjectFile(std::string objCode, Statement *statement);

    std::string getWordObjectCode(Statement *statement);

    void writeWordObjectFile(std::string objCode, Statement *statement);

    void writeByteObjectFile(std::string objCode, Statement *statement);

    std::string getByteObjectCode(Statement *statement);

    ObjectFileWriter *objectWriter;
    ListingFileWriter *listingWriter;

    std::map<std::string, Instruction *> instructionTable;
    const int MAX_WORD_LENGTH = 6;
    const int MAX_BYTE_LENGTH = 15;
    const int MAX_SOURCENAME_LENGTH = 6;
    const std::string START = "START";
    const std::string END = "END";
    const std::string BYTE = "BYTE";
    const std::string WORD = "WORD";
    const std::string RESW = "RESW";
    const std::string RESB = "RESB";
};


#endif //SIC_ASSEMBLER_PASSTWOCONTROLLER_H
