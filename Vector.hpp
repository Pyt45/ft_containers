/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:53:57 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/07/01 09:51:02 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReverseIterator.hpp"
#include <iostream>


namespace ft {
	template <class Vector>
	class VectorIterator {
		public:
			/*typedef typename Vector::value_type value_type;
			typedef typename Vector::reference reference_type;
			typedef typename Vector::const_reference const_reference;
			typedef typename Vector::pointer pointer_type;*/
			typedef std::ptrdiff_t difference_type;
			typedef Vector value_type;
			typedef value_type& reference_type;
			typedef const value_type& const_reference;
			typedef value_type* pointer_type;
		public:
			VectorIterator( void ) : _ptr(nullptr), _index(0) {}
			VectorIterator( pointer_type ptr ) : _ptr(ptr), _index(1) {}
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
				return (*_ptr);
			}
			bool operator!=( VectorIterator const& rhs ) const {
				return _ptr != rhs._ptr;
			}
			bool operator==( VectorIterator const& rhs ) const {
				return (_ptr[_index] == rhs._ptr[rhs._index]);
			}
			VectorIterator& operator++() {
				_index++;
				++_ptr;
				return (*this);
			}
			VectorIterator operator++(int) {
				VectorIterator temp = *this;
				++(*this);
				return (temp);
			}
			VectorIterator& operator--() {
				--_ptr;
				_index--;
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
			unsigned int _get_index() {
				return _index;
			}
			// VectorIterator operator+(difference_type v) {
			// 	++_index;
			// 	++_ptr;
			// 	return (_ptr);
			// }
			difference_type operator-(VectorIterator const &rhs)
			{
				return (_ptr - rhs._ptr);
			}
			// VectorIterator operator-(difference_type v) {
			// 	pointer_type temp;

			// 	temp = _ptr;
			// 	while (v--)
			// 	{
			// 		--_index;
			// 		--_ptr;
			// 	}
			// 	return (_ptr);
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
			typedef VectorIterator< value_type > iterator;
			typedef const VectorIterator< value_type > const_iterator;
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
			void _allocator(size_type size) {
				if (_cap == 0) {
					size = (size > 128) ? size : 128;
					_items = static_cast<value_type*>(::operator new(sizeof(value_type) * size));
					_cap = size;
				} else if (size > _cap) {
					size = (size > _cap * 2) ? size : _cap * 2;
					value_type *tmp = static_cast<value_type*>(::operator new(sizeof(value_type) * size));
					if (_items) {
						//std::memmove(static_cast<void*>(tmp), static_cast<void*>(this->container), this->m_size * sizeof(value_type));
						for (size_t i = 0; i < _size; ++i)
							new(&tmp[i]) value_type(_items[i]);
						::operator delete(_items);
					}
					_items = tmp;
					_cap = size;
				}
			}
			void copy_construct(size_type idx, const_reference val) {
				new (&_items[idx]) value_type(val);
			}
        public:
			vector() : _cap(1), _size(0) {
				_items = new T[1];
			}
			vector(size_type n, const value_type& val = value_type()) {
				_size = _cap = n;
				_items = new T[n];
				this->assign(n, val);
			}
			template<class InputIterator>
				vector(InputIterator first, InputIterator last) {
					_size = _cap = 0;
					_items = nullptr;
					this->assign(first, last);
				}
			vector(vector const& x) {
				_size = 0;
				_cap = 1;
				_items = new T[1];
				for (iterator it = x.begin(); it != x.end(); it++)
					push_back(*it);
			}
			vector& operator=( vector const& rhs );
			~vector() {
				clear();
				delete [] _items;
			}
			
			// Iterators
			iterator begin() {
				return iterator(_items, 0);
			}
			const_iterator begin() const {
				return const_iterator(_items, 0);
			}
			iterator end() {
				return iterator(&_items[_size], _size - 1);
			}
			const_iterator end() const {
				return const_iterator(&_items[_size], _size - 1);
			}
			reverse_iterator rbegin() {
				return reverse_iterator(&_items[_size]);
			}
			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(&_items[_size]);
			}
			reverse_iterator rend() {
				return reverse_iterator(&_items[0]);
			}
			const_reverse_iterator rend() const {
				return const_reverse_iterator(&_items[0]);
			}
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
			void reserve (size_type n) {
				if (n > _cap)
					realloc_container(n);
			}
			reference operator[] (size_type n) {
				return _items[n];
			}
			const_reference operator[] (size_type n) const {
				return _items[n];
			}
			reference at (size_type n) {
				if (n >= _cap)
					throw std::out_of_range("Index out of range");
				return _items[n];
			}
			const_reference at (size_type n) const {
				if (n >= _cap)
					throw std::out_of_range("Index out of range");
				return _items[n];
			}
			reference front() {
				return _items[0];
			}
			const_reference front() const {
				return _items[0];
			}
			reference back() {
				return _items[_size - 1];
			}
			const_reference back() const {
				return _items[_size - 1];
			}
			template <class InputIterator>
				void assign (InputIterator first, InputIterator last) {
					clear();
					for (static_cast<void>(first); first != end(); first++)
						push_back(*first);
				}
			void assign (size_type n, const value_type& val) {
				clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}
			void push_back (const value_type& val) {
				if (_size == _cap)
					realloc_container();
				_items[_size++] = val;
			}
			void pop_back() {
				_items[--_size].value_type::~value_type();
			}
			iterator insert (iterator position, const value_type& val) {
				insert(position, 1, val);
				return (++position);
			}
			
			void insert (iterator position, size_type n, const value_type& val) {
				iterator it = begin();
				size_type i = 0;

				if (_size + n >= _cap)
					_allocator(_size + n);
				while (it != position) {
					it++;
					i++;
				}
				
				for (size_type idx = _size + n; ; idx--)
				{
					copy_construct(idx, _items[idx - n]);
					if (idx == i)
						break ;
				}
				for (size_type k = 0; k < n; k++)
					copy_construct(k + i, val);
				_size += n;
			}
			// template <class InputIterator>
			void insert (iterator position, iterator first, iterator last) {
				iterator it = begin();
				size_type i = 0;
				std::ptrdiff_t len = last - first;
				if (len + _size >= _cap)
					_allocator(len + _size);
				while (it != position) {
					it++;
					i++;
				}
				for (size_type idx = _size + len; ; idx--) {
					copy_construct(idx, _items[idx - len]);
					if (idx == i)
						break ;
				}
				for (size_type k = 0; k < len && first != last; k++, first++)
					copy_construct(k + i, *first);
				_size += len;
			}
			iterator erase (iterator position) {
				iterator it(position);
				++it;
				return (erase(position, it));
			}
			iterator erase (iterator first, iterator last) {
				iterator _retpos = begin();
				size_type i = 0;
				while (_retpos != first)
				{
					_retpos++;
					i++;
				}
				if (_retpos == end())
					return (end());
				size_type _stoppos = i;
				size_type _delete = 0;
				while (first != last)
				{
					(*first++).value_type::~value_type();
					_stoppos++;
					_delete++;
				}
				for (; _stoppos < _size; _stoppos++)
					_items[i++] = _items[_stoppos];
				_size -= _delete;
				return (_retpos);
			}
			void swap (vector& x) {
				vector<T> tmp(*this);

				clear();
				iterator tx = x.begin();
				for (static_cast<void>(tx); tx != end(); tx++)
					push_back(*tx);
				x.clear();
				iterator tobj = tmp.begin();
				for (static_cast<void>(tobj); tobj != end(); tobj)
					x.push_back(*tobj);
			}
			void clear() {
				while (!empty())
					pop_back();
			}
	};
	template <class T>
		bool operator== (const vector<T>& lhs, const vector<T>& rhs) {
			if (lhs.size() != rhs.size())
				return (false);
			for (size_t i = 0; i < lhs.size(); i++) {
				if (lhs[i] != rhs[i])
					return (false);
				i++;
			}
			return (true);
		}
	template <class T>
		bool operator!= (const vector<T>& lhs, const vector<T>& rhs) {
			return !(lhs == rhs);
		}
	template <class T>
		bool operator<  (const vector<T>& lhs, const vector<T>& rhs) {
			typename vector<T>::iterator tlhs = lhs.begin();
			typename vector<T>::iterator trhs = rhs.begin();
			
			while (tlhs != lhs.end()) {
				if (trhs == rhs.end() || *trhs < *tlhs)
					return (false);
				else if (*tlhs < *trhs)
					return (true);
				tlhs++;
				trhs++;
			}
			return (trhs != rhs.end());
		}
	template <class T>
		bool operator<= (const vector<T>& lhs, const vector<T>& rhs) {
			return !(lhs > rhs);
		}
	template <class T>
		bool operator>  (const vector<T>& lhs, const vector<T>& rhs) {
			return (rhs < lhs);
		}
	template <class T>
		bool operator>= (const vector<T>& lhs, const vector<T>& rhs) {
			return !(lhs < rhs);
		}
	template <class T>
		void swap (vector<T>& x, vector<T>& y) {
			x.swap(y);
		}
}
