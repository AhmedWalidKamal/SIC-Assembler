//
// Created by Walid on 5/5/2017.
//

#include "EmptyOperandValidateState.h"
#include "../statement/Statement.h"

int EmptyOperandValidateState::validate(const std::map<std::string, Instruction *> &instructionTable,
                                        const std::map<std::string, Directive *> &directiveTable,
                                        const std::map<std::string, int> &symbolTable, const int &start, const int &end,
                                        const int &locationCounter, Statement *statement) {
    if (!statement->getOperand().isEmpty()) {
        return -4; // operand to a non-operand
    }
    return 0; // valid statement
}
