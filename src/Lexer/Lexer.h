//
// Created by kobia on 05.03.2023.
//

#ifndef MYLANGUAGE_LEXER_H
#define MYLANGUAGE_LEXER_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include "../Token/Token.h"

using namespace std;

class Lexer {
    private:
        const string OPERATOR_CHARS = "+-*/()=";
        const vector<TokenType> OPERATOR_TOKENS = {
                PLUS, MINUS, STAR, SLASH, LPAREN, RPAREN, EQUAL
        };

        string input;
        vector<Token> tokens;
        int pos, length;

        void addToken(TokenType type);
        void addToken(TokenType type, string text);
        char next();
        char peek(int relativePosition);


    public:
        explicit Lexer(const string& input);
        vector<Token> tokenize();
        void tokenizeNumber();
        void tokenizeHexNumber();
        void tokenizeOperator();
        void tokenizeWord();
        static bool isHex(char curr);
};


#endif //MYLANGUAGE_LEXER_H
