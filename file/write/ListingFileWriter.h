//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_LISTINGFILEWRITER_H
#define SIC_ASSEMBLER_LISTINGFILEWRITER_H
#include <string>
#include <fstream>

class ListingFileWriter {
public:
    //constructor
   ListingFileWriter(string listingFile);

    void writeInitialLine();
    void writeLine(int lineNumber,string locationCounter,Statement sourceStatement,string objectCode);

private:
    string listingFile;
};


#endif //SIC_ASSEMBLER_LISTINGFILEWRITER_H
