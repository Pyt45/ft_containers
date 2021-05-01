/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:22:33 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/05/01 16:06:43 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>

template<class Iterator>
class reverse_iterator : public Iterator {
	public:
		typedef Iterator iterator_type;
		// typedef typename std::iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer_type pointer;
		typedef typename Iterator::reference_type refrence;
	public:
		reverse_iterator() : Iterator() {}
		reverse_iterator(pointer ptr) : Iterator(ptr) {}
		reverse_iterator(iterator_type it) {}
		reverse_iterator& operator==( reverse_iterator const & rhs ) {
			if (this != &rhs)
				Iterator::operator==(rhs);
			return (*this);
		}
		template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it) : Iterator(rev_it) {}
		~reverse_iterator() {}

		refrence operator*() const {
			return Iterator::_ptr->_data;
		}
		// reverse_iterator operator+ (difference_type n) const {
		// 	pointer tmp = Iterator::_ptr;
			
		// 	while (n--)
		// 		tmp = tmp->_prev;
		// 	return tmp;
		// }
		reverse_iterator& operator++() {
			if (this->_ptr)
				this->_ptr = this->_ptr->_prev;
			return *this;
		}
		reverse_iterator  operator++(int) {
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		}
		// reverse_iterator operator- (difference_type n) const {
		// 	pointer tmp = Iterator::_ptr;
			
		// 	while (n--)
		// 		tmp = tmp->_next;
		// 	return tmp;
		// }
		reverse_iterator& operator--() {
			if (this->_ptr->_next->_next)
				this->_ptr = this->_ptr->_next;
			return (*this);
		}
		reverse_iterator  operator--(int) {
			reverse_iterator temp = *this;
			--(*this);
			return (temp);
		}
		pointer operator->() const {
			return &(operator*());
		}
		reverse_iterator& operator=( reverse_iterator const & rhs ) {
			Iterator::_ptr = rhs._ptr;
			return (*this);
		}
};

#endif
