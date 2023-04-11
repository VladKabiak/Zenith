//
// Created by kobia on 05.03.2023.
//

#include "Parser.h"


Parser::Parser(const vector<Token> &tokens) : tokens(tokens){
    this->pos = 0;
    this->size = (int)tokens.size();
}

vector<Statement*> Parser::parse() {
    vector<Statement*> res;
    while (!match(TokenType::EOL)) {
        res.push_back(statement());
    }
    return res;
}

Statement* Parser::statement() {
    return assignmentStatement();
}

Statement* Parser::assignmentStatement () {
    Token curr = get(0);
    if (match(WORD) && get(0).getType() == EQUAL) {
        const string var = curr.getText();
        match(EQUAL);
        return new AssignmentStatement(var, expression());
    }
    throw runtime_error("Unexpected operator");
}

Expression* Parser::expression() {
    return addition();
}

Expression* Parser::addition() {
    Expression* res = multiply();

    while (true) {
        if (match(PLUS)) {
            res = new BinaryExpression(res, multiply(), '+');
            continue;
        }
        if (match(MINUS)) {
            res = new BinaryExpression(res, multiply(), '-');
            continue;
        }
        break;
    }

    return res;
}

Expression* Parser::multiply() {
    Expression* res = unary();

    while (true) {
        if (match(STAR)) {
            res = new BinaryExpression(res, unary(), '*');
            continue;
        }
        if (match(SLASH)) {
            res = new BinaryExpression(res, unary(), '/');
            continue;
        }
        break;
    }
    return res;
}

Expression* Parser::unary() {
    if (match(MINUS)) {
        return new UnaryExpression(primary(), '-');
    } else if (match(PLUS)) {
        return new UnaryExpression(primary(), '+');
    }
    return primary();
}

Expression* Parser::primary() {
    Token curr = get(0);
    if (match(NUMBER)) {
        double val = stod(curr.getText());
        return new NumberExpression(val);
    }
    if (match(HEX_NUMBER)) {
        unsigned long val = stoul(curr.getText(), nullptr, 16);
        return new NumberExpression(val);
    }
    if (match(WORD)) {
        return new VariableExpression(curr.getText());
    }
    if (match(LPAREN)) {
        Expression* res = expression();
        if (match(RPAREN)){
            return res;
        }
    }
    throw runtime_error("Unexpected token found");
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
