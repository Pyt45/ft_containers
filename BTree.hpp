/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BTree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:53:57 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/16 14:19:22 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_HPP
# define BTREE_HPP

const int count = 5;

template<class T>
struct				s_node
{
	T				key;
	struct s_node	*left;
	struct s_node	*right;
};

template<class T>

class Btree {
	public:
	Btree() : root(NULL) {}
	~Btree() {}
	void	insert(T key) {
		if (root)
			insert(key, root);
		else {
			root = new s_node<T>();
			root->key = key;
			root->left = NULL;
			root->right = NULL;
		}
	}
	void	printTree() {
		printTree(root, 0);
	}
	private:
		s_node<T>	*root;
		void		insert(T key, s_node<T>* leaf) {
			if (key < leaf->key) {
				if (leaf->left)
					insert(key, leaf->left);
				else {
					leaf->left = new s_node<T>();
					leaf->left->key = key;
					leaf->left->left = NULL;
					leaf->left->right = NULL;
				}
			}
			else if (key >= leaf->key) {
				if (leaf->right)
					insert(key, leaf->right);
				else {
					leaf->right = new s_node<T>();
					leaf->right->key = key;
					leaf->right->left = NULL;
					leaf->right->right = NULL;
				}
			}
		}
		void		printTree(s_node<T>* leaf, int space) {
			if (leaf != NULL)
			{
				space += count;
				printTree(leaf->right, space);
				std::cout << std::endl;
				for (int i = count; i < space; i++)
					std::cout << " ";
				std::cout << leaf->key << std::endl;
				printTree(leaf->left, space);
			}
		}
};

#endif