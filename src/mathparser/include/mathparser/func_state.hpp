#ifndef MATHPARSER_FUNC_STATE_HPP
#define MATHPARSER_FUNC_STATE_HPP

#include <string>

#include "parser_state.hpp"

namespace mp {

class FuncState : public ParserState {
 public:
  using ParserState::ParserState;
  void handle(char) override;
  const std::string& getFuncName() const;
  void setFuncName(const std::string& name);

 private:
  std::string func_name_;
};
}  // namespace mp

#endif  // MATHPARSER_FUNC_STATE_HPP
