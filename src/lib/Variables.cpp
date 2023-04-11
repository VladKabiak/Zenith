//
// Created by kobia on 26.03.2023.
//

#include <iostream>
#include "Variables.h"
unordered_map<string, double> Variables::variables = {
        {"PI", 3.14159},
        {"E", 2.71828},
        {"G", 9.81},
};

bool Variables::isVariable(const string& name) {
    return variables.find(name) != variables.end();
}

double Variables::getVariable(const string& name) {
    if (!isVariable(name)) return 0;
    else return variables.at(name);
}

void Variables::addVariable(const string &key, const double &val) {
    variables.insert({key, val});
}


