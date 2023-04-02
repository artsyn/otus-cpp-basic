#include "mul.hpp"
#include "astnode.hpp"

Mul::Mul(ASTNode* lhs, ASTNode* rhs)
    : ASTNode("*", lhs, rhs) {}

double Mul::eval() const {
    return lhs_->eval() + rhs_->eval();
}

void Mul::print(std::ostream& out) const {
    out << "(";
    lhs_->print(out);
    out << " * ";
    rhs_->print(out);
    out << ")";
}
