// Z Simmons
// CS-1143 Online
// Description: Find 

#include <iostream>
#include <iomanip>
using namespace std;

// func prototypes
void getJudgeData(double&);
void calcScore(double, double, double, double, double, double, double);
double findLowest(double, double, double, double, double, double, double);
double findHighest(double, double, double, double, double, double, double);

int main()
{
    double score1, score2, score3, score4, score5, score6, score7;

    // get user input
    getJudgeData(score1);
    getJudgeData(score2);
    getJudgeData(score3);
    getJudgeData(score4);
    getJudgeData(score5);
    getJudgeData(score6);
    getJudgeData(score7);

    // find score & output
    calcScore(score1, score2, score3, score4, score5, score6, score7);

    return 0;
}

// func definition for user input
void getJudgeData(double& score)
{
    static int judgeNum = 1;

    cout << "Enter score " << judgeNum << ": ";
    cin >> score;

    while (score < 0 || score > 10)
    {
        cout << "Invalid score. Enter a value between 0 and 10: ";
        cin >> score;
    }

    judgeNum++;

    return;
}

// func definition to find low score
double findLowest(double score1, double score2, double score3, double score4, double score5, double score6, double score7)
{
    double lowest;
    lowest = score1;

    if (score2 < lowest) lowest = score2;
    if (score3 < lowest) lowest = score3;
    if (score4 < lowest) lowest = score4;
    if (score5 < lowest) lowest = score5;
    if (score6 < lowest) lowest = score6;
    if (score7 < lowest) lowest = score7;

    return lowest;
}

// func definition to find highest score
double findHighest(double score1, double score2, double score3, double score4, double score5, double score6, double score7)
{
    double highest;
    highest = score1;

    if (score2 > highest) highest = score2;
    if (score3 > highest) highest = score3;
    if (score4 > highest) highest = score4;
    if (score5 > highest) highest = score5;
    if (score6 > highest) highest = score6;
    if (score7 > highest) highest = score7;

    return highest;
}

// func definition to find average & remove high and low score.
void calcScore(double score1, double score2, double score3, double score4, double score5, double score6, double score7)
{
    double lowest;
    double highest;
    double total;
    double average;

    lowest = findLowest(score1, score2, score3, score4, score5, score6, score7);
    highest = findHighest(score1, score2, score3, score4, score5, score6, score7);

    total = score1 + score2 + score3 + score4 + score5 + score6 + score7;
    total = total - lowest - highest;

    average = total / 5.0;

    cout << fixed << setprecision(2);
    cout << "The average after dropping the highest and the lowest scores: " << average << endl;

    return;
}