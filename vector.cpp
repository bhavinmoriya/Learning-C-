#include <iostream>
#include <vector>
// #include <string>
using namespace std;

std::vector<bool> getBinary(int size)
{
    std::vector<bool> result;
    /*
      Insert elements into result
    */
    bool digit;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter only 0 or 1: (Must be 0 or 1)";

        cin >> digit;
        result.push_back(digit);
    }
    return result;
}

int main()
{
    // const int size = 2;
    // bool sum[size + 1];
    int size;
    cout << "Enter the size of the first array:";
    cin >> size;
    vector<bool> a = getBinary(size);
    cout << "Enter the size of the second array:";
    cin >> size;
    vector<bool> b = getBinary(size);
    a.insert(a.end(), b.begin(), b.end());
    for (int num : a)
    {
        std::cout << num << " ";
    }
    cout << endl;
    cout << "Size of a " << a.size() << endl
         << "Size of b " << b.size();

    return 0;
}
