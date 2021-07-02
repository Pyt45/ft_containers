/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:45:04 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/07/02 17:59:23 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft {
	template <bool Cond, class T = void>
		struct enable_if {};
	template <class T>
		struct enable_if<true, T> { typedef T type; };
	
	template <class T>
		struct is_integral {
			static const bool value;
		};
}

#endif