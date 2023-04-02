#include "variable.hpp"
#include "astnode.hpp"

Variable::Variable(const std::string &name, double value)
    : ASTNode(name), name_(name), value_(value) {}

double Variable::eval() const {
    return value_;
}
