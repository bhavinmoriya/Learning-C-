#include <iostream>
#include<cmath>
using namespace std;

class Shape
{
public:
    double area;
    double volume;
};

class Cube : public Shape
{
public:
    double side;

    Cube(double side)
    {
        this->side = side;
        this->area= pow(side,2)*6;
        this->volume= pow(side,3);
    }
};

class Sphere : public Shape
{
public:
    double radius;

    Sphere(double radius)
    {
        this->radius = radius;
        this->area= 4*3.14159*pow(radius,2);
        this->volume= (4/3.0)*3.14159*pow(radius,2);
    }
};

int main(){
    Cube cube(2);
    Sphere sphere(1);
    cout<<"Area of a cube with side = "<<cube.side<<" is "<<cube.area<<endl;
    cout<<"Volume of a cube with side = "<<cube.side<<" is "<<cube.volume<<endl;
    cout<<"Area of a sphere with radius = "<<sphere.radius<<" is "<<sphere.area<<endl;
    cout<<"Volume of a sphere with side = "<<sphere.radius<<" is "<<sphere.volume<<endl;
}