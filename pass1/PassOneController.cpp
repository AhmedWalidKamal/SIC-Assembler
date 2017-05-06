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
#include "../util/Program.h"


PassOneController::PassOneController(std::map<std::string, Instruction *> &instructionTable,
                                     std::map<std::string, Directive *> &directiveTable) {
    PassOneController::instructionTable = instructionTable;
    PassOneController::directiveTable = directiveTable;
    locationCounter = 0;
    startAddress = -1;
    endAddress = -1; // Modified when END directive is reached.
}

std::string PassOneController::execute(std::map<std::string, int> &symbolTable,
                                       FileReader *fileReader, Program *program) {
    IntermediateFileWriter *intermediateFileWriter = new IntermediateFileWriter(fileReader->getFileName(),
                                                                                std::string(".int"));
    while (!fileReader->finishedReading()) {
        Statement *statement = fileReader->getNextStatement();
        if (statement->isComment()) {
            // write line to intermediate file.
        } else {
            try {
                statement->validate(instructionTable, directiveTable, symbolTable,
                                    startAddress, endAddress, locationCounter);
            } catch (ErrorHandler::Error error) {
                /// Write error in file instead of printing it to console, or both?
                std::cerr << ErrorHandler::errors[error] << std::endl;
                continue;
            }
            /// If no error logic:
            /// Updating SymTable
            if (statement->getOperand()->isLabel()) {
                symbolTable[statement->getOperand()->getOperandField()] = -1; // -1 indicating variable not declared yet.
            }
            if (!statement->getLabel()->isEmpty()) {
                symbolTable[statement->getLabel()->getLabelField()] = locationCounter;
            }

            /// Updating LC
            statement->execute(startAddress, endAddress, locationCounter, directiveTable, instructionTable);

            /// Writing to file
            // Write current line in intermediate file.
        }
    }
//        std::cout << "Finished Reading!!!";
//        exit(0);
        //loop over symTable making sure that every label has an address
        //if any label does not have an address

    /// Check this agian.
    if (startAddress == -1 && endAddress == -1) {
        program->setProgramLength(locationCounter);
    } else if (endAddress == -1) {
        program->setProgramLength(locationCounter - startAddress);
    } else {
        program->setProgramLength(endAddress - startAddress);
    }

}

