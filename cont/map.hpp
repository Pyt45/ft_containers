/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_t.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:35:37 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/12/20 16:30:52 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "iterator_traits.hpp"
# include "Utility.hpp"
# include "Tree.hpp"
# include "Type_traits.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, 
	class Alloc = std::allocator< ft::pair<const Key, T> > >
	class map {
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;

			class value_compare : public std::binary_function<value_type, value_type, bool> {
				friend class map;
				protected:
					key_compare comp;
					value_compare (Compare c) : comp(c) { }
				public:
					bool operator()(const value_type& __x, const value_type& __y) const {
						return comp(__x.first, __y.first);
					}
			};

			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef __red_black_tree<const Key, T, value_compare, Alloc>* __map_tree;
			typedef __red_black_tree<const Key, T, value_compare, Alloc> __map_tree_r;
			typedef Node<value_type>* __node_tree;
			// Iterators
			typedef ft::__tree_iterator<__map_tree, __node_tree, value_type> iterator;
			typedef ft::__const_tree_iterator<__map_tree, __node_tree, value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;

		private:
			__map_tree_r __tree;
			allocator_type alloc;
			key_compare __comp;
			value_compare __value_cmp(key_compare());
		public:
			map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): __tree(value_compare(comp)), alloc(alloc), __comp(comp) {}
			template <class InputIterator>
				map(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()): __tree(value_compare(comp)), alloc(alloc), __comp(comp) {
						insert(first, last);
					}
			map& operator=(const map& x) {
				if (this != &x) {
					clear();
					insert(x.begin(), x.end());
				}
				return *this;
			}
			map(const map& x): __tree(value_compare(x.__comp)), alloc(x.alloc), __comp(x.__comp) {
				this->insert(x.begin(), x.end());
			}
			~map() {
				clear();
			}
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
			mapped_type& operator[](const key_type& k) {
				__node_tree node = __tree.__search_key(k);
				if (node)
					return node->_data.second;
				return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
			}
			pair<iterator, bool> insert(const value_type& val) {
				__node_tree node = __tree.__search_key(val.first);
				if (node)
					return pair<iterator, bool>(iterator(node), false);
				__tree.__insert(val);
				node = __tree.__search_key(val.first);
				return pair<iterator, bool>(iterator(node), true);
			}
			iterator insert(iterator position, const value_type& val) {
				static_cast<void>(position);
				return insert(val).first;
			}
			template<class InputIterator>
				void insert(InputIterator first, InputIterator last) {
					while (first != last)
						this->insert(*first++);
				}
			void erase(iterator position) {
				__tree.__remove(position->first);
			}
			size_type erase(const key_type& k) {
				if (__tree.__remove(k))
					return 1;
				return 0;
			}
			void erase(iterator first, iterator last) {
				while (first != last) {
					this->erase(first++);
				}
			}
			void swap(map& x) {
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
			iterator find(const key_type& k) {
				__node_tree node = __tree.__search_key(k);
				if (node)
					return iterator(node);
				return end();
			}
			const_iterator find(const key_type& k) const {
				__node_tree node = __tree.__search_key(k);
				if (node)
					return iterator(node);
				return end();
			}
			size_type count(const key_type& k) const {
				__node_tree node = __tree.__search_key(k);
				if (node)
					return 1;
				return 0;
			}
			iterator lower_bound(const key_type& k) {
				iterator first = begin();
				iterator last = end();
				for (; first != last; first++)
					if (!__comp(first->first, k))
						return first;
				return end();
			}
			const_iterator lower_bound(const key_type& k) const {
				iterator first = begin();
				iterator last = end();
				for (; first != last; first++)
					if (!__comp(first->first, k))
						return first;
				return end();
			}
			iterator upper_bound(const key_type& k) {
				iterator first = begin();
				iterator last = end();
				for (; first != last; first++)
					if (__comp(k, first->first))
						return first;
				return end();
			}
			const_iterator upper_bound(const key_type& k) const {
				iterator first = begin();
				iterator last = end();
				for (; first != last; first++)
					if (__comp(k, first->first))
						return first;
				return end();
			}
			pair<const_iterator, const_iterator>	equal_range(const key_type& k) const {
				iterator first = this->lower_bound(k);
				iterator last = this->upper_bound(k);
				return pair<const_iterator, const_iterator>(first, last);
			}
			pair<iterator, iterator>	equal_range(const key_type& k) {
				iterator first = this->lower_bound(k);
				iterator last = this->upper_bound(k);
				return pair<iterator, iterator>(first, last);
			}
			allocator_type get_allocator() const {
				return alloc;
			}
			void __print_map() {
				__tree.__print_tree();
			}
	};
}

#endif
