//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_ENDDIRECTIVE_H
#define SIC_ASSEMBLER_ENDDIRECTIVE_H


#include "Directive.h"

class EndDirective : public Directive {

    public :
    int execute(int& start, int& end, int& locationCounter,int incrementValue);
};


#endif //SIC_ASSEMBLER_ENDDIRECTIVE_H
