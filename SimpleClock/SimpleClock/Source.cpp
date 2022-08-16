/*
* SNHU CS-210 Clock App
*
* Professor: Bill Chan
* Author: Brian H. Argenti
* Created: 2022 July 16
*/
#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
using namespace std;

int currentTime[3] = { 0, 0, 0 };

// Function prints a two digit string from 00 to 59
string twoDigitString(unsigned int n) {
	string nToStr;

	nToStr = to_string(n);

	if (nToStr.size() == 1) {     // if only one digit 
		nToStr.insert(0, "0");    // append 0 in front of lone digit
	}

	return nToStr;
}

// Function prints a border for the Clock 
string nCharString(size_t n, char c) {
	string border;

	border.append(n, c);         // take empty string and append 'c' n amount of times

	return border;
}

// Function formats time into miilitary time
string formatTime24(unsigned int hours, unsigned int minutes, unsigned int seconds) {
	string milTime;

	milTime = twoDigitString(hours) + ":" + twoDigitString(minutes) + ":" + twoDigitString(seconds);  // concatenates hrs, mins, and secs 
																									  // separated by ":"
	return milTime;
}

// Function formats time into standard time
string formatTime12(unsigned int hours, unsigned int minutes, unsigned int seconds) {
	string standardTime;

	if (hours >= 1 && hours < 12) {  // checks for AM time
		standardTime = twoDigitString(hours) + ":" + twoDigitString(minutes) + ":" + twoDigitString(seconds) + " A M";
	}

	else if (hours >= 12) {  // determines PM time
		if (hours == 12) {
			standardTime = twoDigitString(hours) + ":" + twoDigitString(minutes) + ":" + twoDigitString(seconds) + " P M";
		}
		else {  // converts 24 hr to 12 hr time 
			standardTime = twoDigitString(hours - 12) + ":" + twoDigitString(minutes) + ":" + twoDigitString(seconds) + " P M";
		}
	}

	else {  // 0 has been isolated and converts to 12 AM
		standardTime = twoDigitString(hours + 12) + ":" + twoDigitString(minutes) + ":" + twoDigitString(seconds) + " A M";
	}

	return standardTime;
}

// Function prints 12 and 24 hour clock in side-by-side format
void printClocks() {
	string top;
	string header;
	string formattedClocks;
	string bottom;

	top = nCharString(26, '*') + "     " + nCharString(26, '*');
	header = "*     12-Hour Clock      *     *      24-Hour Clock     *";
	formattedClocks = "*     " + formatTime12(currentTime[0], currentTime[1], currentTime[2]) + "       *     *       "
		+ formatTime24(currentTime[0], currentTime[1], currentTime[2]) + "         *";
	bottom = top;

	cout << top << endl;
	cout << header << endl;
	cout << formattedClocks << endl;
	cout << bottom << endl;
	cout << endl;

}

// Function prints menu
void printMenu() {
	cout << "             " << nCharString(26, '*') << endl;
	cout << "             * 1 - Add One Hour       *" << endl;
	cout << "             * 2 - Add One Minute     *" << endl;
	cout << "             * 3 - Add One Second     *" << endl;
	cout << "             * 4 - Exit Program       *" << endl;
	cout << "             " << nCharString(26, '*') << endl;
	cout << endl;


}

// Function takes Menu Choice and adds hour, minute, or second based on user input.
unsigned int getMenuChoice(unsigned int maxChoice) {

	while (maxChoice != 4) {
		system("CLS");
		printClocks();
		printMenu();
		cout << "Enter your choice.";
		cin >> maxChoice;

		if (maxChoice == 1) {		  // Adds 1 hour
			currentTime[0] += 1;
			if (currentTime[0] % 24 == 0) {  // Resets hours
				currentTime[0] = 0;
			}
		}

		else if (maxChoice == 2) {   // Adds 1 minute			
			currentTime[1] += 1;
			if (currentTime[1] % 60 == 0) {  // Resets minutes
				//currentTime[0] += 1;
				currentTime[1] = 0;
			}
		}

		else if (maxChoice == 3) {   // Adds 1 second			
			currentTime[2] += 1;
			if (currentTime[2] % 60 == 0) {  // Resets seconds
				//currentTime[1] += 1;
				currentTime[2] = 0;
			}
		}

		else if (maxChoice == 4) {
			cout << "Exiting program";
		}

		else if (maxChoice >= 5 || maxChoice <= 0) {
			cout << "invalid entry" << endl;
		}

	}


	return 0;
}



int main() {
	int userAction = 0;

	getMenuChoice(userAction);




	return 0;
}