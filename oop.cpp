#include <iostream>
// #include <string>
using namespace std;

class Car
{
public:
    string make;
    string model;
    int year;
    string color;

    Car(string make,
        string model,
        int year,
        string color = "blue")
    {
        this->make = make;
        this->model = model;
        this->year = year;
        this->color = color;
    }

    void accelerate()
    {
        cout << "You are accelerating!\n";
    }

    void brake()
    {
        cout << "You are braking!\n";
    }

    void colorCar(string color)
    {
        this->color = color;
        cout << "You are coloring the car with color " << color << " !\n ";
    }
    void printCar()
    {
        cout << "The car information is:\n"
             << make << endl
             << model << endl
             << year << endl
             << color << endl;
    }
};

int main()
{
    Car car1("Chevy", "Corvette", 1990);
    
    car1.accelerate();
    car1.brake();

    cout<<"The information of the car before coloring it next is:\n";
    
    car1.printCar();

    car1.colorCar("red");
    car1.printCar();
    return 0;
}
