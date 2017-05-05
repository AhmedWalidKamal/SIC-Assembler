//
// Created by Walid on 5/2/2017.
//

#include "Statement.h"
#include "../validate/State.h"
#include "../validate/LabelValidationState.h"

Statement::Statement() {
    Statement::label = nullptr;
    Statement::mnemonic = nullptr;
    Statement::operand = nullptr;
    Statement::comment = nullptr;
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

int Statement::validate(const std::map<std::string, Instruction *> &instructionTable,
                        const std::map<std::string, Directive *> &directiveTable,
                        const std::map<std::string, int> &symbolTable, const int &start, const int &end,
                        const int &locationCounter) {
    State *state = new LabelValidationState();
    return 0;
}
