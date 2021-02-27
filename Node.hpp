/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:34:27 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/02/27 12:16:10 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>

namespace ft
{
	template<typename T>
	class Node {
		public:
			T		_data;
			Node	*_prev;
			Node	*_next;
			Node<T>(void) {
				_data = 0;
				_prev = nullptr;
				_next = nullptr;
			}
			Node<T>(T data): _prev(nullptr), _next(nullptr) {
				_data = data;
			}
			Node<T>(T const & data, Node<T>* prev, Node<T>* next): _data(data), _prev(prev), _next(next) {}
			Node<T>( Node<T> const & src ) {
				*this = src;
			}
			Node<T> & operator=( Node<T> const & src ) {
				if (this != &src)
				{
					this->_data = src._data;
					this->_prev = src._prev;
					this->_next = src._next;
				}
				return *this;
			}
			~Node<T>(void) {
				delete _prev;
				delete _next;
			}
			void	insert(Node<T>* node) {
				node->_prev = this->_prev;
				node->_next = this;
				if (this->_prev)
					this->_prev->_next = node;
				this->_prev = node;
				return ;
			}

			// void	insert(Node<T>** head_ref, Node<T>* node) {
			// 	Node<T>*	last = *head_ref;
			// 	if (*head_ref == NULL)
			// 	{
			// 		node->_prev = NULL;
			// 		*head_ref = node;
			// 		return ;
			// 	}
			// 	while (last->_next)
			// 		last = last->_next;
			// 	last->_next = node;
			// 	node->_prev = last;
			// 	return ;
			// }
			// void	erase();
			// void	swap(Node<T>& node);
	};
}

#endif