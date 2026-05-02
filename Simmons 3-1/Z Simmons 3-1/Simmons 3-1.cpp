// Z Simmons
// CS 1143 Online
// Description: Convert Fahrenheit to Celsius

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
//Declare Variables
	double celsius, fahrenheit;

//User Input

	cout << "Enter Fahrenheit temperature: ";
	cin >> fahrenheit;

//Conversion Calculation

	celsius = (fahrenheit - 32) * 5/9;

//Output
	cout << setprecision(2) << fixed;
	cout << setw(6) << fahrenheit << " Fahrenheit = " << setw(6) << celsius << " Celsius" << endl;

return 0;
}