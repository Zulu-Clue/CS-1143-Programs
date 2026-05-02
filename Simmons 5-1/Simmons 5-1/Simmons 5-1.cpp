// Z Simmons
// CS-1143 Online
// Description: Fahrenheit to Celsius Table

#include<iostream>
#include<iomanip>

using namespace std;

int main() {

	//Declare Variables
	double startTemp, endTemp, smaller, larger, c;
	int startInt, endInt, f;


	//User Input

	cout << "Enter beginning Fahrenheit temperature: ";
	cin >> startTemp;

	cout << "Enter ending Fahrenheit temperature: ";
	cin >> endTemp;

	// Determine small temp & large temp
	if (startTemp < endTemp)
	{
		smaller = startTemp;
		larger = endTemp;
	}
	else
	{
		smaller = endTemp;
		larger = startTemp;
	}

	// Rounding smaller down
	startInt = (int)smaller;
	if (smaller < 0 && smaller != startInt) {
		startInt -= 1;
	}

	// Rounding larger up
	endInt = (int)larger;
	if (larger > 0 && larger != endInt) {
		endInt += 1;
	}

	// Output table header
	cout << setw(12) << "\n\nFahrenheit" << setw(12) << "Celsius\n" << endl;

	// For loop making table (f=Fahrenheit c=Celsius)
	for (f = startInt; f <= endInt; f++)
	{
		c = (f - 32) * 5.0 / 9.0;

		cout << setw(6) << f << setw(14) << setprecision(2) << fixed << c << endl;
	}

	return 0;
}