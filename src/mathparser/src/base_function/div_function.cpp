#include "mathparser/base_function/div_function.hpp"

namespace mp {
DivFunction::DivFunction() {
  BaseFunction::name_ = "div";
  BaseFunction::arg_number_ = 2;
  BaseFunction::oper_index_ = 20;
  BaseFunction::oper_ = '/';
}

double DivFunction::evaluateImpl(const ArgType& arg) const { return arg[0] / arg[1]; }
}  // namespace mp
