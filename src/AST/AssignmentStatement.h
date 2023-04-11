//
// Created by kobia on 11.04.2023.
//

#ifndef MYLANGUAGE_ASSIGNMENTSTATEMENT_H
#define MYLANGUAGE_ASSIGNMENTSTATEMENT_H


#include "Statement.h"
#include "Expression.h"
#include "../lib/Variables.h"
#include <string>

using namespace std;

class AssignmentStatement: public Statement{
private:
    const string variable;
    Expression *expression;

public:
    AssignmentStatement(string variable, Expression* expression);

    void execute() override;
};


#endif //MYLANGUAGE_ASSIGNMENTSTATEMENT_H
