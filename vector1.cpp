// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char f(string s){
    return s[2];
}

int main() {
    cout<<"String is made from various characters and not strings\n";
    string x = "abc";
    char b=f(x);
    cout<<f(x)<<endl;
    vector<int> v={1,2,3,4,5};
    cout<<"The vector v before the prefixing the elements is \n";
    for(int i=0;i<5;i++){
        cout<<v[i];
    }
    cout<<endl;
    cout<<"We could insert element in the begining of the vector as follows\n";
    for(int i=0;i<5;i++){
        v.insert(v.begin(),i);
    }
    for(int i:v) cout<<i<<" ";

    return 0;
}