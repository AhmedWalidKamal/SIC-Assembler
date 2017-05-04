//
// Created by Walid on 5/1/2017.
//

#include "PassOneController.h"
#include "../file/write/FileWriter.h"


PassOneController::PassOneController(std::unordered_map<std::string, Instruction *> &instructionTable,
                                     std::unordered_map<std::string, Directive *> &directiveTable) {
    this->instructionTable = instructionTable;
    this->directiveTable = directiveTable;
    locationCounter = 0;
    startAddress = -1;
    endAddress = -1; // Modified when END directive is reached.
}

std::string PassOneController::execute(std::unordered_map<std::string, int> &symbolTable, FileReader *fileReader) {
//    FileWriter *fileWriter = new FileWriter("intermediate", "fancyExtension");
//    while (fileReader has not finished reading) {
//        Statement *statement = fileReader.getNextStatement();
//        if (statement.isComment()) {
//            write to intermediate file
//        } else {
//            int errorType = statement.validate(&symTable, instTable, dirTable, start, end); // errorType maps to each error to be printerd.
//            if (error) {
//                write error to intermediate file
//            } else {
//                if (statement.operandIsNewLabel()) {
//                    update symTable without address
//                }
//                if (statement.hasLabel()) {
//                    update symTable with new label address
//                }
//                /// Other possible logic here.
//                if (statement.mnemonicIsDirective()) {
//                    dirTable[statement.getMnemonic()].perform();
//                } else {
//                    if (!statement.isFormatFour()) {
//                        instrTable.getFormat.updateLC();
//                    } else {
//
//                    }
//                }
//                write statement to intermediate file
//            }
//        }
//        loop over symTable making sure that every label has an address
//        if any label does not have an address

//        calculate length
//        fileReader.advance();
//    }
}
