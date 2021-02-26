/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:53:57 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/02/26 17:59:35 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "Node.hpp"
# include "ReverseIterator.hpp"

namespace ft {
	template <typename List>
	class ListIterator {
		public:
			ListIterator<List>( Node<List> * node) : _itr(node) {
				// I have no idea how to do that
			}
			// Do some Stuff
		private:
			Node<List>*	_itr;
	};

	template<class T>
	class List {
		public:
			typedef T value_type;
			typedef T &reference;
			typedef T const &const_reference;
			typedef T *pointer;
			typedef const T *const_pointer;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef Node<value_type> node_type;
			typedef ListIterator<T>* iterator;
		private:
			node_type *_head;
			node_type *_tail;
		public:
			List<T>( T const & data ) {
				_head = new Node<T>(data);
				_tail = new Node<T>(data);
			}
			List<T>( List<T> const & src );
			List<T> & operator=( List<T> const & src );
			~List<T>( void ) {
				return ;
			}
			iterator begin() {
				return ListIterator<T>(_head);
			}
	};
}

#endif