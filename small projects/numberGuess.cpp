#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void drawLine(int n, char symbol);
void rules();

int main()
{
    string playerName;
    int amount;
    int bettingAmount;
    int guess;
    int dice;
    char choice;

    srand(time(0)); //random generator

    system("clear");
    drawLine(60, '_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(60, '_');

    cout << "\nEnter your name: ";
    getline(cin, playerName);

    cout << "\nEnter deposit amount: ";
    cin >> amount;

    do 
    {
        system("clear");
        rules();
        cout << "\n\nYour current balance: " << amount << "\n";

        do
        {
            cout << playerName << " will bet: ";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Insufficient balance!\n" << "\nRe-enter amount :\n";
        } while (bettingAmount > amount);

        do
        {
            cout << "Guess a number between 1 and 10: ";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "Invalid number!\n" << "\nRe-enter data: \n";
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1;

        if (dice == guess)
        {
            cout << "\nYou won " << bettingAmount * 10 << "$";
            amount += bettingAmount * 10;
        }
        else
        {
            cout << "\nYou lost " << bettingAmount << "$";
            amount -= bettingAmount;
        }

        cout << "\nThe winning number was " << dice << "\n";
        cout << "\n" << playerName << " has " << amount << "\n";
        
        if (amount == 0)
        {
            cout << "You have no balance";
            break;
        }
        cout << "\nPlay again? (y/n) ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "\n\nThanks for playing, your amount: " << amount << "\n\n";
    drawLine(70, '=');
    return 0;
}

void drawLine(int n, char symbol)
{
    for (int i=0; i<n; i++)
        cout << symbol;
    cout << "\n";
}

void rules()
{
    system("clear");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}
