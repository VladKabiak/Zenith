//
// Created by kobia on 26.03.2023.
//

#ifndef MYLANGUAGE_CONSTANTEXPRESSION_H
#define MYLANGUAGE_CONSTANTEXPRESSION_H


#include "../lib/Constants.h"
#include "Expression.h"
#include <string>
#include <stdexcept>

using namespace std;

class ConstantExpression: public Expression{
private:
    const string name;
public:
    explicit ConstantExpression(const string &name);

    double eval() override;
};


#endif //MYLANGUAGE_CONSTANTEXPRESSION_H
