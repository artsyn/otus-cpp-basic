#include "div.hpp"
#include "astnode.hpp"

Div::Div(ASTNode* lhs, ASTNode* rhs)
    : ASTNode("/", lhs, rhs) {}

double Div::eval() const {
    return lhs_->eval() + rhs_->eval();
}

void Div::print(std::ostream& out) const {
    out << "(";
    lhs_->print(out);
    out << " / ";
    rhs_->print(out);
    out << ")";
}
