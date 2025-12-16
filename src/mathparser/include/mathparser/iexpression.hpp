#ifndef MATHPARSER_IEXPRESSION_HPP
#define MATHPARSER_IEXPRESSION_HPP

namespace mp {

class IExpression {
 protected:
  IExpression() = default;

 public:
  virtual ~IExpression() = default;
  virtual double Evaluate() = 0;

  IExpression(const IExpression&) = default;
  IExpression& operator=(const IExpression&) = default;
  IExpression(IExpression&&) = default;
  IExpression& operator=(IExpression&&) = default;
};
}  // namespace mp
#endif  // MATHPARSER_IEXPRESSION_HPP
