/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:34:27 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/05/06 16:34:30 by aaqlzim          ###   ########.fr       */
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
			Node(void) {
				_data = 0;
				_prev = nullptr;
				_next = nullptr;
			}
			Node(T data): _prev(nullptr), _next(nullptr) {
				_data = data;
			}
			Node(T const & data, Node<T>* prev, Node<T>* next): _data(data), _prev(prev), _next(next) {}
			Node( Node<T> const & rhs ) {
				_prev = _next = new Node<T>();
				while (rhs)
				{
					_prev->insert(rhs);
					rhs = rhs->_prev;
				}
			}
			Node & operator=( Node<T> const & src ) {
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
			void	push_back(Node<T>* node) {
				
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
			void	swap(Node<T> *node) {
				// 0 -> 4 -> 3 -> 2 -> 1
				if (this->_next == node) {
					std::cout << "next\n";
				}
				else if (this->_prev == node) {
					std::cout << "prev\n";
					if (node->_prev)
						node->_prev->_next = this;
					this->_prev = node->_prev;
					node->_prev = this;
					// if ()
					this->_next = node;
					node->_next = this->_next;
				}
				else {
					// 1 2 3 this, 6 1
					// 4 5 6 node, 6 3
					Node<T>* tmpprev = this->_prev;
					Node<T>* tmpnext = this->_next;
					if (this->_prev)
						this->_prev->_next = node;
					if (this->_next)
						this->_next->_prev = node;
					this->_prev = node->_prev;
					
					this->_next = node->_next;
					if (node->_prev)
						node->_prev->_next = this;
					if (node->_next)
						node->_next->_prev = this;
					node->_prev = tmpprev;
					node->_next = tmpnext;
				}
			}
			// void swap(Node<T> *toswap)
			// {
			// 	if (this->_next == toswap)
			// 	{
			// 		std::cout << "next\n";
			// 		if (this->_prev)
			// 			this->_prev->_next = toswap;
			// 		toswap->_prev = this->_prev;
			// 		this->_prev = toswap;
			// 		if (toswap->_next)
			// 			toswap->_next->_prev = this;
			// 		this->_next = toswap->_next;
			// 		toswap->_next = this;
			// 	}
			// 	else if (this->_prev == toswap)
			// 	{
			// 		std::cout << "prev\n";
			// 		if (toswap->_prev)
			// 			toswap->_prev->_next = this;
			// 		this->_prev = toswap->_prev;
			// 		toswap->_prev = this;
			// 		if (this->_next)
			// 			this->_next->_prev = toswap;
			// 		toswap->_next = this->_next;
			// 		this->_next = toswap;
			// 	}
			// 	else
			// 	{
			// 		Node<T> *tprevious = this->_prev;
			// 		Node<T> *tnext = this->_next;
			// 		if (this->_prev)
			// 			this->_prev->_next = toswap;
			// 		if (this->_next)
			// 			this->_next->_prev = toswap;
			// 		this->_prev = toswap->_prev;
			// 		this->_next = toswap->_next;

			// 		if (toswap->_prev)
			// 			toswap->_prev->_next = this;
			// 		if (toswap->_next)
			// 			toswap->_next->_prev = this;
			// 		toswap->_prev = tprevious;
			// 		toswap->_next = tnext;
			// 	}
			// }
	};
}

#endif