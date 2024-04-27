#include <iostream>
// #include <string>
// #include<cmath>
using namespace std;

int main()
{
    int month;
    cout << "Enter the month:";
    cin >> month;
    switch (month)
    {
    case 1:
        cout << "The month is January" << endl;
        break;
    case 2:
        cout << "The month is Feb" << endl;
        break;
    case 3:
        cout << "The month is Mar" << endl;
        break;
    case 4:
        cout << "The month is Apr" << endl;
        break;
    case 5:
        cout << "The month is May" << endl;
        break;
    case 6:
        cout << "The month is June" << endl;
        break;
    case 7:
        cout << "The month is July" << endl;
        break;
    case 8:
        cout << "The month is Aug" << endl;
        break;
    case 9:
        cout << "The month is Sept" << endl;
        break;
    case 10:
        cout << "The month is Oct" << endl;
        break;
    case 11:
        cout << "The month is Nov" << endl;
        break;
    case 12:
        cout << "The month is Dec" << endl;
        break;
    default:
        cout << "Enter the number in 1-12" << endl;
        break;
    }

    return 0;
}