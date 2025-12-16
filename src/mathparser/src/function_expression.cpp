#include "mathparser/function_expression.hpp"

#include "mathparser/base_function/base_function.hpp"

namespace mp {
double FunctionExpression::Evaluate() {
  size_t a_nb = meta_->getArgNumber();
  if (a_nb) {
    std::vector<double> evaluated_args(a_nb);
    for (size_t i = 0; i < a_nb; ++i) {
      evaluated_args[i] = arg[i]->Evaluate();
    }
    return coef * meta_->evaluate(evaluated_args);
  } else {
    return coef * meta_->evaluate(BaseFunction::ArgType{});
  }
}

FunctionExpression::~FunctionExpression() = default;

void FunctionExpression::setMeta(std::shared_ptr<BaseFunction> t_meta) {
  meta_ = t_meta;
  arg.clear();
  if (meta_->getArgNumber() == 0) {
    return;
  }

  arg.reserve(meta_->getArgNumber());
  for (size_t i = 0; i < meta_->getArgNumber(); ++i) {
    arg.emplace_back(std::make_shared<FunctionExpression>());
  }
}

FunctionExpression::FunctionExpression() = default;
FunctionExpression::FunctionExpression(std::shared_ptr<BaseFunction> t_meta) { setMeta(t_meta); }

}  // namespace mp
