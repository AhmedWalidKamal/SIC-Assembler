//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_INTERMEDIATEFILEWRITER_H
#define SIC_ASSEMBLER_INTERMEDIATEFILEWRITER_H


#include <string>
#include <fstream>
#include <unordered_map>
#include "../../statement/Statement.h"
#include "../../error/ErrorHandler.h"
#include "FileWriter.h"
#include "../../util/StringUtil.h"

class IntermediateFileWriter {
public:
    IntermediateFileWriter(const std::string &fileName, const std::string fileExtension);

public:
    void writeInitialLine();

    void writeStatement(int lineNumber, Statement *statement);

    void writeSymbolTable(std::map<std::string, int> &symbolTable);

    void writeError(ErrorHandler::Error error);

    void writeComment(int lineNumber, std::string line);

private:
    std::ofstream intermediateFileStream;
    const std::string fileName;
    const std::string fileExtension;
    const int LABEL_BOUND = 9;
    const int MNEMONIC_BOUND = 7;
    const int OPERAND_BOUND = 17;
    const int SPACE_BOUND = 8;
    const int SYMBOLTABLE_BOUND = 15;
    const int LINE_LENGTH = 80;
    const int LINE_FORMAT = 10;
    const int LOC_FORAMT = 25;
    StringUtil *stringUtil;
};


#endif //SIC_ASSEMBLER_INTERMEDIATEFILEWRITER_H
