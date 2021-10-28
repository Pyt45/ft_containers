// #include <iostream>
// #include "Vector.hpp"
// // #include <type_traits>
// #include <vector>

// #define ns ft

// template <class T>
// typename std::enable_if< !std::is_integral<T>::value, bool >::type is_odd(T x) {
//     return x[0] % 2;
// }

// template <class T>
// typename std::enable_if< std::is_integral<T>::value, bool >::type is_odd_(T y) {
//     return bool(y % 2);
// }

// int main() {
//     ns::vector<int> v;
//     v.push_back(100);
//     v.push_back(100);
//     v.push_back(100);
//     ns::vector<int> v1;
//     v1.push_back(200);
//     v1.push_back(200);
//     v1.push_back(200);
//     v1.push_back(200);

//     ns::vector<int>::iterator it = v.begin();
//     ns::vector<int>::iterator ite = v.end();
//     // for (; it != ite; it++)
//     //     std::cout << *it << std::endl;
//     v.swap(v1);
//     std::cout << "after wap\n";
//     for (; it != ite; it++)
//         std::cout << *it << std::endl;
//     std::cout << "================\n";
//     ns::vector<int>::iterator t = v.begin();
//     ns::vector<int>::iterator te = v.end();
//     for (; t != te; t++)
//         std::cout << *t << std::endl;
// }

#include <iostream>
#include <string>
#include <deque>

#define NS 1

#if NS //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ns = std;
#else
	#include "Map.hpp"
	#include "Vector.hpp"
    namespace ns = ft;
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	// ft::vector<std::string> vector_str;
	// ft::vector<int> vector_int;
	// ft::stack<int> stack_int;
	// ns::vector<int> vector_buffer;
	// ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
	ns::map<int, int> map_int;

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	vector_buffer.push_back(i);
	// }

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	const int idx = rand() % COUNT;
	// 	vector_buffer[idx] = 5;
	// }
    // for (int i = 0; i < COUNT; i++)
    //     std::cout << vector_buffer[i] << std::endl;
	// ft::vector<Buffer>().swap(vector_buffer);

	// try
	// {
	// 	for (int i = 0; i < COUNT; i++)
	// 	{
	// 		const int idx = rand() % COUNT;
	// 		vector_buffer.at(idx);
	// 		std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	//NORMAL ! :P
	// }
	
	for (int i = 0; i < COUNT; ++i)
		map_int.insert(ns::make_pair(rand(), rand()));
	
	std::cout << map_int.find(5096)->first << std::endl;
    // for (ns::map<int, int>::iterator it = map_int.begin(); it != map_int.end(); it++)
    //    std::cout << it->first << std::endl;
	// int sum = 0;
	// for (int i = 0; i < 10000; i++)
	// {
	// 	int access = rand();
	// 	sum += map_int[access];
	// }
	// std::cout << "should be constant with the same seed: " << sum << std::endl;

	// {
	// 	ft::map<int, int> copy = map_int;
	// }
	// MutantStack<char> iterable_stack;
	// for (char letter = 'a'; letter <= 'z'; letter++)
	// 	iterable_stack.push(letter);
	// for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	// {
	// 	std::cout << *it;
	// }
	// std::cout << std::endl;
	return (0);
}

// // 

// insert()