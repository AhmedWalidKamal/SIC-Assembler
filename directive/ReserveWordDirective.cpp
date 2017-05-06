//
// Created by Walid on 5/3/2017.
//

#include "ReserveWordDirective.h"
#include "../error/ErrorHandler.h"

int ReserveWordDirective :: execute(int& start, int& end, int& locationCounter,int incrementValue) {

    int currentLocationCounter = locationCounter;
    locationCounter += (3 *incrementValue);
    return currentLocationCounter;
}

void ReserveWordDirective::validate(std::map<std::string, Instruction *> &instructionTable,
//                         const std::map<std::string, Directive *> &directiveTable,
                                    std::map<std::string, int> &symbolTable, const int &start, const int &end,
                                    const int &locationCounter, Statement *statement) {
    if (!statement->getOperand()->isDecimalAddress()) {
        throw ErrorHandler::invalid_operand;
    }
}
