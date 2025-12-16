#include "mathparser/init_state.hpp"

#include <string>

#include "mathparser/parser_context.hpp"
namespace mp {

void InitState::handle(char it) {
  if (isdigit(it)) {
    context().changeState(context().coef_state_);
    context().cursor_->setCoef(context().cursor_->coef() * (it - '0'));
  } else if (isalpha(it)) {
    context().changeState(context().funct_state_);
    context().funct_state_.setFuncName(std::string(1, it));
  } else if (it == '+') {
    context().cursor_->setCoef(1);
  } else if (it == '-') {
    context().cursor_->setCoef(-1);
  } else if (it == '(') {
    context().cursor_->setMeta(context().function_map_->getByName("()"));
    context().interpreter_stack_.push(context().cursor_);
    context().cursor_ = context().cursor_->argAt(0);
  }
}
}  // namespace mp
