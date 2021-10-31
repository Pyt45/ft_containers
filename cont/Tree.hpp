/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:41:03 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/10/27 09:56:05 by aaqlzim          ###   ########.fr       */
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
			Node<data_type> *__parent;
			Node<data_type> *__left;
			Node<data_type> *__right;
			bool		_isLeftChild;
			bool		_black;
			data_type _data;
		public:
			Node(): _data() {
				__parent = __left = __right = nullptr;
				_black = false;
				_isLeftChild = false;
			}
			Node(data_type data): _data(data) {
				__parent = __left = __right = nullptr;
				_black = false;
				_isLeftChild = false;
			}
			~Node() {
			}
			friend bool operator==(const Node& __x, const Node& __y) {
				return __x._data.first == __y._data.first;
			}
			friend bool operator!=(const Node& __x, const Node& __y) {
				return !(__x == __y);
			}
	};

	template < class Key, class T, class Compare, class Alloc = std::allocator< ft::pair<const Key, T> > >
	class __red_black_tree {
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef Alloc allocater_type;
			typedef ft::pair<const key_type, mapped_type> value_type;
			typedef Compare value_compare;
			typedef typename allocater_type::reference reference;
			typedef typename allocater_type::const_reference const_reference;
			typedef typename allocater_type::pointer pointer;
			typedef typename allocater_type::const_pointer const_pointer;
			typedef typename allocater_type::difference_type difference_type;
			typedef typename allocater_type::size_type size_type;
			typedef Node< value_type >* __pointer;
			typedef Node< value_type > __node;
			typedef typename Alloc::template rebind< __node >::other __node_allocator;
		private:
			__node_allocator	__alloc;
			size_type			__size;
			__pointer			__root;
			__pointer			__start;
			__pointer			__end;
			value_compare		cmp;
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
			void __remove_end_from_tree() {
				__pointer tmp = __root;
				while (tmp->__right && tmp->__right != __end)
					tmp = tmp->__right;
				tmp->__right = nullptr;
				__end->__parent = nullptr;
			}
			void __reset_start_end() {
				__pointer tmp = __root;
				if (tmp)
					__start = __tree_min(tmp);
				tmp = __root;
				if (tmp) {
					while (tmp->__right)
						tmp = tmp->__right;
					if (tmp == __end)
						tmp = tmp->__parent;
					else 
						tmp->__right = __end;
					__end->__parent = tmp;
				}
			}
			void __insert_(__pointer root, __pointer node) {
				// if (!cmp(node->_data, root->_data)) {
				if (node->_data.first >= root->_data.first) {
					if (root->__right) {
						// __insert_(root->__right, node);
						__pointer tmp = root;
						__pointer y = nullptr;
						while (tmp) {
							y = tmp;
							if (node->_data.first < tmp->_data.first)
								tmp = tmp->__left;
							else
								tmp = tmp->__right;
						}
						
						node->__parent = y;
						if (node->_data.first < y->_data.first) {
							y->__left = node;
							node->_isLeftChild = true;
						}
						else {
							y->__right = node;
							node->_isLeftChild = false;
						}
					}
					else {
						root->__right = node;
						node->__parent = root;
						node->_isLeftChild = false;
						__size++;
					}
				}
				else {
					if (root->__left == nullptr) {
						root->__left = node;
						node->__parent = root;
						node->_isLeftChild = true;
						__size++;
					}
					else {
						// __insert_(root->__left, node);
						__pointer tmp = root;
						__pointer y = nullptr;
						while (tmp) {
							y = tmp;
							if (node->_data.first < tmp->_data.first)
								tmp = tmp->__left;
							else
								tmp = tmp->__right;
						}
						node->__parent = y;
						if (node->_data.first < y->_data.first) {
							y->__left = node;
							node->_isLeftChild = true;
						}
						else {
							y->__right = node;
							node->_isLeftChild = false;
						}
					}
				}
				__check_color(node);
			}
			void __optimize_insert(__pointer root, __pointer node) {
				__pointer tmp = root;
				__pointer y = nullptr;
				while (tmp) {
					y = tmp;
					if (cmp(node->_data, tmp->_data))
						tmp = tmp->__left;
					else
						tmp = tmp->__right;
				}
				node->__parent = y;
				if (cmp(node->_data, y->_data)) {
					y->__left = node;
					node->_isLeftChild = true;
					__size++;
				}
				else {
					y->__right = node;
					node->_isLeftChild = false;
					__size++;
				}
				__check_color(node);
			}
			__pointer __search(__pointer root, __pointer node) {
				if (cmp(node->_data, root->_data)) {
					if (root->__left == nullptr || root->__left->_data.first == node->_data.first)
						return (root->__left);
					return __search(root->__left, node);
				}
				else {
					if (root->__right == nullptr || root->__right->_data.first == node->_data.first)
						return (root->__right);
					return __search(root->__right, node);
				}
			}
			__pointer __search_key_(__pointer root, const key_type& key) const {
				if (key < root->_data.first) {
					if (root->__left == nullptr || root->__left->_data.first == key)
						return root->__left;
					return __search_key_(root->__left, key);
				}
				else {
					if (root->__right == nullptr || root->__right->_data.first == key)
						return root->__right;
					return __search_key_(root->__right, key);
				}
			}
			void __remove_from_tree(__pointer __node_to_del) {
				// Unlink the node
				// 1. node to be deleted has no children
				// 2. node to be deleted has only one child
				// 3. node to be deleted has two children
				__pointer __successor = (!__node_to_del->__left || !__node_to_del->__right) ?
										__node_to_del : __tree_next(__node_to_del);
				__pointer  __successor_child = __successor->__left ? __successor->__left : __successor->__right;
				__pointer __uncle = nullptr; // uncle of __successor_child
				// case (1|2) if __successor == __node_to_del
				// link __successor_child to _successor's parent
				if (__successor_child) {
					__successor_child->__parent = __successor->__parent;
				}
				// find the uncle
				if (__successor->__parent) {
					if (__successor->_isLeftChild) {
						__successor->__parent->__left = __successor_child;
						if (__successor_child)
							__successor_child->_isLeftChild = true;
						if (__successor != __root) {
							__uncle = __successor->__parent->__right;
							if (__uncle)
								__uncle->_isLeftChild = false;
						}
						else
							__root = __successor_child;
					}
					else {
						__successor->__parent->__right = __successor_child;
						if (__successor_child)
							__successor_child->_isLeftChild = false;
						__uncle = __successor->__parent->__left;
						if (__uncle)
							__uncle->_isLeftChild = true;
					}
				}
				else
					__root = __successor_child;
				// save the origin color of the removed_node
				bool __removed_black = __successor->_black;

				// case 3 if __successor != __node_to_del
				if (__successor != __node_to_del) {
					__successor->__parent = __node_to_del->__parent;
					if (__successor->__parent) {
						if (__node_to_del->_isLeftChild) {
							__successor->__parent->__left = __successor;
							__successor->_isLeftChild = true;
						}
						else {
							__successor->__parent->__right = __successor;
							__successor->_isLeftChild = false;
						}
					}
					// link the left child of __node_to_del to __successor's left child
					__successor->__left = __node_to_del->__left;
					if (__successor->__left)
						__successor->__left->__parent = __successor;
					// link the right child of __node_to_del to __successor's right child
					__successor->__right = __node_to_del->__right;
					if (__successor->__right)
						__successor->__right->__parent = __successor;
					// __successor will inherit the color from __node_to_del
					__successor->_black = __node_to_del->_black;
					if (__node_to_del == __root)
						__root = __successor;
				}
				__alloc.destroy(__node_to_del);
				__alloc.deallocate(__node_to_del, 1);
				// there is no need to rebalance if remove a red, or if we removed the last node
				if (__removed_black && __root) {
					// __fix_tree_after_deletion(__uncle, __succsessor_child, __);
					if (__successor_child)
						__successor_child->_black = true;
					else {
						while (true) {
							if (!__uncle->_isLeftChild) {
								if (!__uncle->_black) {
									__uncle->_black = true;
									__uncle->__parent->_black = false;
									__left_rotate(__uncle->__parent);
									if (__root == __uncle->__left)
										__root = __uncle;
									__uncle = __uncle->__left->__right;
								}
								if ((!__uncle->__left || __uncle->__left->_black) &&
									(!__uncle->__right || __uncle->__right->_black)) {
									__uncle->_black = false;
									__successor_child = __uncle->__parent;
									if (__successor_child == __root || !__successor_child->_black) {
										__successor_child->_black = true;
										break ;
									}
									__uncle = (__successor_child->_isLeftChild) ? __successor_child->__parent->__right : __successor_child->__parent->__left;
								}
								else {
									if (!__uncle->__right || __uncle->__right->_black) {
										__uncle->__left->_black = true;
										__uncle->_black = false;
										__right_rotate(__uncle);
										__uncle = __uncle->__parent;
									}
									__uncle->_black = __uncle->__parent->_black;
									__uncle->__parent->_black = true;
									__uncle->__right->_black = true;
									__left_rotate(__uncle->__parent);
									break ;
								}
							}
							else {
								if (!__uncle->_black) {
									__uncle->_black = true;
									__uncle->__parent->_black = false;
									__right_rotate(__uncle->__parent);
									if (__root == __uncle->__right)
										__root = __uncle;
									__uncle = __uncle->__right->__left;
								}
								if ((!__uncle->__left || __uncle->__left->_black) &&
									(!__uncle->__right || __uncle->__right->_black)) {
									__uncle->_black = false;
									__successor_child = __uncle->__parent;
									if (!__successor_child->_black || __successor_child == __root) {
										__successor_child->_black = true;
										break ;
									}
									__uncle = __successor_child->_isLeftChild ? __successor_child->__parent->__right : __successor_child->__parent->__left;
								}
								else {
									if (!__uncle->__left || __uncle->__left->_black) {
										__uncle->__right->_black = true;
										__uncle->_black = false;
										__left_rotate(__uncle);
										__uncle = __uncle->__parent;
									}
									__uncle->_black = __uncle->__parent->_black;
									__uncle->__parent->_black = true;
									__uncle->__left->_black = true;
									__right_rotate(__uncle->__parent);
									break ;
								}
							}
						}
					}
				}
			}
		public:
			__red_black_tree(value_compare c): cmp(c) {
				__root = nullptr;
				__size = 0;
				__start = __end = __alloc.allocate(1);
				__alloc.construct(__start);
				__alloc.construct(__end);
			}
			~__red_black_tree() {
				
			}
			size_type max_size() const {
				return __alloc.max_size();
			}
			__pointer __get_start() const {
				__pointer tmp = __root;
				return __tree_min(tmp);
			}
			__pointer __get_end() const {
				return __end;
			}
			void __insert(const value_type& val) {
				__pointer node = __alloc.allocate(1);
				__alloc.construct(node, val);
				if (this->__root == nullptr) {
					__root = node;
					__root->_black = true;
					__reset_start_end();
					__size++;
					return ;
				}
				__remove_end_from_tree();
				// __insert_(__root, node);
				__optimize_insert(__root, node);
				__reset_start_end();
				// __size++;
			}
			__pointer __search_key(const key_type& key) const {
				if (__root == nullptr || __root->_data.first == key)
					return __root;
				return __search_key_(__root, key);
			}
			__pointer __search(__pointer node) {
				if (__root == nullptr || __root->_data.first == node->_data.first)
					return (__root);
				return __search(__root, node);
			}
			size_type __remove(const key_type& key) {
				__pointer __node_to_del = __search_key(key);
				if (__node_to_del) {
					__remove_end_from_tree();
					__remove_from_tree(__node_to_del);
					__reset_start_end();
					if (!__root)
						__start = __end;
					__size--;
					return 1;
				}
				return 0;
			}
			void swap(__red_black_tree& __t) {
				__pointer _root = __root;
				__pointer _start = __start;
				__pointer _end = __end;
				size_type _size = __size;

				__root = __t.__root;
				__start = __t.__start;
				__end = __t.__end;
				__size = __t.__size;

				__t.__root = _root;
				__t.__start = _start;
				__t.__end = _end;
				__t.__size = _size;
			}
			size_type size() const {
				return __size;
			}
			void set_size(size_type s) {
				__size = s;
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
						__rotate_tree(node);
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
						__rotate_tree(node);
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
				if (node->__parent)
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
			__pointer __tree_max(__pointer __x) const {
				while (__x->__right)
					__x = __x->__right;
				return __x;
			}

			__pointer __tree_min(__pointer __x) const {
				while (__x->__left)
					__x = __x->__left;
				return __x;
			}
			__pointer __tree_next(__pointer __x) const {
				if (__x->__right)
					return __tree_min(__x->__right);
				while(!__x->_isLeftChild)
					__x = __x->__parent;
				return __x->__parent;
			}
			__pointer __tree_prev(__pointer __x) const {
				if (__x->__left)
					return __tree_max(__x->__left);
				__pointer tmp = __x;
				while (tmp->_isLeftChild)
					tmp = tmp->__parent;
				return tmp->__parent;
			}
	};
	template <class __base_iter, class __node_ptr, class __pair_iter>
	class __tree_iterator {
		public:
			typedef __base_iter iterator_type;
			typedef __node_ptr iterator_ptr;
			typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type value_type;
			typedef typename iterator_traits<iterator_type>::difference_type difference_type;

			typedef __pair_iter& reference;
			typedef __pair_iter* pointer;

		private:
			iterator_type __i;
			iterator_ptr __p;
		public:
			__tree_iterator(): __i() {}
			__tree_iterator(iterator_ptr __u) {
				__i = iterator_type(__u);
				__p = __u;
			}
			__tree_iterator(__tree_iterator const & __u) {
				__i = __u.base();
				__p = __u.__p;
			}
			__tree_iterator& operator=(const __tree_iterator & __u) {
				if (this != &__u) {
					this->__i = __u.base();
					this->__p = __u.__base_ptr();
				}
				return (*this);
			}
			~__tree_iterator() {}

			pointer operator->() const {
				return &(operator*());
			}
			reference operator*() const {
				return __p->_data;
			}
			__tree_iterator& operator++() {
				__p = __i->__tree_next(__p);
				return *this;
			}
			__tree_iterator operator++(int) {
				__tree_iterator tmp(*this);
				++(*this);
				return tmp;
			}
			__tree_iterator& operator--() {
				__p = __i->__tree_prev(__p);
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
			iterator_ptr __base_ptr() const {
				return __p;
			}
			friend bool operator==(const __tree_iterator& __x, const __tree_iterator& __y) {
				return __x.__p == __y.__p;
			}
			friend bool operator!=(const __tree_iterator& __x, const __tree_iterator& __y) {
				return !(__x == __y);
			}
	};

	template <class __base_iter, class __node_ptr, class __pair_iter>
	class __const_tree_iterator {
		public:
			typedef __base_iter iterator_type;
			typedef __node_ptr iterator_ptr;
			typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type value_type;
			typedef typename iterator_traits<iterator_type>::difference_type difference_type;
			typedef __tree_iterator<__base_iter, __node_ptr, __pair_iter> iterator;

			typedef __pair_iter& reference;
			typedef __pair_iter* pointer;

		private:
			iterator_type __i;
			iterator_ptr __p;
		public:
			__const_tree_iterator(): __i() {}
			__const_tree_iterator(iterator_ptr __u) {
				__i = iterator_type(__u);
				__p = __u;
			}
			__const_tree_iterator(const iterator& it) {
				__i = it.base();
				__p = it.__base_ptr();
			}
			__const_tree_iterator( __const_tree_iterator const & __u) {
				__i = __u.base();
				__p = __u.__p;
			}

			 __const_tree_iterator& operator=(const __const_tree_iterator& __u) {
				if (this != &__u) {
					this->__i = __u.base();
					this->__p = __u.__base_ptr();
				}
				return (*this);
			}
			~ __const_tree_iterator() {}

			pointer operator->() const {
				return &(operator*());
			}
			reference operator*() const {
				return __p->_data;
			}
			 __const_tree_iterator& operator++() {
				__p = __i->__tree_next(__p);
				return *this;
			}
			 __const_tree_iterator operator++(int) {
				 __const_tree_iterator tmp(*this);
				++(*this);
				return tmp;
			}
			 __const_tree_iterator& operator--() {
				__p = __i->__tree_prev(__p);
				return *this;
			}
			 __const_tree_iterator operator--(int) {
				 __const_tree_iterator tmp(*this);
				--(*this);
				return tmp;
			}
			iterator_type base() const {
				return __i;
			}
			iterator_ptr __base_ptr() const {
				return __p;
			}
			friend bool operator==(const  __const_tree_iterator& __x, const  __const_tree_iterator& __y) {
				return __x.__p == __y.__p;
			}
			friend bool operator!=(const  __const_tree_iterator& __x, const  __const_tree_iterator& __y) {
				return !(__x == __y);
			}
	};
	template <class __base_iter, class __node_ptr, class __pair_iter>
	bool operator==(const __tree_iterator<__base_iter, __node_ptr, __pair_iter>& __x, const __const_tree_iterator<__base_iter, __node_ptr, __pair_iter>& __y) {
		return __x.__base_ptr() == __y.__base_ptr();
	}
	template <class __base_iter, class __node_ptr, class __pair_iter>
	bool operator!=(const __tree_iterator<__base_iter, __node_ptr, __pair_iter>& __x, const __const_tree_iterator<__base_iter, __node_ptr, __pair_iter>& __y) {
		return !(__x == __y);
	}

	template <class __base_iter, class __node_ptr, class __pair_iter>
	class __set_iterator {
		public:
			typedef __base_iter iterator_type;
			typedef __node_ptr iterator_ptr;
			typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type value_type;
			typedef typename iterator_traits<iterator_type>::difference_type difference_type;
			// typedef typename iterator_traits<iterator_type>::pointer pointer;
			// typedef typename iterator_traits<iterator_type>::reference reference;

			typedef typename __pair_iter::first_type& reference;
			typedef typename __pair_iter::first_type* pointer;

		private:
			iterator_type __i;
			iterator_ptr __p;
		public:
			__set_iterator(): __i() {}
			__set_iterator(iterator_ptr __u) {
				__i = iterator_type(__u);
				__p = __u;
			}
			__set_iterator(__set_iterator const & __u) {
				__i = __u.base();
				__p = __u.__p;
				// pair = __u.pair;
			}
			__set_iterator& operator=(__set_iterator const & __u) {
				if (this != &__u) {
					this->__i = __u.base();
					this->__p = __u.__base_ptr();
				}
				return (*this);
			}
			~__set_iterator() {}

			pointer operator->() const {
				return &(operator*());
			}
			reference operator*() const {
				return __p->_data.first;
			}
			__set_iterator& operator++() {
				__p = __i->__tree_next(__p);
				return *this;
			}
			__set_iterator operator++(int) {
				__set_iterator tmp(*this);
				++(*this);
				return tmp;
			}
			__set_iterator& operator--() {
				__p = __i->__tree_prev(__p);
				return *this;
			}
			__set_iterator operator--(int) {
				__set_iterator tmp(*this);
				--(*this);
				return tmp;
			}
			iterator_type base() const {
				return __i;
			}
			iterator_ptr __base_ptr() const {
				return __p;
			}
			friend bool operator==(const __set_iterator& __x, const __set_iterator& __y) {
				return __x.__p == __y.__p;
			}
			friend bool operator!=(const __set_iterator& __x, const __set_iterator& __y) {
				return !(__x == __y);
			}
	};
	template <class __base_iter, class __node_ptr, class __pair_iter>
	class __const_set_iterator {
		public:
			typedef __base_iter iterator_type;
			typedef __node_ptr iterator_ptr;
			typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type value_type;
			typedef typename iterator_traits<iterator_type>::difference_type difference_type;
			typedef __set_iterator<__base_iter, __node_ptr, __pair_iter> iterator;

			typedef typename __pair_iter::first_type& reference;
			typedef typename __pair_iter::first_type* pointer;

		private:
			iterator_type __i;
			iterator_ptr __p;
		public:
			__const_set_iterator(): __i() {}
			__const_set_iterator(iterator_ptr __u) {
				__i = iterator_type(__u);
				__p = __u;
			}
			__const_set_iterator(const __const_set_iterator & __u) {
				__i = __u.base();
				__p = __u.__p;
			}
			__const_set_iterator(const iterator& it) {
				__i = it.base();
				__p = it.__base_ptr();
			}
			__const_set_iterator& operator=(const __const_set_iterator & __u) {
				if (this != &__u) {
					this->__i = __u.base();
					this->__p = __u.__base_ptr();
				}
				return (*this);
			}
			~__const_set_iterator() {}

			pointer operator->() const {
				return &(operator*());
			}
			reference operator*() const {
				return __p->_data.first;
			}
			__const_set_iterator& operator++() {
				__p = __i->__tree_next(__p);
				return *this;
			}
			__const_set_iterator operator++(int) {
				__const_set_iterator tmp(*this);
				++(*this);
				return tmp;
			}
			__const_set_iterator& operator--() {
				__p = __i->__tree_prev(__p);
				return *this;
			}
			__const_set_iterator operator--(int) {
				__const_set_iterator tmp(*this);
				--(*this);
				return tmp;
			}
			iterator_type base() const {
				return __i;
			}
			iterator_ptr __base_ptr() const {
				return __p;
			}
			friend bool operator==(const __const_set_iterator& __x, const __const_set_iterator& __y) {
				return __x.__p == __y.__p;
			}
			friend bool operator!=(const __const_set_iterator& __x, const __const_set_iterator& __y) {
				return !(__x == __y);
			}
	};
	template <class __base_iter, class __node_ptr, class __pair_iter>
	bool operator==(const __set_iterator<__base_iter, __node_ptr, __pair_iter>& __x, const __const_set_iterator<__base_iter, __node_ptr, __pair_iter>& __y) {
		return __x.__base_ptr() == __y.__base_ptr();
	}
	template <class __base_iter, class __node_ptr, class __pair_iter>
	bool operator!=(const __set_iterator<__base_iter, __node_ptr, __pair_iter>& __x, const __const_set_iterator<__base_iter, __node_ptr, __pair_iter>& __y) {
		return !(__x == __y);
	}
}

#endif
