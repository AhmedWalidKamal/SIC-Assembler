//
// Created by Walid on 5/3/2017.
//

#include <regex>
#include "Operand.h"
Operand::Operand(std::string operandField) {
    Operand::operandField = operandField;
}
const std::string &Operand::getOperandField() const {
    return operandField;
}

void Operand::setOperandField(const std::string &operandField) {
    Operand::operandField = operandField;
}


int Operand::getLCIncrement() const {
    return LCIncrement;
}

void Operand::setLCIncrement(int lcIncrement) {
    LCIncrement = lcIncrement;
}

void Operand::setIntValue(int i) {
    operandValue = i;
}

int Operand::getintValue() {
    return operandValue;
}

bool Operand::isEmpty() {
    return regex_match(operandField,regex.isEmpty);
}

bool Operand::isValid() {
    validateIndexed();
    validateLabel();
    validateHexAddress();
    validateDecimalAddress();
    validateCurrentLocationCounter();
    return (type != inValid);
}
bool Operand::isIndexed() {
    return indexed;
}

void Operand::validateIndexed() {
    indexed =  regex_match(operandField,regex.Indexed);
    if (indexed){
        std::size_t found = operandField.find_first_of(",");
        operandField= operandField.substr(0,found-1);
    }
}
void Operand::validateLabel() {

    if (regex_match(operandField,regex.isLabelOperand)){
        std::size_t found = operandField.find_first_of(" ");
        operandField= operandField.substr(0,found);
        type = Label;
    }
}

bool Operand::isLabel() {
    return (type == Label);
}

void Operand::validateHexAddress() {

    if (regex_match(operandField,regex.hexaAddress)){
        type = hexaAddress;
        std::size_t found = operandField.find_first_of("'");
        operandField.erase (found,1);
        found = operandField.find_first_of("'");
        operandField.erase (found,1);
        setLCIncrement(std::stoi(operandField, nullptr, 16));
    }
}

bool Operand::validateDecimalAddress() {
    if (regex_match(operandField,regex.integerAddress)){
        type = decimalAddress;
        setLCIncrement(std::stoi(operandField));
        return  true;
    }
    return false;
}
bool Operand::isFixedAddress() {
    return (type == (hexaAddress || decimalAddress));
}

void Operand::validateCurrentLocationCounter() {
    if (regex_match(operandField,regex.star)){
        type = currentLocationCounter;

    }
}

bool Operand::isCurrentLocationCounter() {
    return (type == currentLocationCounter);
}

bool Operand::validateDecimalValue() {

    if (regex_match(operandField,regex.integerValue)){
        type = DecimalValue;
        setIntValue(std::stoi(operandField));
        setLCIncrement(3);
        return true;
    }
    return false;
}

bool Operand::isDecimalValue() {
    return (type == DecimalValue);
}

bool Operand::validateStringConstant() {
    if (regex_match(operandField, regex.literalString)) {
        type = StringConstant;
        std::size_t start = operandField.find_first_of("'");
        std::size_t end = operandField.find_last_of("'");
        operandField = operandField.substr(start + 1, (end - start - 1));
        setLCIncrement(operandField.length());
        return true;
    }
}

bool Operand::isStringConstant() {

    return (type==StringConstant);
}

bool Operand::validateHexConstant() {
    if (regex_match(operandField,regex.literalHexa)) {
        type = HexConstant;
        std::size_t start = operandField.find_first_of("'");
        std::size_t end = operandField.find_last_of("'");
        operandField= operandField.substr(start+1,(end-start-1));
        int hexDigits = operandField.length();
        if (hexDigits%2==0){
            setLCIncrement(hexDigits/2);
            setIntValue(std::stoi(operandField, nullptr, 16));
            return true;
        } else {
            type = inValid;
            return false;
        }

    }
}

bool Operand::isHexConstant() {
    return (type == HexConstant);
}







