/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:03:28 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/07/02 17:37:15 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft {
	template <class T1, class T2>
	struct pair {
		public:
			typedef T1 first_type;
			typedef T2 second_type;
			first_type 	first;
			second_type second;
			pair() {
				first = T1();
				second = T2();
			}
			template<class U, class V>
				pair (const pair<U, V>& pr) {
					first = (T1)pr.first;
					second = (T2)pr.second;
					*this = pr;
				}
			pair (const first_type& a, const second_type& b) {
				first = a;
				second = b;
			}
			pair& operator=(const pair& pr) {
				if (this != &pr) {
					this->first =(T1)pr.first;
					this->second = (T2)pr.second;
				}
				return (*this);
			}
	};
	// template <bool Cond, class T = void>
	// struct enable_if {
	// 	public:
	// 		typedef T type;
	// };
	// template <class T>
	// struct is_integral : public std::integral_constant {
	// };
}


namespace ft {
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
		while (first1 != last1)
		{
			if ((!comp(*first2, *last2) && !comp(*last2, *first2)) || comp(*first2, *first2) < 0)
				return false;
			else if (comp(*first1, *first2) < 0)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (ft::pair<T1, T2>(x, y));
	}

	template <class T1, class T2>
	  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		  return lhs.first == rhs.first && lhs.second == rhs.second;
	  }

	template <class T1, class T2>
	  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		  return !(lhs == rhs);
	  }

	template <class T1, class T2>
	  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		  return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	  }

	template <class T1, class T2>
	  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		  return !(rhs < lhs);
	  }

	template <class T1, class T2>
	  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		  return (rhs < lhs);
	  }

	template <class T1, class T2>
	  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		  return !(lhs < rhs);
	  }
}

#endif