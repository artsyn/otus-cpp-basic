#include "add.hpp"
#include "astnode.hpp"

Add::Add(ASTNode* lhs, ASTNode* rhs)
    : ASTNode("+", lhs, rhs) {}

double Add::eval() const {
    return lhs_->eval() + rhs_->eval();
}

void Add::print(std::ostream& out) const {
    out << "(";
    lhs_->print(out);
    out << " + ";
    rhs_->print(out);
    out << ")";
}
