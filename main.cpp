#include "Node.hpp"
#include "BTree.hpp"
#include "List.hpp"
#include "Stack.hpp"
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
	l.push_back(10);
	l.push_back(13);
	l.push_back(15);
	l.push_back(19);
	l.push_back(20);
	l.push_back(1005);
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
	// std::list<int> first(3, 100);
	// std::list<int> second(5, 200);

	// first.swap(second);
	// for (std::list<int>::iterator it = first.begin(); it != first.end(); it++)
	// 	std::cout << ' ' << *it;
	// std::cout << std::endl;
	// std::cout << "=====================\n";
	// for (std::list<int>::iterator t = second.begin(); t != second.end(); t++)
	// 	std::cout << ' ' << *t;
	// std::cout << std::endl;
	ft::List<int> l;
	ft::List<int> l1;

	l.push_back(1);
	l.push_back(2);
	std::cout << "size of l = " << l.size() << std::endl;

	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	std::cout << "size of l1 = " << l1.size() << std::endl;
	l1.swap(l);
	std::cout << "after swap" << std::endl;
	std::cout << "l = " << l.size() << " l1 = " << l1.size()
	<< std::endl;
	for (ft::List<int>::iterator it = l1.begin(); it != l1.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "=================\n";
	for (ft::List<int>::iterator it = l.begin(); it != l.end(); it++)
			std::cout << *it << std::endl;
	// if (l < l1)
	// 	std::cout << "Yep\n";
}

bool is_small_than_2(int i) {
	if (i <= 2)
		return true;
	return false;
}

bool equal_test(double i, double j)
{
	return ((int)i < (int)j);
}

void	Operations_test()
{
	ft::List<int> l;
	ft::List<int> l1;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(-1);
	l.push_back(9);
	ft::List<int>::iterator it = l.begin();
	l1.push_back(8);
	l1.push_back(9);
	/*ft::List<int>::iterator e = l1.end();
	e--;
	l.splice(it, l1, l1.begin(), e);*/
	l.remove_if(is_small_than_2);
	for (ft::List<int>::iterator t = l.begin(); t != l.end(); t++)
		std::cout << *t << std::endl;
	std::cout << "size of l1 = " << l1.size() << std::endl;

	std::cout << "===================\n";

	ft::List<int> sl;
	ft::List<int> s;

	sl.push_back(1);
	//l.push_back(1);
	sl.push_back(9);
	sl.push_back(2);
	// sl.push_back(1);
	sl.push_back(5);
	//sl.push_back(5);
	sl.push_back(6);

	s.push_back(3);
	s.push_back(8);
	s.push_back(-1);

	// sl.unique(equal_test);
	// sl.reverse();
	// sl.merge(s, equal_test);
	sl.sort();
	std::cout << "size s = " << sl.size() << std::endl;
	for (ft::List<int>::iterator it = sl.begin(); it != sl.end(); it++)
		std::cout << *it << std::endl;
}

void	test_node()
{
	ft::Node<int> *node = new ft::Node<int>(0);
	ft::Node<int> *n1 = new ft::Node<int>(1);
	ft::Node<int> *n2 = new ft::Node<int>(2);
	ft::Node<int> *n3 = new ft::Node<int>(3);
	ft::Node<int> *n4 = new ft::Node<int>(4);

	ft::Node<int> *nd = new ft::Node<int>(9);
	ft::Node<int> *n = new ft::Node<int>(6);
	ft::Node<int> *n5 = new ft::Node<int>(3);
	ft::Node<int> *n6 = new ft::Node<int>(10);
	ft::Node<int> *n7 = new ft::Node<int>(7);
	nd->insert(n);
	nd->insert(n5);
	nd->insert(n6);
	nd->insert(n7);

	node->insert(n1);
	node->insert(n2);
	node->insert(n3);
	node->insert(n4);
	std::cout << "node->_prev->data : " << node->_prev->_data << std::endl;
	node->swap(node->_prev);

	while (node)
	{
		std::cout << node->_data << std::endl;
		node = node->_prev;
	}
	std::cout << "=============\n";
	while (nd)
	{
		std::cout << nd->_data << std::endl;
		nd = nd->_prev;
	}
	
}

int		main()
{
	// std::list<int> l;
	// l.push_back(1);
	// l.push_back(2);
	// l.push_back(3);
	// l.push_back(4);
	// l.push_back(5);
	// for (std::list<int>::iterator t = l.begin(); t != l.end(); t++)
	// 	std::cout << *t << ' ';
	// std::cout << "\n========\n";
	// std::list<int>::reverse_iterator it = l.rbegin();
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;

	ft::List<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	// for (ft::List<int>::reverse_iterator t = l.rbegin(); t != l.rend(); t++)
	//	std::cout << *t << ' ';
	std::cout << "\n========\n";
	ft::List<int>::reverse_iterator it = l.rend();
	// ft::List<int>::reverse_iterator t = l.rbegin();
	std::cout << *it << std::endl;
	// --it;
	// std::cout << *it << std::endl;
	// test_node();
	// Operations_test();
	// test_erase();
	// mix_test();
	// test_swap();
	// ft::List<int> l;
	// l.push_back(100);
	// l.push_back(10);
	// l.push_back(32);
	// ft::List<int>::iterator t = l.begin();
	// l.erase(t);
	// t++;
	// ft::List<int>::iterator r = l.erase(t);
	// std::cout << *r << std::endl;
	// t++;
	// std::cout << *t << std::endl;
	// ft::List<int>::iterator e = l.erase(t);
	// std::cout << *e << std::endl;
	// xz 
	// node->insert_front(node2);
	// node->insert_front(node3);
	// node->erase(node1);
	// while (node)
	// {
	// 	std::cout << node->_data << std::endl;
	// 	node = node->_prev;
	// }
	/*ft::List<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	for (ft::List<int>::iterator t = l.begin(); t != l.end(); t++)
		std::cout << *t << std::endl;
	std::cout << "============================\n";
	l.resize(7, 12);
	for (ft::List<int>::iterator t = l.begin(); t != l.end(); t++)
		std::cout << *t << std::endl;
	std::cout << "size = " << l.size() << std::endl;*/
	// ft::stack<int> s;
	// for (int i = 0; i < 5; i++)
	// 	s.push(i);
	
	// while (!s.empty())
	// {
	// 	std::cout << ' ' << s.top();
	// 	s.pop();
	// }
	// std::cout << std::endl;
	return 0;
}