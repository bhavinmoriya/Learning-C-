#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Apply a transformation: multiply each element by 2
    std::transform(vec.begin(), vec.end(), vec.begin(), [](int x) { return x * 2; });

    // Print the transformed vector
    for (const auto& val : vec) {
        std::cout << val << " ";  // Output: 2 4 6 8 10
    }
    
    return 0;
}
