//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_INTERMEDIATEFILEWRITER_H
#define SIC_ASSEMBLER_INTERMEDIATEFILEWRITER_H


#include <string>
#include <fstream>

class IntermediateFileWriter {
public:
    IntermediateFileWriter(const std::string &fileName, const std::string fileExtension);

public:
    void writeLine(std::string line);
private:
    std::ofstream outputFileStream;
    const std::string fileName;
    const std::string fileExtension;

};


#endif //SIC_ASSEMBLER_INTERMEDIATEFILEWRITER_H
