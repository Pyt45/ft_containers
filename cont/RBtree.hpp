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

#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <iostream>
# include <memory>

template <class T, class Alloc = std::allocator<T> >
	class Tree {
		public:
			typedef T value_type;
			typedef Alloc allocater_type;
			typedef typename allocater_type::reference reference;
			typedef typename allocater_type::size_type size_type;
			typedef Tree* __pointer_tree;
		private:
			allocater_type __alloc;
			value_type __data;
			__pointer_tree __left;
			__pointer_tree __right;
		public:
			Tree(const allocater_type& alloc = allocater_type()) {
				__data = T();
				__alloc = alloc;
				__left = nullptr;
				__right = nullptr;
			}
			Tree(value_type val, const allocater_type& alloc = allocater_type()) {
				__alloc = alloc;
				__data = val;
				__left = __right = nullptr;
			}
			__pointer_tree __insert(__pointer_tree leaf, int data) {
				if (!leaf)
					return new Tree(data);
				if (data > leaf->__data)
					leaf->__right = __insert(leaf->__right, data);
				else
					leaf->__left = __insert(leaf->__left, data);
				return leaf;
			}

			void __inorder(__pointer_tree leaf) {
				if (!leaf)
					return ;
				__inorder(leaf->__left);
				std::cout << leaf->__data << std::endl;
				__inorder(leaf->__right);
			}
			// Tree(const Tree& rhs) {
			// 	*this = rhs;
			// }
			// Tree& operator==(const Tree& rhs) {
			// 	if (this != &rhs) {
			// 		this->__alloc = rhs.__alloc;
			// 		this->__data = rhs.__data;
			// 	}
			// }
			~Tree() {
			}
	};

#endif