#ifndef SUB_HPP
#define SUB_HPP

#include "astnode.hpp"
#pragma once
class Sub : public ASTNode {
public:
    Sub(ASTNode* lhs, ASTNode* rhs);
    double eval() const;
    void print(std::ostream& out) const;
};

#endif // SUB_HPP
