//
// Created by Walid on 5/23/2017.
//

#include "LtorgDirective.h"
#include "../error/ErrorHandler.h"

int LtorgDirective::execute(int &start, int &end, int &locationCounter,
                            Operand *operand,std::map<std::string, int> &symbolTable,
                            std::map<std::string, std::pair<Operand *, int>> &literalTable) {
    int initLocCtr = locationCounter;
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
    return initLocCtr;
}

void LtorgDirective::validate(std::map<std::string, Instruction *> &instructionTable,
                              std::map<std::string, Directive *> &directiveTable,
                              std::map<std::string, int> &symbolTable, const int &start, const int &end,
                              const int &locationCounter, Statement *statement) {
    if (!statement->getLabel()->isEmpty()) {
        throw ErrorHandler::ltorg_label;
    }
    if (!statement->getOperand()->isEmpty()) {
        throw ErrorHandler::ltorg_operand;
    }
}
