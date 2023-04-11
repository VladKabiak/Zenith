//
// Created by kobia on 26.03.2023.
//

#ifndef MYLANGUAGE_VARIABLEEXPRESSION_H
#define MYLANGUAGE_VARIABLEEXPRESSION_H


#include "../lib/Variables.h"
#include "Expression.h"
#include <string>
#include <stdexcept>

using namespace std;

class VariableExpression: public Expression{
private:
    const string name;
public:
    explicit VariableExpression(const string &name);

    double eval() override;
};


#endif //MYLANGUAGE_VARIABLEEXPRESSION_H
