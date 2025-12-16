#include "mathparser/func_state.hpp"

#include "mathparser/parser_context.hpp"

namespace mp {

void FuncState::handle(char it) {
  if (isdigit(it) || isalpha(it)) {
    func_name_ += it;
    return;
  }
  if (it == '(') {
    context.cursor_->setMeta(context.function_map_->getByName(func_name_));
    func_name_ = "";
    context.interpreter_stack_.push(context.cursor_);
    context.cursor_ = context.cursor_->arg[0];
    context.changeState(context.init_state_);
  } else if (it == ')') {
    context.popToFunc();
  } else if (it == '-') {
    context.newOperator('+');
    context.cursor_->coef *= -1;
    context.changeState(context.init_state_);
  } else {
    context.newOperator(it);
    context.changeState(context.init_state_);
  }
}

void FuncState::setFuncName(const std::string& name) { func_name_ = name; }
const std::string& FuncState::getFuncName() const { return func_name_; }

}  // namespace mp
