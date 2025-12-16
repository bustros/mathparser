#include "mathparser/base_function/sin_function.hpp"

#include <cmath>

namespace mp {
SinFunction::SinFunction() {
  setName("sin");
  setArgNumber(1);
}

double SinFunction::evaluateImpl(const ArgType& arg) const { return std::sin(arg[0]); }
}  // namespace mp
