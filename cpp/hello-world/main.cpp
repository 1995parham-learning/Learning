#include <iostream>
#include <fmt/core.h>

int main() {
  std::cout << fmt::format("Hello, World {}", 42) << std::endl;
  return 0;
}
