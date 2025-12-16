#include "mathparser/base_function/add_function.hpp"

#include <stdexcept>

namespace mp {
namespace {
constexpr int kAddOperIndex = 10;
}

AddFunction::AddFunction() {
  setName("add");
  setArgNumber(2);
  setOperator('+');
  setOperIndex(kAddOperIndex);
}

double AddFunction::evaluateImpl(const ArgType& arg) const { return arg[0] + arg[1]; }
}  // namespace mp
