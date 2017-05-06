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
    stringUtil = new StringUtil();
}

void IntermediateFileWriter::writeInitialLine() {
    //TODO check range for filling spaces
    intermediateFileStream << stringUtil->fillSpaces("Line", LINE_FORMAT) << stringUtil->fillSpaces("Loc", LOC_FORAMT)
                           << "Source Statement" << "\n";
    intermediateFileStream << stringUtil->drawLine(LINE_LENGTH) << "\n";

}

// Writes line to intermediate file "FIXED FORMAT APPLIED".

void IntermediateFileWriter::writeStatement(int lineNumber, Statement *statement) {
    std::string line = stringUtil->fillSpaces(stringUtil->toString(lineNumber), SPACE_BOUND);
    std::string locationCounter = stringUtil->fillSpaces(stringUtil->toString(statement->getStatementLocationPointer()),
                                                         SPACE_BOUND);
    std::string label = stringUtil->fillSpaces(statement->getLabel()->getLabelField(), LABEL_BOUND);
    std::string mnemonic = stringUtil->fillSpaces(statement->getMnemonic()->getMnemonicField(), MNEMONIC_BOUND);
    std::string operand = stringUtil->fillSpaces(statement->getOperand()->getOperandField(), OPERAND_BOUND);
    std::string comment = statement->getComment()->getComment();
    intermediateFileStream << line << locationCounter << label << mnemonic << operand << comment << "\n";
}

void IntermediateFileWriter::writeComment(int lineNumber, std::string line) {
    // Write comment line starting from source statement after writing line number (no loc ctr is written here i guess).
    std::string lineNum = stringUtil->fillSpaces(stringUtil->toString(lineNumber),SPACE_BOUND);
    intermediateFileStream<<lineNum<<line<<"\n";
}


void IntermediateFileWriter::writeSymbolTable(std::map<std::string, int> &symbolTable) {

    intermediateFileStream << stringUtil->drawLine(LINE_LENGTH) << "\n";
    intermediateFileStream << stringUtil->fillSpaces("Symbol", SYMBOLTABLE_BOUND) << "Assigned Address" << "\n";
    intermediateFileStream << stringUtil->drawLine(LINE_LENGTH) << "\n";
    //TODO check the iteration over the map.
    std::map<std::string, int>::iterator it = symbolTable.begin();

    // Iterate over the map using iterator
    while (it != symbolTable.end()) {
        intermediateFileStream << stringUtil->fillSpaces(it->first, SYMBOLTABLE_BOUND)
                               << Hexadecimal::intToHex(it->second) << "\n";
        it++;
    }
}

void IntermediateFileWriter::writeError(ErrorHandler::Error error) {
    intermediateFileStream << "ERROR: " ;
    intermediateFileStream<< ErrorHandler::errors[error] << "\n";
}

