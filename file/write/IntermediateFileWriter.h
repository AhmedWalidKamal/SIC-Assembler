//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_INTERMEDIATEFILEWRITER_H
#define SIC_ASSEMBLER_INTERMEDIATEFILEWRITER_H


#include <string>
#include <fstream>
#include <unordered_map>
#include "../../statement/Statement.h"

class IntermediateFileWriter {
public:
    IntermediateFileWriter(const std::string &fileName, const std::string fileExtension);

public:
    void writeInitialLine();
    void writeLine(int lineNumber,Statement statement);
    void writeSymbolTable(std::unordered_map<std::string, int> &symbolTable);
private:
    std::ofstream outputFileStream;
    const std::string fileName;
    const std::string fileExtension;

};


#endif //SIC_ASSEMBLER_INTERMEDIATEFILEWRITER_H
