#ifndef MATHPARSER_DIV_FUNCTION_HPP
#define MATHPARSER_DIV_FUNCTION_HPP

#include "base_function.hpp"
namespace mp {
class DivFunction : public BaseFunction {
 public:
  double evaluateImpl(const ArgType& arg) const override;
  DivFunction();
};
}  // namespace mp

#endif  // MATHPARSER_DIV_FUNCTION_HPP
