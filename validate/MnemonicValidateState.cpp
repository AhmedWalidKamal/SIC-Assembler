//
// Created by Walid on 5/5/2017.
//

#include <iostream>
#include "MnemonicValidateState.h"
#include "../statement/Statement.h"
#include "EmptyOperandValidateState.h"
#include "SingleOperandValidateState.h"
#include "../error/ErrorHandler.h"

int MnemonicValidateState::validate(std::map<std::string, Instruction *> &instructionTable,
                                    std::map<std::string, Directive *> &directiveTable,
                                    std::map<std::string, int> &symbolTable, const int &start, const int &end,
                                    const int &locationCounter, Statement *statement) {

      if (!statement->getMnemonic()->isValid()){
          throw ErrorHandler::mnemonic_not_found;
      }

    if (instructionTable.find(statement->getMnemonic()->getMnemonicField()) != instructionTable.end()) {
        if (instructionTable[statement->getMnemonic()->getMnemonicField()]->getNumberOfOperands() == 0) {
            EmptyOperandValidateState *state = new EmptyOperandValidateState();
            state->validate(instructionTable, directiveTable, symbolTable, start, end, locationCounter, statement);
        } else {
            SingleOperandValidateState *state = new SingleOperandValidateState();
            state->validate(instructionTable, directiveTable, symbolTable, start, end, locationCounter, statement);
        }
    } else if (directiveTable.find(statement->getMnemonic()->getMnemonicField()) != directiveTable.end()) {
        directiveTable[statement->getMnemonic()->getMnemonicField()]
                ->validate(instructionTable, directiveTable, symbolTable, start, end, locationCounter, statement);
    }else {
        throw ErrorHandler::mnemonic_not_found;
    }
}
