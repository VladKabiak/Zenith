//
// Created by kobia on 26.03.2023.
//

#ifndef MYLANGUAGE_CONSTANTS_H
#define MYLANGUAGE_CONSTANTS_H


#include <string>
#include <unordered_map>

using namespace std;

class Constants {
private:
    static unordered_map<string, double> constants;
public:

    static bool isConstant(const string& name);

    static double getConstant(const string& name);

};


#endif //MYLANGUAGE_CONSTANTS_H
