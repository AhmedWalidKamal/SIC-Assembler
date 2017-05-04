//
// Created by Walid on 5/3/2017.
//

#include "Label.h"

Label::Label(std::string label) {
    Label::label = label;
}

const std::string &Label::getLabel() const {
    return label;
}

void Label::setLabel(const std::string &label) {
    Label::label = label;
}
