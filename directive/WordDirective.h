//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_WORDDIRECTIVE_H
#define SIC_ASSEMBLER_WORDDIRECTIVE_H

#include "Directive.h"

class WordDirective : public Directive {

public :
    int execute(int &start, int &end, int &locationCounter,
                Operand *operand, std::map<std::string, int> &symbolTable,
                std::map<std::string, std::pair<Operand *, int>> &literalTable);

    void validate(std::map<std::string, Instruction *> &instructionTable,
                  std::map<std::string, Directive *> &directiveTable,
                  std::map<std::string, int> &symbolTable, const int &start, const int &end,
                  const int &locationCounter, Statement *statement);

private:
};


#endif //SIC_ASSEMBLER_WORDDIRECTIVE_H
