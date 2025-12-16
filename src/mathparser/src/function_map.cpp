#include "mathparser/function_map.hpp"

#include "mathparser/base_function/add_function.hpp"
#include "mathparser/base_function/brackets_function.hpp"
#include "mathparser/base_function/coe_function.hpp"
#include "mathparser/base_function/cos_function.hpp"
#include "mathparser/base_function/div_function.hpp"
#include "mathparser/base_function/mult_function.hpp"
#include "mathparser/base_function/power_function.hpp"
#include "mathparser/base_function/sin_function.hpp"
namespace mp {
FunctionMap::FunctionMap() {
  addFunction(std::make_shared<CosFunction>());
  addFunction(std::make_shared<SinFunction>());
  addFunction(std::make_shared<MultFunction>());
  addFunction(std::make_shared<DivFunction>());
  addFunction(std::make_shared<AddFunction>());
  addFunction(std::make_shared<PowerFunction>());
  addFunction(std::make_shared<BracketsFunction>());
  addFunction(std::make_shared<CoefFunction>());
}
std::shared_ptr<BaseFunction>& FunctionMap::getByName(const std::string& name) {
  auto bf = map_by_name_.find(name);
  if (bf != map_by_name_.end()) {
    return bf->second;
  } else {
    throw std::runtime_error("Function not found by name: " + name);
  }
}

std::shared_ptr<BaseFunction>& FunctionMap::getByOperator(char oper) {
  auto bf = map_by_operator_.find(oper);
  if (bf != map_by_operator_.end()) {
    return bf->second;
  } else {
    throw std::runtime_error(std::string("Function not found by operator: ") + oper);
  }
}
void FunctionMap::addFunction(std::shared_ptr<BaseFunction> func) {
  if (!func->getName().empty()) {
    this->map_by_name_.insert({func->getName(), func});
  }
  if (func->getOperator()) {
    this->map_by_operator_.insert({func->getOperator(), func});
  }
}

}  // namespace mp
