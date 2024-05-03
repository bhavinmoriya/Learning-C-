#include<iostream>

using namespace std;

template<class T>

void print(T value){
    cout<< value<<endl;
}

int main(){
    print(8);
    print("Hellow");
    print('a');
    return 0;
}