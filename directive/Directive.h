//
// Created by walid on 5/2/2017.
//

#ifndef SIC_ASSEMBLER_DIRECTIVE_H
#define SIC_ASSEMBLER_DIRECTIVE_H


#include <string>
#include <map>
#include "../statement/Instruction.h"
#include "../statement/Statement.h"

class Directive {
public:
    virtual int execute(int& start, int& end, int& locationCounter,int incrementValue) = 0;
//    virtual int validate(const std::map<std::string, Instruction *> &instructionTable,
//                         const std::map<std::string, Directive *> &directiveTable,
//                         const std::map<std::string, int> &symbolTable, const int &start, const int &end,
//                         const int &locationCounter, Statement *statement) = 0;

private:


};


#endif //SIC_ASSEMBLER_DIRECTIVE_H
