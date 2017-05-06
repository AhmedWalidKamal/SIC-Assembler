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

//bool Operand::isValid() {
//    return isLabel() || isHexAddress() || isDecimalAddress() || isCurrentLocationCounter();
//}
//
//bool Operand::isLabel() {
//    return std::regex_match(); // insert label regex.
//}
//// Each one of the below, check with the regex + set the type and the int value.
//bool Operand::isHexAddress() {
//    return false;
//}
//
//bool Operand::isDecimalAddress() {
//    return false;
//}
//
//bool Operand::isCurrentLocationCounter() {
//    return false;
//}
//
//bool Operand::isStringConstant() {
//    return false;
//}
//
//bool Operand::isHexConstant() {
//    return false;
//}
//
//bool Operand::isDecimalValue() {
//    if (regex is true) {
//        setIntValue(3);
//        return  true;
//    }
//    return false;
//}
//
//int Operand::getLocationCounterIncrement() const {
//    return locationCounterIncrement;
//}
//
//void Operand::setLocationCounterIncrement(int locationCounterIncrement) {
//    Operand::locationCounterIncrement = locationCounterIncrement;
//}
