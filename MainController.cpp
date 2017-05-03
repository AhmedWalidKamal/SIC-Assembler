//
// Created by walid on 5/1/2017.
//

#include "MainController.h"
#include "pass1/PassOneController.h"
#include "pass2/PassTwoController.h"

MainController::MainController() {
    initInstructionTable(&instructionTable);
    initDirectiveTable(&directiveTable);
}

void MainController::setsourceFileReader(std::string fileName) {
    sourceFileReader = new FileReader(fileName);
}

void MainController::initInstructionTable(std::unordered_map<std::string, std::pair<opCode *, format *>> *pMap) {

}

void MainController::initDirectiveTable(std::unordered_map<std::string, directve *> *pMap) {

}

void MainController::execute(std::string fileName) {
    setsourceFileReader(fileName);
    symbolTable.clear();
    PassOneController *passOne;
    passOne = new PassOneController(&instructionTable, &directiveTable);
    std::string intermediateFile = passOne.execute(&symbolTable, &sourceFileReader);
    //PassTwoController *passTwo = new PassTwoController(intermediateFile); // salma takes from here.
}
