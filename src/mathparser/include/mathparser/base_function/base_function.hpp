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

 public:
  BaseFunction() = default;
  BaseFunction(const BaseFunction&) = default;
  BaseFunction& operator=(const BaseFunction&) = default;
  BaseFunction(BaseFunction&&) = default;
  BaseFunction& operator=(BaseFunction&&) = default;

 protected:
  void setName(std::string n) { name_ = std::move(n); }
  void setOperator(char o) { oper_ = o; }
  void setArgNumber(size_t n) { arg_number_ = n; }
  void setOperIndex(int i) { oper_index_ = i; }

 private:
  std::string name_;
  char oper_{'\0'};
  size_t arg_number_{0};
  int oper_index_{0};

};

}  // namespace mp

#endif  // MATHPARSER_BASE_FUNCTION_HPP
