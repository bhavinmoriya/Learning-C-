#include <iostream>
#include <string>
using namespace std;
#define pi 3.14159
#define NEWLINE '\n'
#include <sstream>
void duplicate (int& a, int& b, int& c)
{
  a*=2;
  b*=2;
  c*=2;
}
int addition(int a, int b)
{
  int r;
  r = a + b;
  return r;
}

void odd (int x)
{
  if ((x%2)!=0) cout << "It is odd.\n";
  else if (x == 0)
  {
    cout << "It is zero.\n";
  }
  else cout << "It is even.\n";
}

int main()
{
  int z;
  z = addition(5, 3);
  cout << "The result is " << z;

  int x=1, y=3;
  z=7;
  duplicate (x, y, z);
  cout << "x=" << x << ", y=" << y << ", z=" << z;
  // return 0;

  int i;
  while (i!=0){
    cout << "Please, enter number (0 to exit): ";
    cin >> i;
    odd (i);
  } 
}



