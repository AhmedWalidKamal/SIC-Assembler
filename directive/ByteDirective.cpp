//
// Created by Walid on 5/3/2017.
//

#include "ByteDirective.h"
#include "../error/ErrorHandler.h"

int ByteDirective :: execute(int& start, int& end, int& locationCounter,int incrementValue) {
    return locationCounter;
}

void
ByteDirective::validate(std::map<std::string, Instruction *> &instructionTable,
                        std::map<std::string, Directive *> &directiveTable,
                        std::map<std::string, int> &symbolTable, const int &start, const int &end,
                        const int &locationCounter, Statement *statement) {
    if (!statement->getOperand()->validateHexConstant() && !statement->getOperand()->validateStringConstant()) {
        throw ErrorHandler::invalid_operand;
    }
}

