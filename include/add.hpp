#ifndef ADD_HPP
#define ADD_HPP
#pragma once
#include "astnode.hpp"

class Add : public ASTNode {
public:
    Add(ASTNode* lhs, ASTNode* rhs);
    double eval() const;
    void print(std::ostream& out) const;
};

#endif // ADD_HPP
