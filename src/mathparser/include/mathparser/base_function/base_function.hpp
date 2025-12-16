#ifndef MATHPARSER_BASE_FUNCTION_HPP
#define MATHPARSER_BASE_FUNCTION_HPP

#include <string>
#include <vector>

namespace mp {

class BaseFunction {
 public:
  using ArgType = std::vector<double>;
  virtual ~BaseFunction() = default;
  virtual size_t getArgNumber() const;
  virtual const std::string& getName() const;
  virtual char getOperator() const;
  virtual int getOperIndex() const;
  virtual double evaluate(const ArgType& arg) const;
  virtual double evaluateImpl(const ArgType& arg) const = 0;

 protected:
  std::string name_;
  char oper_{'\0'};
  size_t arg_number_{0};
  int oper_index_{0};

  BaseFunction() = default;
};

}  // namespace mp

#endif  // MATHPARSER_BASE_FUNCTION_HPP
