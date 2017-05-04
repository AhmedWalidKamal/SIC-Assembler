//
// Created by walid on 5/2/2017.
//

#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "FileReader.h"
#include "../../statement/Statement.h"

FileReader::FileReader(const std::string &fileName) {
    this->sourceFileStream.open(fileName);
    //std::cout << "File name is: " << fileName << std::endl;
    if (sourceFileStream.fail()) {
        std::cout << "Couldn't open file." << std::endl;
        exit(1);
    }
}

Statement *FileReader::getNextStatement() {
    Label *currentLabel = new Label();
    Mnemonic *currentMnemonic = new Mnemonic();
    Operand *currentOperand = new Operand();
    Comment *currentComment = new Comment();

    std::string currentLine;
    std::getline(sourceFileStream, currentLine);
    std::transform(currentLine.begin(), currentLine.end(), currentLine.begin(),
                   [](unsigned char c) { return std::toupper(c); });

    /// TODO: Fetch the data from the currentLine string into the objects

    return new Statement(currentLabel, currentMnemonic, currentOperand, currentComment);
}

bool FileReader::finishedReading() {
    return this->sourceFileStream.eof();
}
