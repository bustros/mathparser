#ifndef MATHPARSER_PARSER_HPP
#define MATHPARSER_PARSER_HPP

#include "parser_context.hpp"

namespace mp {

class Parser {
 public:
  Parser();
  void buildExpression(const std::string&);
  double eval();

 private:
  ParserContext parser_context_;
  std::shared_ptr<FunctionExpression> func_expression_;
};
}  // namespace mp

#endif  // MATHPARSER_PARSER_HPP
