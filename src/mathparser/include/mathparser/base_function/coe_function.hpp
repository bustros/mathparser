#ifndef MATHPARSER_COE_FUNCTION_HPP
#define MATHPARSER_COE_FUNCTION_HPP
#include "base_function.hpp"
namespace mp {
class CoefFunction : public BaseFunction {
 public:
  double evaluateImpl(const ArgType& arg) const override;
  CoefFunction();
};

}  // namespace mp

#endif  // MATHPARSER_COE_FUNCTION_HPP
