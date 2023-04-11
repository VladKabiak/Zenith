//
// Created by kobia on 26.03.2023.
//

#include "VariableExpression.h"

VariableExpression::VariableExpression(const string &name) : name(name) {}

double VariableExpression::eval() {
    if (!Variables::isVariable(name)) throw runtime_error("Unknown constant");
    return Variables::getVariable(name);
}


