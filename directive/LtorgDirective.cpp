//
// Created by Walid on 5/23/2017.
//

#include "LtorgDirective.h"

int LtorgDirective::execute(int &start, int &end, int &locationCounter, int incrementValue) {
    return 0;
}

void LtorgDirective::validate(std::map<std::string, Instruction *> &instructionTable,
                              std::map<std::string, Directive *> &directiveTable,
                              std::map<std::string, int> &symbolTable, const int &start, const int &end,
                              const int &locationCounter, Statement *statement) {

}
