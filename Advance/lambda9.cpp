#include <iostream>
#include <vector>
#include <algorithm>
// You can use lambda functions within STL algorithms, like std::for_each or std::sort
int main() {
    std::vector<int> vec = {5, 2, 8, 1, 9};

    // Using lambda to sort in descending order
    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return a > b;
    });

    // Using lambda to print the vector
    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";  // Output: 9 8 5 2 1
    });
    std::cout << std::endl;
    return 0;
}
