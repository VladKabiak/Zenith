//
// Created by kobia on 12.03.2023.
//

#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(Expression *expr, char operation) : expr(expr), operation(operation) {}

double UnaryExpression::eval() {
    switch (operation) {
        case '+': return expr->eval();
        case '-': return -expr->eval();
        default: throw invalid_argument("Invalid unary operation");
    }
}
