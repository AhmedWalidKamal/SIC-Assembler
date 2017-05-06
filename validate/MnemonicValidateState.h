//
// Created by Walid on 5/5/2017.
//

#ifndef SIC_ASSEMBLER_MNEMONICVALIDATESTATE_H
#define SIC_ASSEMBLER_MNEMONICVALIDATESTATE_H


#include <string>
#include <map>
#include "../directive/Directive.h"
#include "../statement/Instruction.h"

class MnemonicValidateState {
public:
    int validate(std::map<std::string, Instruction *> &instructionTable,
//                 const std::map<std::string, Directive *> &directiveTable,
                 std::map<std::string, int> &symbolTable, const int &start, const int &end,
                 const int &locationCounter, Statement *statement);
};


#endif //SIC_ASSEMBLER_MNEMONICVALIDATESTATE_H
