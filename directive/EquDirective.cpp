//
// Created by Salma.Ahmed on 22/05/2017.
//


#include "EquDirective.h"
#include "../error/ErrorHandler.h"

int EquDirective::execute(int &start, int &end, int &locationCounter,
                          int incrementValue, std::map<int, std::pair<std::string, int>> &literalTable) {

}

void EquDirective::validate(std::map<std::string, Instruction *> &instructionTable,
                            std::map<std::string, Directive *> &directiveTable,
                            std::map<std::string, int> &symbolTable, const int &start, const int &end,
                            const int &locationCounter, Statement *statement) {

    if (statement->getLabel()->isEmpty()) {
        throw ErrorHandler::equate_missing_label;
    }
    if (statement->getOperand()->isEmpty()) {
        throw ErrorHandler::equate_missing_value;
    }
}