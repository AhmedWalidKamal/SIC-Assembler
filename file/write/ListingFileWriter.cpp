//
// Created by Walid on 5/3/2017.
//


#include "ListingFileWriter.h"


ListingFileWriter::ListingFileWriter(const std::string &fileName)
        : fileName(fileName), fileExtension(".lst") {
    ListingFileWriter::listFileStream.open(std::string(fileName).append(fileExtension));
    stringUtil = new StringUtil();
}

void ListingFileWriter::writeInitialLine() {

    listFileStream << stringUtil->fillSpaces("Line", LINE_FORMAT) << stringUtil->fillSpaces("Loc", LOC_FORAMT);
    listFileStream << stringUtil->fillSpaces("Source Statement", STATEMENT_FORAMT) << "Object Code" << std::endl;
    listFileStream << stringUtil->drawLine(LINE_LENGTH) << std::endl;
}

void ListingFileWriter::writeLine(int lineNumber, Statement *statement, std::string objectCode) {

    std::string lineNum = stringUtil->fillSpaces(stringUtil->toString(lineNumber), SPACE_BOUND);
    std::string locationCounter = stringUtil->fillSpaces(Hexadecimal::intToHex(statement->getStatementLocationPointer()),
                                                         SPACE_BOUND);
    std::string label = stringUtil->fillSpaces(statement->getLabel()->getLabelField(), LABEL_BOUND);
    std::string mnemonic = stringUtil->fillSpaces(statement->getMnemonic()->getMnemonicField(), MNEMONIC_BOUND);
    std::string operand = stringUtil->fillSpaces(statement->getOperand()->getrawInput(), OPERAND_BOUND);
    operand = stringUtil->fillSpaces(operand, OPERAND_BOUND);
    std::string comment = stringUtil->fillSpaces(statement->getComment()->getComment(), COMMENT_BOUND);

    if (objectCode.length() > 0) {
        objectCode = stringUtil->fillZeros(objectCode, 6);
    }
    listFileStream << lineNum << locationCounter << label << mnemonic << operand << comment << objectCode << std::endl;

}

void ListingFileWriter::writeError(ErrorHandler::Error error) {
    listFileStream << "ERROR: " ;
    listFileStream<< ErrorHandler::errors[error] << std::endl;
}

void ListingFileWriter::writeComment(int lineNumber, std::string line) {
    // Write comment line starting from source statement after writing line number (no loc ctr is written here i guess).
    std::string lineNum = stringUtil->fillSpaces(stringUtil->toString(lineNumber), SPACE_BOUND);
    listFileStream<<lineNum<<line<<std::endl;
}