/*
www.cslearner.com
like
comment
subscribe
adopt a kitten
ADOPT A FREAKING KITTEN BECAUSE KITTENS ARE KITTENS
AND THEY BECOME CATS
Adopt a kitty today
*/
#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	//Format for an array is datatype Name[#]
	int CatKennels[5];
	for (int j = 0; j < 5; j++){
		cout << "Enter a cat number: " << endl;
		cin >> CatKennels[j];
	}
	for (int j = 0; j < 5; j++){
		cout << "Cat " << j << " who was a cat with the number " << CatKennels[j] << " escaped from the kennel!" << endl;
	}
	_getch();
	return 0;
}