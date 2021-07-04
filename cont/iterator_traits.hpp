/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:56:38 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/07/04 17:44:32 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iterator>
# include "Type_traits.hpp"

namespace ft {
	template <class Category, class T, class Distance = std::ptrdiff_t,
	class Pointer = T*, class Reference = T &>
	struct iterator {
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};
	template <class Iterator>
	struct iterator_traits {
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};
	template <class T>
	struct iterator_traits<T *> {
		typedef std::random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
	};
	template <class T>
	struct iterator_traits<const T *> {
		typedef std::random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef const T* pointer;
		typedef const T& reference;
	};
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag: public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
	template <class Iterator>
	class reverse_iterator :
		public iterator<typename iterator_traits<Iterator>::iterator_category,
						typename iterator_traits<Iterator>::value_type,
						typename iterator_traits<Iterator>::difference_type,
						typename iterator_traits<Iterator>::pointer,
						typename iterator_traits<Iterator>::reference>
	{
		private:
			Iterator __t;
		protected:
			Iterator current;
		public:
			typedef Iterator iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type difference_type; 
			typedef typename iterator_traits<Iterator>::reference reference;
			typedef typename iterator_traits<Iterator>::pointer pointer;
			reverse_iterator() : __t(), current() {}
			reverse_iterator(iterator_type it) : __t(it), current(it) {}
			template <class Iter>
				reverse_iterator(const reverse_iterator<Iter>& rev_it) : __t(rev_it.base()), current(rev_it.base()) {}
			template <class Iter>
				reverse_iterator& operator=(const reverse_iterator<Iter>& rev_it) {
					__t = current = rev_it.base();
					return (*this);
				}
			iterator_type base() {
				return current;
			}
			reference operator*() const {
				Iterator tmp = current;
				return *--tmp;
			}
			pointer operator->() const {
				return &(operator*());
			}
			reverse_iterator&	operator++() {
				--current;
				return *this;
			}
			reverse_iterator	operator++(int) {
				reverse_iterator tmp(*this);
				++(*this);
				return (tmp);
			}
			reverse_iterator&	operator--() {
				++current;
				return *this;
			}
			reverse_iterator	operator--(int) {
				reverse_iterator tmp(*this);
				--(*this);
				return tmp;
			}
			reverse_iterator	operator+(difference_type n) const {
				return reverse_iterator(current - n);
			}
			reverse_iterator&	operator+=(difference_type n) {
				current -= n;
				return *this;
			}
			reverse_iterator	operator-(difference_type n) const {
				return reverse_iterator(current + n);
			}
			reverse_iterator&	operator-=(difference_type n) {
				current += n;
				return *this;
			}
			reference			operator[](difference_type n) const {
				return *(*this + n);
			}
	};
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() == rhs.base();
	}
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() != rhs.base();
	}
	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() < rhs.base();
	}
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() <= rhs.base();
	}
	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() > rhs.base();
	}
	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() >= rhs.base();
	}
	
	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
		return rev_it.base() - n;
	}
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() - rhs.base();
	}
	
	// Distance
	template <class _InputIter>
	typename iterator_traits<_InputIter>::difference_type
	__distance(_InputIter __first, _InputIter __last, input_iterator_tag) {
		typename iterator_traits<_InputIter>::difference_type __r(0);

		for (; __first != __last; ++__first)
			++__r;
		return __r;
	}
	template <class _RandIter>
	typename iterator_traits<_RandIter>::difference_type
	__distance(_RandIter __first, _RandIter __last, random_access_iterator_tag) {
		return __last - __first;
	}
	template <class _InputIter>
	typename iterator_traits<_InputIter>::difference_type
	distance(_InputIter __first, _InputIter __last){
		return __distance(__first, __last, typename iterator_traits<_InputIter>::iterator_category());
	}
	// Advance
	template <class _InputIter>
	void __advanced(_InputIter& __i,
					typename iterator_traits<_InputIter>::difference_type __n, input_iterator_tag) {
		for (; __n > 0; --__n)
			++__i;
	}
	template <class _BiDirIter>
	void __advanced(_BiDirIter& __i,
					typename iterator_traits<_BiDirIter>::difference_type __n, bidirectional_iterator_tag) {
		if (__n >= 0)
			for (; __n > 0; --__n)
				++__i;
		else
			for (; __n < 0; ++__n)
				--__n;
	}
	template <class _RandIter>
	void __advanced(_RandIter& __i,
					typename iterator_traits<_RandIter>::difference_type __n, random_access_iterator_tag) {
		__i += __n;
	}
	template <class _InputIter>
	void advanced(_InputIter& __i,
					typename iterator_traits<_InputIter>::difference_type __n) {
		__advanced(__i, __n, typename iterator_traits<_InputIter>::iterator_category());
	}

	// Iterator
	template <class _Iter>
	class __wrap_iter {
		public:
			typedef _Iter iterator_type;
			typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type value_type;
			typedef typename iterator_traits<iterator_type>::difference_type difference_type;
			typedef typename iterator_traits<iterator_type>::pointer pointer;
			typedef typename iterator_traits<iterator_type>::reference reference;
		private:
			iterator_type __i;
		public:
			__wrap_iter() : __i() {}
			__wrap_iter(iterator_type __x) : __i(__x) {}
			template <class _Up>
				__wrap_iter(const __wrap_iter<_Up>& __u,
							typename enable_if<!is_integral<_Up>::value, bool>::type = true) : __i(__u.base()) {}
			__wrap_iter& operator=(const __wrap_iter& __u) {
				if (this != &__u)
					__i = __u.__i;
				return (*this);
			}
			~__wrap_iter();

			reference operator*() const {
				return *__i;
			}
			pointer operator->() const {
				return &(operator*());
			}

			__wrap_iter& operator++() {
				++__i;
				return *this;
			}
			__wrap_iter operator++(int) {
				__wrap_iter tmp(*this);
				++(*this);
				return tmp;
			}
			__wrap_iter& operator--() {
				--__i;
				return (*this);
			}
			__wrap_iter operator--(int) {
				__wrap_iter tmp(*this);
				--(*this);
				return (tmp);
			}
			__wrap_iter operator+(difference_type __n) const {
				__wrap_iter __w(*this);
				__w += __n;
				return __w;
			}
			__wrap_iter& operator+=(difference_type __n) {
				__i += __n;
				return *this;
			}
			__wrap_iter operator-(difference_type __n) const {
				return *this + (-__n);
			}
			__wrap_iter& operator-=(difference_type __n) {
				*this += -__n;
				return *this;
			}
			reference operator[](difference_type __n) const {
				return __i[__n];
			}
			iterator_type base() const {
				return __i;
			}
	};
	template <class Iter>
	bool operator== (const __wrap_iter<Iter>& lhs, const __wrap_iter<Iter>& rhs) {
		return lhs.base() == rhs.base();
	}
	template <class Iter>
	bool operator< (const __wrap_iter<Iter>& lhs, const __wrap_iter<Iter>& rhs) {
		return lhs.base() < rhs.base();
	}
	template <class Iter>
	bool operator!= (const __wrap_iter<Iter>& lhs, const __wrap_iter<Iter>& rhs) {
		return !(lhs.base() == rhs.base());
	}
	template <class Iter>
	bool operator> (const __wrap_iter<Iter>& lhs, const __wrap_iter<Iter>& rhs) {
		return rhs.base() < lhs.base();
	}
	template <class Iter>
	bool operator>= (const __wrap_iter<Iter>& lhs, const __wrap_iter<Iter>& rhs) {
		return !(lhs.base() < rhs.base());
	}
	template <class Iter>
	bool operator<= (const __wrap_iter<Iter>& lhs, const __wrap_iter<Iter>& rhs) {
		return !(rhs.base() < lhs.base());
	}
}

#endif