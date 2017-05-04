//
// Created by Walid on 5/4/2017.
//

#include "Initialization.h"
#include "../format/FormatOne.h"
#include "../directive/StartDirective.h"
#include "../directive/EndDirective.h"
#include "../directive/WordDirective.h"
#include "../directive/ByteDirective.h"
#include "../directive/ReserveByteDirective.h"
#include "../directive/ReserveWordDirective.h"

void Initialization::initInstructionTable(std::unordered_map<std::string, Instruction *> &instructionTable) {
    instructionTable["hi"] = new Instruction("s", 2, new FormatOne(), 3);
}

void Initialization::initDirectiveTable(std::unordered_map<std::string, Directive *> &directiveTable) {
    directiveTable["START"] = new StartDirective();
    directiveTable["END"] = new EndDirective();
    directiveTable["WORD"] = new WordDirective();
    directiveTable["BYTE"] = new ByteDirective();
    directiveTable["RESB"] = new ReserveByteDirective();
    directiveTable["RESW"] = new ReserveWordDirective();
}
