/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:34:27 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/02/26 17:52:55 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>

namespace ft
{
	template<typename T>
	class Node {
		private:
			T		_data;
			Node	*_head;
			Node	*_tail;
		public:
			Node<T>(void) {
				_data = 0;
				_tail = nullptr;
				_head = nullptr;
			}
			Node<T>(T data): _tail(nullptr), _head(nullptr) {
				_data = data;
			}
			Node<T>(T const & data, Node<T>* prev, Node<T>* next): _data(data), _tail(prev), _head(next) {}
			Node<T>( Node<T> const & src ) {
				*this = src;
			}
			Node<T> & operator=( Node<T> const & src ) {
				if (this != &src)
				{
					this->_data = src._data;
					this->_tail = src._tail;
					this->_head = src._head;
				}
				return *this;
			}
			~Node<T>(void) {
				delete _tail;
				delete _head;
			}
			// just for testing
			T const & getData(void) const {
				return this->_data;
			}
			// void	insert(Node<T>* node);
			// void	erase();
			// void	swap(Node<T>& node);
	};
}

#endif