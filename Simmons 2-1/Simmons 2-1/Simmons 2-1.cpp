// Z Simmons
// CS 1143 Online
// Description: Calculate the MPG of a car.

#include<iostream>
using namespace std;

int main()
{
// Declare variables

	double mpg, milesDriven, gallonsUsed;

	cout << "Enter the miles driven: ";
	cin >> milesDriven;

	cout << "Enter the gallons of gas used: ";
	cin >> gallonsUsed;

	mpg = milesDriven / gallonsUsed; 

	cout << "MPG: " << mpg << endl;

	return 0;
}