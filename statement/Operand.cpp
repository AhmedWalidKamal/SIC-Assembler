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
    if (literal) {
       if  (validateHexConstant()) { return true; }
       if  (validateStringConstant())  { return true; }
        if (validateDecimalValue())  { return true;}
    }else {
       if (validateLabel()) { return true;}
    }
    if  (validateHexAddress()) { return true;}
    if   (validateDecimalAddress()) { return true;}
    if (validateCurrentLocationCounter()) { return true;}
    return (type != inValid);
}
bool Operand::isIndexed() {
    return indexed;
}

void Operand::validateLiteral() {
 if (operandField.front() == '=') {
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
        operandField = operandField.substr(0, found);
    }
}

bool Operand::validateLabel() {
    if (std::regex_match(operandField, Regex::isLabelOperand)){
        //std::transform(operandField.begin(), operandField.end(), operandField.begin(),
                      // [](unsigned char c) { return std::toupper(c); });
        std::size_t found = operandField.find_first_of(" ");
        operandField= operandField.substr(0,found);
        type = Label;
        return true;
    }
    return false;
}

bool Operand::isLabel() {
    return (type == Label);
}

bool Operand::validateHexAddress() {

    if (std::regex_match(operandField, Regex::hexaAddress)){
        type = hexaAddress;
        std::size_t found = operandField.find_first_of("'");
        operandField.erase (found,1);
        found = operandField.find_first_of("'");
        operandField.erase (found,1);
        setLCIncrement(std::stoi(operandField, nullptr, 16));
        hexValue = operandField;
        return true;
    }
    return false;
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

bool Operand::validateCurrentLocationCounter() {
    if (std::regex_match(operandField, Regex::star)){
        type = currentLocationCounter;
        // to be modified
        return true;
    }
    return false;
}

bool Operand::isCurrentLocationCounter() {
    return (type == currentLocationCounter);
}

bool Operand::validateDecimalValue() {

    if (std::regex_match(operandField, Regex::integerValue)){
        type = DecimalValue;
        setOperandValue(std::stoi(operandField));
        hexValue = operandField;
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
    return false;
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
    return rawInput;
}

const std::string &Operand::getHexValue() const {
    return Operand::hexValue;
}

bool Operand ::validateExpression(std::map<std::string, int> &symbolTable) {

    std::smatch m;

    while(std::regex_search (operandField,m,Regex::expression)) {
        std::vector<int> values;
        std::vector<std::string> operands;
        for (auto x:m) {
            int termValue;
            std::string beforeSign = m.prefix();
            size_t first = beforeSign.find_first_not_of(' ');
            size_t last = beforeSign.find_last_not_of(' ');
            beforeSign = beforeSign.substr(first, (last - first + 1));
            if (symbolTable.find(beforeSign) != symbolTable.end() &&
                symbolTable[beforeSign] != -1){
               values.push_back(symbolTable[beforeSign]);
            } else if (std::regex_match(beforeSign,Regex::integerAddress)){
                values.push_back(std::stoi(beforeSign));

            } else {
                type = inValid;
                return false;
            }
          operands.push_back((std::basic_string<char, std::char_traits<char>, std::allocator<char>> &&) x);
        }
        operandField = m.suffix().str();
        int termValue;
        std::string beforeSign = m.prefix();
        size_t first = beforeSign.find_first_not_of(' ');
        size_t last = beforeSign.find_last_not_of(' ');
        beforeSign = beforeSign.substr(first, (last - first + 1));
        if (symbolTable.find(beforeSign) != symbolTable.end() &&
            symbolTable[beforeSign] != -1){
            values.push_back(symbolTable[beforeSign]);
        } else if (std::regex_match(beforeSign,Regex::integerAddress)){
            values.push_back(std::stoi(beforeSign));

        } else {
            type = inValid;
            return false;
        }
       expressionValue = (*values.begin());
       std::vector<std::string>::iterator it2=operands.begin();
      for (std::vector<int>::iterator it=values.begin()+1 ; it < values.end(); it++,it++ ) {
            if (*(it2) =="+") {
                expressionValue += *(it);
            }
          else {
                expressionValue -= *(it);
            }
          it2++;
      }

        return true;
    }
}

int Operand ::getExpressionValue() {
    return expressionValue;
}




