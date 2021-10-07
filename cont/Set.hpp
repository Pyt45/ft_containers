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
			// typedef pair<key_type, value_type> pair_type;
			typedef Compare key_compare;
			typedef key_compare value_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;

			// Iterators
			typedef pair<key_type, value_type> pair_type;
			typedef __red_black_tree<key_type, value_type>* __set_tree;
			typedef __red_black_tree<key_type, value_type> __set_tree_r;
			typedef Node<pair_type>* __node_tree;
			// Iterators
			typedef ft::__set_iterator<__set_tree, __node_tree, pair_type> iterator;
			typedef const ft::__set_iterator<__set_tree, __node_tree, pair_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;
			// typedef typename allocator_type::template rebind< __red_black_tree<T, T> >::other __set_allocator;
		private:
			__set_tree_r __tree;
			allocator_type alloc;
			// __set_allocator __alloc;
			key_compare __comp;
			value_compare __value_cmp;
		public:
			// Memeber Functions
			set(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) {
					this->__comp = comp;
					this->alloc = alloc;
				}
			template <class InputIterator>
				set(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type());
			set(const set& x);

			// Iterators
			iterator begin() {
				return iterator(__tree.__get_start());
			}
			const_iterator begin() const {
				return const_iterator(__tree.__get_start());
			}
			iterator end() {
				return iterator(__tree.__get_end());
			}
			const_iterator end() const {
				return const_iterator(__tree.__get_end());
			}
			reverse_iterator rbegin() {
				return reverse_iterator(end());
			}
			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(end());
			}
			reverse_iterator rend() {
				return reverse_iterator(begin());
			}
			const_reverse_iterator rend() const {
				return const_reverse_iterator(begin());
			}

			// Capacity
			bool empty() const {
				return __tree.size() == 0;
			}
			size_type size() const {
				return __tree.size();
			}
			size_type max_size() const {
				return __tree.max_size();
			}

			// Modifiers
			pair<iterator,bool> insert (const value_type& val) {
				__node_tree node = __tree.__search_key(val);
				if (node)
					return pair<iterator, bool>(iterator(node), false);
				__tree.__insert(pair<T, T>(val, val));
				node = __tree.__search_key(val);
				return pair<iterator, bool>(iterator(node), true);
			}
			iterator insert (iterator position, const value_type& val) {
				// must return an iterator to newly inserted ele or
				// if alredy exist
				this->insert(val);
				return position;
			}
			template <class InputIterator>
				void insert (InputIterator first, InputIterator last) {
					for (; first != last; first++)
						this->insert(*first);
				}
			void erase (iterator position) {
				// __node_tree node = __tree->__search_key(position->first)
				// __tree->__remove(position->first);
			}
			size_type erase (const value_type& val) {
				if (__tree->__search_key(val)) {
					__tree->__remove(val);
					return 1;
				}
				return 0;
			}
			void erase (iterator first, iterator last) {
				for (; first != last; first++)
					this->erase(first);
			}
			void swap (set& x) {
				set tmp;
				tmp.insert(this->begin(), this->end());
				this->clear();
				this->insert(x.begin(), x.end());
				x.clear();
				x.insert(tmp.begin(), tmp.end());
				tmp.clear();
			}
			void clear() {
				this->erase(this->begin(), this->end());
			}

			// Observers
			key_compare key_comp() const {
				return __comp;
			}
			value_compare value_comp() const {
				return __value_cmp;
			}

			// Operations
			iterator find (const value_type& val) const {
				__node_tree node = __tree.__search_key(val);
				if (node)
					return iterator(node);
				return end();
			}
			size_type count (const value_type& val) const {
				__node_tree node = __tree.__search_key(val);
				if (node)
					return 1;
				return 0;
			}
			iterator lower_bound (const value_type& val) const {
				iterator it = this->find(val);
				if (!__comp(it->first, val))
					return it;
				return end();
			}
			iterator upper_bound (const value_type& val) const {
				iterator it = this->find(val);
				if (it->first) {
					it++;
					if (__comp(val, it->first))
						return it;
				}
				return end();
			}
			pair<iterator,iterator> equal_range (const value_type& val) const {
				return pair<iterator, iterator>(lower_bound(val), upper_bound(val));
			}
			allocator_type get_allocator() const {
				return alloc;
			}
	};
}

#endif