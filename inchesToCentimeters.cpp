/*
www.cslearner.com

This is a simple program that has a method that converts inches to centimeters.  
Each inch is 2.54 centimeters so the program takes a user input of inches and multiplies it by 2.54 and then returns the value.
Additionally I put in some simple error handling in case the user input was not a number.  
The WHILE loops ensure that the user will insert correct data and that the program can loop as many times as the user likes.
*/

//This is used for input and out and other things
#include <iostream>
//This is used for _getch();
#include <conio.h>
//This is used so we don't have to type std::cout or std::cin.  We can just type cout or cin.  
using namespace std;

//This method converts inches to centimeters as long as the input is positive
double inchesToCentimeters(double inches){
	//Checks to make sure input is positive
	if (inches < 0){
		//throws an error if it's not positive
		cerr << "Please input a POSITIVE number." << endl;
		return -1.0;
	}
	else
		return 2.54 * inches;
}

//This is the start of our main program
int main(){
	//variables we need for the WHILE loop
	//This variable is used to check if the user wants to continue using the program after typing the first number in
	bool continueProgram = true;
	//This variable is the user's input of inches
	double inches;
	//This variable is the centimeter value that we return
	double centimeters;

	char continueToProgramCheck;
	
	//Start of the WHILE loop so the program will run as long as the user wants to
	while (continueProgram == true){

		/*Borrowed this user-input-checking code from this thread on Stack Overflow:
		 http://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input
		The purpose of this code is to have error-checking for when a user inputs a string or character or something that's not an integer
		"The reason the program goes into an infinite loop is because std::cin's bad input flag is set due to the input failing. 
		The thing to do is to clear that flag and discard the bad input from the input buffer."
		*/
		while (cout << "Enter a positive number value to convert it from centimeters to inches: " << endl && !(cin >> inches)){
			cin.clear(); //clears the bad input flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discards the incorrect user input
			cout << "Invalid input; please re-enter.\n"; //Asks the user for input again
		}

			//Our variable centimeters is equal to the method's output
			centimeters = inchesToCentimeters(inches);

			//If the centimeter method threw an error we skip this next code
			if (centimeters != -1.0){
				//If the centimeter method was successful we output this code
				cout << inches << " inches is: " << centimeters << " centimeters." << endl;
			}
			//Ask the user if they wish to continue
			//I don't feel the need for error checking here because any input can be a string so anything but Y will end the program
			cout << "Would you like to enter another number?  (Y for yes, N for no)" << endl;
			cin >> continueToProgramCheck;
			//If the user's input is uppercase or lowercase Y then continue the program, otherwise end it
			if (continueToProgramCheck != 'Y' && continueToProgramCheck != 'y'){
				continueProgram = false;
			}
	}
	cout << "Thank you for using this program.  Have a good day" << endl;
	//_getch(); is used in windows to ask the user for a single character input before ending the program
	//This allows the user to see the final output before the program closes
	_getch();
	//return 0 indicates the program was successful
	return 0;
}