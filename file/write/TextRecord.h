//
// Created by Walid on 5/9/2017.
//

#ifndef SIC_ASSEMBLER_TEXTRECORD_H
#define SIC_ASSEMBLER_TEXTRECORD_H


#include <vector>
#include <string>

class TextRecord {
public:
    TextRecord(int startingAddress);

    int getLength() const;

    void setLength(int length);

    int getStartingAddress() const;

    void setStartingAddress(int startingAddress);

    const std::vector<std::string> &getRecords() const;

    void addRecord(std::string record);

private:
    int length, startingAddress;
    std::vector<std::string> records;
};


#endif //SIC_ASSEMBLER_TEXTRECORD_H
