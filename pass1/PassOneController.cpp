//
// Created by Walid on 5/1/2017.
//

#include <iostream>
#include <cstdlib>
#include "PassOneController.h"
#include "../file/write/FileWriter.h"
#include "../format/FormatThree.h"
#include "../file/write/IntermediateFileWriter.h"
#include "../error/ErrorHandler.h"


PassOneController::PassOneController(std::map<std::string, Instruction *> &instructionTable,
                                     std::map<std::string, Directive *> &directiveTable) {
    PassOneController::instructionTable = instructionTable;
    PassOneController::directiveTable = directiveTable;
    locationCounter = 0;
    startAddress = -1;
    endAddress = -1; // Modified when END directive is reached.
}

std::string PassOneController::execute(std::map<std::string, int> &symbolTable, FileReader *fileReader) {
    IntermediateFileWriter *intermediateFileWriter = new IntermediateFileWriter(fileReader->getFileName(),
                                                                                std::string(".int"));
    while (!fileReader->finishedReading()) {
        Statement *statement = fileReader->getNextStatement();
        if (statement->isComment()) {
            // write line to intermediate file.
        } else {
            try {
                statement->validate(instructionTable, directiveTable, symbolTable, startAddress, endAddress, locationCounter);
            } catch (ErrorHandler::Error error) {
                /// Write error in file instead of printing it to console, or both?
                std::cerr << ErrorHandler::errors[error] << std::endl;
            }

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
        std::cout << "Finished Reading!!!";
        exit(0);
//        loop over symTable making sure that every label has an address
//        if any label does not have an address
//
//        calculate length
//        fileReader.advance();
}

