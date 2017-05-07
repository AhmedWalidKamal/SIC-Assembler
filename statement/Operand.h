//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_OPERAND_H
#define SIC_ASSEMBLER_OPERAND_H
#include <string>
#include "../validate/Regex.h"

class Operand {
public:
    Operand(std::string operandField);
    int getintValue();
    bool isEmpty();
    bool isValid(); // Checks if any operand is valid.
    bool isLabel();
    bool isFixedAddress();
    bool isCurrentLocationCounter();
    bool isStringConstant();
    bool isHexConstant();
    bool isDecimalValue();
    bool isIndexed();
    const std::string &getOperandField() const;
    const std::string &getrawInput() const;
    void setOperandField(const std::string &operandField);
    int getLCIncrement() const;

    void setIntValue(int i);
    void setLCIncrement(int lcIncrement);
    void validateIndexed();
    void validateLabel();
    void validateHexAddress();
    bool validateDecimalAddress();
    void validateCurrentLocationCounter();
    bool validateStringConstant();
    bool validateHexConstant();
    bool validateDecimalValue();
private:
    std::string operandField;
    std:: string rawInput;
    enum OperandType {Label,hexaAddress,decimalAddress,
        currentLocationCounter,StringConstant,
        HexConstant,DecimalValue,inValid};
    OperandType type = inValid;
    int operandValue = 0;
    int LCIncrement = 0;
    bool indexed = false;
};


#endif //SIC_ASSEMBLER_OPERAND_H
