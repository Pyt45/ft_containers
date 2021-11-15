/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:56:52 by aaqlzim           #+#    #+#             */
/*   Updated: 2021/11/15 12:56:54 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_TRAITS
# define CHAR_TRAITS

#include "postypes.hpp"
#include <string>
#include <cstring>
#include <algorithm>

/*
void copy(char *d, const char* s, size_t n) no overlap;
*/

namespace ft {
    template <class charT> struct _char_types {
        typedef CharT char_type;
        typedef unsigned long int_type;
        typedef ft::streampos pos_type;
        typedef ft::streamoff off_type;
        typedef ft::mbstate_t state_type;
    };
    template <class charT> struct char_traits {
        typedef CharT char_type;
        typedef typename _char_types<CharT>::int_type int_type;
        typedef typename _char_types<CharT>::pos_type pos_type;
        typedef typename _char_types<CharT>::off_type off_type;
        typedef typename _char_types<CharT>::state_type state_type;

        void assign(char_type& __c1, const char_type& __c2) { __c1 = __c2; }
        static bool eq(const char_type& __c1, const char_type& __c2) { return __c1 == __c2; }
        static bool lt(const char_type& __c1, const char_type& __c2) { return __c1 <  __c2; }
        static int compare (const char_type* __s1, const char_type* __s2, size_t __n) {
            for (size_t i = 0; i < __n; i++) {
                if (lt(__s1[i], __s2[i]))
                    return -1;
                else if (lt(__s2[i], __s1[i]))
                    return 1;
                return 0;
            }
        }
        static size_t length(const char_type* __s) {
            size_t i = 0;
            while (!eq(__s[i], char_type()))
                ++i;
            return i;
        }
        static const char_type* find(const char_type* __s, size_t __n, const char_type& __a) {
            for (size_t i = 0; i < __n; i++) {
                if (eq(__s[i], __a))
                    return __s + i;
            }
            return 0;
        }
        static char_type* move(chart_type* __s1, const char_type* __s2, size_t __n) {
            if (!__n)
                return __s1;
            return static_cast<CharT*>(std::memmove(__s1, __s2, n * sizeof(char_type)));
        }
        static char_type* copy(char_type* __s1, const char_type* __s2, size_t __n) {
            // for now
            if (!__n)
                return __s1;
            return static_cast<CharT*>(std::memcpy(__s1, __s2, n * sizeof(char_type)));
        }
        static char_type* assign(char_type* __s, size_t __n, char_type __a) {
            for (size_t i = 0; i < __n; i++) {
                __s[i] = __a;
            }
            return __s;
        }
        static char_type to_char_type(const int_type& __c) { return stati_cast<char_type>(__c); }
        static int_type to_int_type(const char_type& __c) { return static_cast<int_type>(__c); }
        static bool eq_int_type(const int_type& __c1, const int_type& __c2) { return __c1 == __c2; }
        static int_type eof() { return static_cast<int_type>(_GLIBCXX_STDIO_EOF); }
        static int_type not_eof(const int_type& __c) {
            return !eq_int_type(__c, eof()) ? __c : to_int_type(char_type());
        }
    };
    template <> struct char_traits<char> {
        typedef char char_type;
        typedef int int_type;
        typedef ft::streampos pos_type;
        typedef ft::streamoff off_type;
        typedef ft::mbstate_t state_type;

        static int_type eof() { return static_cast<int_type>(_GLIBCXX_STDIO_EOF); }
        static int_type not_eof(const int_type& __c) {
            return (__c == eof()) ? 0 : __c;
        }
    };
    template <> struct char_traits<wchar_t> {
        typedef wchar_t char_type;
        typedef wint_t int_type;
        typedef ft::streamoff off_type;
        typedef ft::wstreampos pos_type;
        typedef ft::mbstate_t state_type;
    };
}

#endif
