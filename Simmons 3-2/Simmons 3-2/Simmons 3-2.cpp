// Z Simmons
// CS 1143 Online
// Description: Calculate Monthly Sales Tax

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main()
{
	// Declare Variables
	double totalMoney, totalTax, totalSales, totalState, totalCounty, totalCity, totalCombined;
	string month, year;
	const double STATETAX = 0.04, COUNTYTAX = 0.02, CITYTAX = 0.01;

	// User Input
	cout << "Enter the month: ";
	cin >> month;
	cout << "Enter the year: ";
	cin >> year;
	cout << "Enter the total money earned: ";
	cin >> totalMoney;

	// Calculations
	totalTax = (STATETAX + COUNTYTAX + CITYTAX);
	totalSales = totalMoney / (1 + totalTax);
	totalState = totalSales * STATETAX;
	totalCounty = totalSales * COUNTYTAX;
	totalCity = totalSales * CITYTAX;
	totalCombined = totalSales * (STATETAX + COUNTYTAX + CITYTAX);
	
	// Output
	cout << setprecision(2) << fixed;
	cout << "  Sales Tax for " << month << " " << year << endl;
	cout << endl;
	cout << "******************************" << endl;
	cout << "Total Collected:    $" << setw(9) << totalMoney << endl;
	cout << "Sales:              $" << setw(9) << totalSales << endl;
	cout << "City Sales Tax:     $" << setw(9) << totalCity << endl;
	cout << "County Sales Tax:   $" << setw(9) << totalCounty << endl;
	cout << "State Sales Tax:    $" << setw(9) << totalState << endl;
	cout << "Total Sales Tax:    $" << setw(9) << totalCombined << endl;

	return 0;
}