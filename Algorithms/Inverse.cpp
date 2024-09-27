// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
// Source of the algorith is : https://eprint.iacr.org/2019/417
int main() {
    double x;
    int d;
    // Write C++ code here
    std::cout << "Enter a x to compute 1/x, where 0<x<2: ";
    
    cin>>x;
    cout<<endl;
    cout<<"No. of iterations to compute inverse: ";
    cin>>d;
    double a=2-x,b=1-x;
    for(int i=0; i<d; i++){
        b=b*b;
        a=a*(1+b);
    }
    cout<<"Difference of actual inverse and the inverse of x using algorithm is:"<<a-(1/x)<<endl;
    return 0;
}