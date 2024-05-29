

// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
vector<int> base_b(int number, int base){
    vector<int> v;
    while(number !=0){
        v.insert(v.begin(),number %base);
        number /= base;
    }
    return v;
}
int main() {
    int number;
    int base;
    cout<<"Enter a number to be transformed"<<endl;
    cin>>number;
    cout<<"Enter a base to be used for transformation"<<endl;
    cin>>base;
    //int b=f(c);
    // Write C++ code here
    
    vector<int> v=base_b(number, base);
    cout<<"The expansion of "<<number<<" in base "<<base<<" is : ";
    for(int i:v) cout<<i<<" ";
    //std::cout << c;

    return 0;
}
