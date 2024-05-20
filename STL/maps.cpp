#include <iostream>
#include <string>
#include <map>
#define print(x) cout << x << endl;
using namespace std;
int main()
{
    map<int, string> charPrint;
    int sizeSquare =10;
    for (int i = 0; i < sizeSquare; i++)
    {//print(i);
    
    // cout<<x;
        charPrint[i] = string(i,'*')+string(sizeSquare-i,'_');
        cout << charPrint[i] << endl;
    }
    return 0;
}
