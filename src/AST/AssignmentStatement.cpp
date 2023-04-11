//
// Created by kobia on 11.04.2023.
//

#include <iostream>
#include "AssignmentStatement.h"

AssignmentStatement::AssignmentStatement(string variable, Expression* expression) : variable(std::move(variable)), expression(expression) {}

void AssignmentStatement::execute() {
    const double res = expression->eval();
    Variables::addVariable(variable, res);
}
