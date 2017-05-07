////
//// Created by Walid on 5/1/2017.
////
//

#include <iostream>
#include "MainController.h"
#include "pass1/PassOneController.h"
#include "pass2/PassTwoController.h"
#include "util/Initialization.h"
#include "util/Program.h"

MainController::MainController() {
    initDirectiveTable(directiveTable);
    initInstructionTable(instructionTable);
}

void MainController::setSourceFileReader(std::string fileName) {
    sourceFileReader = new FileReader(fileName);
}

void MainController::execute(std::string fileName) {
    setSourceFileReader(fileName);
    symbolTable.clear();
    Program *program = new Program();
    PassOneController *passOne;
    passOne = new PassOneController(instructionTable, directiveTable);
    passOne->execute(symbolTable, sourceFileReader, program);
    PassTwoController *passTwo;
    passTwo = new PassTwoController(instructionTable);
    passTwo->executePass2(symbolTable, program, fileName);
}

void MainController::initDirectiveTable(std::map<std::string,
        Directive *> &directiveTable) {
    Initialization::initInstructionTable(instructionTable);
}

void MainController::initInstructionTable(std::map<std::string,
        Instruction *> &instructionTable) {
    Initialization::initDirectiveTable(directiveTable);
}
