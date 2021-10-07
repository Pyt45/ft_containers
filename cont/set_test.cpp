#include "Set.hpp"
#include <set>

void insert_test() {
	ft::set<int> mine;
	std::set<int> origin;

	// origin.insert(1);
	// origin.insert(2);
	// origin.insert(3);
	// origin.insert(4);
	// std::set<int>::iterator it = origin.begin();
	// for (; it != origin.end(); it++)
	// 	std::cout << *(it) << std::endl;
	mine.insert(1);
	mine.insert(2);
	mine.insert(3);
	mine.insert(4);
	ft::set<int>::iterator t = mine.begin();
	// size_t c = mine.count(1);
	// std::cout << *t << std::endl;
	for (; t != mine.end(); t++)
		std::cout << *t << std::endl;
}

int main() {
	insert_test();
}