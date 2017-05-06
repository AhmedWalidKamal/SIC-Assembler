//
// Created by Walid on 5/5/2017.
//

#ifndef SIC_ASSEMBLER_LABELVALIDATIONSTATE_H
#define SIC_ASSEMBLER_LABELVALIDATIONSTATE_H


#include <string>
#include <map>
#include "../statement/Instruction.h"
#include "../directive/Directive.h"

class LabelValidationState {
public:
    void validate(std::map<std::string, Instruction *> &instructionTable,
                 std::map<std::string, Directive *> &directiveTable,
                 std::map<std::string, int> &symbolTable, const int &start, const int &end,
                 const int &locationCounter, Statement *statement);

};


#endif //SIC_ASSEMBLER_LABELVALIDATIONSTATE_H
