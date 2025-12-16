#include "mathparser/parser_context.hpp"

#include <memory>

namespace mp {

ParserContext::ParserContext() : init_state_(*this), coef_state_(*this), funct_state_(*this) {
  state_ = &init_state_;
  cursor_ = std::make_shared<FunctionExpression>();
}

void ParserContext::handle(char it) { state_->handle(it); }

void ParserContext::changeState(ParserState& t_state) { state_ = &t_state; }

void ParserContext::newOperator(char it) {
  if (!it) return;
  std::shared_ptr<BaseFunction> currentOp = function_map_->getByOperator(it);
  auto func = std::make_shared<FunctionExpression>(currentOp);

  while (true) {
    if (interpreter_stack_.empty()) {
      break;
    }
    std::shared_ptr<BaseFunction> operSearch = interpreter_stack_.top()->meta_;

    if (operSearch->getOperator() && operSearch->getOperIndex() > currentOp->getOperIndex()) {
      cursor_ = std::move(interpreter_stack_.top());
      interpreter_stack_.pop();
    } else {
      break;
    }
  }
  *func->argAt(0) = *cursor_;
  *cursor_ = *func;
  interpreter_stack_.push(std::move(func));
  cursor_ = cursor_->argAt(1);
}

void ParserContext::popToFunc() {
  while (interpreter_stack_.top()->meta_->getOperator()) {
    interpreter_stack_.pop();
  }
  cursor_ = std::move(interpreter_stack_.top());
  interpreter_stack_.pop();
}
}  // namespace mp
