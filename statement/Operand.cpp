//
// Created by Walid on 5/3/2017.
//

#include "Operand.h"
#include "../datatypes/Hexadecimal.h"
#include <string>
#include <iostream>
#include <regex>

Operand::Operand(std::string operandField) {
    Operand::operandField = operandField;
    Operand :: rawInput = operandField;
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

void Operand::setOperandValue(int i) {
    operandValue = i;
}

int Operand::getOperandValue() {
    return operandValue;
}

bool Operand::isEmpty() {
    return std::regex_match(operandField, Regex::isEmpty);
}

bool Operand::isValid() {
    validateIndexed();
    validateLiteral();
    validateLabel();
    validateHexAddress();
    validateDecimalAddress();
    validateCurrentLocationCounter();
    return (type != inValid);
}
bool Operand::isIndexed() {
    return indexed;
}

void Operand::validateLiteral() {
 if (operandField.front()=='=') {
     literal = true;
     operandField = operandField.substr(1,std::string::npos);
 }
}


bool Operand::isLiteral() {
  return literal;
}

void Operand::validateIndexed() {
    indexed = regex_match(operandField, Regex::Indexed);
    if (indexed){
        std::size_t found = operandField.find_first_of(",");
        operandField= operandField.substr(0,found);
    }
}

void Operand::validateLabel() {
    if (std::regex_match(operandField, Regex::isLabelOperand)){
        //std::transform(operandField.begin(), operandField.end(), operandField.begin(),
                      // [](unsigned char c) { return std::toupper(c); });
        std::size_t found = operandField.find_first_of(" ");
        operandField= operandField.substr(0,found);
        type = Label;
    }
}

bool Operand::isLabel() {
    return (type == Label);
}

void Operand::validateHexAddress() {

    if (std::regex_match(operandField, Regex::hexaAddress)){
        type = hexaAddress;
        std::size_t found = operandField.find_first_of("'");
        operandField.erase (found,1);
        found = operandField.find_first_of("'");
        operandField.erase (found,1);
        setLCIncrement(std::stoi(operandField, nullptr, 16));
        hexValue = operandField;
    }
}

bool Operand::validateDecimalAddress() {
    if (std::regex_match(operandField, Regex::integerAddress)){
        type = decimalAddress;
        setLCIncrement(std::stoi(operandField));
        hexValue = (Hexadecimal::intToHex(std::stoi(operandField)));
        return  true;
    }
    return false;
}
bool Operand::isFixedAddress() {
    return (type == (hexaAddress || decimalAddress));
}

void Operand::validateCurrentLocationCounter() {
    if (std::regex_match(operandField, Regex::star)){
        type = currentLocationCounter;
        // to be modified
    }
}

bool Operand::isCurrentLocationCounter() {
    return (type == currentLocationCounter);
}

bool Operand::validateDecimalValue() {

    if (std::regex_match(operandField, Regex::integerValue)){
        type = DecimalValue;
        setOperandValue(std::stoi(operandField));
        setLCIncrement(3);
        return true;
    }
    return false;
}

bool Operand::isDecimalValue() {
    return (type == DecimalValue);
}

bool Operand::validateStringConstant() {
    if (std::regex_match(operandField, Regex::literalString)) {
        type = StringConstant;
        std::size_t start = operandField.find_first_of("'");
        std::size_t end = operandField.find_last_of("'");
        operandField = operandField.substr(start + 1, (end - start - 1));
        setLCIncrement(operandField.length());
        hexValue = Hexadecimal :: stringToHex(operandField);
        return true;
    }
}

bool Operand::isStringConstant() {
    return type == StringConstant;
}

bool Operand::validateHexConstant() {
    if (std::regex_match(operandField, Regex::literalHexa)) {
        type = HexConstant;
        std::size_t start = operandField.find_first_of("'");
        std::size_t end = operandField.find_last_of("'");
        operandField= operandField.substr(start+1,(end-start-1));
        int hexDigits = operandField.length();
        if (hexDigits%2==0){
            setLCIncrement(hexDigits/2);
            setOperandValue(std::stoi(operandField, nullptr, 16));
            return true;
            hexValue = (operandField);
        } else {
            type = inValid;
            return false;
        }
    }
}

bool Operand::isHexConstant() {
    return (type == HexConstant);
}

const std::string &Operand::getrawInput() const {
    return  rawInput;
}

