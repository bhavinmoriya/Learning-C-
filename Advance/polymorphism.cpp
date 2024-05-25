#include <iostream>
#include <string>

// Definition of the class
class Animal {
public:
    virtual void sound() const { std::cout << "Some generic animal sound\n"; }
};

class Dog : public Animal {
public:
    void sound() const override { std::cout << "Bark\n"; }
};

void makeSound(const Animal& a) {
    a.sound();
}

int main() {
    Animal a;
    Dog d;
    makeSound(a); // Output: Some generic animal sound
    
    makeSound(d); // Output: Bark
    return 0;
}
