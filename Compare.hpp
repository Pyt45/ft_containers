/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Compare.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:10:45 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/04/17 11:40:30 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_HPP
# define COMPARE_HPP
# include <functional>
# include <utility>

namespace ft {
	template<typename T>
	struct less : public std::binary_function<T, T, bool> {
		bool operator() (T a, T b) { return (a == b); }
	};
}

#endif