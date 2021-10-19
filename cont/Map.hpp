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
#include "Type_traits.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, 
	class Alloc = std::allocator< ft::pair<const Key, T> > >
	class map {
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef __red_black_tree<Key, T>* __map_tree;
			typedef __red_black_tree<Key, T> __map_tree_r;
			typedef Node<value_type>* __node_tree;
			// Iterators
			typedef ft::__tree_iterator<__map_tree, __node_tree, value_type> iterator;
			typedef ft::__tree_iterator<__map_tree, __node_tree, const value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;
			// typedef typename allocator_type::template rebind< __red_black_tree<Key, T> >::other __map_allocator;

			class value_compare : public std::binary_function<Key, T, bool> {
				friend class map;
				protected:
					key_compare comp;
					value_compare (Compare c) : comp(c) { }
				public:
					typedef bool result_type;
					// typedef value_type first_argument_type;
					// typedef value_type second_argument_type;
					bool operator()(const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};
		private:
			// __map_tree __tree;
			__map_tree_r __tree;
			allocator_type alloc;
			// __map_allocator __alloc;
			key_compare __comp;
			value_compare __value_cmp(Compare());
		public:
			map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				this->__comp = comp;
				this->alloc = alloc;
				// this->__tree = __alloc.allocate(1);
				// __alloc.construct(__tree);
			}
			template <class InputIterator>
				map(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type(),
					typename enable_if< !is_integral<InputIterator>::value, bool >::type = true );
			map& operator=(const map& x) {
				if (this != &x) {
					__tree.clear();
					// __tree.value_comp() = x.__tree.value_comp();
					insert(x.begin(), x.end());
				}
				return *this;
			}
			map(const map& x): __tree(x.__tree) {
				this->insert(x.begin(), x.end());
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
				return (*((this->insert(make_pair(k,mapped_type()))).first)).second;
			}
			pair<iterator, bool> insert(const value_type& val) {
				// pair<iterator, bool> __pair;
				__node_tree node = __tree.__search_key(val.first);
				if (node)
					return pair<iterator, bool>(iterator(node), false);
				__tree.__insert(val);
				node = __tree.__search_key(val.first);
				return pair<iterator, bool>(iterator(node), true);
				// return __pair;
			}
			iterator insert(iterator position, const value_type& val) {
				// must return an iterator to newly inserted ele or
				// if alredy exist
				this->insert(val);
				return position;
			}
			template<class InputIterator>
				void insert(InputIterator first, InputIterator last,
				typename enable_if< !is_integral<InputIterator>::value, bool >::type = true) {
					while (first != last)
						this->insert(*first++);
				}
			void erase(iterator position) {
				// __node_tree node = __tree->__search_key(position->first);
				// __tree->__remove(position->first);
			}
			size_type erase(const key_type& k) {
				if (__tree.__search_key(k)) {
					__tree.__remove(k);
					return 1;
				}
				return 0;
			}
			void erase(iterator first, iterator last) {
				while (first != last)
					this->erase(first++);
			}
			void swap(map& x) {
				map tmp;
				tmp.insert(this->begin(), this->end());
				this->clear();
				this->insert(x.begin(), x.end());
				x.clear();
				x.insert(tmp->begin(), tmp->end());
				tmp.clear();
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
				// iterator it = this->find(k);
				// if (!__comp(it->first, k))
				// 	return it;
				iterator first = begin();
				iterator last = end();
				for (; first != last; first++)
					if (!__comp(first->first, k))
						return first;
				return end();
			}
			const_iterator lower_bound(const key_type& k) const {
				// iterator it = this->find(k);
				// if (!__comp(it->first, k))
				// 	return it;
				// return end();
				iterator first = begin();
				iterator last = end();
				for (; first != last; first++)
					if (!__comp(first->first, k))
						return first;
				return end();
			}
			iterator upper_bound(const key_type& k) {
				// iterator it = this->find(k);
				// if (it->first) {
				// 	it++;
				// 	if (__comp(k, it->first))
				// 		return it;
				// }
				// return end();
				iterator first = begin();
				iterator last = end();
				for (; first != last; first++)
					if (__comp(k, first->first))
						return first;
				return end();
			}
			const_iterator upper_bound(const key_type& k) const {
				// iterator it = this->find(k);
				// if (it->first) {
				// 	it++;
				// 	if (__comp(k, it->first))
				// 		return it;
				// }
				// return end();
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
	};
}

#endif