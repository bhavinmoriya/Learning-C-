#include <iostream>
using namespace std;
int main()
{
    int score = 1;
    int *myp = &score;
    cout << "Value of score is " << score << endl;
    cout << "Value of address of n is " << myp << endl;

    int &anotherScore = score;
    anotherScore = 2;
    cout << "Value of score is " << score << endl;
    cout << "Value of address of n is " << myp << endl;

    
    return 0;
}
