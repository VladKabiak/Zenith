//
// Created by kobia on 09.03.2023.
//

#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression* exp1, Expression* exp2, char operation)
        : exp1(exp1), exp2(exp2), operation(operation) {}

double BinaryExpression::eval() {
    switch (operation) {
        case '+': return exp1->eval() + exp2->eval();
        case '-': return exp1->eval() - exp2->eval();
        case '/': return exp1->eval() / exp2->eval();
        case '*': return exp1->eval() * exp2->eval();
        default: throw invalid_argument("Invalid operation");
    }
}
