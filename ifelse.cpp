#include <iostream>
// #include <string>
using namespace std;

// we shall discuss if else statments and an altenative to it ternary operator

int main()
{
    int age;
    cout << "What is your age:";
    cin >> age;
    

    if (age < 18){
        cout<<"You are not adult.\n";
    }
    else if (age == 18){
        cout<<"You are 18.\n";
    }
    else {
        cout<<"You are adult.\n";
    }

    // We do the same using ternary operator
    cout << "We do the almost same using ternary operator\n";
    cout << "What is your age:";
    cin >> age;
    age >= 18 ? cout<<"You are at least 18.\n":cout<<"You are less than 18.\n";
    
    return 0;
}