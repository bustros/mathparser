#include "mathparser/base_function/coe_function.hpp"

namespace mp {
CoefFunction::CoefFunction() { setName("coef"); setArgNumber(0); }

double CoefFunction::evaluateImpl(const ArgType& arg) const { return arg.empty() ? 1.0 : arg[0]; }
}  // namespace mp
