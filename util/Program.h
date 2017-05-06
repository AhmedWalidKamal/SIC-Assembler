//
// Created by Walid on 5/6/2017.
//

#ifndef SIC_ASSEMBLER_PROGRAM_H
#define SIC_ASSEMBLER_PROGRAM_H


#include "../statement/Statement.h"

class Program {
public:
    Program();

    int getProgramLength() const;
    void setProgramLength(int programLength);
    const std::vector<Statement *> &getStatements() const;
    void setStatements(const std::vector<Statement *> &statements);

private:
    int programLength;
    std::vector<Statement *> statements;

};


#endif //SIC_ASSEMBLER_PROGRAM_H
