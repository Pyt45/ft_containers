#include <iostream>
#include <string>
#include <deque>

// #define NS 0


// #if NS
    #include <map>
    #include <set>
    #include <stack>
    #include <vector>
//     namespace ns = std;
// #else
    #include "map.hpp"
    #include "set.hpp"
    // #include "stack.hpp"
    #include "vector.hpp"
//     namespace ns = ft;
// #endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))
/*
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
*/

// Vector tests
void vector_iterator_test() {
    // std::string arr[] = {"1", "2", "3", "4", "5", "6"};
    // ns::vector<std::string> v(arr, arr + static_cast<int>(sizeof(arr) / sizeof(std::string)));
    ns::vector<std::string> v;
    v.push_back("1");
    v.push_back("2");
    v.push_back("3");
    // v.push_back("4");
    // v.push_back("5");
    // ns::vector<std::string>::const_iterator it = v.begin();
    // ns::vector<std::string>::iterator ite = v.end();
    // for (; it != ite; it++)
        // std::cout << *it << std::endl; 
    std::cout << "size of vector = " << v.size() << std::endl;
    std::cout << "capacity of vector = " << v.capacity() << std::endl;
    ns::vector<std::string> vector_swap;
    for (int i = 0; i < 12; i++)
        vector_swap.push_back("1");
    // vector_swap = v;
    std::cout << "===========\n";
    std::cout << "size of vector_swap = " << vector_swap.size() << std::endl;
    std::cout << "capacity of vector_swap = " << vector_swap.capacity() << std::endl;
}
void vector_capacity_test() {
    ns::vector<int> vector_int(10, 5);
    std::cout << "max size = " << vector_int.max_size() << std::endl;
    std::cout << "size = " << vector_int.size() << std::endl;
    std::cout << "capacity = " << vector_int.capacity() << std::endl;
    vector_int.push_back(1);
    std::cout << "==== after push_back ====\n";
    std::cout << "size = " << vector_int.size() << std::endl;
    std::cout << "capacity = " << vector_int.capacity() << std::endl;
    vector_int.resize(50, 2);
    std::cout << "==== vector_int after resize ====\n";
    std::cout << "size = " << vector_int.size() << std::endl;
    std::cout << "capacity = " << vector_int.capacity() << std::endl;
    vector_int.resize(10, 3);
    std::cout << "size = " << vector_int.size() << std::endl;
    std::cout << "capacity = " << vector_int.capacity() << std::endl;
    std::cout << "==== vector_int after reserve ====\n";
    vector_int.reserve(100);
    std::cout << "size = " << vector_int.size() << std::endl;
    std::cout << "capacity = " << vector_int.capacity() << std::endl;
}
void vector_access_test() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    ns::vector<int> vector_string(arr, arr + static_cast<int>(sizeof(arr) / sizeof(int)));
    std::cout << "==== test try catch ====\n";
    try {
        for (size_t i = 0; i < 8; i++)
            std::cout << vector_string.at(i) << std::endl;
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
void vector_modifiers_test() {
    ns::vector<int> vector_int;
    ns::vector<int> vector_range;
    std::cout << "==== assign range method ====\n";
    for (int i = 0; i < 10; i++)
        vector_range.push_back(i);
    vector_int.assign(vector_range.begin(), vector_range.end());
    std::cout << "vector_int size: " << vector_int.size() << std::endl;
    std::cout << "vector_int capacity: " << vector_int.capacity() << std::endl;
    std::cout << "==== assign method ====\n";
    ns::vector<int> v_range(15, 5);
    v_range.assign(10, 10);
    std::cout << "v_range size: " << v_range.size() << std::endl;
    std::cout << "v_range capacity: " << v_range.capacity() << std::endl;
}

void vector_modifiers_second_test() {
    ns::vector<int> vector_int;
    vector_int.assign(10, 5);
    ns::vector<int>::iterator it = vector_int.insert(vector_int.begin(), 15);
    it = vector_int.insert(vector_int.end(), 100);
    std::cout << *it << std::endl;
    std::cout << "vec\n";
    for (int i = 0; i < (int)vector_int.size(); i++)
        std::cout << vector_int[i] << std::endl;
    vector_int.insert(it, 10, 17);
    std::cout << "vec\n";
    for (int i = 0; i < (int)vector_int.size(); i++)
        std::cout << vector_int[i] << std::endl;
}

void vector_random_test() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    ns::vector<int> vector_range(arr, arr + static_cast<int>(sizeof(arr) / sizeof(int)));
    ns::vector<int> vector_int;
    for (int i = 0; i < 15; i++)
        vector_int.push_back(i); 
    std::cout << "size of vector_int: " << vector_int.size() << std::endl;
    std::cout << "size of vector_range: " << vector_range.size() << std::endl;
    std::cout << "capacity of vector_range: " << vector_range.capacity() << std::endl;
    std::cout << "==== after = operator ====\n";
    vector_int = vector_range;
    std::cout << "size of vector_int: " << vector_int.size() << std::endl;
    std::cout << "capacity of vector_int: " << vector_int.capacity() << std::endl;
    for (int i = 0; i < (int)vector_int.size(); i++)
        std::cout << vector_int[i] << std::endl;
    std::cout << "=== copy constructor ====\n";
    ns::vector<int> vector_copy(vector_int);
    for (int i = 0; i < (int)vector_copy.size(); i++)
        std::cout << vector_copy[i] << std::endl; 
    std::cout << "size of vector_copy: " << vector_copy.size() << std::endl;
    std::cout << "capacity of vector_copy: " << vector_copy.capacity() << std::endl;
}
void vector_time_test() {
    ns::vector<int> vector_int;
    ns::vector<int> vector_swap;
    for (int i = 0; i < COUNT; i++)
        vector_int.push_back(i);
    vector_swap.swap(vector_int);
    std::cout << "vector_swap size: " << vector_swap.size() << std::endl;
    std::cout << "vector_swap capacity: " << vector_swap.capacity() << std::endl;
    for (int i = 0; i < COUNT; i++)
        std::cout << vector_swap[i] << std::endl;
}


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
/*
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
*/
int main(int argc, char **argv) {

    if (argc != 2) {
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}

	const int seed = atoi(argv[1]);
	srand(seed);

    // Vector
    // vector_iterator_test();
    // vector_capacity_test();
    // vector_access_test();
    // vector_modifiers_test();
    vector_modifiers_second_test();
    // vector_time_test();
    // vector_random_test();
    // Map

    // Set

    // Stack
    // stack_test();
}