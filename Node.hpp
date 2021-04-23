/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:34:27 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/23 14:10:44 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>
# include <limits>
# include <cstdlib>

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
			}

			void	insert(Node<T>* node) {
				node->_next = this;
				node->_prev = this->_prev;
				if (this->_prev)
					this->_prev->_next = node;
				this->_prev = node;
				return ;
			}
			void	insert_front(Node<T>* node) {
				node->_next = this;
				if (this->_prev)
					node->_prev = this->_prev;
				if (this->_prev)
					this->_prev->_next = node;
				this->_prev = node;
			}
			Node<T>* erase() {
				Node<T>* node = this->_next;
				// delete this->_prev;
				/*if (this->_prev)
					this->_prev = this->_prev->_prev;
				this->_prev->_next = this;*/
				if (this->_prev)
					this->_prev->_next = this->_next;
				if (this->_next)
					this->_next->_prev = this->_prev;
				delete this;
				return node;
			}
			void	erase(Node<T> **root, Node<T>* del) {
				// this->_next = node->_next;
				// this->_next->_prev = node->_prev;
				if ((*root) == del)
					*root = del->_next;
				if (del->_next)
					del->_next->_prev = del->_prev;
				if (del->_prev)
					del->_prev->_next = del->_next;
				delete del;
			}
			void	erase(Node<T>* del) {
				// this->_prev = NULL;
				if (this->_prev == del)
				{
					this->_prev = NULL;
					del->_next = NULL;
					delete del;
				}
			}
			// void	swap(Node<T>& node);
	};
}

#endif