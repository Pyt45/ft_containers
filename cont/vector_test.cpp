#include <iostream>
#include "Vector.hpp"
#include <type_traits>
#include <vector>

#define ns ft

template <class T>
typename std::enable_if< !std::is_integral<T>::value, bool >::type is_odd(T x) {
    return x[0] % 2;
}

template <class T>
typename std::enable_if< std::is_integral<T>::value, bool >::type is_odd_(T y) {
    return bool(y % 2);
}

int main() {
    ns::vector<int> v(3, 100);
    ns::vector<int> v1(4, 200);
    ns::vector<int>::iterator it = v.begin();
    ns::vector<int>::iterator ite = v.end();
    v.swap(v1);
    while (it != ite)
        std::cout << *it++ << std::endl;
}