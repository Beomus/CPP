#include <iostream>

using namespace std;

/*
start with a return data type
then name and parameters
*/

// create an empty reference for functions
void sayHi(string name);

int main()
{
    sayHi("bruh");
    return 0;
}

// void returns nothing
void sayHi(string name)
{
    cout << "hello " << name << endl;
}
