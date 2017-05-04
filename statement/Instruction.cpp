//
// Created by Walid on 5/4/2017.
//

#include <string>
#include "Instruction.h"
#include "../format/Format.h"

Instruction::Instruction(std::string instructionName, int opCode, Format *format, int numberOfOperands) {
    this->instructionName = instructionName;
    this->opCode = opCode;
    this->format = format;
    this->numberOfOperands = numberOfOperands;
}

const std::string &Instruction::getInstructionName() const {
    return instructionName;
}

int Instruction::getOpCode() const {
    return opCode;
}

Format *Instruction::getFormat() const {
    return format;
}

int Instruction::getNumberOfOperands() const {
    return numberOfOperands;
}
