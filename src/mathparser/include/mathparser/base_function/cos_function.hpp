#ifndef MATHPARSER_COS_FUNCTION_HPP
#define MATHPARSER_COS_FUNCTION_HPP
#include "base_function.hpp"
namespace mp {
class CosFunction : public BaseFunction {
 public:
  double evaluateImpl(const ArgType& arg) const override;
  CosFunction();
};

}  // namespace mp

#endif  // MATHPARSER_COS_FUNCTION_HPP
