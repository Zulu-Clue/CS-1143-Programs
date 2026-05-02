// Z Simmons
// CS-1143 Online
// Description: Average the top five tests

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getScore(double& score);
void calcAverage(double s1, double s2, double s3, double s4, double s5, double s6);
double findLowest(double s1, double s2, double s3, double s4, double s5, double s6);

int main()
{
    // declare variables
    double s1, s2, s3, s4, s5, s6;

    // User getScore function
    getScore(s1);
    getScore(s2);
    getScore(s3);
    getScore(s4);
    getScore(s5);
    getScore(s6);

    calcAverage(s1, s2, s3, s4, s5, s6);

    return 0;
}

// User input function
void getScore(double& score)
{
    static int testNum = 1;

    cout << "Enter test " << testNum << ": ";
    cin >> score;

    while (score < 0 || score > 100)
    {
        cout << "Invalid score. Enter a value between 0 and 100: ";
        cin >> score;
    }

    testNum++;
}

// Finding the lowest score
double findLowest(double s1, double s2, double s3, double s4, double s5, double s6)
{
    double lowest = s1;

    if (s2 < lowest) lowest = s2;
    if (s3 < lowest) lowest = s3;
    if (s4 < lowest) lowest = s4;
    if (s5 < lowest) lowest = s5;
    if (s6 < lowest) lowest = s6;

    return lowest;
}

// Average Calculation
void calcAverage(double s1, double s2, double s3, double s4, double s5, double s6)
{
    double lowest = findLowest(s1, s2, s3, s4, s5, s6);

    double total = s1 + s2 + s3 + s4 + s5 + s6 - lowest;
    double average = total / 5.0;

    cout << fixed << setprecision(2);
    cout << "The average of the top 5 tests: " << average << endl;
}