#include <vector>
#include <iostream>
#include "Vector.hpp"


int main()
{
	std::vector<int> v;

	std::cout << "size = " << v.size() << std::endl;
	std::cout << "cap = " << v.capacity() << std::endl;
}