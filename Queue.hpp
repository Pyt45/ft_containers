/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:53:57 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/25 01:24:08 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

#include "Allocator.hpp"
#include "List.hpp"
#include "ReverseIterator.hpp"

namespace ft {
	template <class T, class Container = ft::List<T> >
	class queue {
		public:
			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			container_type c;
		public:
			queue() {}
			queue( queue const & rhs ) {
				*this = rhs;
			}
			queue &operator=( queue const & rhs ) {
				if (this != &rhs)
					this->c = rhs.c;
				return *this;
			}
			~queue() {}

			bool	empty() const {
				return this->c.empty();
			}

			size_type size() const {
				return this->c.size();
			}

			value_type& front() {
				return this->c.front();
			}

			const value_type& front() const {
				return this->c.front();
			}
            
            value_type& back() {
                return this->c.back();
            }
            
            const value_type& back() const {
                return this->c.back();
            }

			void push(const value_type& val) {
				this->c.push_back(val);
			}
			
			void	pop() {
				this->c.pop_front();
			}
	};
}

#endif