//
// Created by Walid on 5/3/2017.
//

#include "StartDirective.h"
#include "../validate/SingleOperandValidateState.h"

int StartDirective :: execute(int& start, int& end, int& locationCounter,int incrementValue) {
    start = incrementValue;
    locationCounter = incrementValue;
    return locationCounter;
}

int StartDirective::validate(const std::map<std::string, Instruction *> &instructionTable,
                             const std::map<std::string, Directive *> &directiveTable,
                             const std::map<std::string, int> &symbolTable, const int &start, const int &end,
                             const int &locationCounter, Statement *statement) {
    if (statement->getLabel()->isEmpty()) {
        return -325; // Missing Label at Start.
    }
    if (new SingleOperandValidateState().validate(params)) {
        if (statment -> getOperand -> type == label) {
            return -4000; // entered label at start;
        }
    }
    return -335; // invalid operand
}
