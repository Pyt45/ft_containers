#include <map>
#include "Map.hpp"

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

int main() {
	// lower_upper_bound_test();
	// find_test();
	// std::cout << "======================= erase test           =======================\n";
	// erase_test();
	// std::cout << "======================= range insertion test =======================\n";
	// insert_range_test();
	// std::cout << "=======================       insertion test =======================\n";
	// insert_test();
	// std::cout << "====================== insertion at pos test =======================\n";
	// insert_at_position();
	ft::map<int, int> m;
	m[0] = 1;
	m[2] = 2;
	m[3] = 3;

	ft::map<int, int>::iterator cit = m.begin();
	ft::map<int, int>::iterator ite = m.end();
	while (cit != ite) {
		std::cout << cit->first << " " << cit->second << std::endl;
		cit++;
	}
}