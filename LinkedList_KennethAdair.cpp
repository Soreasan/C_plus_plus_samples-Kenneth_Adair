/*
Kenneth Adair
cslearner.com
9/30/14
In my CS 2420 class we learned about linked lists!
The code below is a *HEAVILY* modified version of an assignment.  
(I don't want to enable cheaters.)

The code isn't perfect, but it creates a linked list and allows the user
to either enter a new value into the list, delete a value from the list,
or retrieve/return the value from a specific node in the list.  

The most important part of this assignment for me was ensuring my loops
worked correctly and that I was updating the pointers correctly so I didn't
lose any of my nodes a long the way.  

The main errors in this code right now are a lack of good error checking while
testing the classes.  The classes are set up in a way that if you insert weird
data I believe they react correctly, however my testing code in "int main()"
still outputs that the data was modified correclty which isn't always true.  
*/

//This is the header stuff in every program
#include <iostream>
#include <conio.h>
using namespace std;


//These are the nodes that will be in the linked list.  
//Each node contains information and a pointer to the next node in the linked list.
//It's also worth noting that this is a template class so it can be any data type.
template <typename T>
class Node{
public:
	//info is the actual information in the node
	T info;
	//link is the name of the pointer that points to the next node
	Node *link;
};


//This is the linked list class and it contains the methods and data we'll be working with.
template <typename T>
class LinkedList{
public:
	//constructor, creates the linked list
	LinkedList();
	//destructor, wipes out the linked list
	~LinkedList();
	//Inserts values into the list
	void insertValue(const unsigned int index, const T& value);
	//returns a value 
	T returnValue(const unsigned int index);
	//This one *ISN'T* used in the tests.  However it overloaded the "returnValue" method.  
	//That means variableName->returnValue(2) is the same as variableName[2]
	T& operator[](const unsigned int index);
	//deletes a node and updates the pointers around it
	void deleteValue(const unsigned int index);


protected:
	//tracks the first node in the linked list
	Node<T> *first;
	//tracks the last node in the linked list
	Node<T> *last;
	//tracks how many total nodes are in the list
	int count;
};

//this is the constructor
//When you initially create the list the count is zero and the pointers are null
template <typename T>
LinkedList<T>::LinkedList() {
	first = NULL;
	last = NULL;
	count = 0;
}

//this is the destructor
//This destructor loops through each of the nodes and destroys them
template <typename T>
LinkedList<T>::~LinkedList() {
	Node<T> *temp;
	while (first != NULL) {
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}

//This method loops through the linked list to the correct spot,
//inserts a node, updates the pointers around it, and then increments count;
//There is also error handling for bad indexes
template <typename T>
void LinkedList<T>::insertValue(const unsigned int index, const T& value)
{
	//If the index is negative, throw an error
	//If the index is too big, throw an error
	if (index < 0 || index > count){
		return;
	}	//If the index is the new first node, do this (Copied and pasted INSERT FIRST code)
	else if (index == 0){
		Node<T> *temp = new Node<T>();
		temp->info = value;
		temp->link = NULL;

		//empty list scenario
		if (first == NULL) {
			last = temp;
		}
		else {
			temp->link = first;
		}

		first = temp;
		count++;
		return;

	}	//If the index is the new last node insert it at the end
	else if (index == count){
		Node<T> *temp = new Node<T>;
		temp->info = value;
		temp->link = NULL;

		if (first == NULL) {
			first = temp;
		}
		else {
			//put it on
			last->link = temp;
		}
		last = temp;
		count++;
		return;
	}
	else{
		//GENERAL CASE
		//Create a pointer to track where the pointer is right now
		Node<T> * curr = first;
		//Create a pointer to track where the previous node is
		Node<T> * prev = NULL;
		//Creates a counter so we can compare this to the index
		int counter = 0;
		//Until the counter and the index are the same keep looping
		while (counter < index){
			//the previous node pointer is bumped up one
			prev = curr;
			//The current node pointer is bumped up one
			curr = curr->link;
			//increment counter
			counter++;
		}
		//creates a new node and saves the address as newNode
		Node<T> * newNode = new Node < T >;
		//updates the contents of the newNode node to be equal to the value passed in
		newNode->info = value;
		//updates newNode to point to the next address
		newNode->link = curr;
		//updates prev to point to the new next address which is where newNode is
		prev->link = newNode;
		//Sets our temporary pointers back to null
		curr = NULL;
		newNode = NULL;
		//Increments count
		count++;
		return;
	}
}

//This method loops to the correct index and retrieves the information.  
template <typename T>
T LinkedList<T>::returnValue(const unsigned int index)
{
	//If the index is outside the linked list throw an error
	if (index < 0 || index > count) {
		throw 1;
	}
	//If the index is correct loop to the right spot and get the right information
	else{
		Node<T> * curr = first;
		int counter = 0;
		while (counter < index){
			curr = curr->link;
			counter++;
		}
		return curr->info;
	}
}

//This isn't used at all in the test below.  HOWEVER this overloads the square brackets []
//This method is identical to the returnValue method, just different syntax
template <typename T>
T& LinkedList<T>::operator[](const unsigned int index)
{
	if (index < 0 || index > count) {
		throw 1;
	}
	else{
		Node<T> * curr = first;
		int counter = 0;
		while (counter < index){
			curr = curr->link;
			counter++;
		}
		return curr->info;
	}
}

//This method loops to the correct index and deletes the node and updates the pointers around it
template <typename T>
void LinkedList<T>::deleteValue(const unsigned int index)
{
	//If they try to delete a node outside the range THROW AN ERROR!  WE DON'T WANT YOUR LEMONS!
	if (index < 0 || index > count){
		return;
	}//If there are no nodes
	else if (first == NULL){
		return;
	}//If there's one node
	else if (first == last){
		delete first;
		first = NULL;
		last = NULL;
		count--;
		return;
	}//If it's the last node

	else if (index == count){
		Node<T> * curr = first;
		Node<T> * prev = NULL;
		while (curr->link != NULL){
			prev = curr;
			curr = curr->link;
		}
		prev->link = NULL;
		delete curr;
		last = prev;
		count--;

	}
	else if (index == 0){
		Node<T> * temp = first;
		first = first->link;
		delete temp;
		temp = NULL;
		count--;
	}
	else{
		Node<T> * curr = first;
		Node<T> * prev = NULL;
		Node<T> * nextone = NULL;
		int counter = 0;

		while (counter < index){
			prev = curr;
			curr = curr->link;
			counter++;
		}
		nextone = curr->link;
		prev->link = nextone;
		delete curr;
		count--;

	}
}

//the main method is where we'll actually test all the code above
int main() {
	char userinput;
	cout << "Hello!  This code creates a linked list of any data type and allows you to insert or delete nodes!" << endl;
	cout << "Would you like to create a linked list?  Enter \"y\" for yes or \"n\" for no." << endl;
	cin >> userinput;
	if (userinput != 'y' && userinput != 'Y'){
		cout << "You have selected NO.  Have a good day!" << endl;
		_getch();
		return 0;
	}
	else{
		cout << "Alright!  Let's make a linked list!" << endl;
	}

	cout << "The classes are set up in a way that theoretically we could use any data type." << endl;
	cout << "Specifically, it's set up using template classes." << endl;
	cout << "However for the sake of simple testing we'll use an \"int\" data type for the nodes." << endl;
	
	//These are all the variables we'll need for the next list
	LinkedList<int> *test = new LinkedList < int > ;
	int selectHelper;
	int indexHelper;
	int valueHelper;
	
	while (userinput == 'y' || userinput == 'Y'){
		cout << "Would you like to: "<< endl;
		cout << "Insert a value? (Enter \"1\")" << endl;
		cout << "Delete a value?(Enter \"2\")" << endl;
		cout << "Return a value?(Enter \"3\")" << endl;
		cin >> selectHelper;
		if (selectHelper == 1){
			cout << "Enter the index you would like to place the new node." << endl;
			cout << "(Enter \"0\" for the first node.)" << endl;
			cin >> indexHelper;
			cout << "Enter the value you would like to place into the new node." << endl;
			cout << "(Remember to insert an integer!)" << endl;
			cin >> valueHelper;
			test->insertValue(indexHelper, valueHelper);
			cout << "Your value was successfully entered into the linkedlist." << endl;
		}else if (selectHelper == 2){
			cout << "Enter the index of the node you would like to delete." << endl;
			cout << "(Enter \"0\" for the first node.)" << endl;
			cin >> indexHelper;
			test->deleteValue(indexHelper);
			cout << "The value was successfully deleted from the linkedlist." << endl;
		}
		else if (selectHelper == 3){
			cout << "Enter the index of the node you would like to retrieve information from." << endl;
			cout << "(Enter \"0\" for the first node.)" << endl;
			cin >> indexHelper;
			valueHelper = test->returnValue(indexHelper);
			cout << "The value at node " << indexHelper << " is " << valueHelper << "." << endl;
		}
		else{
			cout << "You did not enter a valid option." << endl;
		}
		cout << "Would you like to continue experimenting with the linked list?" << endl;
		cout << "Enter \"y\" for yes or \"n\" for no." << endl;
		cin >> userinput;
	}
	cout << "Thank you!  Press any key to end the program." << endl;
	_getch();
	return 0;
}