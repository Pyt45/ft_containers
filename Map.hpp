/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:21:20 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/05/18 17:47:06 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "BTree.hpp"
# include "Compare.hpp"
# include "ReverseIterator.hpp"

namespace ft {
	template<class Key, class T, class Compare = ft::less <Key> >
	class map {
		public:
			typedef Key key_type;
			typedef T	mapped_type;
			typedef std::pair<const Key, T> value_type;
			typedef Compare key_compare;
			// typedef Compare value_compare;
			typedef size_t size_type;
		public:
			class value_compare {
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};
		private:
			Btree<T>	*_parent;
			Btree<T>	*_left;
			Btree<T>	*_right;
		public:
			map() {}
			// map(const key_ca)
			map( map const & rhs ) {}
			map & operator=( map const & rhs );
			~map();
	};
}

#endif