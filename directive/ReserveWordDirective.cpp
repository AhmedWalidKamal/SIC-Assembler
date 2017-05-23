//
// Created by Walid on 5/3/2017.
//

#include "ReserveWordDirective.h"
#include "../error/ErrorHandler.h"

int ReserveWordDirective :: execute(int &start, int &end, int &locationCounter,
                                    Operand *operand, std::map<std::string, std::pair<std::string, int>> &literalTable) {

    int currentLocationCounter = locationCounter;
    locationCounter += (3*operand->getLCIncrement());
    return currentLocationCounter;
}

void ReserveWordDirective::validate(std::map<std::string, Instruction *> &instructionTable,
                                    std::map<std::string, Directive *> &directiveTable,
                                    std::map<std::string, int> &symbolTable, const int &start, const int &end,
                                    const int &locationCounter, Statement *statement) {
    if (!statement->getOperand()->validateDecimalAddress()) {
        throw ErrorHandler::invalid_operand;
    }
}
