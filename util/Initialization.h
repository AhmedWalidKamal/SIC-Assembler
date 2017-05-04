//
// Created by Walid on 5/4/2017.
//

#ifndef SIC_ASSEMBLER_INITIALIZATION_H
#define SIC_ASSEMBLER_INITIALIZATION_H


#include <string>
#include <unordered_map>
#include "../statement/Instruction.h"
#include "../directive/Directive.h"

class Initialization {
public:
    static void initInstructionTable(std::unordered_map<std::string, Instruction *> &instructionTable);
    static void initDirectiveTable(std::unordered_map<std::string, Directive *> &directiveTable);

private:
    Initialization () {}
};


#endif //SIC_ASSEMBLER_INITIALIZATION_H
