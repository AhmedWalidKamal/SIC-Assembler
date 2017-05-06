//
// Created by Walid on 5/5/2017.
//

#include "SingleOperandValidateState.h"
#include "../error/ErrorHandler.h"

int SingleOperandValidateState::validate(std::map<std::string, Instruction *> &instructionTable,
                                         std::map<std::string, Directive *> &directiveTable,
                                         std::map<std::string, int> &symbolTable, const int &start,
                                         const int &end, const int &locationCounter, Statement *statement) {
    if (statement->getOperand()->getOperandField().empty()) {
        throw ErrorHandler::missing_operand;
    }
    if (!statement->getOperand()->isValid()) {
        throw ErrorHandler::invalid_operand;
    }
}
