#ifndef MATHPARSER_COEF_STATE_HPP
#define MATHPARSER_COEF_STATE_HPP

#include <memory>
#include <string>

#include "parser_state.hpp"

namespace mp {
class BaseFunction;
class CoefState : public ParserState {
 public:
  using ParserState::ParserState;
  void handle(char);

 private:
  int decimal_ = 0;
  std::shared_ptr<BaseFunction> coef_function_;
  std::string func_name_;
};
}  // namespace mp

#endif  // MATHPARSER_COEF_STATE_HPP
