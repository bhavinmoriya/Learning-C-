#include <iostream>
using namespace std;

enum Day
{
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
};
int main()
{
    Day day = sunday;
    switch (day)
    {
    case sunday:
        cout << "It is sunday";
        break;
    case monday:
        cout << "It is monday";
        break;

    case tuesday:
        cout << "It is tuesday";
        break;

    case wednesday:
        cout << "It is wednesday";
        break;

    case thursday:
        cout << "It is thursday";
        break;

    case friday:
        cout << "It is case friday:";
        break;

    case saturday:
        cout << "It is saturday";
        break;
    }
}