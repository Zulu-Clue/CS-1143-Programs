// Z Simmons
// CS-1143 Online
// Description: Employee Absense Calculator

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
int getNumEmployees();
double getTotalDaysAbsent(int numEmployees);
void displayAverage(int numEmployees, double totalDays);

int main()
{
    int employees = 0;
    double totalDays = 0.0;

    employees = getNumEmployees();
    totalDays = getTotalDaysAbsent(employees);
    displayAverage(employees, totalDays);

    return 0;
}

// Function for number of employees
int getNumEmployees()
{
    int employees = 0;

    cout << "Enter the number of employees: ";
    cin >> employees;

    while (employees < 1)
    {
        cout << "Invalid number, must be greater than 0" << endl;
        cout << "Enter the number of employees: ";
        cin >> employees;
    }

    return employees;
}

// Function to get days absent
double getTotalDaysAbsent(int numEmployees)
{
    double total = 0.0;
    double days = 0.0;

    for (int i = 1; i <= numEmployees; i++)
    {
        cout << "Days missed employee #" << i << ": ";
        cin >> days;

        while (days < 0)
        {
            cout << "Invalid number, must be 0 or greater" << endl;
            cout << "Days missed employee #" << i << ": ";
            cin >> days;
        }

        total = total + days;
    }

    return total;
}

// Function for output
void displayAverage(int numEmployees, double totalDays)
{
    double average = totalDays / numEmployees;

    cout << fixed << setprecision(2);
    cout << "Average days missed: " << average << endl;
}