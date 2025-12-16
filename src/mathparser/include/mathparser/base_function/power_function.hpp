#ifndef MATHPARSER_POWER_FUNCTION_HPP
#define MATHPARSER_POWER_FUNCTION_HPP

#include "base_function.hpp"
namespace mp {

class PowerFunction : public BaseFunction {
 public:
  double evaluateImpl(const ArgType& arg) const override;
  PowerFunction();
};
}  // namespace mp

#endif  // MATHPARSER_POWER_FUNCTION_HPP
