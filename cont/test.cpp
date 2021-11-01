#include <iostream>
#include <string>
#include <deque>

#define NS 0

#if NS
    #include <map>
    #include <set>
    #include <stack>
    #include <vector>
    namespace ns = std;
#else
    #include "map.hpp"
    #include "set.hpp"
    #include "stack.hpp"
    #include "vector.hpp"
    namespace ns = ft;
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template <typename T, class Container = std::deque<T> >
class MuntantStack: public ns::stack<T, Container>
{
    public:
        MuntantStack() {}
        MuntantStack(const MuntantStack<T, Container>& src) { *this = src; }
        MuntantStack<T, Container>& operator=(const MuntantStack<T, Container>& rhs) {
            if (this != &rhs)
                this->c = rhs.c;
            return *this;
        }
        ~MuntantStack() {}
        typedef typename ns::stack<T, Container>::container_type::iterator iterator; 
        typedef typename ns::stack<T, Container>::container_type::const_iterator const_iterator;
        iterator begin() {
            return this->c.begin();
        }
        const_iterator begin() const {
            return this->c.begin();
        }
        iterator end() {
            return this->c.end();
        }
        const_iterator end() const {
            return this->c.end();
        }
};


// Vector tests
// void vector_iterator_test();
// void vector_capacity_test();
// void vector_access_test();
// void vector_modifiers_test();
// void vector_random_test();
// void vector_time_test();


// Map tests
// void map_iterator_test();
// void map_capacity_test();
// void map_access_test();
// void map_modifiers_test();
// void map_operations_test();
// void map_time_test();

// Set tests
// void set_iterator_test();
// void set_capacity_test();
// void set_modifiers_test();
// void set_operations_test();
// void set_time_test();

// Stack tests
void stack_test() {
    MuntantStack<int, ns::vector<int> > s;
    for (int i = 0; i < 10; i++)
        s.push(i);
    MuntantStack<int, ns::vector<int> >::iterator it = s.begin();
    for (; it != s.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "=========== empty ===========\n";
    std::cout << s.empty() << std::endl;
    std::cout << "=========== size ===========\n";
    std::cout << s.size() << std::endl;
    std::cout << "=========== pop ===========\n";
    while (!s.empty()) {
        std::cout << ' ' << s.top();
        s.pop();
    }
    std::cout << "\n";
}
int main(int argc, char **argv) {

    if (argc != 2) {
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}

	const int seed = atoi(argv[1]);
	srand(seed);
    stack_test();

    // ns::vector<std::string> vector_str;
    // ns::vector<int> vector_int;
    // ns::stack<int> stack_int;
    // ns::vector<int> vector_swap;
    // ns::stack<int, std::deque<int> > stack_deq_buffer;
    // ns::map<int, int> map_int;
    // ns::set<int> set_int;

    // for (int i = 0; i < COUNT; i++)
    //     vector_int.push_back(i);
    // vector_swap.swap(vector_int);
    // for (int i = 0; i < COUNT; i++)
    //     std::cout << vector_swap[i] << std::endl;
}