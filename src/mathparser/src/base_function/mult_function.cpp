#include "mathparser/base_function/mult_function.hpp"

namespace mp {
MultFunction::MultFunction() {
  BaseFunction::name_ = "mult";
  BaseFunction::arg_number_ = 2;
  BaseFunction::oper_index_ = 20;
  BaseFunction::oper_ = '*';
}

double MultFunction::evaluateImpl(const ArgType& arg) const { return arg[0] * arg[1]; }
}  // namespace mp
