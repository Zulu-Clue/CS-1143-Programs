// Z Simmons
// CS-1143 Online
// Description: 

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function prototypes
bool hasMinimumLength(string);
bool hasUppercaseLetter(string);
bool hasLowercaseLetter(string);
bool hasDigit(string);
bool hasNoSpaces(string);
bool hasSpecialCharacter(string);

int main()
{
    string password;
    bool validPassword = false;

    while (validPassword == false)
    {
        cout << "Enter a password: ";
        getline(cin, password);

        validPassword = true;

        if (hasMinimumLength(password) == false)
        {
            cout << "- Password must be at least 12 characters long." << endl;
            validPassword = false;
        }

        if (hasUppercaseLetter(password) == false)
        {
            cout << "- Password must contain at least one uppercase letter." << endl;
            validPassword = false;
        }

        if (hasLowercaseLetter(password) == false)
        {
            cout << "- Password must contain at least one lowercase letter." << endl;
            validPassword = false;
        }

        if (hasDigit(password) == false)
        {
            cout << "- Password must contain at least one digit." << endl;
            validPassword = false;
        }

        if (hasNoSpaces(password) == false)
        {
            cout << "- Password must not contain spaces." << endl;
            validPassword = false;
        }

        if (hasSpecialCharacter(password) == false)
        {
            cout << "- Password must contain at least one special character." << endl;
            validPassword = false;
        }

        if (validPassword == true)
        {
            cout << "Password is valid." << endl;
        }

        cout << endl;
    }

    return 0;
}

// Checks for minimum length
bool hasMinimumLength(string password)
{
    bool validLength = false;

    if (password.length() >= 12)
    {
        validLength = true;
    }

    return validLength;
}

// Checks for uppercase letter
bool hasUppercaseLetter(string password)
{
    bool foundUppercase = false;

    for (int index = 0; index < password.length(); index++)
    {
        if (isupper(password[index]))
        {
            foundUppercase = true;
        }
    }

    return foundUppercase;
}

// Checks for lowercase letter
bool hasLowercaseLetter(string password)
{
    bool foundLowercase = false;

    for (int index = 0; index < password.length(); index++)
    {
        if (islower(password[index]))
        {
            foundLowercase = true;
        }
    }

    return foundLowercase;
}

// Checks for digit
bool hasDigit(string password)
{
    bool foundDigit = false;

    for (int index = 0; index < password.length(); index++)
    {
        if (isdigit(password[index]))
        {
            foundDigit = true;
        }
    }

    return foundDigit;
}

// Checks for spaces
bool hasNoSpaces(string password)
{
    bool noSpacesFound = true;

    for (int index = 0; index < password.length(); index++)
    {
        if (isspace(password[index]))
        {
            noSpacesFound = false;
        }
    }

    return noSpacesFound;
}

// Checks for special character
bool hasSpecialCharacter(string password)
{
    bool foundSpecialCharacter = false;

    for (int index = 0; index < password.length(); index++)
    {
        if (isprint(password[index]) && !isalpha(password[index]) && !isdigit(password[index]))
        {
            foundSpecialCharacter = true;
        }
    }

    return foundSpecialCharacter;
}