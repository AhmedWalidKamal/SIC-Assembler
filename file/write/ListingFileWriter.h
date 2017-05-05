//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_LISTINGFILEWRITER_H
#define SIC_ASSEMBLER_LISTINGFILEWRITER_H
#include <string>
#include <fstream>
#include "../../statement/Statement.h"
#include "../../datatypes/Hexadecimal.h"

class ListingFileWriter {
public:
    //constructor
   ListingFileWriter(std::string listingFile);

    void writeInitialLine();
    void writeLine(int lineNumber,Statement sourceStatement,std::string objectCode);

private:
    Hexadecimal *converter;
    std::string fillSpaces(std::string,int length);
    std::string fillZeros(std::string word,int size);
    std::string drawLine(int length);
    std::string toString(int num);
};


#endif //SIC_ASSEMBLER_LISTINGFILEWRITER_H
