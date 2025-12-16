#ifndef MATHPARSER_INIT_STATE_HPP
#define MATHPARSER_INIT_STATE_HPP

#include "parser_state.hpp"

namespace mp {
class ParserContext;
class InitState : public ParserState {
 public:
  using ParserState::ParserState;
  void handle(char);
};
}  // namespace mp

#endif  // MATHPARSER_INIT_STATE_HPP
