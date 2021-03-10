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
	// std::vector<int , ft::Allocator<int> > v;
	// v.push_back(1);
	// v.push_back(2);
	// v.push_back(3);
	// v.push_back(4);
	// v.push_back(5);
	// v.push_back(6);
	// std::cout << v.get_allocator().get_allocator() << std::endl;
	// std::vector<int, ft::Allocator<int> >::iterator it;
	// for (it = v.begin(); it != v.end(); it++)
	// 	std::cout << *it << std::endl;
	// ft::Node<int> *node = new ft::Node<int>(5);
	// ft::Node<int> *node1 = new ft::Node<int>(6);
	// ft::Node<int> *node2 = new ft::Node<int>(7);
	// node->insert(&node, node1);
	// node->insert(node1);
	// node->insert(node2);
	// node->insert(&node, node2);
	// std::cout << node->_data << std::endl;
	// std::cout << node->_prev->_prev->_data << std::endl;
	// std::cout << node->_prev->_data << std::endl;
	// std::cout << node->_next->_next->_data << std::endl;
	// std::cout << node->getData() << std::endl;

	ft::List<int>::iterator it;
	ft::List<int> l = ft::List<int>();
	l.push_back(6);
	l.push_back(7);
	l.push_back(9);
	l.push_back(123);
	for (it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << l.max_size() << std::endl;
	std::cout << l.front() << std::endl;
	std::cout << l.back() << std::endl;
	std::cout << "\n=================\n\n";
	std::list<int>::iterator t;
	std::list<int> lst = std::list<int>();
	lst.push_back(6);
	lst.push_back(7);
	lst.push_back(9);
	lst.push_back(123);
	//std::cout << *it << std::endl;
	for (t = lst.begin(); t != lst.end(); ++t) {
		std::cout << *t << std::endl;
	}
	std::cout << lst.max_size() << std::endl;
	std::cout << lst.front() << std::endl;
	std::cout << lst.back() << std::endl;
	// ::testing::InitGoogleTest(&argc, argv);
 	//return RUN_ALL_TESTS();
	// std::vector<int , Allocator<int> > v1;
	// v1.push_back(1);
	// v1.push_back(2);
	// v1.push_back(3);
	// v1.push_back(4);
	// for (auto & var: v1)
	// 	std::cout << var << std::endl;

	// std::getchar();
	return 0;
}