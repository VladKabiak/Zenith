//
// Created by kobia on 09.03.2023.
//

#include "NumberExpression.h"

NumberExpression::NumberExpression(const double val) : val(val) {}

double NumberExpression::eval() {
    return val;
}
