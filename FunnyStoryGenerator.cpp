/*
Kenneth Adair
www.cslearner.com

This is a simple program that takes user input and puts it into one of five random stories.  
*/

#include <iostream> //Used for input and output
#include <conio.h> //used for _getch();
#include <cstdlib> //Has the random number generator
#include <ctime> //Helps the rand() be even more random, not sure why though...
#include <string> //let's us use CIN to get strings
using namespace std;

int main(){
	//Seeds the program with new random numbers every time
	srand((unsigned)time(0));

	//declare an int variable
	int randomStory;

	//This variable checks if the user wants to continue
	char continueStory;
	continueStory = 'y';

	//These variables will be used to get user input
	string pet = "";
	string hero = "";
	string badGuy = "";
	
	cout << "This program takes three names and based on a random number generates a story." << endl;
	//A WHILE loop loops as long as the condition is true.
	while (continueStory == 'y' || continueStory == 'Y'){
		//this section gathers the user input
		cout << "Enter the name of a hero: " << endl;
		getline(cin, hero);
		cout << "Enter the name of a household pet: " << endl;
		getline(cin, pet);
		cout << "Enter the name of a villain: " << endl;
		getline(cin, badGuy);

		//generates a random number, used to pick which story, it was above the loop before but I moved it down here
		//so that if the user loops through it it will generate a different story each time.
		randomStory = (rand() % 5) + 1;


		if (randomStory == 1){
			cout << badGuy << " kidnaps " << pet << " and tries to get away but then "
				<< hero << " throws a banana and " << badGuy << " dies!" << endl;
		}
		else if (randomStory == 2){
			cout << badGuy << " grabs " << pet << " and tries to eat it but then "
				<< hero << " fire laserbeams out of his face and " << badGuy << " explodes!" << endl;
		}
		else if (randomStory == 3){
			cout << badGuy << " swears at " << pet << " but then out of nowhere "
				<< hero << " goes into super saiyan mode and attacks " << badGuy << " and is victorious!!" << endl;
		}
		else if (randomStory == 4){
			cout << badGuy << " licks " << pet << " and tries to get away with it but "
				<< hero << " licks " << badGuy << " and gives him a taste of his own medicine!" << endl;
		}
		else{
			cout << badGuy << " notices " << pet << " and "
				<< hero << ". They all become friends until " << badGuy << " is mean so the world explodes" << endl;
		}
		cout << "Would you like to continue?" << endl << "Enter Y or y to continue." << endl;
		cin >> continueStory;
		cin.sync(); //If this isn't here then the program will skip lines when it loops
	}

	cout << "Thank you for playing!" << endl << "Press any key to end this program." << endl;
	_getch();
	return 0;
}