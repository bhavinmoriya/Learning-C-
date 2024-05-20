#include <iostream>
#include <string>
#define log(x) cout << x << endl;
using namespace std;
int main()
{
    int i, j;
    j = 1;

    while (j < 10)
    { // i = j++;
        // log(i);
        // i = ++j;
        // log(++j);
        log(j++);
    }

    return 0;
}
