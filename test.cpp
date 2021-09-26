#include <iostream>
#include <vector>
#include <string>

bool binary_search_recursive(std::vector<int> v, int t, int low, int high)
{
    if (low > high)
        return false;
    else {
        int mid = (low + high) / 2;
        if (t == v[mid])
            return true;
        else if (t < v[mid])
            return binary_search_recursive(v, t, low, mid - 1);
        else
            return binary_search_recursive(v, t, mid + 1, high);
    }
}


int main()
{
    int arr[] = {3, 1, 5, 9, 0, 34, 12, 45, 60, 88};
    std::vector<int> v(arr, arr + 10);

    std::cout << binary_search_recursive(v, 3, 0, v.size()) << std::endl;
    std::cout << binary_search_recursive(v, 100, 0, v.size()) << std::endl;
}