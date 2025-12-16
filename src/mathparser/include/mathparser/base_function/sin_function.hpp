#ifndef MATHPARSER_SIN_FUNCTION_HPP
#define MATHPARSER_SIN_FUNCTION_HPP
#include "base_function.hpp"
namespace mp {
class SinFunction : public BaseFunction {
 public:
  double evaluateImpl(const ArgType& arg) const override;
  SinFunction();
};
}  // namespace mp

#endif  // MATHPARSER_SIN_FUNCTION_HPP
