//
// Created by kobia on 05.03.2023.
//

#include "Lexer.h"

Lexer::Lexer(const string& input) : input(input) {
    this->length = (int)input.size();
    this->pos = 0;
}

void Lexer::tokenizeNumber() {
    string val;
    char curr = peek(0);
    while (true){
        if (curr == '.') {
            if (val.find('.' ) != string::npos ) throw invalid_argument("Invalid float");
        } else if (!isdigit(curr)) {
            break;
        }
        val.push_back(curr);
        curr = next();
    }
    addToken(NUMBER, val);
}

void Lexer::tokenizeOperator() {
    int position = distance(OPERATOR_CHARS.begin(), find(OPERATOR_CHARS.begin(), OPERATOR_CHARS.end(), peek(0)));
    addToken(OPERATOR_TOKENS[position]);
    next();
}

vector<Token> Lexer::tokenize() {
    while (pos < length) {
        const char current = peek(0);
        if (isdigit(current)) tokenizeNumber();
        else if (isalpha(current)) tokenizeWord();
        else if (current == '#') {
            next();
            tokenizeHexNumber();
        }
        else if (find(OPERATOR_CHARS.begin(), OPERATOR_CHARS.end(), peek(0)) != OPERATOR_CHARS.end()) {
            tokenizeOperator();
        } else {
            next();
        }
    }
    return tokens;
}

void Lexer::addToken(TokenType type) {
    addToken(type, "");
}

void Lexer::addToken(TokenType type, string text) {
    tokens.push_back(*new Token(type, text));
}

char Lexer::next() {
    pos++;
    return peek(0);
}

char Lexer::peek(int relativePosition) {
    const int position = pos + relativePosition;
    if (position >= length) return '\0';
    return input[position];
}



void Lexer::tokenizeHexNumber() {
    string val;
    char curr = peek(0);
    while (isHex(curr)){
        val.push_back(curr);
        curr = next();
    }
    addToken(HEX_NUMBER, val);
}

bool Lexer::isHex(char curr) {
    string hex_char = "abcdef";
    if (isdigit(curr) || hex_char.find(tolower(curr)) != string::npos) {
        return true;
    }
    return false;
}

void Lexer::tokenizeWord() {
    string val;
    char curr = peek(0);
    while (true){
        if (!isalnum(curr) && curr != '_' && curr != '$') { // isalnum returns true if (a-z or A-Z) or (0-9)
            break;
        }
        val.push_back(curr);
        curr = next();
    }
    if (val == "display") {
        addToken(DISPLAY);
    } else {
        addToken(WORD, val);
    }
}


