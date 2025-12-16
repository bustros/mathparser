#include "mathparser/base_function/sin_function.hpp"

#include <cmath>

namespace mp {
SinFunction::SinFunction() {
  BaseFunction::name_ = "sin";
  BaseFunction::arg_number_ = 1;
}

double SinFunction::evaluateImpl(const ArgType& arg) const { return std::sin(arg[0]); }
}  // namespace mp
