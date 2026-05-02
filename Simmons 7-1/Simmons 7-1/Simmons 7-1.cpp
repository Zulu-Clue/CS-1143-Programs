// Z Simmons
// CS-1143 Online
// Description: Star Search w/ an Array

#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
void getJudgeData(double&, int);
double findLowest(double[], int);
double findHighest(double[], int);
void calcScore(double[], int);

int main()
{
    const int ARRAY_SIZE = 7;
    double scores[ARRAY_SIZE];

    // get user input
    for (int count = 0; count < ARRAY_SIZE; count++)
    {
        getJudgeData(scores[count], count + 1);
    }

    // calculate and display result
    calcScore(scores, ARRAY_SIZE);

    return 0;
}

// get judge score with validation
void getJudgeData(double& score, int judgeNumber)
{
    cout << "Enter score " << judgeNumber << ": ";
    cin >> score;

    while (score < 0 || score > 10)
    {
        cout << "Invalid score. Enter a value between 0 and 10: ";
        cin >> score;
    }

    return;
}

// find lowest score
double findLowest(double scores[], int size)
{
    double lowestScore = scores[0];

    for (int count = 1; count < size; count++)
    {
        if (scores[count] < lowestScore)
        {
            lowestScore = scores[count];
        }
    }

    return lowestScore;
}

// find highest score
double findHighest(double scores[], int size)
{
    double highestScore = scores[0];

    for (int count = 1; count < size; count++)
    {
        if (scores[count] > highestScore)
        {
            highestScore = scores[count];
        }
    }

    return highestScore;
}

// calculate final score
void calcScore(double scores[], int size)
{
    double lowestScore = findLowest(scores, size);
    double highestScore = findHighest(scores, size);

    double totalScore = 0;

    for (int count = 0; count < size; count++)
    {
        totalScore += scores[count];
    }

    totalScore = totalScore - lowestScore - highestScore;

    double averageScore = totalScore / (size - 2);

    cout << fixed << setprecision(2);
    cout << "The average after dropping the highest and the lowest scores: " << averageScore << endl;

    return;
}