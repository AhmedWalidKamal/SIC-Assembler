//
// Created by Walid on 5/3/2017.
//

#include "ReserveByteDirective.h"

int ReserveByteDirective :: execute(int& start, int& end, int& locationCounter,int incrementValue) {

    int currentLocationCounter = locationCounter;
    locationCounter += incrementValue;
    return currentLocationCounter;
}

int ReserveByteDirective::validate(const std::map<std::string, Instruction *> &instructionTable,
                                   const std::map<std::string, Directive *> &directiveTable,
                                   const std::map<std::string, int> &symbolTable, const int &start, const int &end,
                                   const int &locationCounter, Statement *statement) {
    return statement->getOperand()->isDecimalAddress();
}
