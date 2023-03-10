//
// Created by kobia on 05.03.2023.
//

#include "Parser.h"

Parser::Parser(const vector<Token> &tokens) : tokens(tokens){
    this->pos = 0;
    this->size = (int)tokens.size();
}

vector<Expression> Parser::parse() {
    return vector<Expression>();
}

Token Parser::get(int relativePosition) {
    const int position = pos + relativePosition;
    if (position >= size) return EOL;
    return tokens[position]; // maybe doesn't work
}

bool Parser::match(TokenType type) {
    Token curr = get(0);
    if (type != curr.getType()) return false;
    pos++;
    return true;
}