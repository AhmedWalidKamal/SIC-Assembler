//
// Created by Walid on 5/5/2017.
//

#include "LabelValidationState.h"
#include "../statement/Statement.h"
#include "../error/ErrorHandler.h"
#include "MnemonicValidateState.h"

void LabelValidationState::validate(const std::map<std::string, Instruction *> &instructionTable,
 //                                  const std::map<std::string, Directive *> &directiveTable,
                                   const std::map<std::string, int> &symbolTable, const int &start, const int &end,
                                   const int &locationCounter, Statement *statement) {

    //throw ErrorHandler::invalid_label;
    if (symbolTable.find(statement->getLabel()->getLabelField()) != symbolTable.end()) {
        throw ErrorHandler::duplicate_label;
    }
    if (!statement->getLabel()->isValid()) {
        throw ErrorHandler::invalid_label;
    }
    MnemonicValidateState *state = new MnemonicValidateState();
    state->validate(instructionTable, symbolTable, start, end, locationCounter, statement)
}
