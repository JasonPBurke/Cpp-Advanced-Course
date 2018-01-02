// Project00CppClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include <iomanip>
#include <array>
#include <vector>
#include <string>
//#include<sstream>

using namespace std;

int main()
{
	cout << " This program consists of two parts." << endl;
	cout << " We will first collect and display data for part one, " << endl;
	cout << " then we will collect and display data for part two." <<endl<<endl;

	cout << "PART ONE" <<endl<<endl;
	cout << " In this first part, I will ask you to enter the names" << endl;
	cout << " of Game of Thrones characters, the number of dragons" << endl;
	cout << " that character ownes, and then you will enter the" << endl;
	cout << " names of that character's dragons.  We will repeat this" << endl;
	cout << " until you have entered all the characters you wish to enter." << endl;

	cout << endl << "Let's get started!" <<endl<<endl;
	cout << "Character & Dragon data entry:" << endl << endl;
	cout << "Would you like to enter a character?(y/n) ";
	char userChoice;
	cin >> userChoice;

	while (toupper(userChoice) != 'Y' && toupper(userChoice) != 'N') {
		cout << endl << " That is an invalid entry.  Please try again." <<endl<<endl;
		cin.ignore(1024, '\n');
		cin.clear();
		cout << "Would you like to enter a character?(y/n) ";
		cin >> userChoice;
	}
	const size_t rows = 5;
	const size_t columns = 4;
	array< array< string, columns>, rows> names = {};

	while (toupper(userChoice) == 'Y') {
		// Create your function for part one and call it here

		for (size_t i = 0; i < rows; ++i) {
			cin.ignore(1024, '\n');
			cin.clear();
			cout << endl << "Enter character " << i + 1 << "'s name: ";
			string ownerName;
			getline(cin, ownerName);
			//DATA CHECK GOES HERE!!!
			/*while (cin.fail()) {
				cout << "Invalid entry. Please try again." << endl;
				//cin.ignore(1024, '\n');
				//cin.clear();
				cout << "Enter the name of the character: ";
				cin >> ownerName;
			}
			*/
			names[i][0] = ownerName;
			cout << "How many dragons does " << ownerName << " have? ";
			unsigned int totalDragons;
			cin >> totalDragons;
			cin.ignore(1024, '\n');
			cin.clear();
			// DATA CHECK HERE!!!!!!!
			/*while (!isdigit(totalDragons)) {
				cout << "Invalid entry. Please try again." << endl;
				cin.ignore(1024, '\n');
				cin.clear();
				cout << "Enter the number of dragons: ";
				cin >> totalDragons;
			}
			*/
			for (unsigned int j = 0; j < totalDragons; ++j) {
				cout << endl << "Enter dragon #" << j + 1 << "'s name: ";
				string dragonName = "";
				getline(cin, dragonName);
				//cin >> dragonName;
				names[i][j + 1] = dragonName;
			}// end inner for loop

			cout << endl << "Do you want to add another person and their dragons?(y/n) ";
			cin >> userChoice;
			
			while (toupper(userChoice) != 'Y' && toupper(userChoice) != 'N') {
				cout << endl << " That is an invalid entry.  Please try again."<<endl<<endl;
				cin.ignore(1024, '\n');
				cin.clear();
				cout << "Would you like to enter a character?(y/n) ";
				cin >> userChoice;
				
			}
			if (toupper(userChoice) != 'Y') break;			
		}// end outer for loop
	}//end while loop

	for (size_t i = 0; i < rows; ++i) {
		cout << endl << "Here is a list of " << names[i][0] << "'s dragons: ";
		for (size_t j = 1; j < columns; ++j){
			cout << names[i][j] << " ";
		}
		if (i + 1 < rows && names[i + 1][0] == "") {
			break; 
		}
	}
	cout << endl<<endl <<  "PART TWO" <<endl<<endl;
	cout << " In this part, I will ask you to give me the name of one of the " << endl;
	cout << " Seven Kingdoms and the size of their army. You may enter as many" << endl;
	cout << " of the kingdoms and armies as you like." <<endl<<endl;
	// PART 2 GOES HERE -VECTORS
	vector <string> kingdoms; // starting with empty vectors
	vector <int> armySize;
	bool newEntry = true;
	while (newEntry) {
		cin.ignore(1024, '\n');
		cin.clear();
		cout <<endl<<endl << "Please enter the name of one of the Seven Kingdoms: ";
		string kingdomName;
		getline(cin, kingdomName);
		//cin >> kingdomName;
		// ADD DATA CHECK HERE
		kingdoms.push_back(kingdomName);
		cout << "What is the size of the army in " << kingdomName << "? ";
		int sizeOfArmy;
		cin >> sizeOfArmy;
		// DATA CHECK HERE
		armySize.push_back(sizeOfArmy);
		cout << endl << "Do you want to enter another Kingdom?(y/n) ";
		cin >> userChoice;
		while (toupper(userChoice) != 'Y' && toupper(userChoice) != 'N') {
			cout << endl << " That is an invalid entry.  Please try again." << endl << endl;
			cin.ignore(1024, '\n');
			cin.clear();
			cout << "Would you like to enter another Kingdom?(y/n) ";
			cin >> userChoice;
		}
		if (toupper(userChoice) == 'N') {
			newEntry = false;
		}
	}// end while loop

	cout << "Here is the Kingdom data that you entered:" << endl << endl;
	for (size_t i = 0; i < kingdoms.size(); ++i) {
		cout << kingdoms[i] << " has an army of " << armySize[i] << " people." << endl;
	}

	cout << endl << "GoodBye." << endl;
	system("PAUSE");
    return 0;
	
}

