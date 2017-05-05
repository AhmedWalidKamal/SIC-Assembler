//
// Created by Walid on 5/3/2017.
//

#include "WordDirective.h"

int WordDirective :: execute(int& start, int& end, int& locationCounter,int incrementValue) {
    return locationCounter;
}

int WordDirective::validate(const std::map<std::string, Instruction *> &instructionTable,
                            const std::map<std::string, Directive *> &directiveTable,
                            const std::map<std::string, int> &symbolTable, const int &start, const int &end,
                            const int &locationCounter, Statement *statement) {
    if (!statement->getOperand()->isDecimalValue()) {
        return error; // operand not decimal value
    }
    return 0;
}
