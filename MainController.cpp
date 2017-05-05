////
//// Created by Walid on 5/1/2017.
////
//

#include <iostream>
#include "MainController.h"
#include "pass1/PassOneController.h"
#include "pass2/PassTwoController.h"
#include "util/Initialization.h"

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
    PassOneController *passOne;
    passOne = new PassOneController(instructionTable, directiveTable);
//    std::string intermediateFile = passOne->execute(symbolTable, sourceFileReader);
    //PassTwoController *passTwo = new PassTwoController(intermediateFile); // salma takes from here.
}

void MainController::initDirectiveTable(std::map<std::string,
        Directive *> &directiveTable) {
    Initialization::initInstructionTable(instructionTable);
}

void MainController::initInstructionTable(std::map<std::string,
        Instruction *> &instructionTable) {
    Initialization::initDirectiveTable(directiveTable);
}
>>>>>>> 52c09488ec490e1eb07bf61c0b391577700b9eeb
