//
// Created by kobia on 05.03.2023.
//

#ifndef MYLANGUAGE_PARSER_H
#define MYLANGUAGE_PARSER_H


#include "../Token/Token.h"
#include "../AST/Expression.h"

class Parser {
private:
    Token EOL = *new Token(EOL);
    vector<Token> tokens;
    int pos;
    int size;
    Token get (int relativePosition);
    bool match(TokenType type);

public:
    Parser(const vector<Token> &tokens);

    vector<Expression> parse();

};


#endif //MYLANGUAGE_PARSER_H
