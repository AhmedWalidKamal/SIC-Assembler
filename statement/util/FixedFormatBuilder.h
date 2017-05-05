//
// Created by Walid on 5/4/2017.
//

#ifndef SIC_ASSEMBLER_FIXEDFORMATBUILDER_H
#define SIC_ASSEMBLER_FIXEDFORMATBUILDER_H


#include "StatementBuilder.h"

class FixedFormatBuilder : public StatementBuilder {
public:
    FixedFormatBuilder();

    void buildStatement(std::string line);
private:
    static const int MIN_LABEL_LENGTH = 0;
    static const int MIN_MNEMONIC_LENGTH = 9;
    static const int MIN_OPERAND_LENGTH = 17;
    static const int MIN_COMMENT_LENGTH = 35;

    bool canSetLabel(std::string &line);

    bool canSetMnemonic(std::string &line);

    bool canSetOperand(std::string &line);

    bool canSetComment(std::string &line);
};


#endif //SIC_ASSEMBLER_FIXEDFORMATBUILDER_H
