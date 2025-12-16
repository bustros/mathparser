#include "mathparser/base_function/base_function.hpp"

#include <stdexcept>

namespace mp {

int BaseFunction::getOperIndex() const { return oper_index_; }

size_t BaseFunction::getArgNumber() const { return arg_number_; }

const std::string& BaseFunction::getName() const { return name_; }
char BaseFunction::getOperator() const { return oper_; }

double BaseFunction::evaluate(const ArgType& arg) const {
  if (arg.size() != arg_number_) {
    throw std::runtime_error("Invalid number of arguments for function: " + name_);
  }
  return evaluateImpl(arg);
}

}  // namespace mp
