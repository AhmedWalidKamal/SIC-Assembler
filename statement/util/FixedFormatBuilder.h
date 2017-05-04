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
};


#endif //SIC_ASSEMBLER_FIXEDFORMATBUILDER_H
