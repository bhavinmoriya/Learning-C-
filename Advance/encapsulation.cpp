#include <iostream>
#include <string>

// Definition of the class
class Employee {
private:
    // Private attributes - cannot be accessed directly from outside the class
    std::string name;
    int age;
    double salary;

public:
    // Constructor to initialize the attributes
    Employee(const std::string& empName, int empAge, double empSalary) {
        name = empName;
        age = empAge;
        salary = empSalary;
    }

    // Public method to set the name
    void setName(const std::string& empName) {
        name = empName;
    }

    // Public method to get the name
    std::string getName() const {
        return name;
    }

    // Public method to set the age
    void setAge(int empAge) {
        if (empAge > 0) {
            age = empAge;
        }
    }

    // Public method to get the age
    int getAge() const {
        return age;
    }

    // Public method to set the salary
    void setSalary(double empSalary) {
        if (empSalary >= 0) {
            salary = empSalary;
        }
    }

    // Public method to get the salary
    double getSalary() const {
        return salary;
    }

    // Public method to display employee details
    void display() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Salary: " << salary << "\n";
    }
};

int main() {
    // Creating an object of the Employee class
    Employee emp1("John Doe", 30, 50000.0);

    // Accessing and modifying the attributes using public methods
    emp1.setName("Jane Doe");
    emp1.setAge(28);
    emp1.setSalary(55000.0);

    // Displaying the employee details
    emp1.display();

    return 0;
}
