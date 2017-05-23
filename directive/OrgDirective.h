//
// Created by Salma.Ahmed on 22/05/2017.
//

#ifndef SIC_ASSEMBLER_ORGDIRECTIVE_H
#define SIC_ASSEMBLER_ORGDIRECTIVE_H

#include "Directive.h"

class OrgDirective : public Directive {
public :
    int execute(int &start, int &end, int &locationCounter,
                int incrementValue, std::map<int, std::pair<std::string, int>> &literalTable);

    void validate(std::map<std::string, Instruction *> &instructionTable,
                  std::map<std::string, Directive *> &directiveTable,
                  std::map<std::string, int> &symbolTable, const int &start, const int &end,
                  const int &locationCounter, Statement *statement);
};

#endif //SIC_ASSEMBLER_ORGDIRECTIVE_H
