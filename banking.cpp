#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void showBalance(double balance)
{
    cout << "Your balance is: $" << std::setprecision(2) << std::fixed << balance << endl;
}

double deposit()
{
    double amount = 0;
    cout << "Enter the amount to be deposited\n";
    cin >> amount;
    if (amount > 0)
    {
        return amount;
    }
    else
        return 0;
}

double withdraw(double balance)
{
    double amount = 0;
    cout << "Enter the amount to be withdrawn\n";
    cin >> amount;

    if (amount > balance)
    {
        cout << "Insufficient balance!!\n";
        return 0;
    }
    else if (amount < 0)
    {
        cout << "That is not a valid amount!\n";
        return 0;
    }
    else
        return amount;
}

int main()
{
    double balance = 0;
    int choice = 0;

    do
    {
        cout << "******************************************\n";
        cout << "Enter the one of the following options :\n";
        cout << "******************************************\n";
        cout << "1. Check the Balance\n";
        cout << "2. Deposit \n";
        cout << "3. Withdraw \n";
        cout << "4. Exit\n";
        cout << "******************************************\n";
        cin >> choice;

        std::cin.clear();
        fflush(stdin);

        switch (choice)
        {
        case 1:
            showBalance(balance);
            break;
        case 2:
            balance += deposit();
            showBalance(balance);
            break;
        case 3:
            balance -= withdraw(balance);
            showBalance(balance);
            break;
        case 4:
            cout << "Thanks for visiting!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
