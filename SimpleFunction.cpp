/*
www.cslearner.com
Comment
Subscribe
Like
*/

//Header files
#include <iostream> //Input output stream
#include <conio.h> //used for _getch(); gets a character
using namespace std; //Makes it unnecessary to type out std::cout or std::cin

//Function declaration, indicates there is a function at the bottom
void SpewProfanity();
	
int main(){
	//We're asking our program to run our function that we named SpewProfanity:
	SpewProfanity();
	_getch();
	return 0;
}

//-----------------------------
void SpewProfanity(){
	cout << "**** the rules, I have money!" << endl;
	cout << "Piece of ****" << endl;
	cout << "Son of a *****" << endl;
}