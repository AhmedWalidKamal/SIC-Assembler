//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_BYTEDIRECTIVE_H
#define SIC_ASSEMBLER_BYTEDIRECTIVE_H

#include "Directive.h"

class ByteDirective : public Directive {
    public :
    int execute(int &start, int &end, int &locationCounter, int incrementValue);
    int validate(const std::map<std::string, Instruction *> &instructionTable,
                 const std::map<std::string, Directive *> &directiveTable,
                 const std::map<std::string, int> &symbolTable, const int &start, const int &end,
                 const int &locationCounter, Statement *statement);
};


#endif //SIC_ASSEMBLER_BYTEDIRECTIVE_H
