#include "set.hpp"
#include <set>

// void insert_test() {
// 	ft::set<int> mine;
// 	std::set<int> origin;

// 	// origin.insert(1);
// 	// origin.insert(2);
// 	// origin.insert(3);
// 	// origin.insert(4);
// 	// std::set<int>::iterator it = origin.begin();
// 	// for (; it != origin.end(); it++)
// 	// 	std::cout << *(it) << std::endl;
// 	mine.insert(1);
// 	mine.insert(2);
// 	mine.insert(3);
// 	mine.insert(4);
// 	ft::set<int>::iterator t = mine.begin();
// 	// size_t c = mine.count(1);
// 	// std::cout << *t << std::endl;
// 	for (; t != mine.end(); t++)
// 		std::cout << *t << std::endl;
// }

// void lower_upper_bound_test() {
// 	std::set<int> s;
// 	ft::set<int> s1;

// 	s.insert(1);
// 	s.insert(2);
// 	// s.insert(3);
// 	s.insert(4);

// 	s1.insert(1);
// 	s1.insert(2);
// 	// s1.insert(3);
// 	s1.insert(4);

// 	std::cout << "ft->set.lower = " << *s1.lower_bound(3) << std::endl;
// 	std::cout << "ft->set.upper = " << *s1.upper_bound(4) << std::endl;
// 	std::cout << "============================\n";
// 	std::cout << "std->set.lower = " << *s.lower_bound(3) << std::endl;
// 	std::cout << "std->set.upper = " << *s.upper_bound(4) << std::endl;
// }

// void equal_range_test() {
// 	std::set<int> myset;

// 	myset.insert(1);
// 	myset.insert(2);
// 	myset.insert(5);
// 	myset.insert(6);

// 	std::pair<std::set<int>::const_iterator,std::set<int>::const_iterator> ret;
// 	ret = myset.equal_range(4);

// 	std::cout << "the lower bound points to: " << *ret.first << '\n';
// 	std::cout << "the upper bound points to: " << *ret.second << '\n';
// 	std::cout << "===============================\n";
// 	ft::set<int> ftset;

// 	ftset.insert(1);
// 	ftset.insert(2);
// 	ftset.insert(5);
// 	ftset.insert(6);

// 	ft::pair<ft::set<int>::iterator,ft::set<int>::iterator> t;
// 	t = ftset.equal_range(4);

// 	std::cout << "the lower bound points to: " << *t.first << '\n';
// 	std::cout << "the upper bound points to: " << *t.second << '\n';
// }

#define NS ft

int main() {
	// insert_test();
	// lower_upper_bound_test();
	// equal_range_test();
	NS::set<int> s;

	s.insert(100);
	s.insert(140);
	s.insert(90);
	s.insert(120);
	s.insert(101);
	s.insert(130);
	s.insert(150);
	s.insert(132);
	s.insert(160);
	s.insert(170);
	s.insert(165);
	s.insert(169);
	s.insert(180);
	NS::set<int>::iterator it = s.begin();
	NS::set<int>::const_iterator t = s.end();
	for (; it != t; it++)
		std::cout << *it << std::endl;
	std::cout << "===============\n";
	s.__print_set();
}