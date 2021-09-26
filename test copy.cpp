#include <vector>
#include <iostream>
#include <map>

template <class k, class T>
class m {
	public:
		typedef std::pair<k, T> value_type;

		m(value_type data) {
			_data = data;
		}
		~m() {}
		// int getFirst() {
		// 	return _data.first
		// }
	public:
		value_type _data;
};

int main()
{
	std::pair<int ,int> c;
	c.first = 4;
	c.second = 5;
	m<int, int> p(c);

	std::cout << p._data.first << std::endl;
	// std::map<int, int> m;

	// m.insert(std::pair<int, int>(1, 40));

	// std::cout << m[1] << std::endl;
}