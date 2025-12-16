#include "mathparser/base_function/power_function.hpp"

#include <cmath>

namespace mp {
PowerFunction::PowerFunction() {
  BaseFunction::name_ = "pow";
  BaseFunction::arg_number_ = 2;
  BaseFunction::oper_ = '^';
  BaseFunction::oper_index_ = 30;
}

double PowerFunction::evaluateImpl(const ArgType& arg) const { return std::pow(arg[0], arg[1]); }
}  // namespace mp