//
// Created by kobia on 05.03.2023.
//

#ifndef MYLANGUAGE_TOKEN_H
#define MYLANGUAGE_TOKEN_H
#include <iostream>
#include <vector>
#include "TokenType.h"

using namespace std;

class Token {
    private:
        TokenType type;
        string text;

    public:
        Token();
        Token(TokenType type, string text);

    TokenType getType() const;

    void setType(TokenType type);

    string getText();

    void setText(const string &text);
};


#endif //MYLANGUAGE_TOKEN_H
