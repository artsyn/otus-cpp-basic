#ifndef VARIABLE_HPP
#define VARIABLE_HPP
#pragma once
#include "astnode.hpp"

class Variable : public ASTNode {
public:
    Variable(const std::string& name, double value = 0.0);
    virtual double eval() const;

private:
    std::string name_;
    double value_;
};




#endif // VARIABLE_HPP
