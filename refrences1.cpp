#include <iostream>
#include <vector>
// #include <string>
using namespace std;

int f(int x, int &a){
    a =  6*x;
    return 3*x;
}

int g(int x, int a){
    a =  6*x;
    return 3*x;
}

int main() {
    // const int size = 2;
    // bool sum[size + 1];
    int a=2,x=3;
    int b = f(x,a);
    
    std::cout << "Value of b "<<b<<endl<< "Value of a "<<a<<endl;
    
    x=1;
    int c = g(x,a);
    std::cout << "Value of c "<<c<<endl<< "Value of a "<<a<<endl;
       
    return 0;
}