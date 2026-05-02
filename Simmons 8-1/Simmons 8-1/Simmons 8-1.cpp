// Z Simmons
// CS-1143 Online
// Description: Search Benchmarks

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayArray(int [], int);
void randomizeArray(int [], int);
void sortArray(int [], int);
void sequentialSearch(int [], int, int);
void binarySearch(int [], int, int);

int main()
{
    // Declare variables, set array size, seed RNG.
    const int arraySize = 100;
    int numberArray[arraySize];
    int searchValue;

    srand(time(0));

    randomizeArray(numberArray, arraySize);

    cout << "Generated Array:\n";
    displayArray(numberArray, arraySize);

    cout << "\nEnter a number to search for: ";
    cin >> searchValue;

    cout << "\nSequential Search:\n";
    sequentialSearch(numberArray, arraySize, searchValue);

    sortArray(numberArray, arraySize);

    cout << "\nSorted Array:\n";
    displayArray(numberArray, arraySize);

    cout << "\nBinary Search:\n";
    binarySearch(numberArray, arraySize, searchValue);

    return 0;
}

// Func to generate array
void randomizeArray(int numberArray[], int arraySize)
{
    for (int count = 0; count < arraySize; count++)
    {
        numberArray[count] = rand() % 900 + 100;
    }
    return;
}

// Func to display the array in columns
void displayArray(int numberArray[], int arraySize)
{
    for (int count = 0; count < arraySize; count++)
    {
        cout << numberArray[count] << "\t";

        if ((count + 1) % 10 == 0)
        {
            cout << endl;
        }
    }
    return;
}

// Func to search for number sequentially
void sequentialSearch(int numberArray[], int arraySize, int searchValue)
{
    int comparisonCount = 0;
    bool valueFound = false;

    for (int count = 0; count < arraySize; count++)
    {
        comparisonCount++;

        if (numberArray[count] == searchValue)
        {
            valueFound = true;
        }
    }

    if (valueFound == true)
    {
        cout << "Value found.\n";
    }
    else
    {
        cout << "Value not found.\n";
    }

    cout << "Comparisons made: " << comparisonCount << endl;
    return;
}

// Func to sort the array
void sortArray(int numberArray[], int arraySize)
{
    for (int passCount = 0; passCount < arraySize - 1; passCount++)
    {
        for (int count = 0; count < arraySize - passCount - 1; count++)
        {
            if (numberArray[count] > numberArray[count + 1])
            {
                int temporaryValue = numberArray[count];
                numberArray[count] = numberArray[count + 1];
                numberArray[count + 1] = temporaryValue;
            }
        }
    }
    return;
}

// Func to search array in binary
void binarySearch(int numberArray[], int arraySize, int searchValue)
{
    int lowerBound = 0;
    int upperBound = arraySize - 1;
    int comparisonCount = 0;
    bool valueFound = false;

    while (lowerBound <= upperBound)
    {
        int middleIndex = (lowerBound + upperBound) / 2;
        comparisonCount++;

        if (numberArray[middleIndex] == searchValue)
        {
            valueFound = true;
            lowerBound = upperBound + 1;
        }
        else if (numberArray[middleIndex] < searchValue)
        {
            lowerBound = middleIndex + 1;
        }
        else
        {
            upperBound = middleIndex - 1;
        }
    }

    if (valueFound == true)
    {
        cout << "Value found.\n";
    }
    else
    {
        cout << "Value not found.\n";
    }

    cout << "Comparisons made: " << comparisonCount << endl;
    return;
}