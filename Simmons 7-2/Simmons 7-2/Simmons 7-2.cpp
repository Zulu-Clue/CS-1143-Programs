// Z Simmons
// CS-1143 Online
// Description: Exam Grader 

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 30;

// Function prototypes
bool loadFile(char[], char[], int);
void gradeExam(char[], char[], int);

int main()
{
    char correctAnswers[SIZE];
    char studentAnswers[SIZE];
    char correctFileName[100];
    char studentFileName[100];

    bool fileLoaded = false;

    // Validate correct answers file
    do
    {
        cout << "Enter the correct answers filename: ";
        cin.getline(correctFileName, 100);

        fileLoaded = loadFile(correctFileName, correctAnswers, SIZE);

        if (fileLoaded == false)
        {
            cout << "Error: could not open correct answers file. Try again.\n";
        }

    } while (fileLoaded == false);

    bool studentLoaded = false;

    // Validate student answers file
    do
    {
        cout << "Enter the student answers filename: ";
        cin.getline(studentFileName, 100);

        studentLoaded = loadFile(studentFileName, studentAnswers, SIZE);

        if (studentLoaded == false)
        {
            cout << "Error: could not open student answers file. Try again.\n";
        }

    } while (studentLoaded == false);

    gradeExam(correctAnswers, studentAnswers, SIZE);

    return 0;
}

// Load file into array
bool loadFile(char fileName[], char answers[], int size)
{
    ifstream inFile;
    bool openedSuccessfully = false;
    int count = 0;

    inFile.open(fileName);

    if (inFile)
    {
        openedSuccessfully = true;

        while (count < size && inFile >> answers[count])
        {
            count++;
        }

        inFile.close();
    }

    return openedSuccessfully;
}

// Grade exam and display results
void gradeExam(char correctAnswers[], char studentAnswers[], int size)
{
    int missedQuestions = 0;
    int correctCount = 0;
    int count = 0;

    cout << "\nQuestions Missed:\n";
    cout << "Question\tCorrect Answer\tStudent Answer\n";

    for (count = 0; count < size; count++)
    {
        if (studentAnswers[count] != correctAnswers[count])
        {
            cout << (count + 1) << "\t\t"
                << correctAnswers[count] << "\t\t"
                << studentAnswers[count] << endl;

            missedQuestions++;
        }
        else
        {
            correctCount++;
        }
    }

    double percentageCorrect = (static_cast<double>(correctCount) / size) * 100;

    cout << "\nTotal Questions Missed: " << missedQuestions << endl;
    cout << fixed << setprecision(2);
    cout << "Score: " << percentageCorrect << "%" << endl;

    if (percentageCorrect >= 70)
    {
        cout << "Result: PASSED" << endl;
    }
    else
    {
        cout << "Result: FAILED" << endl;
    }
}