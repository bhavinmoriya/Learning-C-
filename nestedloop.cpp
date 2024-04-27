#include <iostream>
// #include <string>
using namespace std;

// print the a matrix of your favorite symbol

int main()
{
    int rows, columns;
    char symbol;
    cout << "Number of rows: \n";
    cin >> rows;
    cout << "Number of columns: \n";
    cin >> columns;
    cout << "Symbol: \n";
    cin >> symbol;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            cout << symbol<<" ";
        }
        cout << endl;
    }

    return 0;
}
