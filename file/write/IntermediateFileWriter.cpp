//
// Created by Walid on 5/3/2017.
//

#include "IntermediateFileWriter.h"
#include "../../statement/Statement.h"
#include "../../util/StringUtil.h"
#include "../../datatypes/Hexadecimal.h"

IntermediateFileWriter::IntermediateFileWriter(const std::string &fileName, const std::string fileExtension)
        : fileName(fileName), fileExtension(fileExtension) {
    // Check this or change it whatever, just open a file with the file name and extension for writing.
    IntermediateFileWriter::outputFileStream.open(std::string(fileName).append(fileExtension));

}
void IntermediateFileWriter::writeInitialLine() {
    //TODO check range for filling spaces
    outputFileStream<<StringUtil::fillSpaces("Line",10)<<StringUtil::fillSpaces("Loc",25)<<StringUtil::fillSpaces("Source Statement",35)<<"\n";
    outputFileStream<<StringUtil::drawLine(80)<<"\n";

}
/// Writes line to intermediate file, uses helper functions or something.
void IntermediateFileWriter::writeLine(int lineNumber,Statement statement) {
    std::string line=StringUtil::fillSpaces(StringUtil::toString(lineNumber),10);
    std::string locationCounter=StringUtil::fillSpaces(StringUtil::toString(statement.getStatementLocationPointer()),8);
    std::string label=StringUtil::fillSpaces(statement.getLabel()->getLabelField(),8);
    std::string mnemonic=StringUtil::fillSpaces(statement.getMnemonic()->getMnemonicField(),8);
    std::string operand=StringUtil::fillSpaces(statement.getOperand()->getOperandField(),8);
    outputFileStream<<line<<locationCounter<<label<<mnemonic<<operand<<"\n";

}
void IntermediateFileWriter::writeSymbolTable(std::unordered_map<std::string, int> &symbolTable) {
    outputFileStream<<StringUtil::drawLine(80)<<"\n";
    outputFileStream<<StringUtil::fillSpaces("Symbol",15)<<"Assigned Address"<<"\n";
    outputFileStream<<StringUtil::drawLine(80)<<"\n";
    //TODO check the iteration over the map.
    std::unordered_map<std::string, int>::iterator it = symbolTable.begin();
    // Iterate over the map using iterator
    while (it != symbolTable.end())
    {
        outputFileStream << StringUtil::fillSpaces(it->first,15) << Hexadecimal::intToHex(it->second)<< "\n";
        it++;
    }

}
