#include <iostream>
// #include <string>
using namespace std;

int main()
{
    string cars[] = {"Mercedes", "BMW", "Audi"};
    for (int i = 0; i < 3; i++)
    {
        cout << cars[i] << endl;
    }
    cout << "**************************************" << endl;
    // Determine the size of an array.
    cout << "Number of elements in the array is: " << sizeof(cars) / sizeof(cars[0]) << endl;
    // Hence we could use size of array in the for loop above
    cout << "**************************************" << endl;
    for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++)
    {
        cout << cars[i] << endl;
    }

    // For each does the same job and very convenient
    cout << "**************************************" << endl;
    for (string car : cars)
    {
        cout << car << endl;
    }
    return 0;
}
