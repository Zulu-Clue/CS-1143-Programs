// Z Simmons
// CS 1143 Online
// Description: String selection sort modification

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes
int loadArray(string[], int, string);
void printArray(string[], int, string);
void selectionSort(string[], int);

int main()
{
    const int MAX_SIZE = 100;
    string presidentNames[MAX_SIZE];
    int presidentCount = 0;
    string fileName;
    ifstream inputFile;
    bool fileOpened = false;

    while (fileOpened == false)
    {
        cout << "Enter the filename: ";
        getline(cin, fileName);

        inputFile.open(fileName);

        if (inputFile)
        {
            fileOpened = true;
            inputFile.close();
        }
        else
        {
            cout << "Error: File not found. Try again." << endl << endl;
        }
    }

    presidentCount = loadArray(presidentNames, MAX_SIZE, fileName);

    printArray(presidentNames, presidentCount, "Unsorted Presidents");

    cout << "Number of presidents: " << presidentCount << endl << endl;

    selectionSort(presidentNames, presidentCount);

    printArray(presidentNames, presidentCount, "Sorted Presidents");

    return 0;
}

// Load names into array
int loadArray(string nameArray[], int maxSize, string fileName)
{
    ifstream inputFile;
    int count = 0;
    string currentLine;

    inputFile.open(fileName);

    if (inputFile)
    {
        while (getline(inputFile, currentLine))
        {
            if (count < maxSize)
            {
                nameArray[count] = currentLine;
                count = count + 1;
            }
        }
        inputFile.close();
    }

    return count;
}

// Print array
void printArray(string nameArray[], int size, string heading)
{
    cout << heading << endl;
    cout << "------------------------" << endl;

    for (int index = 0; index < size; index = index + 1)
    {
        cout << nameArray[index] << endl;
    }

    cout << endl;
}

// Selection sort
void selectionSort(string nameArray[], int size)
{
    int startIndex = 0;
    int minIndex = 0;
    string tempValue;

    for (startIndex = 0; startIndex < size - 1; startIndex = startIndex + 1)
    {
        minIndex = startIndex;

        for (int currentIndex = startIndex + 1; currentIndex < size; currentIndex = currentIndex + 1)
        {
            if (nameArray[currentIndex] < nameArray[minIndex])
            {
                minIndex = currentIndex;
            }
        }

        // manual swap
        tempValue = nameArray[startIndex];
        nameArray[startIndex] = nameArray[minIndex];
        nameArray[minIndex] = tempValue;
    }
}