// Z Simmons
// CS-1143 Online
// Description: Calculate discounts depending on quantity.

#include<iostream>
#include <iomanip>

using namespace std;

int main()
{
	// Declare variables
	const double PRICE = 89.95;
	double discount, regularPrice, discountPrice, netPrice;
	int unitsSold, discountPercent;
	
	// User Input
	cout << "Sold units: ";
	cin >> unitsSold;

	// Calculations

	// Valid Qty discounts
	if (unitsSold > 0)
	{
		// No discount
		if (unitsSold <= 9) discount = 0;
			
		// 5% discount
		else if (unitsSold <= 19) discount = 0.05;

		// 10% discount
		else if (unitsSold <= 29) discount = 0.10;
			
		// 15% discount
		else if (unitsSold <= 39) discount = 0.15;

		// 20% discount
		else if (unitsSold <= 49) discount = 0.20;
		
		// 50% discount
		else discount = 0.50;
		
		// Full price of order
		regularPrice = (unitsSold * PRICE);

		// Applying Discount
		discountPrice = (regularPrice * discount);

		// subtracting discount from full price
		netPrice = (regularPrice - discountPrice);

		// Declaring percentage variable
		discountPercent = (discount * 100);

		// Output
		cout << setprecision(2) << fixed;
		cout << "\nSoftware Sales:\n\n";
		cout << "Regular Price of " << setw(3) << unitsSold << ":" << setw(10) << regularPrice << endl;
		cout << "Discounted " << setw(2) << discountPercent << "%:" << setw(16) << discountPrice << endl;
		cout << "Net Price:" << setw(21) << netPrice << endl;
	}

	// Error msg for bad quantity
	else
	{
		cout << "Error: Invalid quantity provided. Please enter a number over 0." << endl;
	}

	return 0;
}