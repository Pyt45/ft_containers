/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:35:44 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/12/16 23:31:11 by ayoub            ###   ########.fr       */
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
				if (_items) {
					T* tmp = _alloc.allocate(size);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tmp[i], _items[i]);
					if (_items) {
						for (size_type i = 0; i < _size; i++)
							_alloc.destroy(_items + i);
						_alloc.deallocate(_items, size);
					}
					_items = tmp;
				} else {
					_items = _alloc.allocate(size);
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
				_items = nullptr;
				// _items = _alloc.allocate(0);
				// _alloc.construct(_items);
				_size = _cap = 0;
			}
			explicit vector(size_type n, const value_type& val = value_type())
			{
				_cap = n;
				_items = _alloc.allocate(n);
				for (_size = 0; _size < n; _size++)
					__copy_construct(_size, val);
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
					_items = _alloc.allocate(_cap);
					for (; first != last; first++)
						__copy_construct(_size++, *first);
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
					vector tmp(x);
					if (_cap > x._cap) {
						_alloc.deallocate(_items, _size);
						_items = _alloc.allocate(_cap);
						this->_size = x._size;
						for (size_t i = 0; i < _size; i++)
							__copy_construct(i, x._items[i]);
					}
					else
						swap(tmp);
				}
				return *this;
			}
			~vector() {
				if (_items)
				{
					clear();
					_alloc.deallocate(_items, _size);
				}
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
				else if (n > _size) {
					// _size = _cap = n;
					// this->reserve(n);
					if (_size + 1 > _cap)
						reserve(_cap * 2);
					else if (n > _cap)
						__allocate_container(n);
					for (size_type i = _size; i < n; i++)
					{
						__copy_construct(i, val);
						_size++;
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
					throw std::out_of_range("vector");
				return _items[n];
			}
			const_reference at (size_type n) const {
				if (n >= _size)
					throw std::out_of_range("vector");
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
					size_type len = static_cast<size_type>(last - first);
					if (len > _cap)
						_cap = len;
					_size = 0;
					_items = _alloc.allocate(_cap);
					for (; first != last; first++)
						__copy_construct(_size++, *first);
				}
			void assign (size_type n, const value_type& val) {
				size_type s = _size;
				clear();
				if (_items)
					_alloc.deallocate(_items, s);
				_items = _alloc.allocate(n);
				if (n > _cap) {
					_cap = n;
					while (_size < n)
						__copy_construct(_size++, val);
				} else {
					while (_size < n)
						__copy_construct(_size++, val);
				}
			}
			void push_back (const value_type& val) {
				if (_size + 1 > _cap) {
					__allocate_container(_cap == 0 ? 1 : _cap * 2);
					// std::cout << "_cap = " << _cap << std::endl;
				}
				// if (_cap == 0)
				// 	_cap = 1;
				__copy_construct(_size++, val);
			}
			void pop_back() {
				_alloc.destroy(_items + _size);
				_size--;
			}
			iterator insert (iterator position, const value_type& val) {
				size_type i = 0;
				for (iterator it = begin(); it != position; it++, i++) {}
				if (_size + 1 > _cap) {
					__allocate_container(_cap * 2);
					position = _items + i;
				}
				for (iterator it = end(); it != position; it--) {
					_alloc.destroy(it.base());
					_alloc.construct(it.base(), *(it - 1));
				}
				*position = val;
				_size += 1;
				return position;
			}
			void insert (iterator position, size_type n, const value_type& val) {
				size_type i = 0;
				for (iterator it = begin(); it != position; it++, i++) {}
				if (_size + n > _cap) {
					n > _cap ? __allocate_container(_size + n) : __allocate_container(_cap * 2);
					for (size_type j = 0; j < n; j++)
						__copy_construct(j + _size, val);
					position = _items + i;
				}
				for (iterator it = iterator(&_items[(_size + n) - 1]); it != position + n - 1; it--)
				{
					_alloc.destroy(it.base());
					_alloc.construct(it.base(), *(it - n));
				}
				for (iterator it = position; it != position + n; it++) {
					_alloc.destroy(it.base());
					_alloc.construct(it.base(), val);
				}
				_size += n;
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
			typename enable_if< !is_integral<InputIterator>::value, bool >::type = true ) {
				size_type i = 0;
				std::ptrdiff_t len = last - first;
				for (iterator it = begin(); it != position; it++, i++) {}
				if (len + _size > _cap) {
					static_cast<size_type>(len) > _cap ? __allocate_container(len + _size) : __allocate_container(_cap * 2);
					iterator it = first;
					for (size_type j = 0; j < static_cast<size_type>(len) && it != last; j++, it++)
						__copy_construct(j + _size, *it);
					position = iterator(&_items[i]);
				}
				for (iterator t = iterator(&_items[(_size + len) - 1]); t != position + len - 1; t--)
				{
					_alloc.destroy(t.base());
					_alloc.construct(t.base(), *(t - len));
				}
				for (iterator t = position; t != position + len; t++, first++) {
					_alloc.destroy(t.base());
					_alloc.construct(t.base(), *first);
				}
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
					_alloc.destroy((first++).base());
					_stoppos++;
					_delete++;
				}
				for (; _stoppos < _size; _stoppos++)
					__copy_construct(i++, _items[_stoppos]);
				_size -= _delete;
				return (_retpos);
			}
			void swap (vector& x) {
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
			return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.end());
		}
	template <class T, class Alloc>
		bool operator!= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
			return !(lhs == rhs);
		}
	template <class T, class Alloc>
		bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
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