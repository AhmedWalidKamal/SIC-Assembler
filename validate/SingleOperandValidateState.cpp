//
// Created by Walid on 5/5/2017.
//

#include "SingleOperandValidateState.h"
#include "../error/ErrorHandler.h"
#include <iostream>
int SingleOperandValidateState::validate(std::map<std::string, Instruction *> &instructionTable,
                                         std::map<std::string, Directive *> &directiveTable,
                                         std::map<std::string, int> &symbolTable, const int &start,
                                         const int &end, const int &locationCounter, Statement *statement) {
    if (statement->getOperand()->isEmpty()) {
        throw ErrorHandler::missing_operand;
    }

    if (!statement->getOperand()->isValid()) {
        throw ErrorHandler::invalid_operand;
    }

    if (statement->getOperand()->isLabel()) {
        if ((instructionTable.find(statement->getOperand()->getOperandField()) != instructionTable.end()) ||
            (directiveTable.find(statement->getOperand()->getOperandField()) != directiveTable.end())){
            throw ErrorHandler::label_is_mnemonic;
        }
    }
}



