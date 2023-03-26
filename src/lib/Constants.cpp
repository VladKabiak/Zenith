//
// Created by kobia on 26.03.2023.
//

#include "Constants.h"
unordered_map<string, double> Constants::constants = {
        {"PI", 3.14159},
        {"E", 2.71828},
        {"G", 9.81},
};

bool Constants::isConstant(const string& name) {
    return constants.find(name) != constants.end();
}

double Constants::getConstant(const string& name) {
    if (!isConstant(name)) return 0;
    else return constants.at(name);
}
