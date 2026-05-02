// Z Simmons
// CS-1143 Online
// Description: Check service fees at a bank.

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main()
{
	// Declare Variables
	double beginBalance, checksCharge = 0, totalCharges, endBalance;
	string month;
	int year, checks;
	const double BASE_CHARGE = 15, BELOW_MIN_CHARGE = 20, TEN_CHECKS_CHARGE = .10, TWENTY_CHECKS_CHARGE = .08, FOURTY_CHECKS_CHARGE = .06, SIXTY_CHECKS_CHARGE = .04, EIGHTY_CHECKS_CHARGE = .02;
	bool overdrawn, belowMin;
	
	// User input
	cout << "Please enter the year: ";
	cin >> year;
	cout << "\nPlease enter the month name: ";
	cin >> month;
	cout << "\nPlease enter the starting balance: ";
	cin >> beginBalance;
	cout << "\nPlease enter the number of checks written: ";
	cin >> checks;

	// Calculate charges
	if (checks >= 0){
		if (beginBalance < 0) {
			belowMin = true;
			overdrawn = true;
		}
		else if (beginBalance < 500) {
			belowMin = true;
			overdrawn = false;
		}
		else {
			belowMin = false;
			overdrawn = false;
		}
		if (checks >= 1) {
			if (checks < 20)
				checksCharge = TEN_CHECKS_CHARGE;	
			else if (checks <= 39)
				checksCharge = TWENTY_CHECKS_CHARGE;
			else if (checks <= 59) 
				checksCharge = FOURTY_CHECKS_CHARGE;
			else if (checks <= 79) 
				checksCharge = SIXTY_CHECKS_CHARGE;
			else if (checks >= 80)
				checksCharge = EIGHTY_CHECKS_CHARGE;
		}
		
		totalCharges = BASE_CHARGE;
		checksCharge = checks * checksCharge;

		if (belowMin == true) {
			totalCharges += BELOW_MIN_CHARGE;
		}
		totalCharges += checksCharge;
		endBalance = beginBalance - totalCharges;

		// Output ( I think I'm overcomplicating this. Sowwy :) )
		cout << setprecision(2) << fixed << endl;
		cout << setw(29) << right << "OCCC Bank and Trust" << endl;
		cout << "Monthly Bank Charges for " << month << ", " << year << endl;
		cout << setw(23) << "\nBeginning Bank Balance:" << setw(15) << right << beginBalance;
		if (overdrawn == true) {
			cout << setw(20) << " *** Account Overdrawn ***" << endl;
			}
		else cout << endl;
		cout << setw(20) << "Monthly Base Charge:" << setw(18) << right << BASE_CHARGE << endl;
		cout << setw(13) << "Check Charge " << setw(2) << checks << " Checks:" << setw(15) << right << checksCharge << endl;
		cout << setw(15) << "Balance Charge:";
		if (belowMin == true) {
			cout << setw(23) << right << BELOW_MIN_CHARGE << endl;
		}
		else cout << setw(23) << right << "0.00" << endl;
		cout << "Total Charges:" << setw(24) << right << totalCharges << endl;
		cout << "Ending Balance:" << setw(23) << right << endBalance << endl;
	}

	// Error msg for invalid checks
	else
		cout << "Error: An invalid number of checks was provided. Please restart and input a positive number or zero.";

	return 0;
}