//
// Created by kobia on 09.03.2023.
//

#ifndef MYLANGUAGE_NUMBEREXPRESSION_H
#define MYLANGUAGE_NUMBEREXPRESSION_H

#include "Expression.h"

class NumberExpression: public Expression{
private:
    double val;
public:
    explicit NumberExpression(double val);
    double eval() override;
};


#endif //MYLANGUAGE_NUMBEREXPRESSION_H
