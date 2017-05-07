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

    const std::string &getFileName() const;

    void setFileName(const std::string &fileName);

    const std::string &getFileExtension() const;

    void setFileExtension(const std::string &fileExtension);

private:
    std::ifstream sourceFileStream;
    std::string fileName;
    std::string fileExtension;
    StatementBuilder *builder;

    std::string getFormattedLine(std::string basic_string);
};


#endif //SIC_ASSEMBLER_FILEREADER_H
