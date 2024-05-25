#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {10, 584, 1, 2, 3, 4, 5};
    std::sort(vec.begin(), vec.end(), std::greater<int>());//descending

    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    std::sort(vec.begin(), vec.end());//ascending

    for (int v : vec) {
        std::cout << v << " ";
    }
    return 0;
}
