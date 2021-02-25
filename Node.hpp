/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:34:27 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/02/25 12:03:47 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>

namespace ft {
template<typename T>
class Node {
	private:
		T		data;
		Node	*head;
		Node	*tail;
	public:
		Node<T>(void) {
			head = nullptr;
			tail = nullptr;
		}
		Node<T>( Node<T> const & );
		Node<T> & operator=( Node<T> const & );
		~Node<T>(void);

		// bool	empty(void) const;
		// size_type 	size(void) const;
		// size_type max_size(void) const;
		// void	pop_back(void);
		Node	*getHead(void) const {
			return this->head;
		}
		Node	*getTail(void) const {
			return this->tail;
		}
		void	push_back(Node **head_ref, T const & data) {
			
		}
};
}

#endif