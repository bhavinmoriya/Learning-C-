#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

int main()
{
    vector<string> countries = {"Germany",
                                "India", "Brazil", "France", "Spain"};

    for (vector<string>::iterator it = countries.begin();
         it != countries.end(); it++)
        cout << *it << endl;
    return 0;
}