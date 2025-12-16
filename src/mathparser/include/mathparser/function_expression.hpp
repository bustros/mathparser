#ifndef MATHPARSER_FUNCTION_EXPRESSION_HPP
#define MATHPARSER_FUNCTION_EXPRESSION_HPP

#include <memory>
#include <vector>

#include "base_function/base_function.hpp"
#include "iexpression.hpp"

namespace mp {
class FunctionExpression : public IExpression {
 public:
  using ArgsType = std::vector<std::shared_ptr<FunctionExpression>>;
  FunctionExpression(std::shared_ptr<BaseFunction>);
  FunctionExpression();
  ~FunctionExpression();
  double Evaluate();
  ArgsType arg;
  double coef{1.0};
  void setMeta(std::shared_ptr<BaseFunction>);

 private:
  friend class ParserContext;
  std::shared_ptr<BaseFunction> meta_;
};
}  // namespace mp

#endif  // MATHPARSER_FUNCTION_EXPRESSION_HPP
