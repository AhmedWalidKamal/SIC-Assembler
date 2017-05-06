//
// Created by Walid on 5/6/2017.
//

#include "Program.h"

Program::Program() {

}

const std::vector<Statement *> &Program::getStatements() const {
    return statements;
}

int Program::getProgramLength() const {
    return programLength;
}

void Program::setProgramLength(int programLength) {
    Program::programLength = programLength;
}

void Program::addStatement(Statement *statement) {
    Program::statements.push_back(statement);
}
