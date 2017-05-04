//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_OPERAND_H
#define SIC_ASSEMBLER_OPERAND_H
#include <string>

class Operand {

public:
    Operand (std::string operandField);
    void setIntValue(int transformMethod);
    int getintValue();
    // change value to newLabel in Statement Object
    bool isLabel();
    bool isRegister();
    bool isConstant();
    const std::string &getOperandField() const;
    void setOperandField(const std::string &operandField);

private:
    std::string operandField;
public:

};


#endif //SIC_ASSEMBLER_OPERAND_H
