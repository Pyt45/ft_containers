#include "Node.hpp"
#include "List.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
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


int		main()
{
	ft::List<int>::iterator it;
	ft::List<int> l;
	ft::List<int> l1;
	// std::list<int> l1;
	l.push_front(6);
	l.push_front(7);
	l.push_front(9);
	l.push_front(12);
	l.push_front(19);
	// l1
	l1.push_back(10);
	l1.push_back(13);
	l1.push_back(15);
	// l1.push_back(19);
	// l1.push_back(20);
	// l1.push_back(1005);
	for (it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << std::endl;
	}
	ft::List<int>::iterator t = l.begin();
	// ++t;
	// cit = l.begin();
	std::cout << "t = " << *t << std::endl;
	// std::cout << l.max_size() << std::endl;
	// std::cout << l.front() << std::endl;
	// std::cout << l.back() << std::endl;
	std::cout << "\n=================\n\n";
	l.insert(t, l1.begin(), l1.end());
	//int arr[] = {1, 2, 3, 4, 5};
	// l.assign(l1.begin(), l1.end());
	// l.pop_front();
	std::cout << l.size() << std::endl;
	for (it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "\n=================\n\n";
/*	std::list<int>::iterator ti;
	std::list<int> lst;
	// lst.assign(l1.begin(), l1.end());
	lst.push_back(6);
	lst.push_back(7);
	lst.push_back(9);
	lst.push_back(12);
	lst.push_back(19);
	// std::list<int>::const_iterator cit = lst.begin();
	// for (ti = lst.begin(); ti != lst.end(); ++ti) {
	//	std::cout << *ti << std::endl;
	// }
	ti = lst.begin();
	++ti;
	lst.insert(ti, 2, 105);
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
	std::for_each(lst.begin(), lst.end(), [](const int & e){
		std::cout << e << std::endl;
	});
	// std::cout << "\n=================\n\n";
	// f.assign(s.begin(), s.end());
	// std::for_each(lst.begin(), lst.end(), [](const int & e){
	// 	std::cout << e << std::endl;
	// });
	// std::cout << lst.max_size() << std::endl;
	// std::cout << lst.front() << std::endl;
	// std::cout << lst.back() << std::endl;
	// ::testing::InitGoogleTest(&argc, argv);
 	//return RUN_ALL_TESTS();*/
	return 0;
}