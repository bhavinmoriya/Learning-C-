#include <iostream>
#include <string>
#include <list>
#define print(x) cout << x << endl;
using namespace std;
int main()
{
    list<int> integers;
    for (int i = 1; i < 10; i++)
    {
        integers.push_back(i);
    }
    integers.push_back(2);
    integers.push_front(100);
    list<int>::iterator it = integers.begin();
    advance(it, 3); // remove the 4th(=3+1) element from the list
    integers.erase(it);
    for (int i : integers)
    {
        print(i);
    }
    return 0;
}
