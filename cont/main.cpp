#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <memory>
#include <string>

#include "Vector_t.hpp"
#include "Utility.hpp"
#include "Type_traits.hpp"
#include <type_traits>

template <class T>
typename ft::enable_if<ft::is_integral<T>::value, bool>::type is_odd(T i) { return bool(i % 2); }

template <class T, class = typename ft::enable_if<ft::is_integral<T>::value>::type>
bool is_even(T i) {return !bool(i%2);}

void test()
{
	short int i = 1;
	float b = 5;
	std::cout << std::boolalpha;
	std::cout << "is i odd: " << is_odd(i) << std::endl;
	std::cout << "is i even: " << is_even(i) << std::endl;
}

int main()
{
	test();
	// ft::vector<int> v(5, 100);
	// ft::vector<int> f(3, 200);
	// ft::vector<int> v(5, 100);
	// std::vector<int> f(5, 100);

	// f.reserve(31);
	// v.reserve(31);

	// v.push_back(5);
	// f.push_back(5);
	// f.resize(11, 2);
	// v.resize(11, 2);
	// f.push_back(1);
	// v.push_back(1);
	// f.assign(10, 5);
	// v.assign(10, 5);

	// std::cout << "----------------------------------\n";
	// std::cout << "v.size = " << v.size() << std::endl;
	// std::cout << "v.cap = " << v.capacity() << std::endl;
	// std::cout << "----------------------------------\n";
	// std::cout << "f.size = " << f.size() << std::endl;
	// std::cout << "f.cap = " << f.capacity() << std::endl;
	// std::cout << "----------------------------------\n";
	// for (int i = 0; i < v.size(); i++)
	// 	std::cout << "v[" << i << "] = " << v[i] << std::endl;
	// std::cout << "===============\n";
	// for (int i = 0; i < f.size(); i++)
	// 	std::cout << "f[" << i << "] = " << f[i] << std::endl;
	// std::cout << "===============\n";
	// std::cout << "v.size = " << v.size() << std::endl;
	// std::cout << "f.size = " << f.size() << std::endl;
	// std::cout << "===============\n";
	// v = f;
	// for (int i = 0; i < 3; i++)
	// 	std::cout << "arr[" << i << "] = " << v[i] << std::endl;
	// std::cout << "===============\n";
	// f.clear();
	// std::cout << "f.size = " << f.size() << std::endl;
	// for (int i = 0; i < 3; i++)
	// 	std::cout << "arr[" << i << "] = " << f[i] << std::endl;

	// std::allocator<std::string> _alloc;
	// std::string *s = _alloc.allocate(3);
	// _alloc.construct(s, "a");
	// _alloc.construct(s + 1, "b");
	// _alloc.construct(s + 2, "c");

	// std::cout << "s[0] = " << s[0] << std::endl;
	// std::cout << "s[1] = " << s[1] << std::endl;
	// std::cout << "s[2] = " << s[2] << std::endl;
	// _alloc.destroy(s);
	// _alloc.deallocate(s, 3);
	// std::cout << "s[0] = " << s[0] << std::endl;
	// std::cout << "s[1] = " << s[1] << std::endl;
	// std::cout << "s[2] = " << s[2] << std::endl;
	// std::vector<int> v(3, 100);
	// for (size_t i = 0; i < 3; i++)
	// 	std::cout << v[i] << std::endl;
	// v.clear();
	// std::cout << "s = " << v.size() << std::endl;
	// for (size_t i = 0; i < 3; i++)
	// 	std::cout << v[i] << std::endl;
	// ft::pair<int, std::string> p;
	// p = ft::make_pair<int, std::string>(5, "a");
	// std::cout << p.first << std::endl;
	// std::cout << p.second << std::endl;
}