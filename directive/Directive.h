//
// Created by walid on 5/2/2017.
//

#ifndef SIC_ASSEMBLER_DIRECTIVE_H
#define SIC_ASSEMBLER_DIRECTIVE_H


class Directive {
public:
    virtual int execute(int& start, int& end, int& locationCounter,int incrementValue) = 0;

private:


};


#endif //SIC_ASSEMBLER_DIRECTIVE_H
