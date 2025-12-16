#include "mathparser/base_function/mult_function.hpp"

namespace mp {
namespace {
constexpr int kMultOperIndex = 20;
}

MultFunction::MultFunction() {
  setName("mult");
  setArgNumber(2);
  setOperIndex(kMultOperIndex);
  setOperator('*');
}

double MultFunction::evaluateImpl(const ArgType& arg) const { return arg[0] * arg[1]; }
}  // namespace mp
