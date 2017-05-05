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

}
void ListingFileWriter::writeInitialLine() {
 listFile<<fillSpaces("Line",10)<<fillSpaces("Loc",25)<<fillSpaces("Source Statement",35)<<"Object Code"<<"\n";
    listFile<<drawLine(80)<<"\n";
}
void ListingFileWriter::writeLine(int lineNumber,Statement statement, std::string objectCode) {
    std::string lineNum=toString(lineNumber);
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
        objectCode=fillZeros(objectCode,6);
    listFile<<fillSpaces(lineNum,10)<<fillSpaces(locationCounter,8)<<fillSpaces(objectCode,8)<<"\n";
            //<<fillSpaces(label,8)<<
//    <<fillSpaces(mnemonic,8)<<fillSpaces(operand,8)<<fillSpaces(comment,8);

}
std::string ListingFileWriter::toString(int number) {
    std::ostringstream stream;
    stream << number;
    return stream.str();;
}
std::string ListingFileWriter:: fillSpaces(std::string word,int size){
    while(word.length()<size) {
        word+=" ";
    }
    return word;
}
string ListingFileWriter:: fillZeros(std::string word,int size){
    while(word.length()<size) {
        word="0"+word;
    }
    return word;
}
std::string ListingFileWriter:: drawLine(int length){
    std::string line;
    while(length--){
        line+="*";
    }

    return line;
}