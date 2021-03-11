#include <iostream>

using namespace std;

int main() {

    string phrase = "what what";
    
    // different output
    cout << "hello";
    cout << "my name\n";
    cout << "what?" << endl;

    // get length of string
    cout << phrase.length() << endl;

    // indexing
    cout << phrase[3] << endl;
    phrase[2] = ' ';
    cout << phrase << endl;

    // find(string/char, int: starting ind)
    cout << phrase.find("at") << endl;

    // substr(string, int: ind, length: int)
    string phraseSub;
    phraseSub = phrase.substr(2, 5);
    cout << phraseSub;

    return 0;
}