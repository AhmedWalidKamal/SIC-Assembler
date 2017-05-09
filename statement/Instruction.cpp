//
// Created by Walid on 5/4/2017.
//

#include <string>
#include "Instruction.h"

Instruction::Instruction(std::string instructionName, int opCode, int format, int numberOfOperands) {
    Instruction::instructionName = instructionName;
    Instruction::opCode = opCode;
    Instruction::format = format;
    Instruction::numberOfOperands = numberOfOperands;
}

const std::string &Instruction::getInstructionName() const {
    return instructionName;
}

int Instruction::getOpCode() const {
    return opCode;
}

int Instruction::getNumberOfOperands() const {
    return numberOfOperands;
}

int Instruction::getFormat() const {
    return format;
}
