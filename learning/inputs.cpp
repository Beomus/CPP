#include <iostream>
#include <string>

using namespace std;

int main() {
    int x;
    cin >> x;
    cout << cin.fail(); // if there's a failure, return 1, else 0
    cin.clear(); // clear potential error flag from input, does not remove the input text
    cin.ignore(1000, '\n'); // ignore a set of character, eg: ignore 1000 characters from the input, then go to the next line
}