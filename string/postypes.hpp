#ifndef POS_TYPES_HPP
# define POS_TYPES_HPP

#include <iostream>
#define END_OF_FILE -1
namespace ft {
    typedef long long streamoff;
    typedef std::ptrdiff_t streamsize;
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
            fpos(): __off_(0), __st_() {  }
            fpos(streamoff __off = streamoff()): __st_(), __off_(__off) {}
            fpos(const fpos& rhs) {}
            fpos& operator=(const fpos& rhs);
            ~fpos();
            operator streamoff() const { return __off_; }
            StateT state() const { return __st_; }
            void state(StateT __st) { __st_ = __st; }
            fpos& operator+=(streamoff __off) { __off_ += __off; return *this; };
            fpos operator+(streamoff __off) const { fpos __t(*this); __t += __off; return __t; }
            fpos& operator-=(streamoff __off) { __off_ -= __off; return *this; };
            fpos operator-(streamoff __off) const { fpos __t(*this); __t -= __off; return __t; }
    };
    template <class StateT>
        streamoff operator-(const fpos<StateT>& __x, const fpos<StateT>& __y) { return streamoff(__x) - streamoff(__y); }
    template <class StateT>
        bool operator==(const fpos<StateT>& __x, const fpos<StateT>& __y) { return streamoff(__x) == streamoff(__y); }
    template <class StateT>
        streamoff operator!=(const fpos<StateT>& __x, const fpos<StateT>& __y) { return streamoff(__x) != streamoff(__y); }

    typedef fpos<mbstate_t> streampos;
    typedef fpos<mbstate_t> wstreampos;
}

#endif