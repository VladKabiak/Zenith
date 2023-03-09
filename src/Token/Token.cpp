//
// Created by kobia on 05.03.2023.
//

#include "Token.h"


Token::Token() = default;

Token::Token(TokenType type, string text) : type(type), text(text) {}

TokenType Token::getType() const {
    return type;
}

void Token::setType(TokenType type) {
    Token::type = type;
}

string Token::getText() {
    return text;
}

void Token::setText(const string &text) {
    Token::text = text;
}
