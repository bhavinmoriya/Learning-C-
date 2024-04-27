#include <iostream>
// #include <string>
using namespace std;

int main()
{
    string name;

    
    do{   
        cout << "What is your name:";
        // cin >> name;
        getline(cin, name); // if u have a space in the name then we should use getline and ws is to remove any white space.
    }while (name.empty());
    
    cout << "Hello! " << name << endl;
    return 0;
}
