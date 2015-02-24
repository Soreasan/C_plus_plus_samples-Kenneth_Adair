/*
www.cslearner.com

In a math class there was a question where I need to graph out
three equations.  It occurred to me that it's faster to create a
computer program to calculate the three values out for me than to do it by hand
with a scientific calculator.  So I did it!  =D
(I still had to graph the points by hand though...  =(  )

Creating tables of values for 0 through 8 for the following equations:
s = f(t) = t^3 - 12t^2 + 36t = t(t - 2)(t - 6)
v(t) = f'(t) = 3t^2 - 24t + 36 = 3(t^2 - 8t + 12)
a(t) = v'(t) = 6t - 24 = 6(t - 4)
*/

#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	cout << "f(t):" << endl;
	cout << "x y" << endl;
	for (int i = 0; i <= 8; i++){
		int x = i;
		int y;
		y = ((x * x * x) - (12 * x * x) + (36 * x));
		cout << x << " " << y << endl;
	}

	cout << endl << "v(t):" << endl;
	cout << "x y" << endl;
	for (int i = 0; i <= 8; i++){
		int x = i;
		int y;
		y = ((3 * x * x) - (24 * x) + 36);
		cout << x << " " << y << endl;
	}

	cout << endl << "a(t): " << endl;
	cout << "x y" << endl;
	for (int i = 0; i <= 8; i++){
		int x = i;
		int y;
		y = ((6 * x) - 24);
		cout << x << " " << y << endl;
	}

	_getch();
	return 0;
}