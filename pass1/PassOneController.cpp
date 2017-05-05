//
// Created by Walid on 5/1/2017.
//

#include <iostream>
#include "PassOneController.h"
#include "../file/write/FileWriter.h"
#include "../format/FormatThree.h"
#include "../file/write/IntermediateFileWriter.h"


PassOneController::PassOneController(std::map<std::string, Instruction *> &instructionTable,
                                     std::map<std::string, Directive *> &directiveTable) {
    PassOneController::instructionTable = instructionTable;
    PassOneController::directiveTable = directiveTable;
    locationCounter = 0;
    startAddress = -1;
    endAddress = -1; // Modified when END directive is reached.
}

std::string PassOneController::execute(std::unordered_map<std::string, int> &symbolTable, FileReader *fileReader) {
    IntermediateFileWriter *intermediateFileWriter = new IntermediateFileWriter(fileReader->getFileName(),
                                                                                std::string(".int"));
    while (!fileReader->finishedReading()) {
        Statement *statement = fileReader->getNextStatement();
        if (statement->isComment()) {
            // write line to intermediate file.
        } else {
//            int errorType = statement.validate(&symTable, instTable, dirTable, start, end);
//            if (error) {
//                write error to intermediate file
//            } else {
//                if (statement.operandIsNewLabel()) {
//                    update symTable without address
//                }
//                if (statement.hasLabel()) {
//                    update symTable with new label address
//                }
//                /// Other possible logic here. execution from statement Object
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
            }
        }
//        loop over symTable making sure that every label has an address
//        if any label does not have an address
//
//        calculate length
//        fileReader.advance();
}

