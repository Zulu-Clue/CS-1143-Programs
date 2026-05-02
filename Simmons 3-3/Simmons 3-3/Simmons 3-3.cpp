// Z Simmons
// CS-1143 Online
// Description: Word Game

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main()
{
	// Declare Variables
	string name, city, college, job, petType, petName; 
	int age;

	// User Input
	cout << "Enter a name: ";
	getline(cin, name);
	cout << "Enter an age: ";
	cin >> age;
	cin.ignore();
	cout << "Enter a city: ";
	getline(cin, city);
	cout << "Enter a college: ";
	getline(cin, college);
	cout << "Enter an occupation: ";
	getline(cin, job);
	cout << "Enter a type of pet: ";
	getline(cin, petType);
	cout << "Enter the pet's name: ";
	getline(cin, petName);
	
	// Output word game
	cout << "There once was a person named " << name << " who lived in " << city << ". At the age of " << age << ", " << name << " went to" << endl;
	cout << "college at " << college << ". " << name << " graduated and went to work as a teacher. Then," << endl;
	cout << name << " adopted a(n) " << petType << " named " << petName << ". They both lived happily ever after!" << endl;

	return 0;
}