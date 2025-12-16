#include "mathparser/base_function/brackets_function.hpp"

#include <stdexcept>

namespace mp {
BracketsFunction::BracketsFunction() {
  BaseFunction::name_ = "()";
  BaseFunction::arg_number_ = 1;
}

double BracketsFunction::evaluateImpl(const ArgType& arg) const { return arg[0]; }
}  // namespace mp