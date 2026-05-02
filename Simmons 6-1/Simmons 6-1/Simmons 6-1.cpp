// Z Simmons
// CS-1143 Online
// Description: Coin toss

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

// Function prototype
int coinToss(bool toss);

int main() {
	
	// Declare variables
	int numTosses = 0, heads = 0, tails = 0;
	bool result = 0;

	// Seed rng
	srand(time(0));

	cout << "Enter the number of times to toss coin: ";
	cin >> numTosses;

	// Input validation
	while (numTosses <= 0) {
		cout << "\nInvalid input. Enter a number greater than 0: ";
		cin >> numTosses;
	}

	// Loop to toss the coin
	for (int count = 0; count < numTosses; count++)
	{		
		result = coinToss(count);

		if (result == 0)
		{
			cout << "Heads\n";
			heads++;
		}
		else
		{
			cout << "Tails\n";
			tails++;
		}
	}

	// Output totals
	cout << "Total Heads:" << setw(4) << right << heads << endl;
	cout << "Total Tails:" << setw(4) << right << tails << endl;

	return 0;
}

// Function definition
int coinToss(bool toss)
{
	bool answer;

	answer = rand() % 2;

	return answer;
}