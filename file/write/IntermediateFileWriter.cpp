//
// Created by Walid on 5/3/2017.
//

#include <iostream>
#include "IntermediateFileWriter.h"
#include "../../util/StringUtil.h"
#include "../../datatypes/Hexadecimal.h"

IntermediateFileWriter::IntermediateFileWriter(const std::string &fileName, const std::string fileExtension)
        : fileName(fileName), fileExtension(fileExtension) {
    IntermediateFileWriter::intermediateFileStream.open(std::string(fileName).append(fileExtension));
}

void IntermediateFileWriter::writeInitialLine() {
    intermediateFileStream << StringUtil::drawLine(LINE_LENGTH) << std::endl;
    intermediateFileStream << StringUtil::fillSpaces("Line", LINE_FORMAT) << StringUtil::fillSpaces("Loc", LOC_FORAMT)
                           << "Source Statement" << std::endl;
    intermediateFileStream << StringUtil::drawLine(LINE_LENGTH) << std::endl;

}

// Writes line to intermediate file "FIXED FORMAT APPLIED".

void IntermediateFileWriter::writeStatement(int lineNumber, Statement *statement) {
    std::string line = StringUtil::fillSpaces(StringUtil::toString(lineNumber), SPACE_BOUND);
    std::string locationCounter = StringUtil::fillSpaces(Hexadecimal::intToHex(statement->getStatementLocationPointer()),
                                                         SPACE_BOUND);
    std::string label = StringUtil::fillSpaces(statement->getLabel()->getLabelField(), LABEL_BOUND);
    std::string mnemonic = StringUtil::fillSpaces(statement->getMnemonic()->getMnemonicField(), MNEMONIC_BOUND);
    std::string operand = StringUtil::fillSpaces(statement->getOperand()->getrawInput(), OPERAND_BOUND);
    std::string comment = statement->getComment()->getComment();
    intermediateFileStream << line << locationCounter << label << mnemonic << operand << comment << std::endl;
}

void IntermediateFileWriter::writeComment(int lineNumber, std::string line) {
    std::string lineNum = StringUtil::fillSpaces(StringUtil::toString(lineNumber),SPACE_BOUND);
    intermediateFileStream << lineNum << line << std::endl;
}


void IntermediateFileWriter::writeSymbolTable(std::map<std::string, int> &symbolTable) {


    intermediateFileStream << StringUtil::drawLine(LINE_LENGTH) << std::endl;
    intermediateFileStream << StringUtil::fillSpaces("Symbol", SYMBOLTABLE_BOUND);
    intermediateFileStream << "Assigned Address";
    intermediateFileStream << std::endl;
    intermediateFileStream << StringUtil::drawLine(LINE_LENGTH) << std::endl;

    // Iterate over the map using iterator
    for (auto curr : symbolTable) {
        intermediateFileStream << StringUtil::fillSpaces(curr.first, SYMBOLTABLE_BOUND)
                        << Hexadecimal::intToHex(curr.second) << std::endl;
    }
}
void IntermediateFileWriter::writeLiteralTable(std::map<int, std::pair<std::string, int>> &literalTable) {
    
}

void IntermediateFileWriter::writeError(ErrorHandler::Error error) {
    intermediateFileStream << "ERROR: " ;
    intermediateFileStream<< ErrorHandler::errors[error] << std::endl;
}

