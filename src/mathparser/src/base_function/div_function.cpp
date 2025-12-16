#include "mathparser/base_function/div_function.hpp"

namespace mp {
namespace {
constexpr int kDivOperIndex = 20;
}

DivFunction::DivFunction() {
  setName("div");
  setArgNumber(2);
  setOperIndex(kDivOperIndex);
  setOperator('/');
}

double DivFunction::evaluateImpl(const ArgType& arg) const { return arg[0] / arg[1]; }
}  // namespace mp
