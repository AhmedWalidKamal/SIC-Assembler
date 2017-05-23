//
// Created by Salma.Ahmed on 22/05/2017.
//
#include "OrgDirective.h"
#include "../error/ErrorHandler.h"

int OrgDirective::execute(int &start, int &end, int &locationCounter,
                          Operand *operand, std::map<std::string, std::pair<std::string, int>> &literalTable) {

//update the location counter with the operand of the org or reset it back to last value before Org
    locationCounter=operand->getLCIncrement();
    return locationCounter;
}

void OrgDirective::validate(std::map<std::string, Instruction *> &instructionTable,
                            std::map<std::string, Directive *> &directiveTable,
                            std::map<std::string, int> &symbolTable, const int &start, const int &end,
                            const int &locationCounter, Statement *statement) {
    if (!statement->getLabel()->isEmpty()) {
        throw ErrorHandler::label_before_org;
    }
}
