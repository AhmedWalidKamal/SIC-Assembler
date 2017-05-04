//
// Created by Walid on 5/3/2017.
//

#include "ListingFileWriter.h"
#include "../../statement/statement.h"
std::ofstream outFile;

ListingFileWriter::ListingFileWriter(std::string listingFile) {
    this->listingFile=listingFile;
    outFile.open(listingFile);

}
void ListingFileWriter::writeInitialLine() {

}
void ListingFileWriter::writeLine(int lineNumber, std::string locationCounter,Statement statement, std::string objectCode) {

}