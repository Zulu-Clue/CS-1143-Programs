// Z Simmons
// CS-1143 Online
// Description: Reverse a string

#include <iostream>
#include <string>

using namespace std;

// Function prototype
string reverseString(string);

int main()
{
    string input;
    string reversed;

    cout << "Enter the word/phrase to reverse: ";
    getline(cin, input);

    reversed = reverseString(input);

    cout << "Reversed word/phrase: " << reversed << endl;

    return 0;
}

// Reverse String Function
string reverseString(string str)
{
    string reversed = "";
    int index = str.length() - 1;

    while (index >= 0)
    {
        reversed += str[index];
        index--;
    }

    return reversed;
}