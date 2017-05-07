//
// Created by Walid on 5/5/2017.
//

#include <iostream>
#include "LabelValidationState.h"
#include "../statement/Statement.h"
#include "../error/ErrorHandler.h"
#include "MnemonicValidateState.h"

void LabelValidationState::validate(std::map<std::string, Instruction *> &instructionTable,
                                   std::map<std::string, Directive *> &directiveTable,
                                   std::map<std::string, int> &symbolTable, const int &start, const int &end,
                                   const int &locationCounter, Statement *statement) {

      //must be called first to trim string from space if valid, indicates this statement has new label
    if (!statement->getLabel()->isValid()) {
        throw ErrorHandler::invalid_label;
    }
    if (symbolTable.find(statement->getLabel()->getLabelField()) != symbolTable.end() &&
            symbolTable[statement->getLabel()->getLabelField()] != -1) {
        throw ErrorHandler::duplicate_label;
    }

    if ((instructionTable.find(statement->getLabel()->getLabelField()) != instructionTable.end()) ||
    (directiveTable.find(statement->getLabel()->getLabelField()) != directiveTable.end())){
        throw ErrorHandler::label_is_mnemonic;
    }
    MnemonicValidateState *state = new MnemonicValidateState();
    state->validate(instructionTable, directiveTable, symbolTable, start, end, locationCounter, statement);
}
