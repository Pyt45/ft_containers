#include "Node.hpp"
// #include "List.hpp"
#include <vector>
#include <iostream>

template<typename type>
struct Allocator : std::allocator<type> {
	// public:
	// 	Allocator<type>( void ) {}
	type * allocate(size_t size) {
		std::cout << "Allocation request size => " << size << std::endl;
		return new type[size];
	}
	void	deallocate(type * ptr, size_t size) {
		std::cout << "Deallocate size => " << size << std::endl;
		delete [] ptr;
	}
};

int		main()
{
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

	//ft::List<int> *l = new ft::List<int>(5);
	//ft::List<int>::iterator it = l->begin();
	//std::cout << *it << std::endl;
	std::vector<int , Allocator<int> > v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	for (auto & var: v1)
		std::cout << var << std::endl;

	std::getchar();
	return 0;
}