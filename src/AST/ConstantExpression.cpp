//
// Created by kobia on 26.03.2023.
//

#include "ConstantExpression.h"

ConstantExpression::ConstantExpression(const string &name) : name(name) {}

double ConstantExpression::eval() {
    if (!Constants::isConstant(name)) throw runtime_error("Unknown constant");
    return Constants::getConstant(name);
}


