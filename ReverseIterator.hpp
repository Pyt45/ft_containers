/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:22:33 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/05/02 00:14:19 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

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
		reverse_iterator& operator=( reverse_iterator const & rhs ) {
			if (this != &rhs)
				Iterator::operator=(rhs);
			return (*this);
		}
		template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it) : Iterator(rev_it) {}
		~reverse_iterator() {}

		refrence operator*() const {
			Iterator it(*this);
			return *--it;
		}
		// reverse_iterator operator+ (difference_type n) const {
		// 	pointer tmp = Iterator::_ptr;
			
		// 	while (n--)
		// 		tmp = tmp->_prev;
		// 	return tmp;
		// }
		reverse_iterator& operator++() {
			return Iterator::operator--();
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
			return Iterator::operator++();
		}
		reverse_iterator  operator--(int) {
			reverse_iterator temp = *this;
			--(*this);
			return (temp);
		}
		pointer operator->() const {
			return &(operator*());
		}
};

#endif
