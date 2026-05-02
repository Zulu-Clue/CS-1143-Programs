// Z Simmons
// CS-1143 Online
// Description: List prime numbers

#include <iostream>
#include <fstream>
using namespace std;

// Function prototype
bool isPrime(int number);

int main()
{
    int startingNumber;
    int endingNumber;
    string outputFilename;

    cout << "Enter starting number: ";
    cin >> startingNumber;

    cout << "Enter ending number: ";
    cin >> endingNumber;

    cout << "Enter output filename: ";
    cin >> outputFilename;

    // Fix reversed range
    if (startingNumber > endingNumber)
    {
        int temporaryValue = startingNumber;
        startingNumber = endingNumber;
        endingNumber = temporaryValue;
    }

    // Start output file
    ofstream outputFile(outputFilename);

    int primeCount = 0;

    for (int currentNumber = startingNumber; currentNumber <= endingNumber; currentNumber++)
    {
        if (isPrime(currentNumber))
        {
            outputFile << currentNumber << endl;
            primeCount = primeCount + 1;
        }
    }

    outputFile.close();

    cout << "Number of prime numbers found: " << primeCount << endl;

    return 0;
}

// Function definition
bool isPrime(int number)
{
    bool isNumberPrime = true;

    if (number < 2)
    {
        isNumberPrime = false;
    }
    else
    {
        for (int divisor = 2; divisor * divisor <= number; divisor++)
        {
            if (number % divisor == 0)
            {
                isNumberPrime = false;
            }
        }
    }

    return isNumberPrime;
}