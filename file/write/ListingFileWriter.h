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
   ListingFileWriter(const std::string &fileName, const std::string fileExtension);

    void writeInitialLine();
    void writeLine(int lineNumber,Statement sourceStatement,std::string objectCode);

private:
    std::ofstream outputFileStream;
    const std::string fileName;
    const std::string fileExtension;
};


#endif //SIC_ASSEMBLER_LISTINGFILEWRITER_H
