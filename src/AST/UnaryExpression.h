//
// Created by kobia on 12.03.2023.
//

#ifndef MYLANGUAGE_UNARYEXPRESSION_H
#define MYLANGUAGE_UNARYEXPRESSION_H


#include "Expression.h"
#include <stdexcept>

using namespace std;

class UnaryExpression: public Expression{
private:
    Expression* expr;
    char operation;

public:
    UnaryExpression(Expression *expr, char operation);
    double eval() override;
};


#endif //MYLANGUAGE_UNARYEXPRESSION_H
