#include <map>
#include "Map.hpp"

int main() {
	ft::map<int, int> m;
	std::map<int, int> m1;

	m1.insert(std::pair<int, int>(1, 2));
	m1.insert(std::pair<int, int>(2, 3));
	m1.insert(std::pair<int, int>(3, 4));

	m.insert(ft::pair<int, int>(1, 2));
	m.insert(ft::pair<int, int>(2, 3));
	m.insert(ft::pair<int, int>(3, 4));

	std::map<int, int>::iterator it1 = m1.begin();
	ft::map<int, int>::iterator it = m.begin();

	std::cout << m1[10] << std::endl;
	std::cout << m[10] << std::endl;
	std::cout << "====================\n";
	for (; it1 != m1.end(); it1++)
		std::cout << it1->first << std::endl;
	std::cout << "====================\n";
	for (; it != m.end(); it++) {
		std::cout << it->first << std::endl;
	}
}