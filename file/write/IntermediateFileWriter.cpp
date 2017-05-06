//
// Created by Walid on 5/3/2017.
//

#include "IntermediateFileWriter.h"
#include "../../util/StringUtil.h"
#include "../../datatypes/Hexadecimal.h"

IntermediateFileWriter::IntermediateFileWriter(const std::string &fileName, const std::string fileExtension)
        : fileName(fileName), fileExtension(fileExtension) {
    // Check this or change it whatever, just open a file with the file name and extension for writing.
    IntermediateFileWriter::intermediateFileStream.open(std::string(fileName).append(fileExtension));

}

void IntermediateFileWriter::writeInitialLine() {
    //TODO check range for filling spaces
    intermediateFileStream << StringUtil::fillSpaces("Line", LINE_FORMAT) << StringUtil::fillSpaces("Loc", LOC_FORAMT)
                           << "Source Statement" << "\n";
    intermediateFileStream << StringUtil::drawLine(LINE_LENGTH) << "\n";

}

// Writes line to intermediate file "FIXED FORMAT APPLIED".

void IntermediateFileWriter::writeStatement(int lineNumber, Statement *statement) {
    std::string line = StringUtil::fillSpaces(StringUtil::toString(lineNumber), SPACE_BOUND);
    std::string locationCounter = StringUtil::fillSpaces(StringUtil::toString(statement->getStatementLocationPointer()),
                                                         SPACE_BOUND);
    std::string label = StringUtil::fillSpaces(statement->getLabel()->getLabelField(), LABEL_BOUND);
    std::string mnemonic = StringUtil::fillSpaces(statement->getMnemonic()->getMnemonicField(), MNEMONIC_BOUND);
    std::string operand = StringUtil::fillSpaces(statement->getOperand()->getOperandField(), OPERAND_BOUND);
    std::string comment = statement->getComment()->getComment();
    intermediateFileStream << line << locationCounter << label << mnemonic << operand << comment << "\n";
}

void IntermediateFileWriter::writeComment(int lineNumber, std::string line) {
    // Write comment line starting from source statement after writing line number (no loc ctr is written here i guess).
}


void IntermediateFileWriter::writeSymbolTable(std::unordered_map<std::string, int> &symbolTable) {

    intermediateFileStream << StringUtil::drawLine(LINE_LENGTH) << "\n";
    intermediateFileStream << StringUtil::fillSpaces("Symbol", SYMBOLTABLE_BOUND) << "Assigned Address" << "\n";
    intermediateFileStream << StringUtil::drawLine(LINE_LENGTH) << "\n";
    //TODO check the iteration over the map.
    std::unordered_map<std::string, int>::iterator it = symbolTable.begin();

    // Iterate over the map using iterator
    while (it != symbolTable.end()) {
        intermediateFileStream << StringUtil::fillSpaces(it->first, SYMBOLTABLE_BOUND)
                               << Hexadecimal::intToHex(it->second) << "\n";
        it++;
    }

}

void IntermediateFileWriter::writeError(ErrorHandler::Error error) {
    intermediateFileStream << "ERROR: " << ErrorHandler::errors[error] << "\n";
}

