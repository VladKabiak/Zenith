#include <iostream>
#include <vector>
#include "Token/Token.h"
#include "Lexer/Lexer.h"
#include "AST/Expression.h"
#include "Parser/Parser.h"

using namespace std;


int main() {
    string input = "(2+2) * #0F";
    vector<Token> tokens = (new Lexer(input))->tokenize();
    for (auto el : tokens) {
        cout << el.getType() << " " << el.getText() << endl;
    }
    vector<Expression*> expressions = (new Parser(tokens))->parse();
    for (auto el : expressions) {
        cout << el << " " << el->eval() << endl;
    }
}
