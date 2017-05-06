//
// Created by Walid on 5/3/2017.
//

#include "StartDirective.h"
#include "../validate/SingleOperandValidateState.h"
#include "../error/ErrorHandler.h"

int StartDirective :: execute(int& start, int& end, int& locationCounter,int incrementValue) {
    start = incrementValue;
    locationCounter = incrementValue;
    return locationCounter;
}

void StartDirective::validate(std::map<std::string, Instruction *> &instructionTable,
                              std::map<std::string, Directive *> &directiveTable,
                              std::map<std::string, int> &symbolTable, const int &start, const int &end,
                              const int &locationCounter, Statement *statement) {
    // Assumption -> Start must have a label (as per the machine)
    if (statement->getLabel()->isEmpty()) {
        throw ErrorHandler::missing_label_at_start;
    }
    SingleOperandValidateState *state = new SingleOperandValidateState();
    state->validate(instructionTable, symbolTable, start, end, locationCounter, statement);
    if (statement->getOperand()->isLabel()) {
        throw ErrorHandler::undefined_symbol_at_start;
    }

}

