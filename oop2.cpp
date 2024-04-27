#include <iostream>
// #include <string>
using namespace std;

// getters and setters to prevent access of the object attributes directly outside the class

class Student
{
private:
    string name;
    int age;
    int gpa;

public:
    Student(string name,
            int age,
            int gpa)
    {
        setStudent(name,
                   age,
                   gpa);
    }
    void setStudent(string name,
                    int age,
                    int gpa)
    {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }

    void getStudent() // setter
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

    student1.getStudent();
    return 0;
}
