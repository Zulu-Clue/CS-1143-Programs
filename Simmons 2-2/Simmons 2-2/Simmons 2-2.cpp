// Z Simmons
// CS 1143 Online
// Description: Calculate acres from sqft

#include<iostream>
using namespace std;

int main()
{
// Declare variables
	double sqft, acres;

// Declare & assign Sqft in an Acre constant

	const double SQFTINACRE = 43560;

// Prompt user input

	cout << "Enter square feet: ";
	cin >> sqft;

// Calculation

	acres = sqft / SQFTINACRE;

// Output

	cout << "Acres: " << acres << endl;

return 0;
}