/*#include <iostream>
#include <locale>
#include <string>
#include <codecvt>
#include <fstream>

int main ()
{
  std::u32string str ( U"\U00004f60\U0000597d" );  // ni hao (你好)

  std::locale loc (std::locale(), new std::codecvt_utf8<char32_t>);
  std::basic_ofstream<char32_t> ofs ("test.txt");
  ofs.imbue(loc);

  std::cout << "Writing to file (UTF-8)... ";
  ofs << str;
  std::cout << "done!\n";

  return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <future>
#include <cmath>
#include <functional>
#include <utility>
#define __cpp_17 0
class Test {
    public:
        std::string name;
        int age;
        Test(int a, std::string name): age(a), name(name) {}
};
#if __cpp_17
std::optional<std::string> createB(bool b) {
    if (b)
        return "Created";
    return {};
}
#else
    #define T 0
#endif

int main() {
    /*Test a = Test(15, "jack");
    Test a1 = Test(18, "adb");
    std::vector<Test> v;
    v.push_back(a);
    v.push_back(a1);

    std::sort(v.begin(), v.end(), [](Test e, Test e1) {
        if (e.name > e1.name)
            return 1;
        else if (e.name < e1.name)
            return -1;
        else
            return 0;
    });
    std::for_each(v.begin(), v.end(), [](Test e) {
        std::cout << e.age << " " << e.name << std::endl;
    });*/
    /*std::pointer_to_binary_function<double, double, double> powObj(pow);
    double num[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double squares[5];
    std::transform(num, num + 5, squares, std::bind2nd(powObj, 2));
    for (auto i: squares)
        std::cout << i << " ";
    std::cout << std::endl;*/
    //std::pair<int*, int*> p;
    //int first[] = {1, 2, 3, 4, 5};
    //int second[] = {1, 2, 8, 9, 10};
    /*int rslt[5];
    std::transform(first, first + 5, second, rslt, std::plus<int>());
    for (auto i: rslt)
        std::cout << i << " ";
    std::cout << std::endl;*/
    //p = std::mismatch(first, first + 5, second, std::equal_to<int>());
    //std::cout << "first mismatching pair is " << *p.first << " and " << *p.second << std::endl;
}
