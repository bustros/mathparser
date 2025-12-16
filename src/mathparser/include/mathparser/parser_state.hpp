#ifndef MATHPARSER_PARSER_STATE_HPP
#define MATHPARSER_PARSER_STATE_HPP

namespace mp {
class ParserContext;
class ParserState {
 public:
  ParserState(ParserContext& t_context) : context(t_context) {}
  virtual void handle(char) = 0;

 protected:
  ParserContext& context;
};
}  // namespace mp
#endif  // MATHPARSER_PARSER_STATE_HPP
