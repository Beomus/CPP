#include <iostream>
#include <cmath> // include some math functions

using namespace std;

int main() {
    int num1 = 5;
    double num2 = 5.5;

    num1++;
    cout << num1 << endl;

    num1 += 10;
    cout << num1 << endl;

    num1 = 5;
    cout << num1 * num2 << endl;

    // pow()
    cout << pow(2, 5) << endl;

    // squrt()
    cout << sqrt(4) << endl;

    // round()
    cout << round(4.2) << endl;
    cout << round(4.7) << endl;
    
    // floor()
    cout << floor(4.2) << endl;
    cout << floor(4.7) << endl;

    // fmax(), fmin()
    cout << fmax(4.2, 5) << endl;
    cout << fmin(4.2, 5) << endl;

    return 0;
}