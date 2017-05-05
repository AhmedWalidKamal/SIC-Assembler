//
// Created by Walid on 5/2/2017.
//

#ifndef SIC_ASSEMBLER_FILEREADER_H
#define SIC_ASSEMBLER_FILEREADER_H

#include <string>
#include <fstream>
#include "../../statement/Statement.h"
#include "../../statement/util/StatementBuilder.h"

class FileReader {

public:
    FileReader(const std::string &fileName);

    Statement *getNextStatement();
    bool finishedReading();

private:
    std::ifstream sourceFileStream;
    std::string fileName;
public:
    const std::string &getFileName() const;

    void setFileName(const std::string &fileName);

    const std::string &getFileExtension() const;

    void setFileExtension(const std::string &fileExtension);

private:
    std::string fileExtension;
    StatementBuilder *builder;
};


#endif //SIC_ASSEMBLER_FILEREADER_H
