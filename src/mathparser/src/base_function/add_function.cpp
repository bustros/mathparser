#include "mathparser/base_function/add_function.hpp"

#include <stdexcept>

namespace mp {
AddFunction::AddFunction() {
  BaseFunction::name_ = "add";
  BaseFunction::arg_number_ = 2;
  BaseFunction::oper_ = '+';
  BaseFunction::oper_index_ = 10;
}

double AddFunction::evaluateImpl(const ArgType& arg) const { return arg[0] + arg[1]; }
}  // namespace mp
