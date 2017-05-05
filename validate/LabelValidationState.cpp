//
// Created by Walid on 5/5/2017.
//

#include "LabelValidationState.h"
#include "../statement/Statement.h"

int LabelValidationState::validate(const std::map<std::string, Instruction *> &instructionTable,
                                   const std::map<std::string, Directive *> &directiveTable,
                                   const std::map<std::string, int> &symbolTable, const int &start, const int &end,
                                   const int &locationCounter, Statement *statement) {
    if (symbolTable.find(statement->getLabel()->getLabelField()) == symbolTable.end() ) {
        return -1; // duplicate label.
    }
    if (!statement->getLabel()->isValid()) {
        return -2; // invalid label.
    }
    return MnemonicValidationState.validate(instructionTable, directiveTable, symbolTable, start, end, locationCounter, statement);
}
