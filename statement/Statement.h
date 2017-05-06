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

class Statement {
public:
    Statement();
    Statement(Label *label, Mnemonic *mnemonic, Operand *operand, Comment *comment);

    bool isComment();

//    int validate(const std::map<std::string, Instruction *> &instructionTable,
//                 const std::map<std::string, Directive *> &directiveTable,
//                 const std::map<std::string, int> &symbolTable, const int &start, const int &end,
//                 const int &locationCounter);
    void validate(const std::map<std::string, Instruction *> &instructionTable,
//                 const std::map<std::string, Directive *> &directiveTable,
                 const std::map<std::string, int> &symbolTable, const int &start, const int &end,
                 const int &locationCounter);
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

    void execute(int& start, int& end, int& locationCounter);
private:
    Label *label;
    Mnemonic *mnemonic;
    Operand *operand;
    Comment *comment;
    int statementLocationPointer;
};

#endif //SIC_ASSEMBLER_STATEMENT_H
