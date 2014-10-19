/*
Kenneth Adair
Student at Weber State University
www.cslearner.com

This is a simple program that allows the user to enter 2 integers and adds them together.
It doesn't have any error handling so the program goes crazy if you enter non-integer values.
The WHILE loop allows the user to do multiple additon problems if they'd like to.  
*/

//Header stuff
#include <iostream>
#include <conio.h>
using namespace std;

//int main is the start of the real program
int main(){

	//These two integer variables are the numbers we'll store
	int firstNumber;
	int secondNumber;
	//This CHARACTER type variable will allow us to check if the user wants to keep using the program
	char confirm = 'y';

	//This is the message that introduces the program to the users in the console
	cout << "This is a program that adds two integers together." << endl;

	//A WHILE loop keeps looping as long as the condition is satisfied
	while (confirm == 'y' || 'Y'){
		
		//CIN is the syntax that allows our program to retrieve the user's input and put it as the value of our variable
		cout << "Enter first integer: " << endl;
		cin >> firstNumber;
		cout << "Enter second integer: " << endl;
		cin >> secondNumber;

		//This COUT message displays the information the user wants
		cout << firstNumber << " + " << secondNumber << " is equal to " << firstNumber + secondNumber << "." << endl;
		cout << "The answer to the question is: " << firstNumber + secondNumber << endl << endl;

		//This part allows the user to have the option to continue the loop by typing 'y' or 'Y'
		//If they type anything else the program ends.
		cout << "Would you like to continue?  ('y' for yes)" << endl;
		cin >> confirm;
	}

	//The end of the program and shameless advertising for my website
	cout << "Thank you for using this program!" << endl;
	cout << "Check out www.cslearner.com" << endl;
	cout << "Press any key to close this program" << endl;

	//_getch() is a GET CHARACTER command.  This prevents my program from closing immediately by waiting for the user to enter a key
	_getch();
	//return 0 confirms to the C++ program that the program worked.  In C it was used a lot more but in C++ it just confirms the program worked
	return 0;
}