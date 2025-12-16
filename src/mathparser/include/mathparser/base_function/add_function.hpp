#ifndef MATHPARSER_ADD_FUNCTION_HPP
#define MATHPARSER_ADD_FUNCTION_HPP
#include "base_function.hpp"
namespace mp {
class AddFunction : public BaseFunction {
 public:
  double evaluateImpl(const ArgType& arg) const override;
  AddFunction();
};
}  // namespace mp

#endif  // MATHPARSER_ADD_FUNCTION_HPP
