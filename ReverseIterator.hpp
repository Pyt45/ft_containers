/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:22:33 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/05/02 18:36:38 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

template<class Iterator>
class ReverseIterator : public Iterator {
	public:
		typedef Iterator iterator_type;
		// typedef typename std::iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer_type pointer;
		typedef typename Iterator::reference_type refrence;
	public:
		ReverseIterator() : Iterator() {}
		ReverseIterator(Iterator const & ptr) : Iterator(ptr) {}
		ReverseIterator& operator=( ReverseIterator const & rhs ) {
			if (this != &rhs)
				this->_ptr = rhs._ptr;
			return (*this);
		}
		template <class Iter>
			ReverseIterator(const ReverseIterator<Iter>& rev_it) : Iterator(rev_it) {}
		~ReverseIterator() {}

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
		ReverseIterator operator++() {
			// this->_ptr = this->_ptr->_prev;
			return Iterator::operator--();
		}
		ReverseIterator  operator++(int) {
			ReverseIterator temp = *this;
			++(*this);
			return temp;
		}
		// reverse_iterator operator- (difference_type n) const {
		// 	pointer tmp = Iterator::_ptr;
			
		// 	while (n--)
		// 		tmp = tmp->_next;
		// 	return tmp;
		// }
		ReverseIterator operator--() {
			// this->_ptr = this->_ptr->_next;
			return Iterator::operator++();
		}
		ReverseIterator  operator--(int) {
			ReverseIterator temp = *this;
			--(*this);
			return (temp);
		}
		pointer operator->() const {
			return &(operator*());
		}
};

#endif
