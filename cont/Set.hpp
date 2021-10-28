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
		private:
			class val_cmp: public std::binary_function< pair<const T, const T>, pair<const T, const T>, bool > {
				friend class set;
				protected:
					Compare cmp;
					val_cmp (Compare c): cmp(c) { }
				public:
					bool operator()(const pair<const T, const T>& __x, const pair<const T, const T>& __y) const {
						return cmp(__x.first, __y.first);
					}
			};
		public:
			typedef T key_type;
			typedef T value_type;
			typedef Compare key_compare;
			typedef key_compare value_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;

			// Iterators
			typedef pair<const key_type, const value_type> pair_type;
			typedef __red_black_tree<const key_type, const value_type, val_cmp>* __set_tree;
			typedef __red_black_tree<const key_type, const value_type, val_cmp> __set_tree_r;
			typedef Node<pair_type>* __node_tree;
			// Iterators
			typedef ft::__set_iterator<__set_tree, __node_tree, pair_type> iterator;
			typedef ft::__const_set_iterator<__set_tree, __node_tree, pair_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;

		private:
			__set_tree_r __tree;
			allocator_type alloc;
			key_compare __comp;
			value_compare __value_cmp;
			// val_cmp __val_cmp(value_compare());
		public:
			// Memeber Functions
			set(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): __tree(val_cmp(comp)), alloc(alloc), __comp(comp) {}
			template <class InputIterator>
				set(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()): __tree(val_cmp(comp)), alloc(alloc), __comp(comp) {
						insert(first, last);
					}
			set& operator=(const set& x) {
				if (this != &x) {
					clear();
					insert(x.begin(), x.end());
				}
				return *this;
			}
			set(const set& x): __tree(x.__tree) {
				this->insert(x.begin(), x.end());
			}
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
			bool empty() const {
				return __tree.size() == 0;
			}
			size_type size() const {
				return __tree.size();
			}
			size_type max_size() const {
				return __tree.max_size();
			}
			pair<iterator,bool> insert (const value_type& val) {
				__node_tree node = __tree.__search_key(val);
				if (node)
					return pair<iterator, bool>(iterator(node), false);
				__tree.__insert(pair<T, T>(val, val));
				node = __tree.__search_key(val);
				return pair<iterator, bool>(iterator(node), true);
			}
			iterator insert (iterator position, const value_type& val) {
				static_cast<void>(position);
				return insert(val).first;
			}
			template <class InputIterator>
				void insert (InputIterator first, InputIterator last) {
					for (; first != last; first++)
						this->insert(*first);
				}
			void erase (iterator position) {
				__tree->__remove(position->first);
			}
			size_type erase (const value_type& val) {
				if (__tree.__remove(val))
					return 1;
				return 0;
			}
			void erase (iterator first, iterator last) {
				for (; first != last; first++)
					this->erase(first);
			}
			void swap (set& x) {
				__tree.swap(x.__tree);
			}
			void clear() {
				this->erase(this->begin(), this->end());
			}
			key_compare key_comp() const {
				return __comp;
			}
			value_compare value_comp() const {
				return __value_cmp;
			}
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
				iterator first = begin();
				iterator last = end();
				for (; first != last; first++)
					if (!__comp(*first, val))
						return first;
				return end();
			}
			iterator upper_bound (const value_type& val) const {
				iterator first = begin();
				iterator last = end();
				for (; first != last; first++)
					if (__comp(val, *first))
						return first;
				return end();
			}
			pair<iterator,iterator> equal_range (const value_type& val) const {
				return pair<iterator, iterator>(lower_bound(val), upper_bound(val));
			}
			allocator_type get_allocator() const {
				return alloc;
			}
			void __print_set() {
				__tree.__print_tree();
			}
	};
}

#endif