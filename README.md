# Cheatsheet
**Disclaimer. All the instructions here are taken from the internet with bit of my vision.**

The first of them, known as line comment, discards everything from where the pair of slash signs (//) are found up to the end of that same line. The second one, known as block comment, discards everything between the /* characters and the first appearance of the */ characters, with the possibility of including multiple lines.

```cpp
/* my second program in C++
   with more comments */

#include <iostream>

int main ()
{
  std::cout << "Hello World! ";     // prints Hello World!
  std::cout << "I'm a C++ program"; // prints I'm a C++ program
}
```

If you have seen C++ code before, you may have seen cout being used instead of ```std::cout```. Both name the same object: the first one uses its unqualified name (cout), while the second qualifies it directly within the namespace std (as ``std::cout``).
```cpp
// my second program in C++
#include <iostream>
using namespace std;

int main ()
{
  cout << "Hello World! ";\\unqualified
  std::cout << "I'm a C++ program";\\qualified
}
```