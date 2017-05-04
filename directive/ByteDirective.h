//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_BYTEDIRECTIVE_H
#define SIC_ASSEMBLER_BYTEDIRECTIVE_H

#include "Directive.h"

class ByteDirective : public Directive {
    public :
    int execute(int &start, int &end, int &locationCounter, int incrementValue);
};


#endif //SIC_ASSEMBLER_BYTEDIRECTIVE_H
