#include "mathparser/parser.hpp"

#include <memory>
namespace mp {

Parser::Parser() { parser_context_.setFunctionMap(std::make_shared<FunctionMap>()); }

void Parser::buildExpression(const std::string& str) {
  func_expression_ = parser_context_.getCursor();
  for (auto it : str) {
    parser_context_.handle(it);
  }
  parser_context_.handle(0);
}

double Parser::eval() { return func_expression_->evaluate(); }

}  // namespace mp
