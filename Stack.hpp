#include "Allocator.hpp"
#include "List.hpp"
#include "ReverseIterator.hpp"

namespace ft {
	template <class T, class Container = ft::List<T> >
	class stack {
		public:
			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef typename Container::reference reference;
			typedef typename Container::const_reference const_reference;
			container_type c;
		public:
			stack() {}
			stack( stack const & rhs ) {
				*this = rhs;
			}
			stack &operator=( stack const & rhs ) {
				if (this != &rhs)
					this->c = rhs.c;
				return *this;
			}
			~stack() {}

			bool	empty() const {
				return this->c.empty();
			}

			size_type size() const {
				return this->c.size();
			}

			value_type& top() {
				return this->c.back();
			}

			const value_type& top() const {
				return this->c.back();
			}

			void push (const value_type& val) {
				this->c.push_back(val);
			}
			
			void	pop() {
				this->c.pop_back();
			}
	};
}