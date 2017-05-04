//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_RESERVEBYTEDIRECTIVE_H
#define SIC_ASSEMBLER_RESERVEBYTEDIRECTIVE_H

#include "Directive.h"

class ReserveByteDirective : public Directive {

    public :
    int execute(int& start, int& end, int& locationCounter,int incrementValue);
};


#endif //SIC_ASSEMBLER_RESERVEBYTEDIRECTIVE_H
