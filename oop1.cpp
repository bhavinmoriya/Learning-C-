#include <iostream>
// #include <string>
using namespace std;

// We shall do construction overloading in a pizza class. That is using the same name for Pizza for either no topping or one or two 
// toppings

class Pizza
{
public:
    string topping1;
    string topping2;
    // No topping
    Pizza()
    {
    }

    // One topping
    Pizza(string topping1)
    {
        this->topping1 = topping1;
    }

    // Two topping
    Pizza(string topping1, string topping2)
    {
        this->topping2 = topping1;
        this->topping2 = topping2;
    }
}; 

class Student
{
public:
    string name;
    int age;
    int gpa;

    Student(string name,
            int age,
            int gpa)
    {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }

    void studentInfo()
    {
        cout << "Information of the student is:\n"
             << name << "\n"
             << age << "\n"
             << gpa << "\n";
    }
};

int main()
{
    Student student1("James", 15, 5);

    student1.studentInfo();

    Pizza pizza1();
    Pizza pizza2("parmesan");
    Pizza pizza3("parmesan","mushroom");


    return 0;
}
