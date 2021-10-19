#include <iostream>
#include "Vector.hpp"
// #include <type_traits>
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
    ns::vector<int> v;

    for (int i = 0; i < 1000000; i++)
        v.push_back(i);
    // ns::vector<int>::iterator it = v.begin();
    for (ns::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        std::cout << *it << std::endl;
}