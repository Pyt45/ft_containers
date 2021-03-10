#ifndef ALLOCATOR_HPP
# define ALLOCATOR_HPP

# include <memory>
# include <limits>

namespace ft {
	template<class T>
	class Allocator {
		public:
			// using value_type = T;
			typedef T value_type;
			typedef T* pointer;
			typedef const T* const_pointer;
			typedef void* void_pointer;
			typedef const void* const_void_pointer;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			template<class U>
			struct rebind {
				typedef Allocator<U> other;
			};
			Allocator( void ) {}
			template<class U>
			Allocator( Allocator<U> const & rhs ) {

			}
			~Allocator( void ) {}

			pointer allocate(size_type numObjs) {
				mAllocs += numObjs;
				return static_cast<pointer>(operator new(sizeof(T) * numObjs));
			}
			pointer allocate(size_type numObjs, const_pointer hint) {
				return allocate(numObjs);
			}
			void	deallocate(pointer p, size_type numObjs) {
				operator delete(p);
			}
			size_type max_size() const {
				return std::numeric_limits<size_type>::max() / sizeof(T);
			}
			// template<class U, class... Args>
			// void	construct(U *p, Args && ...args) {
			// 	new(p) U(std::forward<Args>(args)...);
			// }
			// template<class U>
			// void	destroy(U *p) {
			// 	p->~U();
			// }
			size_type get_allocator() const {
				return mAllocs;
			}
		private:
			static size_type mAllocs;
	};
};

template<class T>
typename ft::Allocator<T>::size_type ft::Allocator<T>::mAllocs = 0;

#endif