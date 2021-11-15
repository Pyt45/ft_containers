#ifndef BASIC_STRING_HPP
# define BASIC_STRING_HPP

#include "char_traits.hpp"
#include <memory>

namespace ft {
    template <class charT, class traits = ft::char_traits<charT>, class Alloc = std::allocator<charT> >
    class basic_string {
        public:
            typedef traits traits_type;
            typedef Alloc allocator_type;
            typedef traits_type::char_type value_type;
    };
}

#endif