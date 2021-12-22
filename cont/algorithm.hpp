/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:21:22 by ayoub             #+#    #+#             */
/*   Updated: 2021/12/21 21:23:39 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP
# include "iterator_traits.hpp"
#include <algorithm>

namespace ft {
	template <typename Iter>
	void swap(Iter __x, Iter __y) {
		typename ft::iterator_traits<Iter>::value_type tmp;

		tmp = *__x;
		*__x = *__y;
		*__y = tmp;
	}
// Distance
	template <class _InputIter>
	typename iterator_traits<_InputIter>::difference_type
	__distance_(_InputIter __first, _InputIter __last, std::input_iterator_tag) {
		typename iterator_traits<_InputIter>::difference_type __r(0);

		for (; __first != __last; ++__first)
			++__r;
		return __r;
	}
	template <class _RandIter>
	typename iterator_traits<_RandIter>::difference_type
	__distance_(_RandIter __first, _RandIter __last, std::random_access_iterator_tag) {
		return __last - __first;
	}
	template <class _InputIter>
	typename iterator_traits<_InputIter>::difference_type
	_distance(_InputIter __first, _InputIter __last){
		return __distance_(__first, __last, typename iterator_traits<_InputIter>::iterator_category());
	}
	// Advance
	template <class _InputIter>
	void __advanced_(_InputIter& __i,
					typename iterator_traits<_InputIter>::difference_type __n, std::input_iterator_tag) {
		for (; __n > 0; --__n)
			++__i;
	}
	template <class _BiDirIter>
	void __advanced_(_BiDirIter& __i,
					typename iterator_traits<_BiDirIter>::difference_type __n, std::bidirectional_iterator_tag) {
		if (__n >= 0)
			for (; __n > 0; --__n)
				++__i;
		else
			for (; __n < 0; ++__n)
				--__n;
	}
	template <class _RandIter>
	void __advanced_(_RandIter& __i,
					typename iterator_traits<_RandIter>::difference_type __n, std::random_access_iterator_tag) {
		__i += __n;
	}
	template <class _InputIter>
	void _advanced(_InputIter& __i,
					typename iterator_traits<_InputIter>::difference_type __n) {
		__advanced_(__i, __n, typename iterator_traits<_InputIter>::iterator_category());
	}
}


#endif