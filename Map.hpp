/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:21:20 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/17 11:21:51 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "BTree.hpp"
# include "Compare.hpp"
# include "ReverseIterator.hpp"

namespace ft {
	template<class Key, class T, class Compare = ft::less<Key>>
	class map {
		public:
			typedef Key key_type;
			typedef T	mapped_type;
			// typedef std::pair<const Key, T> value_type;
			typedef size_type std::size_t;
		private:
		public:
			map();
			map( map const & rhs );
			map & operator=( map const & rhs );
			~map();
	}
}

#endif