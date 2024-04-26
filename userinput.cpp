#include <iostream>
// #include <string>
using namespace std;

int main()
{
    string name;
    cout << "What is your name:";
    cin >> name;

    int age;
    cout << "What is your age:";
    cin >> age;

    cout << "Hello! " << name << " You are " << age << " years old.";

    return 0;
}
