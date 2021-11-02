/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:35:44 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/07/05 10:41:10 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include "Type_traits.hpp"
# include "iterator_traits.hpp"
# include "Utility.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T value_type;
			typedef std::allocator<value_type> allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::size_type size_type;
			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef ft::__wrap_iter<pointer> iterator;
			typedef ft::__wrap_iter<const_pointer> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		private:
			T* _items;
			size_type _size;
			size_type _cap;
			allocator_type _alloc;
			void	__allocate_container(size_type size) {
				// size_type size = size ? size : _cap * 2;
				if (_items) {
					T* tmp = _items;
					// _items = new T[size];
					_items = _alloc.allocate(size);
					for (size_type i = 0; i < _size; i++)
						__copy_construct(i, tmp[i]);
					// _items[i] = tmp[i];
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(tmp + i);
					_alloc.deallocate(tmp, size);
				}
				_cap = size;
			}
			void __copy_construct(size_type idx, const_reference val)
			{
				_alloc.construct(&_items[idx], val);
			}
		public:
			explicit vector(const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_items = _alloc.allocate(0);
				_alloc.construct(_items);
				_size = _cap = 0;
			}
			explicit vector(size_type n, const value_type& val = value_type())
			{
				_size = _cap = n;
				_items = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					__copy_construct(i, val);
			}
			template <class InputIterator>
				vector(InputIterator first, InputIterator last,
						const allocator_type& alloc = allocator_type(),
						typename enable_if< !is_integral<InputIterator>::value, bool >::type = true)
				{
					size_type len = static_cast<size_type>(last - first);
					_cap = len;
					_size = 0;
					_alloc = alloc;
					_items = _alloc.allocate(0);
					_alloc.construct(_items);
					this->assign(first, last);
				}
			vector(vector const& x): _size(0), _cap(x._size), _alloc(x._alloc)
			{
				this->_items = _alloc.allocate(_cap);
				for (;_size < _cap; _size++)
					__copy_construct(_size, x._items[_size]);
			}
			vector& operator=(vector const& x)
			{
				if (this != &x)
				{
					// this->_size = x._size;
					// this->_cap = x._cap;
					// this->_alloc = x._alloc;
					// this->_items = _alloc.allocate(_size);
					// for (size_type i = 0; i < x._size; i++)
					// 	__copy_construct(i, x._items[i]);
					if (x._size > _cap) {
						__allocate_container(x._size);
						this->_size = x._size;
					} else {
						__allocate_container(x._cap);
						this->_size = x._size;
					}
				}
				return *this;
			}
			~vector() {
				// clear();
				if (_items)
					_alloc.deallocate(_items, _cap);
			}
			iterator begin() {
				return iterator(&_items[0]);
			}
			const_iterator begin() const {
				return const_iterator(&_items[0]);
			}
			iterator end() {
				return iterator(&_items[_size]);
			}
			const_iterator end() const {
				return const_iterator(&_items[_size]);
			}
			reverse_iterator rbegin() {
				return reverse_iterator(this->end());
			}
			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(this->end());
			}
			reverse_iterator rend() {
				return reverse_iterator(this->begin());
			}
			const_reverse_iterator rend() const {
				return const_reverse_iterator(this->begin());
			}
			size_type size() const {
				return _size;
			}
			size_type max_size() const {
				return _alloc.max_size();
			}
			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size) {
					for (size_type i = _size - n; i > 0; i--)
						pop_back();
				}
				if (n > _size) {
					// _size = _cap = n;
					// this->reserve(n);
					if (_size + 1 > _cap)
						reserve(n);
					else if (n > _cap)
						__allocate_container(_cap * 2);
					for (size_type i = _size; i < n; i++)
					{
						__copy_construct(i, val);
						_size++;
						// push_back(val);
					}
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
					__allocate_container(n);
			}
			reference operator[](size_type n) {
				return _items[n];
			}
			const_reference operator[](size_type n) const {
				return _items[n];
			}
			reference at (size_type n) {
				if (n >= _size)
					throw std::out_of_range("Index out of range");
				return _items[n];
			}
			const_reference at (size_type n) const {
				if (n >= _size)
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
				void assign (InputIterator first, InputIterator last,
				typename enable_if<!is_integral<InputIterator>::value, bool>::type = true) {
					clear();
					for (; first != last; first++)
						push_back(*first);
				}
			void assign (size_type n, const value_type& val) {
				clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}
			void push_back (const value_type& val) {
				if (_size == _cap) {
					__allocate_container(_cap * 2);
				}
				if (_cap == 0)
					_cap = 1;
				__copy_construct(_size++, val);
			}
			void pop_back() {
				_alloc.destroy(_items + _size);
				_size--;
			}
			iterator insert (iterator position, const value_type& val) {
				insert(position, 1, val);
				return (++position);
			}
			void insert (iterator position, size_type n, const value_type& val) {
				iterator it = begin();
				size_type i = 0;
				if (_size + n >= _cap)
					__allocate_container(_size + n);
				while (it != position) {
					it++;
					i++;
				}
				
				for (size_type idx = _size + n; ; idx--)
				{
					__copy_construct(idx, _items[idx - n]);
					if (idx == i)
						break ;
				}
				for (size_type k = 0; k < n; k++)
					__copy_construct(k + i, val);
				_size += n;
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
			typename enable_if< !is_integral<InputIterator>::value, bool >::type = true ) {
				iterator it = begin();
				size_type i = 0;
				std::ptrdiff_t len = last - first;
				if (len + _size >= _cap)
					__allocate_container(len + _size);
				while (it != position) {
					it++;
					i++;
				}
				for (size_type idx = _size + len; ; idx--) {
					__copy_construct(idx, _items[idx - len]);
					if (idx == i)
						break ;
				}
				for (size_type k = 0; k < len && first != last; k++, first++)
					__copy_construct(k + i, *first);
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
					// (*first++).value_type::~value_type();
					_alloc.destroy((*first++));
					_stoppos++;
					_delete++;
				}
				for (; _stoppos < _size; _stoppos++)
					__copy_construct(i++, _items[_stoppos]);
					// _items[i++] = _items[_stoppos];
				_size -= _delete;
				return (_retpos);
			}
			void swap (vector& x) {
				// vector<T> tmp = *this;
				value_type* ptr = this->_items;
				size_type size = this->_size;
				size_type cap = this->_cap;
				allocator_type alloc = this->_alloc;

				this->_alloc = x._alloc;
				this->_size = x._size;
				this->_cap = x._cap;
				this->_items = x._items;

				x._alloc = alloc;
				x._items = ptr;
				x._size = size;
				x._cap = cap;
			}
			void clear()
			{
				while (!empty())
					pop_back();
			}
			allocator_type get_allocator() const {
				return _alloc;
			}
	};
	template <class T, class Alloc>
		bool operator== (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return (false);
			for (size_t i = 0; i < lhs.size(); i++) {
				if (lhs[i] != rhs[i])
					return (false);
				// i++;
			}
			return (true);
		}
	template <class T, class Alloc>
		bool operator!= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
			return !(lhs == rhs);
		}
	template <class T, class Alloc>
		bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
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
	template <class T, class Alloc>
		bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
			return !(lhs > rhs);
		}
	template <class T, class Alloc>
		bool operator>  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
			return (rhs < lhs);
		}
	template <class T, class Alloc>
		bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
			return !(lhs < rhs);
		}
	template <class T, class Alloc>
		void swap (vector<T, Alloc>& x, vector<T, Alloc>& y) {
			x.swap(y);
		}
}


#endif