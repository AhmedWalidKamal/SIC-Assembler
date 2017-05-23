//
// Created by Walid on 5/3/2017.
//

#include "StartDirective.h"
#include "../validate/SingleOperandValidateState.h"
#include "../error/ErrorHandler.h"

int StartDirective :: execute(int &start, int &end, int &locationCounter,
                              Operand *operand, std::map<std::string, int> &symbolTable,std::map<std::string, std::pair<Operand *, int>> &literalTable) {
    start = operand->getLCIncrement();
    locationCounter = operand->getLCIncrement();
    return locationCounter;
}

void StartDirective::validate(std::map<std::string, Instruction *> &instructionTable,
                              std::map<std::string, Directive *> &directiveTable,
                              std::map<std::string, int> &symbolTable, const int &start, const int &end,
                              const int &locationCounter, Statement *statement) {
    /// Assumption -> Multiple starts not allowed.
    if (start != -1) {
         throw ErrorHandler::multiple_starts;
    }

    /// Assumption -> Code before start not allowed.
    if (locationCounter !=0 ) {
        throw ErrorHandler::code_before_start;
    }
    // Assumption -> Start must have a label (as per the machine)
    if (statement->getLabel()->isEmpty()) {
        throw ErrorHandler::missing_label_at_start;
    }

    if (!statement->getOperand()->isEmpty()) {
        SingleOperandValidateState *state = new SingleOperandValidateState();
        state->validate(instructionTable, directiveTable, symbolTable, start, end, locationCounter, statement);

    }
    if (statement->getOperand()->isLabel()) {
        throw ErrorHandler::undefined_symbol_at_start;
    }

}

