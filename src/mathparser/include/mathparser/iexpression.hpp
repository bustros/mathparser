#ifndef MATHPARSER_IEXPRESSION_HPP
#define MATHPARSER_IEXPRESSION_HPP

namespace mp {

class IExpression {
 protected:
  IExpression() {}

 public:
  virtual ~IExpression() {}
  virtual double Evaluate() = 0;
};
}  // namespace mp
#endif  // MATHPARSER_IEXPRESSION_HPP
