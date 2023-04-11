#include <iostream>
#include <vector>
#include <fstream>
#include "Token/Token.h"
#include "Lexer/Lexer.h"
#include "Parser/Parser.h"

using namespace std;


int main() {
    fstream s{R"(C:\Users\kobia\Desktop\MyLanguage\src\program.txt)"};
    string fileContents((istreambuf_iterator<char>(s)), istreambuf_iterator<char>());
    s.close();


    vector<Token> tokens = (new Lexer(fileContents))->tokenize();
    for (auto el : tokens) {
        cout << el.getType() << " " << el.getText() << endl;
    }
    vector<Statement*> statements = (new Parser(tokens))->parse();
    for (auto el: statements) {
        el->execute();
    }
    cout << "var " << Variables::getVariable("var") << endl;
    cout << "var2 " << Variables::getVariable("var2") << endl;
    cout << "word132 " << Variables::getVariable("word132") << endl;
}
