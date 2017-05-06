//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_LABEL_H
#define SIC_ASSEMBLER_LABEL_H


#include<string>
#include "../validate/Regex.h"
class Label {
public:
    Label(std::string labelField);

    const std::string &getLabelField() const;

    // to be called in passOne before addinglabel to SymbolTable
    bool isEmpty();

    /// trim the spaces
    bool isValid();

    void setLabelField(const std::string &labelField);
private:
    std::string labelField;
    Regex  regex;
};


#endif //SIC_ASSEMBLER_LABEL_H
