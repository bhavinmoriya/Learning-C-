#include <iostream>

class Person
{
protected:
    std::string name;
    int age;

public:
    void display() const
    {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        // std::cout << "Salary: " << salary << "\n";
    }
    void setName(std::string n) { name = n; }
    void setAge(int a) { age = a; }
};

class Employee : public Person
{ // Employee inherits from Person
private:
    double salary;

public:
    void setSalary(double s) { salary = s; }
    void display() const
    {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Salary: " << salary << "\n";
    }
};

int main()
{
    Person p1;

    p1.setName("Jane");
    p1.setAge(48);
    std::cout << "*****************************************" << "\n";
    std::cout << "We will display person's attributes next." << "\n";
    std::cout << "*****************************************" << "\n";
    p1.display();

    Employee emp1;

    // Accessing and modifying the attributes using public methods
    emp1.setName("Jane Doe");
    emp1.setAge(28);
    emp1.setSalary(55000.0);
    std::cout << "*****************************************" << "\n";
    std::cout << "We will display Employee's attributes next." << "\n";
    std::cout << "*****************************************" << "\n";
    // Displaying the employee details
    emp1.display();

    return 0;
}
