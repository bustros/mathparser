#ifndef MATHPARSER_MULT_FUNCTION_HPP
#define MATHPARSER_MULT_FUNCTION_HPP

#include "base_function.hpp"
namespace mp {
class MultFunction : public BaseFunction {
 public:
  double evaluateImpl(const ArgType& arg) const override;
  MultFunction();
};
}  // namespace mp

#endif  // MATHPARSER_MULT_FUNCTION_HPP
