#ifndef MATHPARSER_FUNCTION_MAP_HPP
#define MATHPARSER_FUNCTION_MAP_HPP

#include <memory>
#include <string>
#include <unordered_map>

#include "base_function/base_function.hpp"

namespace mp {
class FunctionMap {
 public:
  FunctionMap();
  std::shared_ptr<BaseFunction>& getByName(const std::string&);
  std::shared_ptr<BaseFunction>& getByOperator(char);
  void addFunction(std::shared_ptr<BaseFunction>);

 private:
  std::unordered_map<std::string, std::shared_ptr<BaseFunction>> map_by_name_;
  std::unordered_map<char, std::shared_ptr<BaseFunction>> map_by_operator_;
};
}  // namespace mp

#endif  // MATHPARSER_FUNCTION_MAP_HPP
