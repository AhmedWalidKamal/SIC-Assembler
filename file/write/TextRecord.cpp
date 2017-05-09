//
// Created by Walid on 5/9/2017.
//

#include "TextRecord.h"


TextRecord::TextRecord(int startingAddress) : startingAddress(startingAddress), length(0) {}

int TextRecord::getLength() const {
    return length;
}

void TextRecord::setLength(int length) {
    TextRecord::length = length;
}

int TextRecord::getStartingAddress() const {
    return startingAddress;
}

void TextRecord::setStartingAddress(int startingAddress) {
    TextRecord::startingAddress = startingAddress;
}

const std::vector<std::string> &TextRecord::getRecords() const {
    return records;
}

void TextRecord::addRecord(std::string record) {
    TextRecord::records.push_back(record);
    TextRecord::length += (record.length() / 2);
}
