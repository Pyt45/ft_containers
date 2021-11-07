#include <iostream>
#include <vector>

class Test {
    public:
        std::string name;
        int age;
        Test(int a, std::string name): age(a), name(name) {}
};


int main() {
    Test a = Test(15, "jack");
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
    });
}
