//
// Created by Walid on 5/4/2017.
//

#ifndef SIC_ASSEMBLER_INITIALIZATION_H
#define SIC_ASSEMBLER_INITIALIZATION_H


#include <string>
#include <unordered_map>
#include <map>
#include "../statement/Instruction.h"
#include "../directive/Directive.h"

class Initialization {
public:
    static void initInstructionTable(std::map<std::string, Instruction *> &instructionTable);
    static void initDirectiveTable(std::map<std::string, Directive *> &directiveTable);

private:
    Initialization () {}
};


#endif //SIC_ASSEMBLER_INITIALIZATION_H
