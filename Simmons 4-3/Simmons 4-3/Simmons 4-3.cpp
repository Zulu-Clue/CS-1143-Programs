// Z Simmons
// CS-1143 Online
// Description: Freight shipping calculator.

#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	
	// Declare Variables
	double weight, distance, charge, baseRate;
	double const SMALLEST_KG = 2.10, TWO_KG = 3.20, SIX_KG = 4.30, TEN_KG = 5.40;

	// User input
	cout << "Please enter the weight of the package: ";
	cin >> weight;
	cout << "Please enter the miles driven: ";
	cin >> distance;

	// input validation
	if (weight > 0 && weight <= 20 && distance >= 10 && distance <= 3000) {
		
		// Find base rate
		if (weight <= 2) 
			baseRate = SMALLEST_KG;
		else if (weight <= 6)
			baseRate = TWO_KG;
		else if (weight <= 10)
			baseRate = SIX_KG;
		else if (weight <= 20)
			baseRate = TEN_KG;

		// Find distance & pro-rate if over 500 miles
		if (distance <= 500) 
			charge = baseRate;
		else 
			charge = ( baseRate / 500 ) * distance;

		// Output
		cout << setprecision(2) << fixed;
		cout << "\nFast Freight Shipping" << endl;
		cout << setw(7) << "\nWeight:" << setw(10) << right << weight << endl;
		cout << setw(9) << "Distance:" << setw(8) << right << distance << endl;
		cout << setw(11) << "Charge:   $" << setw(6) << right << charge << endl;
	}

	// Error msg for invalid weight or distance.
	else {
	cout << "Error: Invalid weight or distance. Weight must be over 0 and not larger than 20 kg." << endl;
	cout << "Distance must be over 10 miles or under 3000." << endl;
	}

	
}