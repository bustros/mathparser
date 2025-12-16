#ifndef MATHPARSER_BRACKETS_FUNCTION_HPP
#define MATHPARSER_BRACKETS_FUNCTION_HPP
#include "base_function.hpp"
namespace mp {
class BracketsFunction : public BaseFunction {
 public:
  double evaluateImpl(const ArgType& arg) const override;
  BracketsFunction();
};
}  // namespace mp

#endif  // MATHPARSER_BRACKETS_FUNCTION_HPP
