#include "mathparser/base_function/cos_function.hpp"

#include <cmath>

namespace mp {
CosFunction::CosFunction() {
  setName("cos");
  setArgNumber(1);
}

double CosFunction::evaluateImpl(const ArgType& arg) const { return std::cos(arg[0]); }
}  // namespace mp