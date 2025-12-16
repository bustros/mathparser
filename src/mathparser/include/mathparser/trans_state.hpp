#ifndef MATHPARSER_TRANS_STATE_HPP
#define MATHPARSER_TRANS_STATE_HPP
#include "parser_state.hpp"
namespace mp {
class TransState : public ParserState {
 public:
  TransState();
  virtual void handle();
};

}  // namespace mp

#endif  // MATHPARSER_TRANS_STATE_HPP
