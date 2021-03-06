/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:53:57 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/06/28 09:53:24 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "Node.hpp"
# include "Allocator.hpp"
# include "ReverseIterator.hpp"
# include <algorithm>

namespace ft {
	template <typename List>
	class ListIterator {
		public:
			typedef typename List::value_type	value_type;
			typedef typename List::node_type*	pointer_type;
			typedef typename List::value_type&	reference_type;
			typedef typename List::const_reference	const_reference_type;
			typedef ptrdiff_t difference_type;
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
				if (this != &rhs)
					_ptr = rhs._ptr;
				return *this;
			}
			ListIterator operator+(difference_type v) {
				pointer_type tmp;

				tmp = _ptr;
				while (v--)
					tmp = tmp->_next;
				return tmp;
			}
			ListIterator operator-(difference_type v) {
				pointer_type tmp;

				tmp = _ptr;
				while (v--)
					tmp = tmp->_prev;
				return *tmp;
			}
			pointer_type getPtr() const {
				return _ptr;
			}
		protected:
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
			typedef ReverseIterator< iterator > const const_reverse_iterator;
			typedef ReverseIterator< iterator > reverse_iterator;
		private:
			node_type*	_head;
			node_type*	_tail;
			size_type	_size;
			void	unlink(Node<T>* node) {
				_head->unlinkNode(node);
			}
		public:
			List( void ) {
				_size = 0;
				_head = _tail = new Node<T>();
			}
			List( T const & data ) {
				_size = 0;
				_head = _tail = new Node<T>(data);
			}
			List (size_type n, const value_type& val = value_type()) {
				_head = _tail = new Node<T>();
				_size = 0;
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}
			template <class InputIterator>
				List (InputIterator first, InputIterator last) {
					_size = 0;
					_head = _tail = new Node<T>();
					for (static_cast<void>(first); first != last; first++)
						push_back(*first);
				}
			List( List<T> const & rhs ) {
				_size = 0;
				_head = _tail = new Node<T>();
				for (iterator it = rhs.begin(); it != rhs.end(); ++it)
					push_back(*it);
			}
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
			reverse_iterator rbegin() {
				// std::cout << _tail->_prev->_data << std::endl;
				return reverse_iterator(_tail);
			}
			// const_reverse_iterator rbegin() const {
			// 	return iterator(_tail);
			// }
			reverse_iterator rend() {
				// std::cout << "h = " << _head->_prev->_data << std::endl;
				return reverse_iterator(_head);
			}
			// const_reverse_iterator rend() const {
			// 	return iterator(_head);
			// }
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
				//  new_node->_next = _head;
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
			iterator erase (iterator position) {
				Node<T>* node = position.getPtr();
				_head->erase(&_head, node);
				if (--_size == 0)
				{
					_head = _tail;
					return iterator(_tail);
				}
				return iterator(node->_next);
			}
			iterator erase (iterator first, iterator last) {
				for (static_cast<void>(first); first != last; first++)
					erase(first);
				return last;
			}
			void 	swap (List<T>& x) {
				List<T> tmp(*this);

				clear();
				iterator tx = x.begin();
				for (static_cast<void>(tx); tx != x.end(); tx++)
					push_back(*tx);
				x.clear();
				iterator tobj = tmp.begin();
				for (static_cast<void>(tobj); tobj != tmp.end(); tobj++)
					x.push_back(*tobj);
			}
			void 	resize (size_type n, value_type val = value_type()) {
				if (n < _size) {
					for (size_type i = _size - n; i > 0; i--)
						pop_back();
				}
				if (n > _size) {
					Node<T>* node = new Node<T>(val);
					iterator pos = iterator(node);
					for (size_type i = _size + 1; i <= n; i++)
						push_back(*pos);
				}
			}
			void	clear() {
				while (!empty())
					pop_back();
			}
			// Operations
			void splice (iterator position, List& x) {
				splice(position, x, x.begin(), x.end());
			}
			void splice (iterator position, List& x, iterator i) {
				iterator it = i;
				splice(position, x, i, ++it);
			}
			void splice (iterator position, List& x, iterator first, iterator last) {
				node_type* iter;
				iterator tmp1;
				
				node_type* pos = position.getPtr();
				while (first != last) {
					if (_head == pos)
						_head = first.getPtr();
					if (x._head == first.getPtr())
						x._head = first.getPtr()->_next;
					tmp1 = first;
					tmp1++;
					iter = first.getPtr()->unlinkNode();
					pos->linkNode(iter);
					first = tmp1;
					x._size--;
					_size++;
				}
			}
			void remove (const value_type& val) {
				for (iterator it = begin(); it != end(); it++) {
					if (*it == val)
						erase(it);
				}
			}
			template <class Predicate>
				void remove_if (Predicate pred) {
					for (iterator it = begin(); it != end(); it++) {
						if (pred(*it))
							erase(it);
					}
				}
			void unique() {
				for (iterator it = begin(); it != end(); it++) {
					if (*(it + 1) == *it)
						erase(it);
				}
			}
			template <class BinaryPredicate>
				void unique (BinaryPredicate binary_pred) {
					for (iterator it = begin(); it != end(); it++) {
						if (binary_pred(*(it + 1), *it))
							erase(it);
					}
				}
			void merge (List& x) {
				iterator it = begin();
				iterator eit = end();

				iterator itx = x.begin();
				iterator eitx = x.end();

				while (it != eit && itx != eitx) {
					if (*itx < *it) {
						insert(it, *itx);
						x.pop_front();
						itx++;
					}
					else
						it++;
				}
				splice(it, x);
			}
			void merge1 (List& x) {
				if (this != &x)
				{
					node_type *node;
					iterator it = begin();
					iterator eit = end();

					iterator itx = x.begin();
					iterator eitx = x.end();

					while (it != eit && itx != eitx) {
						if (*itx < *it) {
							if (it.getPtr() == _head)
								_head = itx.getPtr();
							node_type *node = itx.getPtr();
							iterator tmp = itx;
							tmp++;
							node = itx.getPtr()->__unlink_node();
							it.getPtr()->__link_node(node);
							
							// node->unlinkNode();
							
							// insert(it, *itx);
							// x.pop_front();
							x._size--;
							itx = tmp;
						}
						else
							it++;
					}
					splice(it, x);
				}
			}
			template <class Compare>
				void merge (List& x, Compare comp) {
					iterator it = begin();
					iterator eit = end();

					iterator itx = x.begin();
					iterator eitx = x.end();

					while (it != eit && itx != eitx) {
						if (comp(*itx, *it)) {
							insert(it, *itx);
							x.pop_front();
							itx++;
						}
						else
							it++;
					}
					splice(it, x);
				}
			template<typename v_type>
				bool less_than(v_type const & a, v_type const & b) {
					return (a < b);
				}
			void sort() {
				if (size() < 2)
					return ;
				//sort(&less_than<value_type>);
				iterator tmp;
				iterator its;
				Node<T>* node;
				for (iterator it = begin(); it != end(); it++) {
					its = it;
					its++;
					for (; its != end(); its++) {
						if (*its < *it) {
							if (it.getPtr() == _head)
								_head = its.getPtr();
							node = its.getPtr()->unlinkNode();
							it.getPtr()->linkNode(node);
							tmp = its;
							its = it;
							it = tmp;
						}
					}
				}
			}
			template <class Compare>
				void sort (Compare comp) {
					iterator tmp;
					iterator its;
					Node<T>* node;
					for (iterator it = begin(); it != end(); it++) {
						its = it;
						its++;
						for (; its != end(); its++) {
							if (comp(*its, *it)) {
								if (it.getPtr() == _head)
									_head = its.getPtr();
								node = its.getPtr()->unlinkNode();
								it.getPtr()->linkNode(tmp);
								tmp = its;
								its = it;
								it = tmp;
							}
						}
					}
				}
			void reverse() {
				List<T> tmp(*this);

				clear();
				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					push_front(*it);
			}
	};
	// Non-member function overloads
	template <class T>
		bool operator== (const List<T>& lhs, const List<T>& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			typename List<T>::iterator tlhs = lhs.begin();
			typename List<T>::iterator trhs = rhs.begin();
			while (tlhs != lhs.end()) {
				if (*tlhs != *trhs)
					return false;
				tlhs++;
				trhs++;
			}
			return true;
		}
	template <class T>
		bool operator!= (const List<T>& lhs, const List<T>& rhs) {
			return !(lhs == rhs);
		}
	template <class T>
		bool operator<  (const List<T>& lhs, const List<T>& rhs) {
			typename List<T>::iterator tlhs = lhs.begin();
			typename List<T>::iterator trhs = rhs.begin();

			while (tlhs != lhs.end()) {
				if (trhs == rhs.end() || *trhs < *tlhs)
					return false;
				else if (*tlhs < *trhs)
					return true;
				tlhs++;
				trhs++;
			}
			return (trhs != rhs.end());
		}
	template <class T>
		bool operator<= (const List<T>& lhs, const List<T>& rhs) {
			return !(lhs > rhs);
		}
	template <class T>
		bool operator>  (const List<T>& lhs, const List<T>& rhs) {
			return (rhs < lhs);
		}
	template <class T>
		bool operator>= (const List<T>& lhs, const List<T>& rhs) {
			return !(lhs < rhs);
		}
	template<class T>
		void swap(List<T>& x, List<T>& y) {
			x.swap(y);
		}
}

#endif
