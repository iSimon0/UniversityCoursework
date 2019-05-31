//Program Name: Doubly Linked Lists
//Programmer Name: Ian Simon
//Description: Takes in values from a file and puts them in a
	//linked list and the even numbers only in a linked list.
	//User can add or delete numbers from the list
//Date Created: 10/30/17
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

typedef struct node
{
	node *next;
	int num;
};//defines the struct used for moving through the linked list

typedef struct list
{
	node *allHead, *allCurr;
	node *evenHead, *evenCurr;
	node *prior;
	node *temp;
};//defines the struct used for the pointers that hold the linked list
//function prototypes
void deleteList(list list);
void displayList(list list, node nodes);
void sortList(list list, node nodes, char userChoice);
void insertNode(list list, node nodes, int newValue, ofstream& ofs);
void deleteNode(list list, node nodes, int deleteValue, ofstream& ofs);

int main()
{
	ifstream ifs;
	ofstream ofs;
	string fileName;
	list list;
	node nodes;
	char userChoice1, userChoice2, userChoice3;
	int newValue;
	int deleteValue;
	
	cout << "Welcome to the program!" << endl;
	cout << "Enter a file name: ";
	cin >> fileName;
	
	ifs.open(fileName.c_str());
	ofs.open("log.txt");//opens both the input and output files
	
	while(ifs.fail())
	{
		cout << "File does not exist." << endl;
		cout << "ERROR SENT TO LOG.TXT" << endl;
		ofs << "Error: File name does not exist." << endl;//outputs text to a file
		cin >> fileName;//if the file does not exist the loop contunes until it finds one
		ifs.open(fileName.c_str());
	}
	
	list.allHead = new node;
	list.allCurr = list.allHead;
	ifs >> list.allHead -> num;//inputs the first data from the file to a head of a list
	list.allHead -> next = new node;
	list.allCurr = list.allHead -> next;
	while(ifs.good())
	{
		ifs >> list.allCurr -> num;
		list.allCurr -> next = new node;
		list.allCurr = list.allCurr -> next;//inputs the data into a list
	}
	list.allCurr -> next = NULL;
	if(list.allHead -> num % 2 == 0)
	{//sets the pointers to the first even number in the list
		list.evenHead = list.allHead;
	}
	list.allCurr = list.allHead;
	list.evenCurr = list.evenHead;
	while(list.allCurr -> next != NULL)
	{
		if(list.allCurr -> num % 2 == 0)
		{//sets the rest of the even umbers to the lsit
			list.evenCurr = list.allCurr;
		}
		list.allCurr = list.allCurr -> next;
		list.evenCurr = list.evenCurr -> next;
	}
	cout << "Which way would you like to output this list? (A for ascending, or D for decsending)" << endl;
	cin >> userChoice1;
	while(userChoice1 != 'A' && userChoice1 != 'a' && userChoice1 != 'D' && userChoice1 != 'd')
	{//user chooses to make the list ascend
		cout << "ERROR: INVALID CHAR; A or D." << endl;
		cout << "ERROR SENT TO LOG.TXT" << endl;
		ofs << "Error: Invalid char." << endl;
		cin >> userChoice1;
	}
	sortList(list, nodes, userChoice1);
	displayList(list, nodes);
	cout << endl;
	cout << "Would you like to add a number? (Y or N)" << endl;
	cin >> userChoice2;
	if(userChoice2 == 'Y' || userChoice2 == 'y')
	{//if the user wants to add a number
		cout << "What number would you like to insert?" << endl;
		cin >> newValue;//new number to be added
		insertNode(list, nodes, newValue, ofs);
		sortList(list, nodes, userChoice1);
		displayList(list, nodes);
		cout << endl;
	}
	else if(userChoice2 == 'N' || userChoice2 == 'n')
	{
		cout << "The list remains: ";
		displayList(list, nodes);
		cout << endl;//no changes to the list
	}
	else
	{
		cout << "ERROR SENT TO LOG.TXT" << endl;
		ofs << "Error: Invalid char." << endl;
	}
	cout << "Would you like to delete a number? (Y or N)" << endl;
	cin >> userChoice3;
	if(userChoice3 == 'Y' || userChoice3 =='y')
	{//if the user wants to delete a number from the list
		cout << "What number would you like to delete?" << endl;
		cin >> deleteValue;
		deleteNode(list, nodes, deleteValue, ofs);
		displayList(list, nodes);
		cout << endl;
	}
	else if(userChoice3 == 'N' || userChoice3 == 'n')
	{
		cout << "The list remains: ";
		displayList(list, nodes);
		cout << endl;//no changes made to the list
	}
	else
	{
		cout << "ERROR SENT TO LOG.TXT" << endl;
		ofs << "Error: Invalid char." << endl;
	}
	cout << "Thanks for using this program!" << endl;
	ofs.close();
	ifs.close();
	deleteList(list);
	
		
	
		
	return 0;
}
//Description: Displays both the all list and even list to the console
//Pre-condition: List and nodes are parameters
//Post-condition: Prints the lists to the console
void displayList(list list, node nodes)
{
	list.allCurr = list.allHead;
	list.evenCurr = list.evenHead;
	cout << "All integers contained: ";
	while(list.allCurr -> next != NULL)
	{//prints all the numbers of the list
		cout << list.allCurr -> num << " ";
		list.allCurr = list.allCurr -> next;
	}
	cout << "Even integers contained: ";
	while(list.evenCurr -> next != NULL)
	{
		if(list.evenCurr -> num % 2 == 0)
		{//prints the even numbers ot the list
			cout << list.evenCurr -> num << " ";
		}
		list.evenCurr = list.evenCurr -> next;
	}
}
//Description: Sorts the linked list in the user specified direction
//Pre-condition: list, nodes and the user direction are parameters
//Post-condition: Sorts the list in the specfied direction
void sortList(list list, node nodes, char userChoice)
{
	list.allCurr = list.allHead;
	list.prior = list.allHead;
	int tempNum;
	if(userChoice == 'A' || userChoice == 'a')
	{//ascending order
		while(list.allCurr -> next != NULL)
		{
			list.prior = list.allHead;
			while(list.prior -> next != NULL)
			{
				if(list.prior -> num > list.allCurr -> num)
				{
					tempNum = list.prior -> num;//bubble sorts the list
					list.prior -> num = list.allCurr -> num;
					list.allCurr -> num = tempNum;
				}
				list.prior = list.prior -> next;
			}
			list.allCurr = list.allCurr -> next;
		}
		list.allCurr = list.allHead;
	}
	else if(userChoice == 'D' || userChoice == 'd')
	{//descending order
		while(list.allCurr -> next != NULL)
		{
			list.prior = list.allHead;
			while(list.prior -> next != NULL)
			{
				if(list.prior -> num < list.allCurr -> num)
				{
					tempNum = list.allCurr -> num;//bubble sorts the list
					list.allCurr -> num = list.prior -> num;
					list.prior -> num = tempNum;
				}
				list.prior = list.prior -> next;
			}
			list.allCurr = list.allCurr -> next;
		}
		list.allCurr = list.allHead;
	}
}
//Description: Inserts a value in the specified direction
//Pre-condition: list, nodes, newValue, and the output file are parameters
//Post-condition: Inserts a number into the list
void insertNode(list list, node nodes, int newValue, ofstream& ofs)
{
	list.prior = list.allHead;
	list.allCurr = list.allHead -> next;
	while(list.allCurr != NULL && newValue > list.allCurr -> num && newValue != list.allCurr -> num)
	{//moves through the list to find a certain position
		list.prior = list.allCurr;
		list.allCurr = list.allCurr -> next;
	}
	if(newValue == list.allCurr -> num || newValue < 0)
	{//the number is already in the list this will run
		cout << "NUMBER ALREADY CONTAINED IN LIST OR INVALID INT" << endl;
		cout << "ERROR SENT TO LOG.TXT" << endl;
		if(newValue == list.allCurr -> num)
		{
			ofs << "Error: User added number already contained in the list." << endl;
		}
		else
		{
			ofs << "Error: Invalid integer." << endl;
		}
	}
	else
	{//as long as it passes the earlier conditions this will run
		list.temp = new node;
		list.temp -> num = newValue;
		list.temp -> next = list.allCurr;
		list.prior -> next = list.temp;
	}
}
//Description: Deletes the specified node
//Pre-condition: list, node, deleteValue and output file are parameters
//Post-condition: Node is deleted for the specified position
void deleteNode(list list, node nodes, int deleteValue, ofstream& ofs)
{
	list.prior = list.allHead;
	list.allCurr = list.allHead -> next;
	list.temp = list.allHead -> next -> next;
	while(list.allCurr -> next != NULL && deleteValue != list.allCurr -> num)
	{//moves through the list to find the deleted number wanted
		list.prior = list.allCurr;
		list.allCurr = list.temp;
		list.temp = list.temp -> next;
	}
	if(deleteValue == list.allCurr -> num)
	{//when the numbers match it will delete the number in the list
		delete list.allCurr;
		list.prior -> next = list.temp;
	}
	else
	{//passes the other conditions, will delete the specified number
		list.allCurr = list.allHead;
		cout << "NUMBER DOES NOT EXIST IN LIST" << endl;
		cout << "ERROR SENT TO LOG.TXT" << endl;
		ofs << "Error: User deleted number does not exist in the list." << endl;
	}
}
//Description: De-allocates memory saved for the linked list
//Pre-condition: List in put
//Post-condition: Deletes list
void deleteList(list list)
{
	list.allCurr = list.allHead;
	while(list.allCurr != NULL)
	{
		list.allCurr = list.allHead -> next;
		delete list.allHead;
		list.allHead = list.allCurr;
	}
}
