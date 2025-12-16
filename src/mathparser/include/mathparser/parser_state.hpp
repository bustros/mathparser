#ifndef MATHPARSER_PARSER_STATE_HPP
#define MATHPARSER_PARSER_STATE_HPP

namespace mp {
class ParserContext;
class ParserState {
 public:
  explicit ParserState(ParserContext& t_context) : context_(t_context) {}
  virtual ~ParserState() = default;
  virtual void handle(char) = 0;

  ParserState(const ParserState&) = delete;
  ParserState& operator=(const ParserState&) = delete;
  ParserState(ParserState&&) = delete;
  ParserState& operator=(ParserState&&) = delete;

 private:
  ParserContext& context_;

 protected:
  ParserContext& context() { return context_; }
  const ParserContext& context() const { return context_; }
};
}  // namespace mp
#endif  // MATHPARSER_PARSER_STATE_HPP
