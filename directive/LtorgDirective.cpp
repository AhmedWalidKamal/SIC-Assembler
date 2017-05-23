//
// Created by Walid on 5/23/2017.
//

#include "LtorgDirective.h"
#include "../error/ErrorHandler.h"

int LtorgDirective::execute(int &start, int &end, int &locationCounter,
                            int incrementValue, std::map<int, std::pair<std::string, int>> &literalTable) {
    return 0;
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
