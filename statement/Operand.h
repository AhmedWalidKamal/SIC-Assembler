//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_OPERAND_H
#define SIC_ASSEMBLER_OPERAND_H
#include <string>

class Operand {

public:
    Operand (std::string operand);
    std::string getValue();
    void setIntValue(int transformMethod);
    int getintValue();
    // change value to newLabel in Statment Object
    bool isLabel();
    bool isRegister();
    bool isConstant();


private:
    std::string operand;
};


#endif //SIC_ASSEMBLER_OPERAND_H
