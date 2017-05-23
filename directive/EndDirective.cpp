//
// Created by Walid on 5/3/2017.
//

#include "EndDirective.h"
#include "../validate/SingleOperandValidateState.h"
#include "../error/ErrorHandler.h"

int EndDirective :: execute(int& start, int& end, int& locationCounter,
                            int incrementValue, std::map<int, std::pair<std::string, int>> &literalTable) {
    end = locationCounter;
    return locationCounter;
}

void EndDirective::validate(std::map<std::string, Instruction *> &instructionTable,
                            std::map<std::string, Directive *> &directiveTable,
                            std::map<std::string, int> &symbolTable, const int &start, const int &end,
                            const int &locationCounter, Statement *statement) {
    if (end != -1) {
        throw ErrorHandler::multiple_ends;
    }
    if (!statement->getLabel()->isEmpty()) {
        throw ErrorHandler::label_at_end;
    }
    if (!statement->getOperand()->isEmpty()) {
        SingleOperandValidateState *state = new SingleOperandValidateState();
        state->validate(instructionTable, directiveTable, symbolTable, start, end, locationCounter, statement);
    }
}
