//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_LABEL_H
#define SIC_ASSEMBLER_LABEL_H


#include <string>

class Label {
public:
   Label(std::string labelField);

    const std::string &getLabelField() const;
    void setLabelField(const std::string &labelField);
private:
    std::string labelField;
};


#endif //SIC_ASSEMBLER_LABEL_H
