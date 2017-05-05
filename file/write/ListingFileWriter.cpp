//
// Created by Walid on 5/3/2017.
//


#include "ListingFileWriter.h"
#include "../../statement/statement.h"
#include <fstream>
#include <sstream>

std::ofstream listFile;

ListingFileWriter::ListingFileWriter(std::string listingFile) {
    listFile.open(listingFile);
    this->converter=new Hexadecimal();
    this->stringUtil=new StringUtil();
}
void ListingFileWriter::writeInitialLine() {
 listFile<<stringUtil->fillSpaces("Line",10)<<stringUtil->fillSpaces("Loc",25)<<stringUtil->fillSpaces("Source Statement",35)<<"Object Code"<<"\n";
    listFile<<stringUtil->drawLine(80)<<"\n";
}
void ListingFileWriter::writeLine(int lineNumber,Statement statement, std::string objectCode) {
    std::string lineNum=stringUtil->toString(lineNumber);
    std::string locationCounter=converter->intToHex(statement.getStatementLocationPointer());
   // std::string label=statement.getLabel()->getLabelField();
//    std::string mnemonic=statement.getMnemonic()->getMnemonicField();
//    std::string operand;
//    //if(statement.getOperand()->isLabel())
//         operand=statement.getOperand()->getOperandField();
//    //else
//        //operand=statement.getOperand()->getintValue();
//    std::string comment=statement.getComment()->getComment();
    if(objectCode.length()>0)
        objectCode=stringUtil->fillZeros(objectCode,6);
    listFile<<stringUtil->fillSpaces(lineNum,10)<<stringUtil->fillSpaces(locationCounter,8)<<stringUtil->fillSpaces(objectCode,8)<<"\n";
            //<<fillSpaces(label,8)<<
//    <<fillSpaces(mnemonic,8)<<fillSpaces(operand,8)<<fillSpaces(comment,8);

}
