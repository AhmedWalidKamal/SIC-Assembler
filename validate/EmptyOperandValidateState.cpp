//
// Created by Walid on 5/5/2017.
//

#include "EmptyOperandValidateState.h"
#include "../statement/Statement.h"
#include "../error/ErrorHandler.h"

int EmptyOperandValidateState::validate(std::map<std::string, Instruction *> &instructionTable,
//                                        const std::map<std::string, Directive *> &directiveTable,
                                        std::map<std::string, int> &symbolTable, const int &start, const int &end,
                                        const int &locationCounter, Statement *statement) {
    if (!statement->getOperand()->getOperandField().empty()) {
        throw ErrorHandler::invalid_operand;
    }
}
