//
// Created by Walid on 5/3/2017.
//

#include "Operand.h"
Operand::Operand() {
    Operand::operandField = "";
}
Operand::Operand(std::string operandField) {
    Operand::operandField = operandField;
}
const std::string &Operand::getOperandField() const {
    return operandField;
}

void Operand::setOperandField(const std::string &operandField) {
    Operand::operandField = operandField;
}
