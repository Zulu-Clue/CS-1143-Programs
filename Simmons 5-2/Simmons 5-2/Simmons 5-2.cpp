// Z Simmons
// CS-1143 Online
// Description: Distribution of Random Numbers

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

int main()
{
	// Declare variables & setup array
	int totalNums, counts[10] = {0}, group, randNum, sum = 0, lower, upper;
	double percentage;

	// Seed random number generator
	srand(time(0));

	cout << "Enter how many numbers to generate: ";
	cin >> totalNums;

	// Checking for valid input
	if (totalNums >= 1)
	{

		// Generate random numbers and count groups, adding 1 to the array the number belongs in.
		for (int count = 0; count < totalNums; count++)
		{
			randNum = rand() % 100;
			group = randNum / 10;
			counts[group]++;
		}

		// Output
		cout << fixed << setprecision(1);

		cout << "\nDistribution of " << setw(3) << totalNums << " random numbers.\n\n";
		cout << setw(8) << "Range" << setw(10) << "Total" << setw(12) << "Percent\n\n";


		// Finding percentage & formatting left column using a loop.
		for (int count = 0; count < 10; count++)
		{
			lower = count * 10;
			upper = count * 10 + 9;

			percentage = 0.00;

			// Calculating percentage
			if (totalNums > 0)
			{
				percentage = (counts[count] / (double)totalNums) * 100.0;
				percentage = (int)(percentage * 10 + 0.5) / 10.0;
			}

			cout << setw(3) << lower << "-" << setw(2) << upper << setw(10) << counts[count] << setw(11) << percentage << "%\n";

			sum += counts[count];
		}

		cout << "\n";
		cout << setw(8) << "Total" << setw(10) << sum << setw(11) << "100%\n";

	}

	else {
		cout << "\nError: Please enter a positive number greater than 0.\n";
	}

	return 0;
}