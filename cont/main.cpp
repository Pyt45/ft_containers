#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <memory>
#include <string>
#include <typeinfo>
#include <type_traits>
#include <iterator>
#include <stack>

#include "Vector.hpp"
#include "Utility.hpp"
#include "Type_traits.hpp"
// #include "Stack.hpp"
#include "Tree.hpp"
// #include "Btree.hpp"

// template <class T>
// typename ft::enable_if<ft::is_integral<T>::value, bool>::type is_odd(T i) { return bool(i % 2); }

// template <class T, class = typename ft::enable_if<ft::is_integral<T>::value>::type>
// bool is_even(T i) {return !bool(i%2);}

// void test()
// {
// 	short int i = 1;
// 	float b = 5;
// 	std::cout << std::boolalpha;
// 	std::cout << "is i odd: " << is_odd(i) << std::endl;
// 	std::cout << "is i even: " << is_even(i) << std::endl;
// }

template <class BidirIt>
void ft_reverse(BidirIt first, BidirIt last)
{
	typename ft::iterator_traits<BidirIt>::difference_type n = ft::distance(first, last);
	--n;
	while (n > 0)
	{
		typename ft::iterator_traits<BidirIt>::value_type tmp = *first;
		*first++ = *--last;
		*last = tmp;
		n -= 2;
	}
}
template <class Iter>
void ft_swap(Iter first, Iter second)
{
	typename ft::iterator_traits<Iter>::value_type tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

template < class Key, class T, class Compare = std::less< ft::pair<Key, T> > >
class Test {
	public:
		typedef Compare key_compare;
	public:
		Test() {
			ft::pair<int, int> p = ft::make_pair<int, int>(1, 2);
			ft::pair<int, int> p1 = ft::make_pair<int, int>(2, 3);

			// if (compare(p.first, p1.second))
			key_compare C = Compare();
			if (C(p, p1))
				std::cout << "* yeay *\n";
			else if (!C(p, p1))
				std::cout << "* NoNo *\n";
		}
};


void run_iter()
{
	std::vector<int> l;
	ft::vector<int> v;
	// int arr[] = {1,2,3,4,5};
	// l.assign(arr, arr + 5);

	// for (int i = 0; i < 5; i++)
	// 	std::cout << l[i] << std::endl;
	// std::cout << "=========================\n";
	// v.assign(arr, arr + 5);
	// for (int i = 0; i < 5; i++)
	// 	std::cout << v[i] << std::endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	l.push_back(1);
	l.push_back(2);
	// v.erase(v.begin());

	// for (int i = 0; i < 2; i++)
	// 	std::cout << v[i] << std::endl;
	// ft::vector<int>::iterator it = v.begin();
	ft::vector<int>::reverse_iterator rit = v.rbegin();
	for (; rit != v.rend(); rit++)
		std::cout << *rit << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// std::cout << "l.size = " << l.size() << std::endl;
	// std::cout << "l.cap = " << l.capacity() << std::endl;
	// std::cout << "v.size = " << v.size() << std::endl;
	// std::cout << "v.cap = " << v.capacity() << std::endl;
}

int main()
{
	ft::pair<int, int> p = ft::make_pair<int, int>(2, 1);
	ft::pair<int, int> p1 = ft::make_pair<int, int>(-3, 6);
	ft::pair<int, int> p2 = ft::make_pair<int, int>(-4, 7);
	ft::pair<int, int> p3 = ft::make_pair<int, int>(-6, 8);
	ft::pair<int, int> p4 = ft::make_pair<int, int>(6, -8);

	ft::Node< ft::pair<int, int> > n(p);
	ft::Node< ft::pair<int, int> > n1(p1);
	ft::Node< ft::pair<int, int> > n2(p2);
	ft::Node< ft::pair<int, int> > n3(p3);
	ft::Node< ft::pair<int, int> > n4(p4);

	ft::__red_black_tree<int, int> r;

	r.__insert(&n);
	r.__insert(&n1);
	r.__insert(&n2);
	// r.__insert(&n3);
	// r.__insert(&n4);
	r.__print_tree();
	std::cout << "========================\n";  
	/*std::map<int, int> m;
	std::pair<int, int> p1(5, 6);
	m.insert(p1);
	p1 = std::make_pair<int, int>(10, 5);
	m.insert(p1);
	p1 = std::make_pair<int, int>(3, 2);
	m.insert(p1);
	p1 = std::make_pair<int, int>(11, 9);
	m.insert(p1);

	std::map<int, int>::iterator it = m.begin();
	for (; it != m.end(); it++)
		std::cout << "f = " << it->first << " | s = " <<
		it->second << std::endl;
	*/
	// run_iter();
	// int t[] = {1, 2, 3, 4, 5};
	// for (int i = 0; i < 5; i++)
	// 	std::cout << t[i] << std::endl;
	// std::cout << "======================\n";
	// ft_reverse(t, t + 5);
	// for (int i = 0; i < 5; i++)
	// 	std::cout << t[i] << std::endl;
	// test();
	// ft::vector<int> v(5, 100);
	// ft::vector<int> f(3, 200);
	// ft::vector<int> v(5, 100);
	// std::vector<int> f(5, 100);

	// f.reserve(31);
	// v.reserve(31);

	// v.push_back(5);
	// f.push_back(5);
	// f.resize(11, 2);
	// v.resize(11, 2);
	// f.push_back(1);
	// v.push_back(1);
	// f.assign(10, 5);
	// v.assign(10, 5);

	// std::cout << "----------------------------------\n";
	// std::cout << "v.size = " << v.size() << std::endl;
	// std::cout << "v.cap = " << v.capacity() << std::endl;
	// std::cout << "----------------------------------\n";
	// std::cout << "f.size = " << f.size() << std::endl;
	// std::cout << "f.cap = " << f.capacity() << std::endl;
	// std::cout << "----------------------------------\n";
	// for (int i = 0; i < v.size(); i++)
	// 	std::cout << "v[" << i << "] = " << v[i] << std::endl;
	// std::cout << "===============\n";
	// for (int i = 0; i < f.size(); i++)
	// 	std::cout << "f[" << i << "] = " << f[i] << std::endl;
	// std::cout << "===============\n";
	// std::cout << "v.size = " << v.size() << std::endl;
	// std::cout << "f.size = " << f.size() << std::endl;
	// std::cout << "===============\n";
	// v = f;
	// for (int i = 0; i < 3; i++)
	// 	std::cout << "arr[" << i << "] = " << v[i] << std::endl;
	// std::cout << "===============\n";
	// f.clear();
	// std::cout << "f.size = " << f.size() << std::endl;
	// for (int i = 0; i < 3; i++)
	// 	std::cout << "arr[" << i << "] = " << f[i] << std::endl;

	// std::allocator<std::string> _alloc;
	// std::string *s = _alloc.allocate(3);
	// _alloc.construct(s, "a");
	// _alloc.construct(s + 1, "b");
	// _alloc.construct(s + 2, "c");

	// std::cout << "s[0] = " << s[0] << std::endl;
	// std::cout << "s[1] = " << s[1] << std::endl;
	// std::cout << "s[2] = " << s[2] << std::endl;
	// _alloc.destroy(s);
	// _alloc.deallocate(s, 3);
	// std::cout << "s[0] = " << s[0] << std::endl;
	// std::cout << "s[1] = " << s[1] << std::endl;
	// std::cout << "s[2] = " << s[2] << std::endl;
	// std::vector<int> v(3, 100);
	// for (size_t i = 0; i < 3; i++)
	// 	std::cout << v[i] << std::endl;
	// v.clear();
	// std::cout << "s = " << v.size() << std::endl;
	// for (size_t i = 0; i < 3; i++)
	// 	std::cout << v[i] << std::endl;
	// ft::pair<int, std::string> p;
	// p = ft::make_pair<int, std::string>(5, "a");
	// std::cout << p.first << std::endl;
	// std::cout << p.second << std::endl;
}
/*
		5b
	/		\
   3b		  7b
			   \
			     8r
				  \
				    12r
	    	8b
		3b
	
	2b      null || red
1b
*/
/*
	8r
7b		12b

	5b
3r		8r
	7b		12b
*/