//
// Created by Walid on 5/4/2017.
//

#ifndef SIC_ASSEMBLER_INSTRUCTION_H
#define SIC_ASSEMBLER_INSTRUCTION_H

class Instruction {
public:
    Instruction(std::string instructionName, int opCode, int format, int numberOfOperands);

    const std::string &getInstructionName() const;
    int getOpCode() const;
    int getNumberOfOperands() const;
    int getFormat() const;

private:
    std::string instructionName;
    int opCode, format, numberOfOperands;

};


#endif //SIC_ASSEMBLER_INSTRUCTION_H
