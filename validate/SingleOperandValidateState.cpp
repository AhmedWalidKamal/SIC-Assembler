//
// Created by Walid on 5/5/2017.
//

#include "SingleOperandValidateState.h"

int SingleOperandValidateState::validate(const std::map<std::string, Instruction *> &instructionTable,
                                         const std::map<std::string, Directive *> &directiveTable,
                                         const std::map<std::string, int> &symbolTable, const int &start,
                                         const int &end, const int &locationCounter, Statement *statement) {
    if (statement->getOperand().isEmpty()) {
        return -3553; // Missing operand.
    }
    if (!statement->getOperand()->isValid()) {
        return -5; // invalid operand.
    }
    return 0; // valid statement
}
