#include <iostream>

#include "mathparser/parser.hpp"

void test() {
  mp::Parser p;
  std::string test = "5*(54+7+cos(3.1415))^(1+sin(3.1415/2))";
  p.buildExpression(test);
  std::cout << p.eval() << "\n";
}

int main(int argc, char** argv) {
  test();
  return 0;
}
