/*
Kenneth Adair
www.cslearner.com

This is a simple game that randomly generates a number between 1 and 10.  
The user guesses what the number is until they get it right while the program gives them hints
to guess HIGHER or LOWER.  
Once the user wins they are allowed to play again if they'd like.  

The program is very simple and doesn't have error checking.  
For example: right now the program goes into an infinite loop if you enter a letter instead of a number.
*/

#include <iostream>	//basic input/output stuff
#include <ctime>	//Used to ensure the random number generator has a different number each time
#include <cstdlib>	//Used for random number generator
#include <conio.h>	//used for _getch(); which is used to prevent the program from closing early
using namespace std;

int main(){
	char continuePlaying = 'y';
	while (continuePlaying == 'y' || continuePlaying == 'Y'){
	srand((unsigned)time(0));	//ensures the random number is truly random, generates a new number each round
	int guessThisNumber;		//creates an integer variable
	int guess = 0;				//This is the integer variable that contains the player's guess
	guessThisNumber = (rand() % 10) + 1;	//sets the integer variable equal to a random number

	while (guess != guessThisNumber)
	{
		cout << "Guess a number between 1 and 10: " << endl;
		cin >> guess;
		if (guess == guessThisNumber){
			cout << "Congrats!  You guessed the correct number!" << endl;
			cout << "You guessed: " << guess << endl;
			cout << "The correct answer was also: " << guess << endl;
			cout << "Play again? ('Y' for YES or 'N' for NO)" << endl;
			cin >> continuePlaying;
		}
		else if (guess > guessThisNumber){
			cout << "Your guess is too high.  Guess lower." << endl;
		}
		else if (guess < guessThisNumber){
			cout << "Your guess is too low.  Guess higher." << endl;
		}
		else{
			cout << "ERROR 404: Does not compute." << endl;
		}

	}//end of guessing loop

}//First WHILE loop
	cout << "Thank you for playing this game.  Press any key to close this program." << endl;
	_getch();
	return 0;
}//end of program