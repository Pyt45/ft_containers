/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Btree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:41:10 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/07/18 13:27:57 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_HPP
# define BTREE_HPP

# include <iostream>
# include <map>
# include "Utility.hpp"
# include <iomanip>

template <class K, class V>
class Node {
	public:
		typedef K key_type;
		typedef V mapped_type;
	public:
		// Declare data type here Okey
		Node<K, V>* _parent;
		Node<K, V>* _left;
		Node<K, V>* _right;
		bool		_isLeftChild;
		bool		_black; // black = true, red = false
		key_type	_key;
		mapped_type	_val;
		ft::pair<K, V> _data;
	public:
		Node() {
			_parent = nullptr;
			_left = nullptr;
			_right = nullptr;
			_black = false;
			_isLeftChild = false;
			_key = K();
			_val = V();
			_data = ft::make_pair<K, V>(K(), V());
		}
		Node(key_type k, mapped_type v) {
			_parent = nullptr;
			_left = nullptr;
			_right = nullptr;
			_black = false;
			_isLeftChild = false; 
			_key = k;
			_val = v;
			_data = ft::make_pair<K, V>(k, v);
		}
		Node<K, V>& operator=(const Node<K, V>& rhs) {
			if (this != &rhs) {
				_parent = rhs._parent;
				_left = rhs._left;
				_right = rhs._right;
				_black = rhs._black;
				_isLeftChild = rhs._isLeftChild;
				_key = rhs._key;
				_val = rhs._val;
				_data = rhs._data;
			}
			return *this;
		}
		~Node() {
		}
};

template <class K, class V>
class RedBlackTree : public Node<K, V> {
	public:
		typedef K key_type;
		typedef V mapped_type;
	private:
		Node<K, V>*	_root;
		int			_size;
		void __insert(Node<K, V>* parent, Node<K, V>* node) {
			if (node->_key >= parent->_key) {
				if (!parent->_right) {
					parent->_right = node;
					node->_parent = parent;
					node->_isLeftChild = false;
				}
				else
					__insert(parent->_right, node);
			}
			else if (node->_key < parent->_key)
			{
				if (!parent->_left) {
					parent->_left = node;
					node->_parent = parent;
					node->_isLeftChild = true;
				}
				else
					__insert(parent->_left, node);
			}
			__check_color(node);
		}
		Node<K, V> *__search(key_type k, Node<K, V> *node) {
			if (node) {
				if (k == node->_key)
					return node;
				else if (k < node->_key)
					return __search(k, node->_left);
				else if (k >= node->_key)
					return __search(k, node->_right);
			}
			return nullptr;
		}
		void __print(Node<K, V>* node, int indent) {
			if (node != NULL)
			{
				if (node->_right)
					__print(node->_right, indent + 4);
				if (indent)
					std::cout << std::setw(indent) << ' ';
				if (node->_right) std::cout << " /\n" << std::setw(indent) << ' ';
				std::cout << node->_key << "|" << node->_black << std::endl;
				if (node->_key)
				{
					std::cout << std::setw(indent) << ' ' << " \\\n";
					__print(node->_left, indent + 4);
				}
			}
		}
		int __black_node(Node<K, V>* node) {
			if (!node)
				return 1;
			int rightblacknode = __black_node(node->_right);
			int leftblacknode = __black_node(node->_left);
			if (rightblacknode != leftblacknode)
				throw std::runtime_error("black node not the same");
			if (node->_black)
				leftblacknode++;
			return leftblacknode;
		}
	public:
		RedBlackTree() {
			_root = nullptr;
			_size = 0;
		}
		RedBlackTree(key_type k, mapped_type v) {
			_root = new Node<K, V>(k, v);
			_size = 0;
		}
		void __insert(key_type k, mapped_type v) {
			Node<K, V> *node = new Node<K, V>(k, v);
			if (this->_root == nullptr)
			{
				_root = node;
				this->_root->_black = true;
				this->_size++;
				return ;
			}
			this->__insert(this->_root, node);
			this->_size++;
		}
		void __left_rotate(Node<K, V>* node) {
			Node<K, V> *tmp = node->_right;
			node->_right = tmp->_left;
			if (node->_right) {
				std::cout << "1\n";
				node->_right->_parent = node;
				node->_right->_isLeftChild = false;
			}
			if (!node->_parent) {
				std::cout << "2\n";
				// we are the root node
				_root = tmp;
				tmp->_parent = nullptr;
			}
			else {
				std::cout << "3\n";
				tmp->_parent = node->_parent;
				if (node->_isLeftChild) {
					std::cout << "3->1\n";
					tmp->_isLeftChild = true;
					tmp->_parent->_left = tmp;
				}
				else {
					std::cout << "3->2\n";
					tmp->_isLeftChild = false;
					tmp->_parent->_right = tmp;
				}
			}
			tmp->_left = node;
			node->_isLeftChild = true;
			node->_parent = tmp;
			std::cout << "4\n";
		}
		void __right_rotate(Node<K, V>* node) {
			Node<K, V> *tmp = node->_left;
			node->_left = tmp->_right;
			if (node->_left) {
				node->_left->_parent = node;
				node->_left->_isLeftChild = true;
			}
			if (!node->_parent) {
				// we are the root node
				_root = tmp;
				tmp->_parent = nullptr;
			}
			// I think there well be a problem here
			else {
				tmp->_parent = node->_parent;
				if (node->_isLeftChild) {
					tmp->_isLeftChild = true;
					tmp->_parent->_left = tmp;
				}
				else {
					tmp->_isLeftChild = false;
					tmp->_parent->_right = tmp;
				}
			}
			// And here Also
			tmp->_left = node;
			node->_isLeftChild = true;
			node->_parent = tmp;
		}
		void __left_right_rotate(Node<K, V>* node) {
			__left_rotate(node->_left);
			//__right_rotate(node);
			// std::cout << "2\n";
		}
		void __right_left_rotate(Node<K, V>* node) {
			__right_rotate(node->_right);
			__left_rotate(node);
		}
		void __rotate(Node<K, V>* node) {
			if (node->_isLeftChild) {
				std::cout << "leftchild\n";
				if (node->_parent->_isLeftChild) {
					__right_rotate(node->_parent->_parent);
					node->_black = false;
					node->_parent->_black = true;
					if (node->_parent->_right)
						node->_parent->_right->_black = false;
				}
				else {
					__right_left_rotate(node->_parent->_parent);
					node->_black = true;
					node->_right->_black = false;
					node->_left->_black = false;
				}
			}
			else {
				if (!node->_parent->_isLeftChild) {
					std::cout << "left\n";
					__left_rotate(node->_parent->_parent);
					node->_black = false;
					node->_parent->_black = true;
					if (node->_parent->_left)
						node->_parent->_left->_black = false;
				}
				else {
					std::cout << "left_right\n";
					__left_right_rotate(node->_parent->_parent);
					node->_black = true;
					if (node->_right)
						node->_right->_black = false;
					if (node->_left)
						node->_left->_black = false;
				}
			}
		}
		void __correct_tree(Node<K, V>* node) {
			if (node->_parent->_isLeftChild) {
				std::cout << "rotate at the right\n";
				// aunt is node->_parent->_parent->_right
				if (!node->_parent->_parent->_right ||
				node->_parent->_parent->_right->_black)
					__rotate(node);
				else if (node->_parent->_parent->_right)
					node->_parent->_parent->_right->_black = true;
				node->_parent->_parent->_black = false;
				node->_parent->_black = true;
			}
			else {
				// aunt is grandparent.left
				// aunt = node->_parent->_parent->_left
				std::cout << "rotate here\n";
				if (!node->_parent->_parent->_left ||
				node->_parent->_parent->_left->_black)
					__rotate(node);
				else if (node->_parent->_parent->_left)
					node->_parent->_parent->_left->_black = true;
				if (node->_parent->_parent != _root)
					node->_parent->_parent->_black = false;
				node->_parent->_black = true;
			}
		}
		void __check_color(Node<K, V>* node) {
			if (node == _root)
				return ;
			else if (node->_parent && !node->_black && !node->_parent->_black)
				__correct_tree(node);
			else if (node->_parent)
				__check_color(node->_parent);
		}
		int __tree_height() {
			if (!_root)
				return 0;
			return __tree_height(_root) - 1;
		}
		int __tree_height(Node<K, V>* node) {
			if (!node)
				return 0;
			int leftheight = __tree_height(node->_left) + 1;
			int rightheight = __tree_height(node->_right) + 1;
			if (leftheight > rightheight)
				return leftheight;
			return rightheight;
		}
		int __black_node() {
			return __black_node(_root);
		}
		Node<K, V> *__search(key_type k) {
			return __search(k, _root);
		}
		void __print() {
			if (!_root)
				return ;
			__print(_root, 0);
		}
};

#endif