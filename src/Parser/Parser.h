//
// Created by kobia on 05.03.2023.
//

#ifndef MYLANGUAGE_PARSER_H
#define MYLANGUAGE_PARSER_H


#include "../Token/Token.h"
#include "../AST/Expression.h"
#include "../AST/NumberExpression.h"
#include "../AST/BinaryExpression.h"

using namespace std;

class Parser {
private:
    Token EOL = Token(TokenType::EOL, "");
    vector<Token> tokens;
    int pos;
    int size;
    Expression* expression();
    Expression* addition();
    Expression* multiply();
    Expression* unary();
    Expression* primary();
    Token get (int relativePosition);
    bool match(TokenType type);

public:
    explicit Parser(const vector<Token> &tokens);

    vector<Expression*> parse();

};


#endif //MYLANGUAGE_PARSER_H
