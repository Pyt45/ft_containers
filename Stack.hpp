/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:53:57 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/26 13:00:26 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "Allocator.hpp"
#include "List.hpp"
#include "ReverseIterator.hpp"

namespace ft {
	template <class T, class Container = ft::List<T> >
	class stack {
		public:
			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			container_type c;
		public:
			stack() {}
			stack( stack const & rhs ) {
				*this = rhs;
			}
			stack &operator=( stack const & rhs ) {
				if (this != &rhs)
					this->c = rhs.c;
				return *this;
			}
			~stack() {}

			bool	empty() const {
				return this->c.empty();
			}

			size_type size() const {
				return this->c.size();
			}

			value_type& top() {
				return this->c.back();
			}

			const value_type& top() const {
				return this->c.back();
			}

			void push (const value_type& val) {
				this->c.push_back(val);
			}
			
			void	pop() {
				this->c.pop_back();
			}
	};
	template <class T, class Container>
  		bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	template <class T, class Container>
		bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	template <class T, class Container>
		bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	template <class T, class Container>
		bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	template <class T, class Container>
		bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	template <class T, class Container>
		bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
}

#endif