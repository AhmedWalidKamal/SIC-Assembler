//
// Created by Walid on 5/3/2017.
//


#include "ListingFileWriter.h"
#include "../../statement/statement.h"
#include <fstream>
#include <sstream>

std::ofstream listFile;

ListingFileWriter::ListingFileWriter( std::string fileName) {
    ListingFileWriter::outputFileStream.open(fileName);
}

void ListingFileWriter::writeInitialLine() {

  listFile<<StringUtil::fillSpaces("Line",LINE_FORMAT)<<StringUtil::fillSpaces("Loc",LOC_FORAMT);
  listFile<<StringUtil::fillSpaces("Source Statement",STATEMENT_FORAMT)<<"Object Code"<<"\n";
  listFile<<StringUtil::drawLine(LINE_LENGTH)<<"\n";
}
void ListingFileWriter::writeLine(int lineNumber,Statement statement, std::string objectCode) {

    std::string lineNum=StringUtil::fillSpaces(StringUtil::toString(lineNumber),SPACE_BOUND);
    std::string locationCounter=StringUtil::fillSpaces(Hexadecimal::intToHex(statement.getStatementLocationPointer()),SPACE_BOUND);
    std::string label=StringUtil::fillSpaces(statement.getLabel()->getLabelField(),LABEL_BOUND);
    std::string mnemonic=StringUtil::fillSpaces(statement.getMnemonic()->getMnemonicField(),MNEMONIC_BOUND);
    std::string operand;
    if(statement.getOperand()->isLabel())
         operand=statement.getOperand()->getOperandField();
    else
        operand=statement.getOperand()->getintValue();
    operand=StringUtil::fillSpaces(operand,OPERAND_BOUND);
    std::string comment=StringUtil::fillSpaces(statement.getComment()->getComment(),COMMENT_BOUND);

    if(objectCode.length()>0)
        objectCode=StringUtil::fillZeros(objectCode,6);

    listFile<<lineNum<<locationCounter<<label<<mnemonic<<operand<<comment<<objectCode<<"\n";;

}
