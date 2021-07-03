/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_t.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:35:53 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/07/03 10:11:05 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "Vector_t.hpp"

namespace ft {
	template < class T, class Container = ft::vector<T> >
	class stack {
		public:
			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
		protected:
			container_type c;
		public:
			stack(const container_type& ctnr = container_type()) {
				c = ctnr;
			}
			stack( stack const & rhs ) {
				*this = rhs;
			}
			stack &operator=( stack const & rhs ) {
				if (this != &rhs)
					this->c = rhs.c;
				return *this;
			}
			~stack() {
			}

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
			friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	};
	template <class T, class Container>
  		bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			  return (lhs.c == rhs.c);
		  }
	template <class T, class Container>
		bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs.c != rhs.c);
		}
	template <class T, class Container>
		bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs.c < rhs.c);
		}
	template <class T, class Container>
		bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs.c <= rhs.c);
		}
	template <class T, class Container>
		bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs.c > rhs.c);
		}
	template <class T, class Container>
		bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			return (lhs.c >= rhs.c);
		}
}

#endif