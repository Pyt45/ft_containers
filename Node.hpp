/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:34:27 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/02/24 12:50:11 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define BODE_HPP

# include <iostream>

namespace ft {
template<typename T>
class Node {
	private:
		T		data;
		Node	*next;
	public:
		class Iterator {
			public:
				Iterator<T>(void);
		};
		Node<T>(void);
		Node<T>( Node<T> const & );
		Node<T> & operator=( Node<T> const & );
		~Node<T>(void);

		bool	empty(void) const;
		// size_type 	size(void) const;
		// size_type max_size(void) const;
		void	pop_back(void);
		void	push_back(T data);
};
}

#endif