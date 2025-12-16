#include "mathparser/coef_state.hpp"

#include <cmath>

#include "mathparser/parser_context.hpp"

namespace mp {

void CoefState::handle(char it) {
  constexpr int kBase = 10;
  if (isdigit(it)) {
    if (decimal_ == 0) {
      double c = context().cursor_->coef();
      context().cursor_->setCoef(c * kBase + (it - '0'));
      return;
    }
    double c = context().cursor_->coef();
    context().cursor_->setCoef(c + static_cast<double>(it - '0') / (std::pow(kBase, decimal_)));
    ++decimal_;

    return;
  }

  context().cursor_->setMeta(context().function_map_->getByName("coef"));
  decimal_ = 0;
  if (isalpha(it)) {
    context().changeState(context().funct_state_);
    context().funct_state_.setFuncName(std::string(1, it));
    return;
  }

  if (it == ')') {
    context().popToFunc();
    context().changeState(context().funct_state_);
  } else if (it == '.') {
    ++decimal_;
  } else if (it == '-') {
    context().newOperator('+');
    context().cursor_->setCoef(context().cursor_->coef() * -1);
    context().changeState(context().init_state_);
  } else if (it == '(') {
    context().newOperator('*');
    context().cursor_->setMeta(context().function_map_->getByName("()"));
    context().interpreter_stack_.push(context().cursor_);
    context().cursor_ = context().cursor_->argAt(0);
    context().changeState(context().init_state_);
  } else {
    context().newOperator(it);
    context().changeState(context().init_state_);
  }
} 

}  // namespace mp
