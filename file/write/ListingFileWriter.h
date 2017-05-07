//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_LISTINGFILEWRITER_H
#define SIC_ASSEMBLER_LISTINGFILEWRITER_H

#include <string>
#include <fstream>
#include "../../statement/Statement.h"
#include "../../datatypes/Hexadecimal.h"
#include "../../util/StringUtil.h"
#include "../../error/ErrorHandler.h"

class ListingFileWriter {
public:
    ListingFileWriter(const std::string &fileName);

    void writeInitialLine();

    void writeLine(int lineNumber, Statement *sourceStatement, std::string objectCode);

    void writeError(ErrorHandler::Error error);

    void writeComment(int lineNumber, std::string line);

private:
    std::ofstream listFileStream;
    const std::string fileName;
    const std::string fileExtension;
    const int LABEL_BOUND = 9;
    const int MNEMONIC_BOUND = 7;
    const int OPERAND_BOUND = 17;
    const int COMMENT_BOUND = 30;
    const int SPACE_BOUND = 8;
    const int LINE_FORMAT = 10;
    const int LOC_FORAMT = 25;
    const int STATEMENT_FORAMT = 35;
    const int LINE_LENGTH = 80;
    StringUtil *stringUtil;
};


#endif //SIC_ASSEMBLER_LISTINGFILEWRITER_H
