#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string color, noun, number;

    cout << "enter a color: ";
    getline(cin, color);

    cout << "enter a noun: ";
    getline(cin, noun);

    cout << "enter a number: ";
    getline(cin, number);

    cout << color << endl;
    cout << noun << endl;
    cout << number << endl;

    return 0;
}