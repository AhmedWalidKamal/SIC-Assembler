//
// Created by Walid on 5/3/2017.
//

#include <iostream>
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
    intermediateFileStream << stringUtil->drawLine(LINE_LENGTH) << std::endl;
    intermediateFileStream << stringUtil->fillSpaces("Line", LINE_FORMAT) << stringUtil->fillSpaces("Loc", LOC_FORAMT)
                           << "Source Statement" << std::endl;
    intermediateFileStream << stringUtil->drawLine(LINE_LENGTH) << std::endl;

}

// Writes line to intermediate file "FIXED FORMAT APPLIED".

void IntermediateFileWriter::writeStatement(int lineNumber, Statement *statement) {
    std::string line = stringUtil->fillSpaces(stringUtil->toString(lineNumber), SPACE_BOUND);
    std::string locationCounter = stringUtil->fillSpaces(Hexadecimal::intToHex(statement->getStatementLocationPointer()),
                                                         SPACE_BOUND);
    std::string label = stringUtil->fillSpaces(statement->getLabel()->getLabelField(), LABEL_BOUND);
    std::string mnemonic = stringUtil->fillSpaces(statement->getMnemonic()->getMnemonicField(), MNEMONIC_BOUND);
    std::string operand = stringUtil->fillSpaces(statement->getOperand()->getrawInput(), OPERAND_BOUND);
    std::string comment = statement->getComment()->getComment();
    intermediateFileStream << line << locationCounter << label << mnemonic << operand << comment << std::endl;
}

void IntermediateFileWriter::writeComment(int lineNumber, std::string line) {
    // Write comment line starting from source statement after writing line number (no loc ctr is written here i guess).
    std::string lineNum = stringUtil->fillSpaces(stringUtil->toString(lineNumber),SPACE_BOUND);
    intermediateFileStream << lineNum << line << std::endl;
}


void IntermediateFileWriter::writeSymbolTable(std::map<std::string, int> &symbolTable) {


    intermediateFileStream << stringUtil->drawLine(LINE_LENGTH) << std::endl;
    intermediateFileStream << stringUtil->fillSpaces("Symbol", SYMBOLTABLE_BOUND);
    intermediateFileStream << "Assigned Address";
    intermediateFileStream << std::endl;
    intermediateFileStream << stringUtil->drawLine(LINE_LENGTH) << std::endl;

    // Iterate over the map using iterator
    for (auto curr : symbolTable) {
        intermediateFileStream << stringUtil->fillSpaces(curr.first, SYMBOLTABLE_BOUND)
                        << Hexadecimal::intToHex(curr.second) << std::endl;
    }
}

void IntermediateFileWriter::writeError(ErrorHandler::Error error) {
    intermediateFileStream << "ERROR: " ;
    intermediateFileStream<< ErrorHandler::errors[error] << std::endl;
}

