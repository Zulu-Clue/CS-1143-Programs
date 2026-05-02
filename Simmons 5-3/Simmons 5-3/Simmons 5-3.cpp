// Z Simmons
// CS-1143 Online
// Description: Student line up using files.

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	string students, name, firstStudent, lastStudent;
	ifstream inFile;
	int count = 0;

	// User input
	cout << "Enter filename: ";
	cin >> students;

	inFile.open(students);

	// Error loop checking if file opened
	while (!inFile) {
		cout << "File not found. Enter filename again: ";
		cin >> students;
		inFile.open(students);
	}

	// Read names and determine who is first and last
	while (getline(inFile, name)) {
		if (count == 0) {
			firstStudent = name;
			lastStudent = name;
		}
		else {
			if (name < firstStudent) {
				firstStudent = name;
			}
			if (name > lastStudent) {
				lastStudent = name;
			}
		}
		count++;
	}

	inFile.close();

	// output
	cout << "\nTotal Students: " << count << endl;
	cout << "First Student: " << firstStudent << endl;
	cout << "Last Student: " << lastStudent << endl;

	return 0;
}