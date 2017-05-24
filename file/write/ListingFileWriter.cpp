//
// Created by Walid on 5/3/2017.
//


#include "ListingFileWriter.h"


ListingFileWriter::ListingFileWriter(const std::string &fileName)
        : fileName(fileName), fileExtension(".lst") {
    ListingFileWriter::listFileStream.open(std::string(fileName).append(fileExtension));
}

void ListingFileWriter::writeInitialLine() {

    listFileStream << StringUtil::fillSpaces("Line", LINE_FORMAT) << StringUtil::fillSpaces("Loc", LOC_FORAMT);
    listFileStream << StringUtil::fillSpaces("Source Statement", STATEMENT_FORAMT) << "Object Code" << std::endl;
    listFileStream << StringUtil::drawLine(LINE_LENGTH) << std::endl;
}

void ListingFileWriter::writeLine(int lineNumber, Statement *statement, std::string objectCode) {

    std::string lineNum = StringUtil::fillSpaces(StringUtil::toString(lineNumber), SPACE_BOUND);
    std::string locationCounter = StringUtil::fillSpaces(Hexadecimal::intToHex(statement->getStatementLocationPointer()),
                                                         SPACE_BOUND);
    std::string label = StringUtil::fillSpaces(statement->getLabel()->getLabelField(), LABEL_BOUND);
    std::string mnemonic = StringUtil::fillSpaces(statement->getMnemonic()->getMnemonicField(), MNEMONIC_BOUND);
    std::string operand = StringUtil::fillSpaces(statement->getOperand()->getrawInput(), OPERAND_BOUND);
    operand = StringUtil::fillSpaces(operand, OPERAND_BOUND);
    std::string comment = StringUtil::fillSpaces(statement->getComment()->getComment(), COMMENT_BOUND);

    if (objectCode.length() > 0) {
        objectCode = StringUtil::fillZeros(objectCode, 6);
    }
    listFileStream << lineNum << locationCounter << label << mnemonic << operand << comment << objectCode << std::endl;

}

void ListingFileWriter::writeError(ErrorHandler::Error error) {
    listFileStream << "ERROR: " ;
    listFileStream<< ErrorHandler::errors[error] << std::endl;
}

void ListingFileWriter::writeComment(int lineNumber, std::string line) {
    std::string lineNum = StringUtil::fillSpaces(StringUtil::toString(lineNumber), SPACE_BOUND);
    listFileStream<<lineNum<<line<<std::endl;
}

