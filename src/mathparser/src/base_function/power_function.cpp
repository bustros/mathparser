#include "mathparser/base_function/power_function.hpp"

#include <cmath>

namespace mp {
namespace {
constexpr int kPowerOperIndex = 30;
}

PowerFunction::PowerFunction() {
  setName("pow");
  setArgNumber(2);
  setOperator('^');
  setOperIndex(kPowerOperIndex);
}

double PowerFunction::evaluateImpl(const ArgType& arg) const { return std::pow(arg[0], arg[1]); }
}  // namespace mp