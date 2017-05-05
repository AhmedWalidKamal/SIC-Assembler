////
//// Created by Walid on 5/1/2017.
////
//
//#include "MainController.h"
//#include "pass1/PassOneController.h"
//#include "pass2/PassTwoController.h"
//#include "util/Initialization.h"
//
//MainController::MainController() {
//    initDirectiveTable(directiveTable);
//    initInstructionTable(instructionTable);
//}
//
//void MainController::setSourceFileReader(std::string fileName) {
//    sourceFileReader = new FileReader(fileName);
//}
//
//void MainController::execute(std::string fileName) {
//    setSourceFileReader(fileName);
//    symbolTable.clear();
//    PassOneController *passOne;
//    passOne = new PassOneController(instructionTable, directiveTable);
//    std::string intermediateFile = passOne->execute(symbolTable, sourceFileReader);
//    //PassTwoController *passTwo = new PassTwoController(intermediateFile); // salma takes from here.
//}
//
//void MainController::initDirectiveTable(std::unordered_map<std::string,
//        Directive *> &directiveTable) {
//    Initialization::initInstructionTable(instructionTable);
//}
//
//void MainController::initInstructionTable(std::unordered_map<std::string,
//        Instruction *> &instructionTable) {
//    Initialization::initDirectiveTable(directiveTable);
//}
