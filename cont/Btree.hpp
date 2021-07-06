/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Btree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:41:10 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/07/06 16:39:56 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_HPP
# define BTREE_HPP

# include <iostream>
# include <map>
enum _redBlack_tree_color { _S_red = false, _S_black = true };
struct _redBlack_tree_node_base {
	typedef _redBlack_tree_node_base* _Base_ptr;
	typedef const _redBlack_tree_node_base* _Const_Base_ptr;

	_redBlack_tree_color _M_color;
	_Base_ptr _M_parent;
	_Base_ptr _M_left;
	_Base_ptr _M_right;
};

template <class Key, class T>
class Node {
	public:
		typedef Key key_type;
		typedef T mapped_type;
	private:
		// Declare data type here Okey
	public:
};

#endif