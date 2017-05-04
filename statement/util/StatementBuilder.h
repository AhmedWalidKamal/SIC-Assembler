//
// Created by Walid on 5/4/2017.
//

#ifndef SIC_ASSEMBLER_STATEMENTBUILDER_H
#define SIC_ASSEMBLER_STATEMENTBUILDER_H


#include "../Statement.h"

class StatementBuilder {
public:
    virtual void buildStatement(std::string line) = 0;
    Statement *getStatement();

protected:
    Statement *statement;
};


#endif //SIC_ASSEMBLER_STATEMENTBUILDER_H
