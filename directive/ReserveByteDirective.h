//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_RESERVEBYTEDIRECTIVE_H
#define SIC_ASSEMBLER_RESERVEBYTEDIRECTIVE_H

#include "Directive.h"

class ReserveByteDirective : public Directive {

    public :
    int execute(int& start, int& end, int& locationCounter,
                Operand *operand, std::map<int, std::pair<std::string, int>> &literalTable);
    void validate(std::map<std::string, Instruction *> &instructionTable,
                  std::map<std::string, Directive *> &directiveTable,
                  std::map<std::string, int> &symbolTable, const int &start, const int &end,
                  const int &locationCounter, Statement *statement);
};


#endif //SIC_ASSEMBLER_RESERVEBYTEDIRECTIVE_H
