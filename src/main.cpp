#include <iostream>
#include <vector>
#include "Token/Token.h"
#include "Lexer/Lexer.h"

using namespace std;


int main() {
    string input = "23 + -          /               121";
    vector<Token> tokens = (new Lexer(input))->tokenize();
    for (auto el : tokens)
        cout << el.getType() << " " << el.getText() << endl;
}
