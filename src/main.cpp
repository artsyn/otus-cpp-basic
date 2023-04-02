// OTUS C++ Basic course homework skeleton.
// Lexer using example

#include <iostream>

#include "astnode.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mul.hpp"
#include "variable.hpp"


int main() {
    // TODO
    // Implement the next classes:
    // Add
    // Sub
    // Mul
    // Div
    // Variable

    // Without implementation that classes this application works only with numbers
    while (true) {
    std::cout << "Enter expression: ";
    //std::string expression;
    //std::getline(std::cin, expression);

    Lexer lexer(std::cin);
    Parser parser(lexer);

    ASTNode *ast = parser.parse();
    if (ast) {
         ast->print(std::cout);
         //std::cout << " = " << ast->eval() << std::endl;
         //std::cin.get(); 
         delete ast; // очищаем дерево
    }
    else {
        std::cout << "Error: invalid expression" << std::endl;
    }
    }



    return 0;
}
