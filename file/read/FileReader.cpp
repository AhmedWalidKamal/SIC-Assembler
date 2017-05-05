//
// Created by walid on 5/2/2017.
//

#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "FileReader.h"
#include "../../statement/util/FixedFormatBuilder.h"

FileReader::FileReader(const std::string &fileName) {
    this->sourceFileStream.open(fileName);
    FileReader::fileName = fileName;
    /// I need to check that extension is .asm and store it in the private field.
    std::cout << "File name is: " << fileName << std::endl;
    if (sourceFileStream.fail()) {
        std::cout << "Couldn't open file." << std::endl;
        exit(1);
    }
    // This could be changed in the future to a FreeFormatBuilder if desired.
    builder = new FixedFormatBuilder();

    /// File prints correctly, but i think there's an error in the file reading line by line.
}

Statement *FileReader::getNextStatement() {
    std::string currentLine;
    std::getline(sourceFileStream, currentLine);
    std::transform(currentLine.begin(), currentLine.end(), currentLine.begin(),
                   [](unsigned char c) { return std::toupper(c); }); // Clean this up and test it.
    builder->buildStatement(currentLine);
    return builder->getStatement();
}

bool FileReader::finishedReading() {
    return this->sourceFileStream.eof();
}

const std::string &FileReader::getFileName() const {
    return fileName;
}

void FileReader::setFileName(const std::string &fileName) {
    FileReader::fileName = fileName;
}

const std::string &FileReader::getFileExtension() const {
    return fileExtension;
}

void FileReader::setFileExtension(const std::string &fileExtension) {
    FileReader::fileExtension = fileExtension;
}
