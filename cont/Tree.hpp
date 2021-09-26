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
	template <class D>
	class Node {
		public:
			typedef D data_type;
			Node<D> *__root;
			Node<D> *__left;
			Node<D> *__right;
			bool		_isLeftChild;
			bool		_black;
			data_type _data;
		public:
			Node() {
				__root = __left = __right = nullptr;
				_black = true;
			}
			Node(data_type data) {
				__root = __left = __right = nullptr;
				_black = false;
				_data = data;
			}
			Node<D>& operator=(const Node<D>& rhs) {
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
			typedef Node< ft::pair<Key, T> >* __pointer;
			typedef typename Alloc::template rebind< Node< ft::pair<Key, T> > >::other __node_allocator;
		public:
			__node_allocator __alloc;
			size_type __size;
			__pointer __parent;
			__pointer __start;
			__pointer __end;
		public:
			__red_black_tree() {
				__parent = __alloc.allocate(1);
				__alloc.construct(__parent);
				__size = 1;
				__start = nullptr;
				__end == nullptr;
			}
			__red_black_tree(value_type data) {
				__parent = __alloc.allocate(1);
				__alloc.construct(__parent, data);
				__size = 1;
				__start = nullptr;
				__end = nullptr;
			}
	};
}

#endif
