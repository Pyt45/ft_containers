/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:41:03 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/07/05 11:26:49 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <iostream>
# include "Utility.hpp"
# include <memory>

namespace ft {
	template <class Key, class T>
	class Node {
		public:
			Node<Key, T> *__root;
			Node<Key, T> *__left;
			Node<Key, T> *__right;
			bool		_isLeftChild;
			bool		_black;
			ft::pair<Key, T> _data;
		public:
			Node() {
				__root = __left = __right = nullptr;
				_black = true;
				_data = ft::make_pair<Key, T>(Key(), T());
			}
			Node(ft::pair<Key, T> data) {
				__root = __left = __right = nullptr;
				_data = data;
			}
			Node<Key, T>& operator=(const Node<Key, T>& rhs) {
				if (this != &rhs) {
					__root = rhs.__root;
					__left = rhs.__left;
					__right = rhs.__right;
					_black = rhs._black;
					_data = rhs._data;
				}
			}
			~Node() {
			}
	};
	template <class Key, class T>
	class __tree_iterator {
	};

	template < class Key, class T, class Alloc = std::allocator< ft::pair<const Key, T> > >
	class __red_black_tree {
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef Alloc allocater_type;
			typedef ft::pair<key_type, mapped_type> value_type;
			typedef typename allocater_type::reference reference;
			typedef typename allocater_type::const_reference const_reference;
			typedef typename allocater_type::pointer pointer;
			typedef typename allocater_type::const_pointer const_pointer;
			typedef typename allocater_type::difference_type difference_type;
			typedef typename allocater_type::size_type size_type;
			typedef Node<key_type, mapped_type>* __pointer;
			typedef typename Alloc::template rebind< Node<Key, T> >::other __node_allocator;
		public:
			__node_allocator __alloc;
			size_type __size;
			__pointer __parent;
			__pointer __start;
			__pointer __end;
		public:
			__red_black_tree(value_type data) {
				// value_type p = __alloc.allocate(1);
				__parent = __alloc.allocate(1);
				__size = 0;
			}
			// __red_black_tree(value_type data) {
			// 	__parent = __alloc.allocate();
			// }
	};
}

#endif