// OTUS C++ basic course homework.
// ASTNode

#pragma once

#include <cctype>
#include <iostream>
#include <string>

class ASTNode {
  public:
    explicit ASTNode(const std::string &repr);

    ASTNode(const std::string &repr, ASTNode *lhs, ASTNode *rhs);

    ASTNode(const ASTNode &other) = delete;

    ASTNode &operator=(const ASTNode &other) = delete;

    ~ASTNode();

    std::string repr() const { return repr_; }

    virtual double eval() const { return 0.0; }  // объявляем метод eval

    void print(std::ostream &out) const;

  protected:
    ASTNode *lhs_;
    ASTNode *rhs_;
  private:
    void inner_print(std::ostream &out, size_t indent) const;

    std::string repr_;

};
