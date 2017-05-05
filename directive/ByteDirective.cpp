//
// Created by Walid on 5/3/2017.
//

#include "ByteDirective.h"

int ByteDirective :: execute(int& start, int& end, int& locationCounter,int incrementValue) {
    return locationCounter;
}

int ByteDirective::validate(const std::map<std::string, Instruction *> &instructionTable,
                            const std::map<std::string, Directive *> &directiveTable,
                            const std::map<std::string, int> &symbolTable, const int &start, const int &end,
                            const int &locationCounter, Statement *statement) {
    if (statement->getOperand()->isStringConstant() || statement->getOperand()->isHexConstant())
}
