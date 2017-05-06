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

Statement::Statement(Label *label, Mnemonic *mnemonic, Operand *operand, Comment *comment) {
    Statement::label = label;
    Statement::mnemonic = mnemonic;
    Statement::operand = operand;
    Statement::comment = comment;
}

bool Statement::isComment() {
    return label->startsWithComment();
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

void Statement::execute(int &start, int &end, int &locationCounter) {

 //   if (statement.mnemonicIsDirective()) {
//                 setStatementLocationPointer(dirTable[statement.getMnemonic()].execute());
//                } else {
//                    if (!statement.isFormatFour()) {
//                  setStatementLocationPointer(instrTable.getFormat.updateLC());
//                    } else {
//
//                    }
//                }s

}

void Statement::validate(std::map<std::string, Instruction *> &instructionTable,
                         std::map<std::string, Directive *> &directiveTable,
                         std::map<std::string, int> &symbolTable, const int &start, const int &end,
                         const int &locationCounter) {
    LabelValidationState *state = new LabelValidationState();
    state->validate(instructionTable, directiveTable, symbolTable, start, end, locationCounter, this);
}

//int Statement::validate(const std::map<std::string, Instruction *> &instructionTable,
//                        const std::map<std::string, Directive *> &directiveTable,
//                        const std::map<std::string, int> &symbolTable, const int &start, const int &end,
//                        const int &locationCounter) {
//    State *state = new LabelValidationState();
//    return 0;
//}

