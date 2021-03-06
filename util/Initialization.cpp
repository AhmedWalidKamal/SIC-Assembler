//
// Created by Walid on 5/4/2017.
//


#include "Initialization.h"
#include "../directive/StartDirective.h"
#include "../directive/EndDirective.h"
#include "../directive/WordDirective.h"
#include "../directive/ByteDirective.h"
#include "../directive/ReserveByteDirective.h"
#include "../directive/ReserveWordDirective.h"
#include "../directive/EquDirective.h"
#include "../directive/OrgDirective.h"
#include "../directive/LtorgDirective.h"

void Initialization::initInstructionTable(std::map<std::string, Instruction *> &instructionTable) {
    instructionTable["ADD"] = new Instruction("ADD", 24,3, 1);
    instructionTable["AND"] = new Instruction("AND", 64, 3, 1);
    instructionTable["COMP"] = new Instruction("COMP", 40, 3, 1);
    instructionTable["DIV"] = new Instruction("DIV", 36, 3, 1);
    instructionTable["J"] = new Instruction("J", 60, 3, 1);
    instructionTable["JEQ"] = new Instruction("JEQ", 48, 3, 1);
    instructionTable["JGT"] = new Instruction("JGT", 52, 3, 1);
    instructionTable["JLT"] = new Instruction("JLT", 56, 3, 1);
    instructionTable["JSUB"] = new Instruction("JSUB", 72, 3, 1);
    instructionTable["LDA"] = new Instruction("LDA", 0, 3, 1);
    instructionTable["LDCH"] = new Instruction("LDCH", 80, 3, 1);
    instructionTable["LDL"] = new Instruction("LDL", 8, 3, 1);
    instructionTable["LDX"] = new Instruction("LDX", 4, 3, 1);
    instructionTable["MUL"] = new Instruction("MUL", 32, 3, 1);
    instructionTable["OR"] = new Instruction("OR", 68, 3, 1);
    instructionTable["RD"] = new Instruction("RD", 216, 3, 1);
    instructionTable["RSUB"] = new Instruction("RSUB", 76, 3, 0); /// Assumption -> Rsub doens't take any operands.
    instructionTable["STA"] = new Instruction("STA", 12, 3, 1);
    instructionTable["STCH"] = new Instruction("STCH", 84, 3, 1);
    instructionTable["STL"] = new Instruction("STL", 20, 3, 1);
    instructionTable["STX"] = new Instruction("STX", 16, 3, 1);
    instructionTable["SUB"] = new Instruction("SUB", 28, 3, 1);
    instructionTable["TD"] = new Instruction("TD", 224, 3, 1);
    instructionTable["TIX"] = new Instruction("TIX", 44, 3, 1);
    instructionTable["WD"] = new Instruction("WD", 220, 3, 1);
}

void Initialization::initDirectiveTable(std::map<std::string, Directive *> &directiveTable) {
    directiveTable["START"] = new StartDirective();
    directiveTable["END"] = new EndDirective();
    directiveTable["WORD"] = new WordDirective();
    directiveTable["BYTE"] = new ByteDirective();
    directiveTable["RESB"] = new ReserveByteDirective();
    directiveTable["RESW"] = new ReserveWordDirective();
    directiveTable["EQU"] = new EquDirective();
    directiveTable["ORG"] = new OrgDirective();
    directiveTable["LTORG"] = new LtorgDirective();
}
