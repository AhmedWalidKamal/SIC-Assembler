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

/// Check this.
bool Label::startsWithComment() {
    return Label::labelField.front() == '.';
}

bool Label::isEmpty() {
    // use regex
    return false;
}

bool Label::isValid() {
    // use regex for validity || return isEmpty()
    return false;
}


