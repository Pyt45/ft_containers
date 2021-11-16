#include "char_traits.hpp"

int main() {
    std::cout << ~(static_cast<size_t>(~0) >> 1) << std::endl;
    std::cout << (0x1ul) << std::endl;
}