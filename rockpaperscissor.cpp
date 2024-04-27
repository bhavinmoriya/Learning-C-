#include <iostream>
#include <string>
#include <ctime>
using namespace std;

char getUserChoice()
{
    char player;
    cout << "Rock Paper Scissors game \n";
    cout << "***************************\n";
    do
    {
        cout << "Input rock(r), paper(p) or scissors(s)\n";
        cin >> player;
    } while (player != 'r' && player != 's' && player != 'p');

    return player;
}

char getComputerChoice()
{
    srand(time(0));
    int num = rand() % 3 + 1;
    switch (num)
    {
    case 1:
        return 'r';
    case 2:
        return 's';
    case 3:
        return 'p';
    }
}

void chooseWinner(char player, char computer)
{
    switch (player)
    {
    case 'r':
        if (computer == 'r')
        {
            cout << "There is a tie!";
        }
        else if (computer == 's')
        {
            cout << "You win!";
        }
        else
            cout << "You lose";
        break;
    case 's':
        if (computer == 's')
        {
            cout << "There is a tie!";
        }
        else if (computer == 'p')
        {
            cout << "You win!";
        }
        else
            cout << "You lose";
        break;

    case 'p':
        if (computer == 'p')
        {
            cout << "There is a tie!";
        }
        else if (computer == 'r')
        {
            cout << "You win!";
        }
        else
            cout << "You lose";
        break;
    }
}

void showChoice(char choice)
{
    cout << "Your choice is: ";
    switch (choice)
    {
    case 'r':
        cout << "Rock\n";
        break;
    case 's':
        cout << "Scissors\n";
        break;
    case 'p':
        cout << "Paper\n";
        break;
    default:
        cout << "Invalid input!!";
        break;
    };
}
int main()
{
    char player;
    char computer;

    player = getUserChoice();
    cout << "Your choice: ";
    showChoice(player);

    computer = getComputerChoice();
    cout << "Computer choice: ";
    showChoice(computer);

    chooseWinner(player, computer);
    return 0;
}
