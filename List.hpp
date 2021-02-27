/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:53:57 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/02/27 17:50:26 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "Node.hpp"
#include "Allocator.hpp"
# include "ReverseIterator.hpp"

namespace ft {
	template <typename List>
	class ListIterator {
		public:
			// typedef typename List::value_type	value_type;
			typedef typename List::node_type*	pointer_type;
			typedef typename List::value_type&	reference_type;
			ListIterator( void ) : _ptr(nullptr) {}
			ListIterator(pointer_type ptr) : _ptr(ptr) {}
			ListIterator( ListIterator const & rhs ) : _ptr(rhs._ptr) {}
			reference_type operator*() {
				return _ptr->_data;
			}
		private:
			pointer_type	_ptr;
	};

	template<class T, class Alloc = ft::Allocator<T> >
	class List {
		public:
			typedef T value_type;
			typedef T &reference;
			typedef T const &const_reference;
			typedef T *pointer;
			typedef const T *const_pointer;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef Node<value_type> node_type;
			typedef ListIterator< List<T> > iterator;
		private:
			node_type*	_head;
			node_type*	_tail;
			size_type	_size;
		public:
			List<T>( void ) : _size(0) {
				_head = new Node<T>();
				_tail = new Node<T>();
			}
			List<T>( T const & data ) {
				_head = new Node<T>(data);
				_tail = new Node<T>(data);
			}
			List<T>( List<T> const & src );
			List<T> & operator=( List<T> const & src );
			~List<T>( void ) {
				return ;
			}
			iterator begin() {
				return iterator(_head);
			}
			iterator end() {
				return iterator(_tail);
			}

			// void	push_back(const value_type& val) {
			// 	node_type*	new_node = new Node<T>(val);
			// 	_tail->insert(new_node);
			// 	if (_size++ == 0)
			// 		_head = new_node;
			// }
	};
}

#endif