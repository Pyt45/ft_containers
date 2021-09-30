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
# include <iomanip>
# define DEBUG 1

namespace ft {
	template <class D>
	class Node {
		public:
			typedef D data_type;
			Node<D> *__parent;
			Node<D> *__left;
			Node<D> *__right;
			bool		_isLeftChild;
			bool		_black;
			data_type _data;
		public:
			Node() {
				__parent = __left = __right = nullptr;
				_black = false;
				_isLeftChild = false;
			}
			Node(data_type data) {
				__parent = __left = __right = nullptr;
				_black = false;
				_isLeftChild = false;
				_data = data;
			}
			Node<D>& operator=(const Node<D>& rhs) {
				if (this != &rhs) {
					__parent = rhs.__parent;
					__left = rhs.__left;
					__right = rhs.__right;
					_black = rhs._black;
					_data = rhs._data;
				}
			}
			~Node() {
			}
	};

	template < class Key, class T, class Compare = std::less< ft::pair<Key, T> >, class Alloc = std::allocator< ft::pair<const Key, T> > >
	class __red_black_tree {
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef Alloc allocater_type;
			typedef ft::pair<key_type, mapped_type> value_type;
			typedef Compare key_compare;
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
			__pointer __root;
			__pointer __start;
			__pointer __end;
			key_compare cmp;
			// Debug mode

			# if DEBUG >= 1
			void __print_tree(__pointer node, int indent) {
				if (node) {
					if (node->__right)
						__print_tree(node->__right, indent + 4);
					if (indent)
						std::cout << std::setw(indent) << ' ';
					if (node->__right) std::cout << " /\n" << std::setw(indent) << ' ';
					std::cout << node->_data.first << "|" << node->_black << std::endl;
					if (node->_data.first) {
						std::cout << std::setw(indent) << ' ' << " \\\n";
						__print_tree(node->__left, indent + 4);
					}
				}
			}
			# endif
			void __reset_start_end() {
				__pointer tmp = __root;
				while (tmp->_data.first <= __root->_data.first)
					tmp = tmp->__left;
				__start = tmp;
				tmp = __root;
				while (tmp->_data.first >= __root->_data.first)
					tmp = tmp->__right;
				__end = tmp;
			}
			void __insert(__pointer root, __pointer node) {
				// if (node->_data.first > root->_data.first) 
				if (cmp(root->_data, node->_data)) {
					if (root->__right == nullptr) {
						root->__right = node;
						node->__parent = root;
						node->_isLeftChild = false;
					}
					else
						__insert(root->__right, node);
				}
				// if (node->_data.first <= root->_data.first)
				else {
					if (root->__left == nullptr) {
						root->__left = node;
						node->__parent = root;
						node->_isLeftChild = true;
					}
					else
						__insert(root->__left, node);
				}
				// __check_color(node);
				// __fix_tree_after_insertion();
				// __fix_tree_after_deletion();
			}
		public:
			__red_black_tree() {
				cmp = key_compare();
				__root = __alloc.allocate(1);
				// __alloc.construct(__root);
				__root = nullptr;
				__size = 0;
				__start = nullptr;
				__end = nullptr;
			}
			__red_black_tree(value_type data) {
				cmp = key_compare();
				__root = __alloc.allocate(1);
				__alloc.construct(__root, data);
				__size = 1;
				__start = nullptr;
				__end = nullptr;
			}
			void __insert(__pointer node) {
				if (this->__root == nullptr) {
					__root = node;
					__root->_black = true;
					__size++;
					return ;
				}
				__insert(__root, node);
			}
			// Debug mode
			# if DEBUG >= 1
			void __print_tree() {
				if (__root == nullptr)
					return ;
				__print_tree(__root, 0);
			}
			# endif
	};
	template <class Key, class T>
	class __tree_iterator {
	};
}

#endif
