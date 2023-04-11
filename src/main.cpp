#include <iostream>
#include <vector>
#include "Token/Token.h"
#include "Lexer/Lexer.h"
#include "Parser/Parser.h"

using namespace std;


int main() {
    string input = "var = 2 + 7; word2 = 1+var";
    vector<Token> tokens = (new Lexer(input))->tokenize();
    for (auto el : tokens) {
        cout << el.getType() << " " << el.getText() << endl;
    }
    vector<Statement*> statements = (new Parser(tokens))->parse();
    for (auto el: statements) {
        el->execute();
    }
    cout << "var " << Variables::getVariable("var") << endl;
    cout << "word2 " << Variables::getVariable("word2") << endl;
    cout << "word132 " << Variables::getVariable("word132") << endl;
}
