//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_WORDDIRECTIVE_H
#define SIC_ASSEMBLER_WORDDIRECTIVE_H

#include "Directive.h"

class WordDirective : public Directive {

    public :
    int execute(int &start, int &end, int &locationCounter, int incrementValue);

};


#endif //SIC_ASSEMBLER_WORDDIRECTIVE_H
