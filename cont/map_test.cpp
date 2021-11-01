// void insert_range_test() {
// 	std::map<int ,int> origin;
// 	std::map<int, int> mine;

// 	// std::swap(origin, mine);

// 	origin.insert(std::pair<int, int>(1, 2));
// 	origin.insert(std::pair<int, int>(2, 3));
// 	origin.insert(std::pair<int, int>(3, 4));
// 	origin.insert(std::pair<int, int>(10, 4));

// 	mine.insert(std::pair<int, int>(11, 2));
// 	mine.insert(std::pair<int, int>(14, 3));
// 	mine.insert(std::pair<int, int>(15, 4));
// 	mine.insert(std::pair<int, int>(16, 4));

// 	std::map<int, int>::iterator it = mine.begin();
// 	it++;
// 	it++;
// 	it++;
// 	origin.insert(mine.begin(), it);
// 	std::map<int, int>::iterator o = origin.begin();
// 	for (; o != origin.end(); o++)
// 		std::cout<< o->first << std::endl;
// 	std::cout << "=======================\n";
// 	ft::map<int ,int> origin1;
// 	ft::map<int, int> mine1;

// 	origin1.insert(ft::pair<int, int>(1, 2));
// 	origin1.insert(ft::pair<int, int>(2, 3));
// 	origin1.insert(ft::pair<int, int>(3, 4));
// 	origin1.insert(ft::pair<int, int>(10, 4));

// 	mine1.insert(ft::pair<int, int>(11, 2));
// 	mine1.insert(ft::pair<int, int>(14, 3));
// 	mine1.insert(ft::pair<int, int>(15, 4));
// 	mine1.insert(ft::pair<int, int>(16, 4));

// 	ft::map<int, int>::iterator it1 = mine1.begin();
// 	it1++;
// 	it1++;
// 	it1++;
// 	origin1.insert(mine1.begin(), it1);
// 	ft::map<int, int>::iterator o1 = origin1.begin();
// 	for (; o1 != origin1.end(); o1++)
// 		std::cout<< o1->first << std::endl;
// }

// void insert_test() {
// 	std::map<int ,int> origin;

// 	origin.insert(std::pair<int, int>(1, 2));
// 	origin.insert(std::pair<int, int>(2, 3));
// 	origin.insert(std::pair<int, int>(3, 4));
// 	origin.insert(std::pair<int, int>(10, 4));

// 	std::map<int, int>::iterator o = origin.begin();
// 	for (; o != origin.end(); o++)
// 		std::cout<< o->first << std::endl;
// 	std::cout << "=======================\n";
// 	ft::map<int ,int> origin1;

// 	origin1.insert(ft::pair<int, int>(1, 2));
// 	origin1.insert(ft::pair<int, int>(2, 3));
// 	origin1.insert(ft::pair<int, int>(3, 4));
// 	origin1.insert(ft::pair<int, int>(10, 4));

// 	ft::map<int, int>::iterator o1 = origin1.begin();
// 	for (; o1 != origin1.end(); o1++)
// 		std::cout<< o1->first << std::endl;
// }

// void insert_at_position() {
// 	std::map<int ,int> origin;

// 	origin.insert(std::pair<int, int>(1, 2));
// 	origin.insert(std::pair<int, int>(2, 3));
// 	origin.insert(std::pair<int, int>(3, 4));
// 	origin.insert(std::pair<int, int>(10, 4));

// 	std::map<int, int>::iterator o = origin.begin();
// 	origin.insert(origin.begin()++, std::pair<int, int>(11, 5));
// 	for (; o != origin.end(); o++)
// 		std::cout<< o->first << std::endl;
// 	std::cout << "=======================\n";
// 	ft::map<int ,int> origin1;

// 	origin1.insert(ft::pair<int, int>(1, 2));
// 	origin1.insert(ft::pair<int, int>(2, 3));
// 	origin1.insert(ft::pair<int, int>(3, 4));
// 	origin1.insert(ft::pair<int, int>(10, 4));

// 	ft::map<int, int>::iterator o1 = origin1.begin();
// 	origin1.insert(origin1.begin()++, ft::pair<int, int>(11, 5));
// 	for (; o1 != origin1.end(); o1++)
// 		std::cout<< o1->first << std::endl;
// }

// void erase_test() {
// 	std::map<int ,int> origin;

// 	origin.insert(std::pair<int, int>(1, 2));
// 	origin.insert(std::pair<int, int>(2, 3));
// 	origin.insert(std::pair<int, int>(3, 4));
// 	origin.insert(std::pair<int, int>(10, 4));

// 	ft::map<int ,int> origin1;

// 	origin1.insert(ft::pair<int, int>(1, 2));
// 	origin1.insert(ft::pair<int, int>(2, 3));
// 	origin1.insert(ft::pair<int, int>(3, 4));
// 	origin1.insert(ft::pair<int, int>(10, 4));
// 	ft::map<int, int>::iterator it = origin1.begin();
// 	origin1.erase(it);
// }

// void find_test() {
// 	std::map<int ,int> origin;

// 	origin.insert(std::pair<int, int>(1, 2));
// 	origin.insert(std::pair<int, int>(2, 3));
// 	origin.insert(std::pair<int, int>(3, 4));
// 	origin.insert(std::pair<int, int>(10, 4));
// 	std::map<int, int>::iterator it = origin.find(10);

// 	std::cout << it->first << std::endl;

// 	ft::map<int ,int> origin1;

// 	origin1.insert(ft::pair<int, int>(1, 2));
// 	origin1.insert(ft::pair<int, int>(2, 3));
// 	origin1.insert(ft::pair<int, int>(3, 4));
// 	origin1.insert(ft::pair<int, int>(10, 4));
// 	ft::map<int, int>::iterator t = origin1.find(10);
// 	std::cout << t->first << std::endl;
// }

// void lower_upper_bound_test() {
// 	std::map<int ,int> origin;

// 	origin.insert(std::pair<int, int>(1, 2));
// 	origin.insert(std::pair<int, int>(2, 3));
// 	origin.insert(std::pair<int, int>(3, 4));
// 	origin.insert(std::pair<int, int>(10, 4));
// 	origin.insert(std::pair<int, int>(100, 4));

// 	std::map<int, int>::iterator it = origin.lower_bound(4);
// 	std::cout << "std->lower = " << it->first << std::endl;
// 	std::cout << "std->upper = " << origin.upper_bound(11)->first << std::endl;
// 	std::cout << "=======================\n";

// 	ft::map<int ,int> origin1;
// 	origin1.insert(ft::pair<int, int>(1, 2));
// 	origin1.insert(ft::pair<int, int>(2, 3));
// 	origin1.insert(ft::pair<int, int>(3, 4));
// 	origin1.insert(ft::pair<int, int>(10, 4));
// 	origin1.insert(ft::pair<int, int>(100, 4));
// 	ft::map<int, int>::iterator t = origin1.lower_bound(4);
// 	std::cout << "ft->lower = " << t->first << std::endl;
// 	std::cout << "ft->upper = " << origin1.upper_bound(11)->first << std::endl;
// 	std::cout << "=======================\n";
// }

#include <map>
#include <iostream>
#include "map.hpp"
// #include <typeinfo>
// #include <future>
// #include <functional>
// #include <thread>

#define NS ft

// void print_map(NS::map<int, int> m) {
// 	NS::for_each(m.begin(), m.end(), [](NS::map<int, int>::const_iterator it) {
// 		std::cout << it->first << std::endl;
// 	});
// }

// void print_int(std::future<int>& fut) {
// 	int x = fut.get();
// 	std::cout << "val of x: " << x << std::endl;
// }

int main() {
	NS::map<int, int> m;
	m[100] = 1;
	m[140] = 6;
	m[90] = 7;
	m[120] = 8;
	m[101] = -8;
	m[130] = 9;
	m[150] = 9;
	m[132] = 9;
	m[160] = 9;
	m[170] = 9;
	m[165] = 9;
	m[169] = 9;
	m[180] = 9;

	m.erase(170);
	m.__print_map();
	std::cout << "=====================\n";
	std::cout << m.size() << std::endl;
	// NS::map<int, int>::iterator it = m.begin();
	// for (; it != m.end(); it++)
	// 	std::cout << it->first << std::endl;
	// std::promise< int > prom;
	// std::future< int > fut = prom.get_future();
	// // std::thread th1 (print_map, std::ref(m));
	// std::thread th1 (print_int, std::ref(fut));
	// prom.set_value(10);
	// th1.join();
	// return 0;
}