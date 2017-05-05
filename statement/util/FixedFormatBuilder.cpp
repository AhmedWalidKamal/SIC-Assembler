//
// Created by Walid on 5/4/2017.
//

#include "FixedFormatBuilder.h"

FixedFormatBuilder::FixedFormatBuilder() {

}

void FixedFormatBuilder::buildStatement(std::string line) {
    // Here i guess we need a new statement each time, that's why it could be better as a pointer.
    // or should i make a new statement in the constructor?
    statement = new Statement();
    /// Replace indices here with static const variables.
    if (canSetLabel(line)) {
        statement->setLabel(new Label(line.substr(0, 9)));
    }
    if (canSetMnemonic(line)) {
        statement->setMnemonic(new Mnemonic(line.substr(9, 8)));
    }
    if (canSetOperand(line)) {
        statement->setOperand(new Operand(line.substr(17, 18)));
    }
    if (canSetComment(line)) {
        statement->setComment(new Comment(line.substr(35, 31)));
    }
}

bool FixedFormatBuilder::canSetLabel(std::string &line) {
    return line.length() > FixedFormatBuilder::MIN_LABEL_LENGTH;
}

bool FixedFormatBuilder::canSetMnemonic(std::string &line) {
    return line.length() > FixedFormatBuilder::MIN_MNEMONIC_LENGTH;
}
bool FixedFormatBuilder::canSetOperand(std::string &line) {
    return line.length() > FixedFormatBuilder::MIN_OPERAND_LENGTH;
}
bool FixedFormatBuilder::canSetComment(std::string &line) {
    return line.length() > FixedFormatBuilder::MIN_COMMENT_LENGTH;
}