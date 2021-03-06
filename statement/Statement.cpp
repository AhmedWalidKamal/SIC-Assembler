//
// Created by Walid on 5/2/2017.
//

#include <iostream>
#include "Statement.h"
#include "../validate/LabelValidationState.h"

Statement::Statement() {
    Statement::label = new Label("");
    Statement::mnemonic = new Mnemonic("");
    Statement::operand = new Operand("");
    Statement::comment = new Comment("");
}

bool Statement::isComment() {
    return std::regex_match(Statement::statementField, Regex::commentOrEmptyLine);
}

Label *Statement::getLabel() const {
    return label;
}

void Statement::setLabel(Label *label) {
    Statement::label = label;
}

Mnemonic *Statement::getMnemonic() const {
    return mnemonic;
}

void Statement::setMnemonic(Mnemonic *mnemonic) {
    Statement::mnemonic = mnemonic;
}

Operand *Statement::getOperand() const {
    return operand;
}

void Statement::setOperand(Operand *operand) {
    Statement::operand = operand;
}

Comment *Statement::getComment() const {
    return comment;
}

void Statement::setComment(Comment *comment) {
    Statement::comment = comment;
}

int Statement::getStatementLocationPointer() const {
    return statementLocationPointer;
}

void Statement::setStatementLocationPointer(int statementLocationPointer) {
    Statement::statementLocationPointer = statementLocationPointer;
}

void Statement::validate(std::map<std::string, Instruction *> &instructionTable,
                         std::map<std::string, Directive *> &directiveTable,
                         std::map<std::string, int> &symbolTable, const int &start, const int &end,
                         const int &locationCounter) {
    LabelValidationState *state = new LabelValidationState();
    state->validate(instructionTable, directiveTable, symbolTable, start, end, locationCounter, this);
}

void Statement::execute(int &start, int &end, int &locationCounter,
                        std::map<std::string, Directive *> &directiveTable,
                        std::map<std::string, Instruction *> &instructionTable,
                        std::map<std::string, int> &symbolTable,
                        std::map<std::string, std::pair<Operand *, int>> &literalTable) {
    if (directiveTable.find(getMnemonic()->getMnemonicField()) != directiveTable.end()) {
       statementLocationPointer = directiveTable[getMnemonic()->getMnemonicField()]
                ->execute(start, end, locationCounter, getOperand(),symbolTable, literalTable);
    } else {
        statementLocationPointer = locationCounter;
        locationCounter += instructionTable[getMnemonic()->getMnemonicField()]->getFormat();
    }
}

const std::string &Statement::getStatementField() const {
    return statementField;
}

void Statement::setStatementField(const std::string &statementField) {
    Statement::statementField = statementField;
}

