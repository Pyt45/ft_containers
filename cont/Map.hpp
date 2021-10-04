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
# include "Tree.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, 
	class Alloc = std::allocator< ft::pair<const Key, T> > >
	class map {
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef __red_black_tree<Key, T>* __map_tree;
			// Iterators
			typedef ft::__tree_iterator<__map_tree> iterator;
			// typedef implementation-defined iterator;
			// typedef implementation-defined const_iterator;
			// typedef ft::reverse_iterator<iterator> reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;
			typedef typename allocator_type::template rebind< __red_black_tree<Key, T> >::other __map_allocator;
		private:
			__map_tree __tree;
			allocator_type alloc;
			__map_allocator __alloc;
			key_compare __comp;
		public:
			map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				this->__comp = comp;
				this->alloc = alloc;
				this->__tree = __alloc.allocate(1);
				__alloc.construct(__tree);
			}
			template <class InputIterator>
				map(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type());
			map& operator=(const map& x);
			map(const map& x);
			// iterator begin() {
			// 	return iterator()
			// }
			// const_iterator begin() const;
			// iterator end();
			// const_iterator end() const;
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;
			bool empty() const;
			size_type size() const {
				return __tree->size();
			}
			// size_type max_size() const {
			// 	return allocator_type::max_size();
			// }
			mapped_type& operator[](const key_type& k) {
				
			}
			// pair<iterator, bool> insert(const value_type& val);
			// iterator insert(iterator position, const value_type& val);
			// template<class InputIterator>
			// 	void insert(InputIterator first, InputIterator last);
			// void erase(iterator position);
			// size_type erase(const key_type& k);
			// void erase(iterator first, iterator last);
			// void swap(map& x);
			// void clear();
			// key_compare key_comp() const;
			// value_compare value_comp() const;
			// iterator find(const key_type& k);
			// const_iterator find(const key_type& k) const;
			// size_type count(const key_type& k) const;
			// iterator lower_bound(const key_type& k);
			// const_iterator lower_bound(const key_type& k) const;
			// iterator upper_bound(const key_type& k);
			// const_iterator upper_bound(const key_type& k) const;
			// pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
			// pair<iterator,iterator>	equal_range(const key_type& k);
			// allocator_type get_allocator() const;
	};
}

#endif