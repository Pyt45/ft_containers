#include "Node.hpp"
#include "BTree.hpp"
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
// namespace ft{
// 	template<class T1, class T2>
// 	struct pair;
// }

void	test_erase()
{
	// l1
	std::list<int> l1;
	l1.push_back(10);
	l1.push_back(13);
	l1.push_back(15);
	l1.push_back(19);
	l1.push_back(20);
	l1.push_back(1005);
	std::list<int>::iterator l1t;
	for (l1t = l1.begin(); l1t != l1.end(); ++l1t) {
		std::cout << *l1t << std::endl;
	}
	std::cout << "\n=================\n\n";
	l1t = l1.begin();
	std::list<int>::iterator l1er = l1t;
	l1er++;
	l1er++;
	std::cout << "last = " << *l1er << std::endl;
	std::list<int>::iterator r = l1.erase(l1t, l1er);
	std::cout << "r = " << *r << std::endl;
	std::cout << "\n=================\n\n";
	for (l1t = l1.begin(); l1t != l1.end(); ++l1t) {
		std::cout << *l1t << std::endl;
	}
	std::cout << "\n=================\n\n";
	// l
	ft::List<int> l;
	l.push_front(6);
	l.push_front(7);
	l.push_front(9);
	l.push_front(12);
	l.push_front(19);
	ft::List<int>::iterator it;
	for (it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "\n=================\n\n";
	std::cout << l.size() << std::endl;
	it = l.begin();
	ft::List<int>::iterator er = it;
	er++;
	er++;
	std::cout << "last = " << *er << std::endl;
	// l.erase(it);
	// it++;;
	// l.erase(it);
	// it++;;
	// l.erase(it);
	ft::List<int>::iterator lr = l.erase(it, er);
	std::cout << "lr = " << *lr << std::endl;
	std::cout << "\n=================\n\n";
	std::cout << "size = " << l.size() << std::endl;
	for (it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << std::endl;
	}
}

void	mix_test(void)
{
	// std::pair<int ,int> foo;
	// foo = std::make_pair(10, 20);
	// std::cout << foo.first << std::endl;
	// std::cout << foo.second << std::endl;

	// Btree<std::string> b;
	// b.insert("hi");
	// b.insert("hello");
	// b.insert("print");
	// b.insert("take");
	// b.printTree();
	
	// t++;
	// std::cout << *t << std::endl;
	// ft::List<int>::iterator e = l.erase(t);
	// std::cout << *e << std::endl;
	// std::cout << "\n\n\n";
	// for (it = l.begin(); it != l.end(); ++it) {
	// 	std::cout << *it << std::endl;
	// }
	// std::list<int>::iterator t = l1.begin();
	// std::list<int>::iterator e = l1.erase(t);
	// std::cout << "f = " << *e << std::endl;
	// for (t = l1.begin(); t != l1.end(); ++t) {
	// 	std::cout << *t << std::endl;
	// }
	// ++t;
	// cit = l.begin();
	// std::cout << "t = " << *t << std::endl;
	// std::cout << l.max_size() << std::endl;
	// std::cout << l.front() << std::endl;
	// std::cout << l.back() << std::endl;
	// l.insert(t, l1.begin(), l1.end());
	//int arr[] = {1, 2, 3, 4, 5};
	// l.assign(l1.begin(), l1.end());
	// l.pop_front();
	// std::cout << l.size() << std::endl;
	// for (it = l.begin(); it != l.end(); ++it) {
	// 	std::cout << *it << std::endl;
	// }
	// std::cout << "\n=================\n\n";
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
}

void	test_swap(void)
{
	std::list<int> first(3, 100);
	std::list<int> second(5, 200);

	first.swap(second);
	for (std::list<int>::iterator it = first.begin(); it != first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "=====================\n";
	for (std::list<int>::iterator t = second.begin(); t != second.end(); t++)
		std::cout << ' ' << *t;
	std::cout << std::endl;
	ft::List<int> l;
	ft::List<int> l1;

	l.push_back(1);
	l.push_back(2);

	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);

	if (l == l1)
		std::cout << "Yep\n";
}

int		main()
{
	// test_erase();
	// mix_test();
	test_swap();
	return 0;
}