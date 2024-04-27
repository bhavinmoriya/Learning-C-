#include <iostream>
// #include <string>
using namespace std;

class Animal
{
public:
    bool alive = true;
    void eat()
    {
        cout << "It is eating :)\n";
    }
};

class Dog : public Animal
{
public:
    void bark()
    {
        cout << "It is barkingggg :)\n";
    }
};

class Cat : public Animal
{
public:
    void meaw()
    {
        cout << "It is meawiinnng :)\n";
    }
};

int main()
{
    Dog dog;

    cout << dog.alive << endl;
    dog.eat();
    dog.bark();

    Cat cat;
    cout << dog.alive << endl;
    cat.eat();
    cat.meaw();

    return 0;
}
