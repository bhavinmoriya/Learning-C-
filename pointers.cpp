#include <iostream>
// #include <string>
using namespace std;

int main(){
    int n = 4;
    printf("Values of n and its memory address are  %d %p\n", n, &n);

    int *myp;//create the pointer, assign n mem address
    myp = &n;

    printf("Values of my pointer and the value stored at the locations are %p %d\n", 
    myp, *myp);
    
    *myp = 40;
    printf("Values of n and myp are  %d %p\n", n, myp);
    
    return 0;
}