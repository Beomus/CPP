#include <iostream>

using namespace std;

int main()
{
    // put the square brackets and assign
    // nums[20]: meaning that we're specifying
    // that our array can have upto 20 elements
    // cannot have non-size or non initializer for arrays
    int nums[20] = {4, 5, 6, 7, 8};

    cout << nums[0];

    nums[3] = 7;

    nums[10] = 11;

    cout << nums;

    return 0;
}