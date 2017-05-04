//
// Created by Walid on 5/4/2017.
//

#ifndef SIC_ASSEMBLER_INSTRUCTION_H
#define SIC_ASSEMBLER_INSTRUCTION_H


#include "../format/Format.h"

class Instruction {
public:
    Instruction(std::string instructionName, int opCode, Format *format, int numberOfOperands);

    const std::string &getInstructionName() const;
    int getOpCode() const;
    Format *getFormat() const;
    int getNumberOfOperands() const;

private:
    std::string instructionName;
    int opCode;
    Format *format;
    int numberOfOperands;
};


#endif //SIC_ASSEMBLER_INSTRUCTION_H
