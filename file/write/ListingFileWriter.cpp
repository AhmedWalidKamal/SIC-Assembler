//
// Created by Walid on 5/3/2017.
//


#include "ListingFileWriter.h"
#include "../../statement/statement.h"
#include <fstream>
#include <sstream>

std::ofstream listFile;

ListingFileWriter::ListingFileWriter(const std::string &fileName, const std::string fileExtension) {
    ListingFileWriter::outputFileStream.open(std::string(fileName).append(fileExtension));
}
void ListingFileWriter::writeInitialLine() {
 listFile<<StringUtil::fillSpaces("Line",10)<<StringUtil::fillSpaces("Loc",25)<<StringUtil::fillSpaces("Source Statement",35)<<"Object Code"<<"\n";
    listFile<<StringUtil::drawLine(80)<<"\n";
}
void ListingFileWriter::writeLine(int lineNumber,Statement statement, std::string objectCode) {
    std::string lineNum=StringUtil::toString(lineNumber);
    std::string locationCounter=Hexadecimal::intToHex(statement.getStatementLocationPointer());
   // std::string label=statement.getLabel()->getLabelField();
//    std::string mnemonic=statement.getMnemonic()->getMnemonicField();
//    std::string operand;
//    //if(statement.getOperand()->isLabel())
//         operand=statement.getOperand()->getOperandField();
//    //else
//        //operand=statement.getOperand()->getintValue();
//    std::string comment=statement.getComment()->getComment();
    if(objectCode.length()>0)
        objectCode=StringUtil::fillZeros(objectCode,6);
    listFile<<StringUtil::fillSpaces(lineNum,10)<<StringUtil::fillSpaces(locationCounter,8)<<StringUtil::fillSpaces(objectCode,8)<<"\n";
            //<<fillSpaces(label,8)<<
//    <<fillSpaces(mnemonic,8)<<fillSpaces(operand,8)<<fillSpaces(comment,8);

}
