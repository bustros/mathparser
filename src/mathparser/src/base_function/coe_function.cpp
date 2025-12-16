#include "mathparser/base_function/coe_function.hpp"

namespace mp {
CoefFunction::CoefFunction() {
  BaseFunction::name_ = "coef";
  BaseFunction::arg_number_ = 0;
}

double CoefFunction::evaluateImpl(const ArgType& arg) const { return 1; }
}  // namespace mp
