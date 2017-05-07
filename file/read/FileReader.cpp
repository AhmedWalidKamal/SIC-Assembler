//
// Created by walid on 5/2/2017.
//

#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "FileReader.h"
#include "../../statement/util/FixedFormatBuilder.h"
#include <regex>

FileReader::FileReader(const std::string &fileName) {
    this->sourceFileStream.open(fileName);
    if (sourceFileStream.fail()) {
        std::cout << "Couldn't open file." << std::endl;
        exit(1);
    }
//    Regex regex;
//    if (!regex_match(regex.asmFile, fileName) {
//        std::cout << "Invalid file name format." << std::endl;
//        exit(1);
//    }
    std::size_t dotPos = fileName.find_first_of(".");
    FileReader::fileName = fileName.substr (0, dotPos);
    FileReader::fileExtension = fileName.substr(dotPos);
    // This could be changed in the future to a FreeFormatBuilder if desired.
    builder = new FixedFormatBuilder();
}

Statement *FileReader::getNextStatement() {
    std::string currentLine;
    std::getline(sourceFileStream, currentLine);
    std::transform(currentLine.begin(), currentLine.end(), currentLine.begin(),
                   [](unsigned char c) { return std::toupper(c); }); // Clean this up and test it.
    // Replace all tabs with spaces
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
