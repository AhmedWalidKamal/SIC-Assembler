//
// Created by Walid on 5/3/2017.
//


#include "ListingFileWriter.h"
#include "../../statement/statement.h"
#include "../../error/ErrorHandler.h"
#include <fstream>
#include <sstream>


ListingFileWriter::ListingFileWriter(const std::string &fileName, const std::string fileExtension)
    : fileName(fileName), fileExtension(fileExtension) {

    ListingFileWriter::listFileStream.open(std::string(fileName).append(fileExtension));
}

void ListingFileWriter::writeInitialLine() {

  listFileStream<<StringUtil::fillSpaces("Line",LINE_FORMAT)<<StringUtil::fillSpaces("Loc",LOC_FORAMT);
  listFileStream<<StringUtil::fillSpaces("Source Statement",STATEMENT_FORAMT)<<"Object Code"<<"\n";
  listFileStream<<StringUtil::drawLine(LINE_LENGTH)<<"\n";
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

    listFileStream<<lineNum<<locationCounter<<label<<mnemonic<<operand<<comment<<objectCode<<"\n";;

}

void ListingFileWriter::writeError(ErrorHandler::Error error) {
    listFileStream<<ErrorHandler::errors[error]<<"\n";
}
