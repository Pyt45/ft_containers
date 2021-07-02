/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:45:04 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/07/02 19:28:27 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

# include <iostream>

namespace ft {
	template <bool Cond, class T = void>
		struct enable_if {};
	template <class T>
		struct enable_if<true, T> { typedef T type; };
	
	template <class T>
		struct is_integral {
			static const bool value = false;
		};
	template <>
		struct is_integral<bool> {
			static const bool value = true;
		};
	template <>
		struct is_integral<char> {
			static const bool value = true;
		};
	template <>
		struct is_integral<char16_t> {
			static const bool value = true;
		};
	template <>
		struct is_integral<char32_t> {
			static const bool value = true;
		};
	template <>
		struct is_integral<wchar_t> {
			static const bool value = true;
		};
	template <>
		struct is_integral<signed char> {
			static const bool value = true;
		};
	template <>
		struct is_integral<short int> {
			static const bool value = true;
		};
	template <>
		struct is_integral<int> {
			static const bool value = true;
		};
	 template <>
		struct is_integral<long int> {
			static const bool value = true;
		};
	template <>
		struct is_integral<long long int> {
			static const bool value = true;
		};
	template <>
		struct is_integral<unsigned char> {
			static const bool value = true;
		};
	template <>
		struct is_integral<unsigned short int> {
			static const bool value = true;
		};
	template <>
		struct is_integral<unsigned int> {
			static const bool value = true;
		};
	template <>
		struct is_integral<unsigned long int> {
			static const bool value = true;
		};
	template <>
		struct is_integral<unsigned long long int> {
			static const bool value = true;
		};
}

#endif