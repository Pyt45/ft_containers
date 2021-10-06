/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set_t.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:36:03 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/06/29 18:36:04 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "iterator_traits.hpp"
# include "Tree.hpp"
# include "Type_traits.hpp"
# include "Utility.hpp"

namespace ft {
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set {
		public:
			typedef T key_type;
			typedef T value_type;
			typedef Compare key_compare;
			typedef Compare value_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;

			// Iterators
			typedef pair<const key_type, value_type> pair_type;
			typedef __red_black_tree<T, T>* __set_tree;
			typedef ft::__tree_iterator<__set_tree> iterator;
			// typedef implementation-defined iterator;
			// typedef implementation-defined const_iterator;
			// typedef ft::reverse_iterator<iterator> reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename allocater_type::difference_type difference_type;
			typedef typename allocater_type::size_type size_type;
			typedef typename allocator_type::template rebind< __red_black_tree<T, T> >::other __set_allocator;
		private:
			__set_tree __tree;
			allocator_type alloc;
			__set_allocator __alloc;
			key_compare __comp;
		public:
			// Memeber Functions
			set(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());
			template <class InputIterator>
				set(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type());
			set(const set& x);

			// Iterators
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;

			// Capacity
			bool empty() const;
			size_type size() const;
			size_type max_size() const;

			// Modifiers
			pair<iterator,bool> insert (const value_type& val);
			iterator insert (iterator position, const value_type& val);
			template <class InputIterator>
				void insert (InputIterator first, InputIterator last);
			void erase (iterator position);
			size_type erase (const value_type& val);
			void erase (iterator first, iterator last);
			void swap (set& x);
			void clear();

			// Observers
			key_compare key_comp() const;
			value_compare value_comp() const;

			// Operations
			iterator find (const value_type& val) const;
			size_type count (const value_type& val) const;
			iterator lower_bound (const value_type& val) const;
			iterator upper_bound (const value_type& val) const;
			pair<iterator,iterator> equal_range (const value_type& val) const;
			allocator_type get_allocator() const;
	};
}

#endif