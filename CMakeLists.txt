cmake_minimum_required(VERSION 3.24)
project(MyLanguage)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyLanguage src/main.cpp src/Token/Token.cpp src/Token/Token.h src/Parser/Parser.cpp src/Parser/Parser.h src/Lexer/Lexer.cpp src/Lexer/Lexer.h src/Token/TokenType.h src/AST/Expression.h src/AST/NumberExpression.cpp src/AST/NumberExpression.h src/AST/BinaryExpression.cpp src/AST/BinaryExpression.h src/AST/UnaryExpression.cpp src/AST/UnaryExpression.h src/AST/VariableExpression.cpp src/AST/VariableExpression.h src/lib/Variables.cpp src/lib/Variables.h src/AST/Statement.h src/AST/AssignmentStatement.cpp src/AST/AssignmentStatement.h)
