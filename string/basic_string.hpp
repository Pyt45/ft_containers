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
            typedef allocator_type::reference reference;
            typedef allocator_type::const_reference const_reference;
            typedef allocator_type::pointer pointer;
            typedef allocator_type::const_pointer const_pointer;
            // pre-defined iterator
            // typedef chart_iterator<charT> iterator;
            // typedef chart_iterator<const charT> const_iterator;
            // typedef reverse_iterator<iterator> reverse_iterator;
            // typedef reverse_iterator<const_iterator> const_reverse_iterator;
            typedef allocator_type::difference_type difference_type;
            typedef allocator_type::size_type size_type;
        private:
    };
}

#endif