/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:53:57 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/03/10 23:56:06 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "Node.hpp"
# include "Allocator.hpp"
# include "ReverseIterator.hpp"

namespace ft {
	template <typename List>
	class ListIterator {
		public:
			typedef typename List::value_type	value_type;
			typedef typename List::node_type*	pointer_type;
			typedef typename List::value_type&	reference_type;
			ListIterator( void ) : _ptr(nullptr) {}
			ListIterator(pointer_type ptr) : _ptr(ptr) {}
			ListIterator( ListIterator const & rhs ) : _ptr(rhs._ptr) {}
			reference_type operator*() {
				return _ptr->_data;
			}
			bool	operator!=( ListIterator const & rhs ) const {
				return _ptr != rhs._ptr;
			}
			ListIterator& operator++() {
				_ptr = _ptr->_next;
				return *this;
			}
			ListIterator operator++(int) {
				ListIterator iter = *this;
				++(*this);				
				return iter;
			}
			ListIterator& operator=( ListIterator const & rhs ) {
				_ptr = rhs._ptr;
				return *this;
			}
		private:
			pointer_type	_ptr;
	};

	template<class T>
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
			List( void ) {
				_size = 0;
				_head = _tail = new Node<T>();
			}
			List( T const & data ) {
				_size = 0;
				_head = _tail = new Node<T>(data);
			}
			List( List<T> const & rhs ) {
				/*_size = 0;
				_head = _tail = new Node<T>();
				for (iterator it = rhs.begin(); it != rhs.end(); ++it)
					push_back(*it);*/
			};
			List & operator=( List<T> const & src );
			~List( void ) {
				return ;
			}
			// Iterators
			iterator begin() {
				return iterator(_head);
			}
			iterator end() {
				return iterator(_tail);
			}
			// Capacity
			bool	empty() const {
				return _size == 0;
			}
			size_type size() const {
				return _size;
			}
			size_type max_size() const {
				return std::numeric_limits<size_type>::max() / sizeof(Node<T>);
			}
			// Element Access
			reference front() {
				return _head->_data;
			}
			const_reference front() const {
				return _head->_data;
			}
			reference back() {
				return _tail->_prev->_data;
			}
			const_reference back() const {
				return _tail->_prev->_data;
			}
			// Modifiers
			void	assign(iterator first, iterator end);
			void	assign (size_type n, const value_type& val);
			void	push_back(const value_type& val) {
				node_type* new_node = new Node<T>(val);
				_tail->insert(new_node);
				if (_size++ == 0)
					_head = new_node;
			}
			void	clear();
			// Operations
			// Observers
	};
	// Non-member function overloads
}

#endif