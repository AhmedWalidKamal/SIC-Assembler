//
// Created by Walid on 5/2/2017.
//

#ifndef SIC_ASSEMBLER_STATEMENT_H
#define SIC_ASSEMBLER_STATEMENT_H


#include <map>
#include "Label.h"
#include "Mnemonic.h"
#include "Operand.h"
#include "Comment.h"
#include "Instruction.h"
#include "../directive/Directive.h"

class Directive;
class Statement {
public:
    Statement();

    bool isComment();
    void validate(std::map<std::string, Instruction *> &instructionTable,
                 std::map<std::string, Directive *> &directiveTable,
                 std::map<std::string, int> &symbolTable, const int &start, const int &end,
                 const int &locationCounter);

    void execute(int& start, int& end, int& locationCounter,
                 std::map<std::string, Directive *> &directiveTable,
                 std::map<std::string, Instruction *> &instructionTable,
                 std::map<std::string, std::pair<Operand *, int> > &literalTable);

    //bool operandIsNewLabel();
    //bool operandHasLabel();

    Label *getLabel() const;

    void setLabel(Label *label);

    Mnemonic *getMnemonic() const;

    void setMnemonic(Mnemonic *mnemonic);

    Operand *getOperand() const;

    void setOperand(Operand *operand);

    Comment *getComment() const;

    void setComment(Comment *comment);

    int getStatementLocationPointer() const;

    void setStatementLocationPointer(int statementLocationPointer);

    const std::string &getStatementField() const;

    void setStatementField(const std::string &statementField);

private:
    Label *label;
    Mnemonic *mnemonic;
    Operand *operand;
    Comment *comment;
    std::string statementField;
    int statementLocationPointer;
};

#endif //SIC_ASSEMBLER_STATEMENT_H
