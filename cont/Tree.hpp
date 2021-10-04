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
# include "iterator_traits.hpp"
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
			typedef Node< ft::pair<Key, T> > __node;
			typedef typename Alloc::template rebind< __node >::other __node_allocator;
		private:
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
				if (node->_data.first > root->_data.first) {
				// if (cmp(root->_data, node->_data)) {
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
				__check_color(node);
				// __fix_tree_after_insertion();
				// __fix_tree_after_deletion();
				// __reset_start_end();
			}
			__pointer __search(__pointer root, __pointer node) {
				if (cmp(root->_data, node->_data)) {
					if (root->__right == nullptr || root->__right->_data.first == node->_data.first)
						return (root->__right);
					return __search(root->__right, node);
				}
				else {
					if (root->__left == nullptr || root->__left->_data.first == node->_data.first)
						return (root->__left);
					return __search(root->__left, node);
				}
			}
		public:
			__red_black_tree() {
				// cmp = key_compare();
				// __root = __alloc.allocate(0);
				// __alloc.construct(__root);
				__root = nullptr;
				__size = 0;
				__start = nullptr;
				__end = nullptr;
			}
			__red_black_tree(value_type data) {
				// cmp = key_compare();
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
				__size++;
			}
			__pointer __search(__pointer node) {
				if (__root == nullptr || __root->_data.first == node->_data.first)
					return (__root);
				return __search(__root, node);
			}
			size_type size() const {
				return __size;
			}
			void __left_rotate(__pointer node) {
				__pointer tmp = node->__right;
				node->__right = tmp->__left;
				if (node->__right) {
				 	node->__right->__parent = node;
				 	node->__right->_isLeftChild = false;
				}
				if (!node->__parent) {
					__root = tmp;
					tmp->__parent = nullptr;
				}
				else {
				 	tmp->__parent = node->__parent;
				 	if (node->_isLeftChild) {
				 		tmp->_isLeftChild = true;
				 		tmp->__parent->__left = tmp;
				 	}
				 	else {
				 		tmp->_isLeftChild = false;
				 		tmp->__parent->__right = tmp;
				 	}
				}
				tmp->__left = node;
				node->_isLeftChild = true;
				node->__parent = tmp;
				return ;
			}
			void __right_rotate(__pointer node) {
				__pointer tmp = node->__left;
				node->__left = tmp->__right;
				if (node->__left) {
					node->__left->__parent = node;
					node->__left->_isLeftChild = true;
				}
				if (!node->__parent) {
					__root = tmp;
					tmp->__parent = nullptr;
				}
				else {
					tmp->__parent = node->__parent;
					if (node->_isLeftChild) {
						tmp->_isLeftChild = true;
						tmp->__parent->__left = tmp;
					}
					else {
						tmp->_isLeftChild = false;
						tmp->__parent->__right = tmp;
					}
				}
				tmp->__right = node;
				node->_isLeftChild = false;
				node->__parent = tmp;
			}
			void __left_right_rotate(__pointer node) {
				__left_rotate(node->__left);
				__right_rotate(node);
			}
			void __right_left_rotate(__pointer node) {
				__right_rotate(node->__right);
				__left_rotate(node);
			}
			void __rotate_tree(__pointer node) {
				if (!node->_isLeftChild) {
					if (!node->__parent->_isLeftChild) {
						__left_rotate(node->__parent->__parent);
						node->_black = false;
						node->__parent->_black = true;
						if (node->__parent->__left)
							node->__parent->__left->_black = false;
					}
					else {
						__left_right_rotate(node->__parent->__parent);
						node->_black = true;
						if (node->__right)
							node->__right->_black = false;
						if (node->__left)
							node->__left->_black = false;
					}
				} else {
					if (node->__parent->_isLeftChild) {
						__right_rotate(node->__parent->__parent);
						node->_black = false;
						node->__parent->_black = true;
						if (node->__parent->__right)
							node->__parent->__right->_black = false;
					}
					else {
						__right_left_rotate(node->__parent->__parent);
						node->_black = true;
						if (node->__right)
							node->__right->_black = false;
						if (node->__left)
							node->__left->_black = false;
					}
				}
			}
			void __correct_tree(__pointer node) {
				if (node->__parent->_isLeftChild) {
					// aunt is node->_parent->_parent->_right
					if (!node->__parent->__parent->__right ||
						node->__parent->__parent->__right->_black)
					{
						std::cout << "right rotate\n";
						__rotate_tree(node);
					}
					else if (node->__parent->__parent->__right) {
							node->__parent->__parent->__right->_black = true;
						if (node->__parent->__parent != __root)
							node->__parent->__parent->_black = false;
						node->__parent->_black = true;
					}
				}
				else {
					if (!node->__parent->__parent->__left ||
						node->__parent->__parent->__left->_black)
					{
						std::cout << "left rotate\n";
						__rotate_tree(node);
					}
					else if (node->__parent->__parent->__left) {
						node->__parent->__parent->__left->_black = true;
						if (node->__parent->__parent != __root)
							node->__parent->__parent->_black = false;
						node->__parent->_black = true;
					}
				}
			}
			void __check_color(__pointer node) {
				if (node == __root)
					return ;
				else if (node->__parent && !node->_black && !node->__parent->_black)
						__correct_tree(node);
				else if (node->__parent)
					__check_color(node->__parent);
			}
			// Debug mode
			# if DEBUG >= 1
			void __print_tree() {
				if (__root == nullptr)
					return ;
				__print_tree(__root, 0);
			}
			# endif
			__pointer __tree_max(__pointer __x) {
				while (__x->__right)
					__x = __x->__right;
				return __x;
			}

			__pointer __tree_min(__pointer __x) {
				while (__x->__left)
					__x = __x->__left;
				return __x;
			}
			__pointer __tree_next(__pointer __x) {
				if (__x->__right)
					return __tree_min(__x->__right);
				while(!__x->_isLeftChild)
					__x = __x->__parent;
				return __x->__parent;
			}
			__pointer __tree_prev(__pointer __x) {
				if (__x->__left)
					return __tree_max(__x->__left);
				__pointer tmp = __x;
				while (tmp->_isLeftChild)
					tmp = tmp->__parent;
				return tmp->__parent;
			}
	};
	template <class __base_iter>
	class __tree_iterator {
		public:
			typedef __base_iter iterator_type;
			typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type value_type;
			typedef typename iterator_traits<iterator_type>::difference_type difference_type;
			typedef typename iterator_traits<iterator_type>::pointer pointer;
			typedef typename iterator_traits<iterator_type>::reference reference;
		private:
			iterator_type __i;
			reference operator*() const {
				return *__i;
			}
		public:
			__tree_iterator(): __i() {}
			__tree_iterator(__tree_iterator const & __u): __i(__u.base()) {}
			__tree_iterator& operator=(__tree_iterator const & __u) {
				if (this != &__u)
					this->__i = __u.base();
				return (*this);
			}
			~__tree_iterator() {}

			pointer operator->() const {
				return &(operator*());
			}
			__tree_iterator& operator++() {
				__i = __i->__tree_next(__i);
				return *this;
			}
			__tree_iterator operator++(int) {
				__tree_iterator tmp(*this);
				++(*this);
				return tmp;
			}
			__tree_iterator& operator--() {
				__i = __i->__tree_prev(__i);
				return *this;
			}
			__tree_iterator operator--(int) {
				__tree_iterator tmp(*this);
				--(*this);
				return tmp;
			}
			iterator_type base() const {
				return __i;
			}
			friend bool operator==(const __tree_iterator& __x, const __tree_iterator& __y) {
				return __x.__ptr_ == __y.__ptr_;
			}
			friend bool operator!=(const __tree_iterator& __x, const __tree_iterator& __y) {
				return !(__x == __y);
			}
	};
}

#endif
