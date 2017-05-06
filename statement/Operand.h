//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_OPERAND_H
#define SIC_ASSEMBLER_OPERAND_H
#include <string>

class Operand {

public:

    Operand(std::string operandField);
    void setIntValue(int transformMethod);
    int getintValue();
    // change value to newLabel in Statement Object

    bool isRegister();
    bool isValid(); // Checks if any operand is valid.
    bool isLabel();
    bool isHexAddress();
    bool isDecimalAddress();
    bool isCurrentLocationCounter();
    bool isStringConstant();
    bool isHexConstant();
    bool isDecimalValue();

    const std::string &getOperandField() const;
    void setOperandField(const std::string &operandField);

private:
    std::string operandField;
//    enum type;
    int locationCounterIncrement;
public:
    int getLocationCounterIncrement() const;

    void setLocationCounterIncrement(int locationCounterIncrement);

public:

};


#endif //SIC_ASSEMBLER_OPERAND_H
