//
// Created by kobia on 09.03.2023.
//

#ifndef MYLANGUAGE_BINARYEXPRESSION_H
#define MYLANGUAGE_BINARYEXPRESSION_H

#include "Expression.h"
#include <stdexcept>

using namespace std;

class BinaryExpression: public Expression{
private:
     Expression* exp1;
     Expression* exp2;
     char operation;
public:
    BinaryExpression(Expression* exp1, Expression* exp2, char operation);

    double eval() override;

};


#endif //MYLANGUAGE_BINARYEXPRESSION_H
