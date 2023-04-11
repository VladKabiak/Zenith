//
// Created by kobia on 26.03.2023.
//

#ifndef MYLANGUAGE_VARIABLES_H
#define MYLANGUAGE_VARIABLES_H

#include <string>
#include <unordered_map>

using namespace std;

class Variables {
private:
public:
    static unordered_map<string, double> variables;

    static bool isVariable(const string& name);

    static double getVariable(const string& name);

    static void addVariable(const string& key, const double& val);
};


#endif //MYLANGUAGE_VARIABLES_H
