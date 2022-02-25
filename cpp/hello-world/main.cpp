#include <iostream>
#include <fmt/core.h>

int main() {
  int answer {42};

  std::cout << fmt::format("Hello, World {}", answer) << std::endl;

  return 0;
}
