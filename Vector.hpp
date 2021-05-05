/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:53:57 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/05/05 10:39:54 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReverseIterator.hpp"
#include <iostream>


namespace ft {
	template <class Vector>
	class VectorIterator {
		public:
			typedef typename Vector::value_type value_type;
			typedef typename Vector::reference reference_type;
			typedef typename Vector::const_reference const_reference;
			typedef typename Vector::pointer pointer_type;
			typedef std::ptrdiff_t difference_type;
		public:
			VectorIterator( void ) : _ptr(nullptr), _index(0) {}
			VectorIterator( pointer_type ptr ) : _ptr(ptr), _index(0) {}
			VectorIterator(pointer_type ptr, unsigned int index) : _ptr(ptr), _index(index) {}
			VectorIterator( VectorIterator const& rhs ) : _ptr(rhs._ptr), _index(rhs._index) {}
			VectorIterator& operator=( VectorIterator const& rhs ) {
				if (this != &rhs) {
					this->_ptr = rhs._ptr;
					this->_index = rhs._index;
				}
				return (*this);
			}
			~VectorIterator() {}
			reference_type operator*() {
				return _ptr[_index];
			}
			bool operator!=( VectorIterator const& rhs ) const {
				return _ptr != rhs._ptr;
			}
			bool operator==( VectorIterator const& rhs ) const {
				return _ptr == rhs._ptr;
			}
			VectorIterator& operator++() {
				++_index;
				return (*this);
			}
			VectorIterator operator++(int) {
				VectorIterator temp = *this;
				++(*this);
				return (temp);
			}
			VectorIterator& operator--() {
				--_index;
				return (*this);
			}
			VectorIterator operator--(int) {
				VectorIterator temp = *this;
				--(*this);
				return (temp);
			}
			pointer_type operator->() const {
				return &(operator*());
			}
			// VectorIterator& operator+(difference_type v) {
			// 	pointer temp;

			// 	temp = _ptr;
			// 	while (v--)
			// 		_index++;
			// 	return (temp);
			// }
			// VectorIterator& operator-(difference_type v) {
			// 	pointer temp;

			// 	temp = _ptr;
			// 	while (v--)
			// 		_index--;
			// 	return (temp);
			// }
		protected:
			pointer_type 	_ptr;
			unsigned int 	_index;
	};
    template <class T>
    class vector {
		public:
			typedef T value_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef VectorIterator< vector<T> > iterator;
			typedef const VectorIterator< vector<T> > const_iterator;
			typedef ReverseIterator< iterator > reverse_iterator;
			typedef const ReverseIterator< iterator > const_reverse_iterator;
			typedef std::ptrdiff_t difference_type;
			typedef size_t size_type;
        private:
            T* _items;
            size_type   _size;
            size_type   _cap;
            size_type   _top;
			void	realloc_container(size_type size = 0) {
				size_type _new_size = size ? size : _cap * 2;
				if (_items) {
					T* tmp = _items;
					_items = new T[_new_size];
					for (size_t i = 0; i < _cap; i++)
						_items[i] = tmp[i];
					delete [] tmp;
				}
				_cap = _new_size;
			}
        public:
			vector() : _cap(1), _size(0) {
				_items = new T[1];
			}
			vector(size_type n, const value_type& val = value_type());
			template<class InputIterator>
				vector(InputIterator first, InputIterator last);
			vector(vector const& x);
			vector& operator=( vector const& rhs );
			~vector() {
				_size = _cap = 0;
				delete [] _items;
			}
			
			// Iterators
			iterator begin() {
				return iterator(_items, 0);
			}
			const_iterator begin() const {
				return iterator(_items, 0);
			}
			iterator end() {
				return iterator(_items, _size - 1);
			}
			const_iterator end() const {
				return iterator(_items, _size - 1);
			}
			// reverse_iterator rbegin() {
			// 	return reverse_iterator(_items);
			// }
			// const_reverse_iterator rbegin() const {
			// 	return reverse_iterator(_items);
			// }
			// reverse_iterator rend() {
			// 	return reverse_iterator(_items);
			// }
			// const_reverse_iterator rend() const {
			// 	return reverse_iterator(_items);
			// }
			size_type size() const {
				return _size;
			}
			size_type max_size() const {
				return std::numeric_limits<size_type>::max() / sizeof(T);
			}
			void resize (size_type n, value_type val = value_type()) {
				if (n < _size) {
					for (size_type i = _size - n; i > 0; i--)
						pop_back();
				}
				if (n > _size) {
					for (size_type i = _size + 1; i <= n; i++)
						push_back(val);
				}
			}
			size_type capacity() const {
				return _cap;
			}
			bool empty() const {
				return (_size == 0);
			}
			void reserve (size_type n);
			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;
			reference at (size_type n);
			const_reference at (size_type n) const;
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;
			template <class InputIterator>
				void assign (InputIterator first, InputIterator last);
			void assign (size_type n, const value_type& val);
			void push_back (const value_type& val) {
				if (_size == _cap)
					realloc_container();
				_items[_size++] = val;
			}
			void pop_back();
			iterator insert (iterator position, const value_type& val);
			    void insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
			    void insert (iterator position, InputIterator first, InputIterator last);
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void swap (vector& x);
			void clear() {
				while (!empty())
					pop_back();
			}
	};
	template <class T>
		bool operator== (const vector<T>& lhs, const vector<T>& rhs);
	template <class T>
		bool operator!= (const vector<T>& lhs, const vector<T>& rhs);
	template <class T>
		bool operator<  (const vector<T>& lhs, const vector<T>& rhs);
	template <class T>
		bool operator<= (const vector<T>& lhs, const vector<T>& rhs);
	template <class T>
		bool operator>  (const vector<T>& lhs, const vector<T>& rhs);
	template <class T>
		bool operator>= (const vector<T>& lhs, const vector<T>& rhs);
	template <class T>
		void swap (vector<T>& x, vector<T>& y);
}