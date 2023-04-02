#pragma once

#include <istream>

#include "astnode.hpp"
#include "lexer.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mul.hpp"
#include "variable.hpp"

class Parser {
  public:
    explicit Parser(Lexer &lexer)
        : lexer_(lexer) {}

    Parser(const Parser &other) = delete;

    Parser &operator=(const Parser &other) = delete;

    ~Parser() = default;

    ASTNode *parse();

  private:
    void next_token();

    ASTNode *expr();

    ASTNode *term();

    ASTNode *prim();

    Lexer &lexer_;
    Lexer::Token tok_;
};
