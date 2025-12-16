#ifndef MATHPARSER_PARSER_CONTEXT_HPP
#define MATHPARSER_PARSER_CONTEXT_HPP

#include <memory>
#include <stack>

#include "coef_state.hpp"
#include "func_state.hpp"
#include "function_expression.hpp"
#include "function_map.hpp"
#include "init_state.hpp"

namespace mp {
class ParserState;
class ParserContext {
 public:
  ParserContext();
  void handle(char);
  std::shared_ptr<FunctionExpression> getCursor() const { return cursor_; }
  void setFunctionMap(std::shared_ptr<FunctionMap> fm) { function_map_ = std::move(fm); }

 private:
  std::stack<std::shared_ptr<FunctionExpression>> interpreter_stack_;
  std::shared_ptr<FunctionMap> function_map_;
  std::shared_ptr<FunctionExpression> cursor_;

  ParserState* state_{nullptr};

  void changeState(ParserState&);
  void handleDefault(char);
  void newOperator(char it);
  void popToFunc();
  InitState init_state_;
  FuncState funct_state_;
  CoefState coef_state_;

  friend class InitState;
  friend class FuncState;
  friend class CoefState;
};

}  // namespace mp

#endif  // MATHPARSER_PARSER_CONTEXT_HPP
