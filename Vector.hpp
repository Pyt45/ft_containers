/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:53:57 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/05/02 22:36:56 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReverseIterator.hpp"


namespace ft {
	template <class Vector>
	class VectorIterator {
		public:
			typedef typename Vector::reference reference;
			typedef typename Vector::const_reference const_reference;
			typedef typename Vector::pointer pointer;
			typedef std::ptrdiff_t difference_type;
		public:
			VectorIterator( void ) : _ptr(nullptr) {}
			VectorIterator(pointer ptr) : _ptr(ptr) {}
			VectorIterator( VectorIterator const & rhs ) : _ptr(rhs._ptr) {}
			~VectorIterator() {}
			reference operator*() {
				return _ptr;
			}
		protected:
			pointer _ptr;
	};
    template <class T>
    class vector {
        public:
            typedef T value_type;
            typedef value_type& reference;
			typedef const value_type& const_reference;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            // typedef VectorIterator< vector<T> > iterator;
            // typedef const VectorIterator< vector<T> > const_iterator;
            // typedef ReverseIterator<iterator> reverse_iterator;
            // typedef const ReverseIterator<iterator> const_reverse_iterator;
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;
        private:
            T* _items;
            size_type   _size;
            size_type   _cap;
            size_type   _top;
        public:
            vector() : _size(0), _cap(0), _top(0) {}
            ~vector() {}
            /*iterator begin();
            const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;*/
            size_type size() const {
                return _size;
            }
            size_type max_size() const {
                return std::numeric_limits<size_type>::max() / sizeof(T);
            }
            void resize (size_type n, value_type val = value_type());
            size_type capacity() const;
            bool empty() const;
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
    };
}