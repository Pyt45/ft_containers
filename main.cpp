#include "Node.hpp"
#include "List.hpp"
#include <vector>
#include <iostream>
#include <list>
#include <memory>
#include "Allocator.hpp"
// #include <gtest/gtest.h>

// template<typename type>
// struct Allocator : std::allocator<type> {
// 	// public:
// 	// 	Allocator<type>( void ) {}
// 	type * allocate(size_t size) {
// 		std::cout << "Allocation request size => " << size << std::endl;
// 		return new type[size];
// 	}
// 	void	deallocate(type * ptr, size_t size) {
// 		std::cout << "Deallocate size => " << size << std::endl;
// 		delete [] ptr;
// 	}
// };

// namespace ft {
// 	template<typename type>
// 	class Allocator {
// 		public:
// 			typedef T value_type
// 			Allocator( void );
// 			~Allocator( void );
// 	};
// };
/*
TEST(module_name, test_name) {
	std::cout << "Hello world!" << std::endl;
	// Google Test will also provide macros for assertions.
	ASSERT_EQ(1+1, 2);
}
*/

int		main(int argc, char **argv)
{

	ft::List<int>::iterator it;
	ft::List<int> l = ft::List<int>();
	l.push_front(6);
	l.push_front(7);
	l.push_front(9);
	l.push_front(12);
	l.push_front(19);
	for (it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << std::endl;
	}
	// ft::List<int>::const_iterator cit = l.begin();

	// cit = l.begin();
	// std::cout << *cit << std::endl;
	// std::cout << l.max_size() << std::endl;
	// std::cout << l.front() << std::endl;
	// std::cout << l.back() << std::endl;
	std::cout << "\n=================\n\n";
	l.pop_back();

	for (it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << std::endl;
	}
	// std::list<int>::iterator t;
	// std::list<int> lst = std::list<int>();
	// lst.push_back(6);
	// lst.push_back(7);
	// lst.push_back(9);
	// lst.push_back(12);
	// lst.push_back(19);
	// std::list<int>::const_iterator cit = lst.begin();
	// for (t = lst.begin(); t != lst.end(); ++t) {
	// 	std::cout << *t << std::endl;
	// }
	// std::cout << *cit << std::endl;
	// std::list<int> f;
	// std::list<int> s;

	// f.assign(7, 100);
	// s.assign(5, 50);
	// f.push_front(1);
	// f.push_front(2);
	// f.push_front(3);
	// f.push_front(4);
	// f.push_front(5);
	// std::for_each(f.begin(), f.end(), [](const int & e){
	// 	std::cout << e << std::endl;
	// });
	// std::cout << "\n=================\n\n";
	// f.assign(s.begin(), s.end());
	// std::for_each(f.begin(), f.end(), [](const int & e){
	// 	std::cout << e << std::endl;
	// });
	// std::cout << lst.max_size() << std::endl;
	// std::cout << lst.front() << std::endl;
	// std::cout << lst.back() << std::endl;
	// ::testing::InitGoogleTest(&argc, argv);
 	//return RUN_ALL_TESTS();
	// ft::Node<int>* node = new ft::Node<int>(1);
	// ft::Node<int>* node1 = new ft::Node<int>(2);
	// ft::Node<int>* node2 = new ft::Node<int>(3);
	// ft::Node<int>* node3 = new ft::Node<int>(4);
	// node->insert(node1);
	// node->insert(node2);
// 
	// std::cout << node->_data << std::endl;
	// std::cout << node->_prev->_data << std::endl;
	// std::cout << node->_prev->_prev->_data << std::endl;
	return 0;
}