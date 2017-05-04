//
// Created by Walid on 5/2/2017.
//

#ifndef SIC_ASSEMBLER_FILEREADER_H
#define SIC_ASSEMBLER_FILEREADER_H


#include <bits/basic_string.h>
#include <bits/char_traits.h>
#include <bits/allocator.h>
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
    StatementBuilder *builder;
};


#endif //SIC_ASSEMBLER_FILEREADER_H