#include "Node.hpp"
#include "List.hpp"

int		main()
{
	ft::Node<int> *node = new ft::Node<int>(5);
	ft::Node<int> *node1 = new ft::Node<int>(6);
	node->insert(node1);
	std::cout << node->_prev->_data << std::endl;
	// std::cout << node->getData() << std::endl;

	//ft::List<int> *l = new ft::List<int>(5);
	//ft::List<int>::iterator it = l->begin();
	//std::cout << *it << std::endl;
}