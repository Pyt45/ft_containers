/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:53:57 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/03/11 23:29:18 by ayoub            ###   ########.fr       */
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
			typedef typename List::const_reference	const_reference_type;
			ListIterator( void ) : _ptr(nullptr) {}
			ListIterator(pointer_type ptr) : _ptr(ptr) {}
			ListIterator( ListIterator const & rhs ) : _ptr(rhs._ptr) {}
			reference_type operator*() {
				return _ptr->_data;
			}

			bool	operator!=( ListIterator const & rhs ) const {
				return _ptr != rhs._ptr;
			}
			bool	operator==( ListIterator const & rhs ) const {
				return _ptr == rhs._ptr;
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
			ListIterator& operator--() {
				_ptr = _ptr->_prev;
				return *this;
			}
			ListIterator operator--(int) {
				ListIterator iter = *this;
				--(*this);
				return iter;
			}
			ListIterator& operator=( ListIterator const & rhs ) {
				_ptr = rhs._ptr;
				return *this;
			}
			pointer_type getPtr() const {
				return _ptr;
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
			typedef ListIterator< List<T> > const const_iterator;
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
			const_iterator begin() const {
				return iterator(_head);
			}
			iterator end() {
				return iterator(_tail);
			}
			const_iterator end() const {
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
			void	assign(iterator first, iterator end) {
				clear();
				for(static_cast<void>(first); first != end; first++)
					push_back(*first);
			}
			void	assign(size_type n, const value_type& val) {
				clear();
				Node<T>* new_node = new Node<T>(val);
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}
			
			void	push_front(const value_type& val) {
				node_type* new_node = new Node<T>(val);
				_head->insert(new_node);
				// _head->insert_front(new_node);
				// _head->_prev = new_node;
				// new_node->_next = _head;
				_head = new_node;
				_size++;
			}
			
			void 	pop_front() {
				if (!_size)
					return ;
				_head = _head->erase();
				if (_size-- == 1)
					_head = _tail;
			}
			void	push_back(const value_type& val) {
				node_type* new_node = new Node<T>(val);
				_tail->insert(new_node);
				if (_size++ == 0)
					_head = new_node;
			}
			void 	pop_back() {
					if (!_size)
						return ;
				_tail->_prev->erase();
				if (_size-- == 1)
					_head = _tail;
			}
			iterator insert (iterator position, const value_type& val) {
				Node<T>* node = new Node<T>(val);
				position.getPtr()->insert(node);
				_size++;
				if (position == begin())
					_head = node;
				return iterator(node);
			}
			void 	insert (iterator position, size_type n, const value_type& val) {
				for (size_type i = 0; i < n; i++)
					insert(position, val);
				return ;
			}
    		void	insert (iterator position, iterator first, iterator last) {
				for (static_cast<void>(first); first != last; ++first)
					insert(position, *first);
			}
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void 	swap (List<T>& x);
			void 	resize (size_type n, value_type val = value_type());
			void	clear() {
				while (!empty())
					pop_back();
			}
			// Operations
			// Observers
	};
	// Non-member function overloads
}

#endif