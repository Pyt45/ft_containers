/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_t.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:35:37 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/07/05 09:09:05 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "iterator_traits.hpp"
# include "Utility.hpp"
# include <map>
# include "Tree.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, 
	class Alloc = std::allocator< pair<const Key, T> > >
	class map {
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocater_type;
			typedef typename allocater_type::reference reference;
			typedef typename allocater_type::const_reference const_reference;
			typedef typename allocater_type::pointer pointer;
			typedef typename allocater_type::const_pointer const_pointer;
			// Iterators
			// typedef implementation-defined iterator;
			// typedef implementation-defined const_iterator;
			// typedef ft::reverse_iterator<iterator> reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename allocater_type::difference_type difference_type;
			typedef typename allocater_type::size_type size_type;
		private:
			__red_black_tree* __tree;
		public:
			map(const key_compare& comp = key_compare(),
				const allocater_type& alloc = allocater_type());
			template <class InputIterator>
				map(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type());
			map(const map& x);
			// iterator begin();
			// const_iterator begin() const;
			// iterator end();
			// const_iterator end() const;
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;
			bool empty() const;
			size_type size() const;
			size_type max_size() const;
			mapped_type& operator[](const key_type& k);
			pair<iterator, bool> insert(const value_type& val);
			iterator insert(iterator position, const value_type& val);
			template<class InputIterator>
				void insert(InputIterator first, InputIterator last);
			void erase(iterator position);
			size_type erase(const key_type& k);
			void erase(iterator first, iterator last);
			void swap(map& x);
			void clear();
			key_compare key_comp() const;
			value_compare value_comp() const;
			iterator find(const key_type& k);
			const_iterator find(const key_type& k) const;
			size_type count(const key_type& k) const;
			iterator lower_bound(const key_type& k);
			const_iterator lower_bound(const key_type& k) const;
			iterator upper_bound(const key_type& k);
			const_iterator upper_bound(const key_type& k) const;
			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
			pair<iterator,iterator>	equal_range(const key_type& k);
			allocator_type get_allocator() const;
	};
}

#endif