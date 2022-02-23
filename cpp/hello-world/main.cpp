#include <iostream>
#include <fmt/core.h>

int main() {
  std::cout << fmt::format("Hello, World {}", 10) << std::endl;
  return 0;
}
