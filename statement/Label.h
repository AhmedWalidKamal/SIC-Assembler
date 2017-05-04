//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_LABEL_H
#define SIC_ASSEMBLER_LABEL_H


#include <string>

class Label {
public:
    Label(std::string label);

    const std::string &getLabel() const;
private:
    std::string label;
};


#endif //SIC_ASSEMBLER_LABEL_H
