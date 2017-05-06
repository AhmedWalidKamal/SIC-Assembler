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
class ListingFileWriter {
public:
    //constructor
   ListingFileWriter( std::string fileName);

    void writeInitialLine();
    void writeLine(int lineNumber,Statement sourceStatement,std::string objectCode);

private:
    std::ofstream outputFileStream;
    const std::string fileName;
    const int LABEL_BOUND=9;
    const int MNEMONIC_BOUND=7;
    const int OPERAND_BOUND=17;
    const int COMMENT_BOUND=30;
    const int SPACE_BOUND=8;
    const int LINE_FORMAT=10;
    const int LOC_FORAMT=25;
    const int STATEMENT_FORAMT=35;
    const int LINE_LENGTH=80;

};


#endif //SIC_ASSEMBLER_LISTINGFILEWRITER_H
