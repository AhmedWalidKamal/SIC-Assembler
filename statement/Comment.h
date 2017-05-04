//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_COMMENT_H
#define SIC_ASSEMBLER_COMMENT_H


#include <string>

class Comment {
public:
    Comment(std::string commentField);

    const std::string &getComment() const;
    void setComment(const std::string &commentField);

private:
    std::string commentField;
};


#endif //SIC_ASSEMBLER_COMMENT_H
