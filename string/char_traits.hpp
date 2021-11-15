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

#include <iostream>
#include <string>


namespace ft {
    typedef long long streamoff;
    typedef union {
        char __mbstate8[128];
        long long _mbstteL;
    } __mbstate_t;
    typedef __mbstate_t __darwin_mbstate_t;
    typedef __darwin_mbstate_t mbstate_t;
    template <class StateT> class fpos {
        private:
            StateT __st_;
            streamoff __off_;
        public:
            fpos(streamoff __off = streamoff()): __st_(), __off_(__off) {}
            operator streamoff() const { return __of_; }
            StateT state() const { return __st_; }
            void state(StateT __st) { __st_ = __st; }
            fpos& operator+=(streamoff __off) { __off_ += __off; return *this };
            fpos operator+(streamoff __off) const { fpos __t(*this); __t += __off; return __t; }
            fpos& operator-=(streamoff __off) { __off_ -= __off; return *this };
            fpos operator-(streamoff __off) const { fpos __t(*this); __t -= __off; return __t; }
    };
    template <class StateT>
    streamoff operator-(const fpos<StateT>& __x, const fpos<StateT>& __y) { return streamoff(__x) - streamoff(__y); }
    template <class StateT>
    bool operator==(const fpos<StateT>& __x, const fpos<StateT>& __y) { return streamoff(__x) == streamoff(__y); }
    template <class StateT>
    streamoff operator!=(const fpos<StateT>& __x, const fpos<StateT>& __y) { return streamoff(__x) != streamoff(__y); }

    typedef fpos<mbstate_t> streampos;
    template <class charT> struct char_traits {
        typedef CharT char_type;
        typedef int int_type;
        typedef streamoff off_type;
        typedef streampos pos_type;
        typedef mbstate_t state_type;

        void assign(char_type& __c1, const char_type& __c2) { __c1 = __c2; }
        static bool eq(const char_type& __c1, const char_type& __c2) { return __c1 == __c2; }
        static bool lt(const char_type& __c1, const char_type& __c2) { return __c1 <  __c2; }
        static int compare (const char_type* __s1, const char_type* __s2, size_t __n);
        static size_t length(const char_type* __s);
        static const char_type* find(const char_type* __s, size_t __n, const char_type& __a);
    };
    // template <> struct char_traits<char>;
    // template <> struct char_traits<wchar_t>;
    
}

#endif
