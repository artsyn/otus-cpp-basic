#ifndef DIV_HPP
#define DIV_HPP
#pragma once
#include "astnode.hpp"

class Div : public ASTNode {
public:
    Div(ASTNode* lhs, ASTNode* rhs);
    double eval() const;
    void print(std::ostream& out) const;
};

#endif // DIV_HPP
