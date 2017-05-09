//
// Created by Walid on 5/3/2017.
//

#include "Label.h"

Label::Label(std::string labelField) {
    Label::labelField = labelField;
}

const std::string &Label::getLabelField() const {
    return labelField;
}

void Label::setLabelField(const std::string &labelField) {
    Label::labelField = labelField;
}

bool Label::isEmpty() {
    return regex_match(labelField,regex.isEmpty);
}

bool Label::isValid() {
    bool isEmpty = regex_match(labelField,regex.isEmpty);
    bool isLabel = regex_match(labelField,regex.isLabel);
    if (isLabel) {
        //std::transform(labelField.begin(), labelField.end(), labelField.begin(),
        //[](unsigned char c) { return std::toupper(c); });
        std::size_t found = labelField.find_first_of(" ");
        labelField = labelField.substr(0,found);

    }
    return isEmpty|| isLabel;
}


