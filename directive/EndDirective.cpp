//
// Created by Walid on 5/3/2017.
//

#include "EndDirective.h"
#include "../validate/SingleOperandValidateState.h"
#include "../error/ErrorHandler.h"

int EndDirective::execute(int &start, int &end, int &locationCounter,
                          Operand *operand, std::map<std::string, std::pair<Operand *, int>> &literalTable) {
    for (auto &literal : literalTable) {
        // If literal doesn't have an address
        if (literal.second.second == -1) {
            literal.second.second = locationCounter;
            if (operand->isHexConstant() || operand->isStringConstant()) {
                locationCounter += literal.second.first->getLCIncrement();
            } else {
                locationCounter += 3;
            }
        }
    }
    // Because END's statement LC isn't displayed.
    return 0;

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
