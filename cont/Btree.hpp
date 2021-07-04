/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Btree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:41:10 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/07/04 23:28:43 by ayoub            ###   ########.fr       */
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

#endif