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
    ns::vector<int> v(3, 100);
    ns::vector<int> v1(4, 200);

    ns::vector<int>::iterator it = v.begin();
    ns::vector<int>::iterator ite = v.end();
    // for (; it != ite; it++)
    //     std::cout << *it << std::endl;
    std::cout << "after wap\n";
    v.swap(v1);
    for (; it != ite; it++)
        std::cout << *it << std::endl;
    std::cout << "================\n";
    ns::vector<int>::iterator t = v.begin();
    ns::vector<int>::iterator te = v.end();
    for (; t != te; t++)
        std::cout << *t << std::endl;
}