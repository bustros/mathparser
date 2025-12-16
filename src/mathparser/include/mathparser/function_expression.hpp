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
  explicit FunctionExpression(std::shared_ptr<BaseFunction>);
  FunctionExpression();
  ~FunctionExpression() override = default;
  double Evaluate() override;

  size_t argCount() const { return arg_.size(); }
  std::shared_ptr<FunctionExpression>& argAt(size_t i) { return arg_.at(i); }
  const std::shared_ptr<FunctionExpression>& argAt(size_t i) const { return arg_.at(i); }
  void ensureArgSize(size_t n) { arg_.resize(n); }

  double coef() const { return coef_; }
  void setCoef(double c) { coef_ = c; }

  void setMeta(std::shared_ptr<BaseFunction>);

  FunctionExpression(const FunctionExpression&) = default;
  FunctionExpression& operator=(const FunctionExpression&) = default;
  FunctionExpression(FunctionExpression&&) = default;
  FunctionExpression& operator=(FunctionExpression&&) = default;

 private:
  friend class ParserContext;
  ArgsType arg_;
  double coef_{1.0};
  std::shared_ptr<BaseFunction> meta_;
};
}  // namespace mp

#endif  // MATHPARSER_FUNCTION_EXPRESSION_HPP
