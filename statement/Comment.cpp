//
// Created by Walid on 5/3/2017.
//

#include "Comment.h"

Comment::Comment(std::string commentField) {
    Comment::commentField = commentField;
}

const std::string &Comment::getComment() const {
    return commentField;
}

void Comment::setComment(const std::string &commentField) {
    Comment::commentField = commentField;
}
