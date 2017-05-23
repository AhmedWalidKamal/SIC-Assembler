//
// Created by Walid on 5/3/2017.
//

#include "ReserveByteDirective.h"
#include "../error/ErrorHandler.h"

int ReserveByteDirective :: execute(int &start, int &end, int &locationCounter, Operand *operand,
                                    std::map<std::string, int> &symbolTable,std::map<std::string,
                                    std::pair<Operand *, int>> &literalTable) {

    int currentLocationCounter = locationCounter;
    locationCounter += operand->getLCIncrement();
    return currentLocationCounter;
}

void ReserveByteDirective::validate(std::map<std::string, Instruction *> &instructionTable,
                                    std::map<std::string, Directive *> &directiveTable,
                                    std::map<std::string, int> &symbolTable, const int &start, const int &end,
                                    const int &locationCounter, Statement *statement) {

    if (!statement->getOperand()->validateDecimalAddress()) {
        throw ErrorHandler::invalid_operand;
    }
}

