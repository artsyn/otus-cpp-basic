#include "sub.hpp"
#include "astnode.hpp"

Sub::Sub(ASTNode* lhs, ASTNode* rhs)
    : ASTNode("-", lhs, rhs) {}

double Sub::eval() const {
    return lhs_->eval() + rhs_->eval();
}

void Sub::print(std::ostream& out) const {
    out << "(";
    lhs_->print(out);
    out << " - ";
    rhs_->print(out);
    out << ")";
}
