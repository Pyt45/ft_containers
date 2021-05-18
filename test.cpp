#include <vector>
#include <iostream>
#include <map>


int main()
{
	std::map<int, int> m {
		{1, 5},
		{2, 9},
		{3, 7}
	};

	std::cout << m[12] << std::endl;
}