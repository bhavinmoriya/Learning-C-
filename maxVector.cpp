#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {3,4,6};
    
    if (vec.empty()) {
        std::cout << "The vector is empty." << std::endl;
        return 0;
    }

    int maxElement = vec[0];
    for (const int& element : vec) {
        if (element > maxElement) {
            maxElement = element;
        }
    }

    std::cout << "The maximum element is " << maxElement << std::endl;
    //vec = {3,4,64545};
    int max_vec=*std::max(vec.begin(), vec.end());
    std::cout << "The maximum element(using STD library) is " << max_vec << std::endl;

    return 0;
}
