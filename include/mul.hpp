#ifndef MUL_HPP
#define MUL_HPP

#include "astnode.hpp"
#pragma once
class Mul : public ASTNode {
public:
    Mul(ASTNode* lhs, ASTNode* rhs);
    double eval() const;
    void print(std::ostream& out) const;
};

#endif // MUL_HPP
