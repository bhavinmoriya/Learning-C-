#include <iostream>
#include <string>
// #define log(x) cout << x << endl;
using namespace std;

// int add(int a, int b)
// {
//     return a + b;
// }
// float add(float a, float b)
// {
//     return a + b;
// }
// string add(string a, string b)
// {
//     return a + b;
// }

template <typename T>

class Calculator
{
public:
    T add(T a, T b)
    {
        return a + b;
    }
    T subtract(T a, T b)
    {
        return a - b;
    }
    T multiply(T a, T b)
    {
        return a * b;
    }
    T divide(T a, T b)
    {
        if (b != 0)
        {
            return a / b;
        }
        else
        {
            cout << "Division by zero is not permitted!!!" << endl;
            return 0;
        }
    }
};

int main()
{

    // cout << add("Helllo, ", "3.8");
    Calculator<float> calFloat;
    cout << calFloat.add(1.3, 3.3) << endl;
    Calculator<int> calInt;
    cout << calInt.add(1, 3.3) << endl;
    Calculator<string> calStr;
    cout << calStr.add("Hellow", " Buddy") << endl;
    Calculator<float> cal1;
    cout << cal1.divide(1.3, 0) << endl;

    return 0;
}
