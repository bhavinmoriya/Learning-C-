#include <iostream>
using namespace std;
 double getAverage(int arr[],int size) {
  int i, sum = 0;    
  
  double avg;          

   for (i = 0; i < size; ++i) {
      sum += arr[i];
   }
   avg = double(sum) / size;

   return avg;
}


int main () {
   // an int array with 5 elements.
   int N=5;
   int balance[N] = {1000, 2, 3, 17, 50};
   double avg;

   // pass pointer to the array as an argument.
   avg = getAverage( balance,N) ;
 
   // output the returned value 
   cout << "Average value is: " << avg << endl; 
    
   return 0;
}
