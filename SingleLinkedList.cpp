//Program Name: Linked list for sorting and counting strings
//Programmer Name: Ian Simon
//Description:Program takes two strings, sorts, then inputs into linked list for how many times the letter occurred
#include <iostream>
#include <string>

using namespace std;

struct data
{//stores the data needed to perform the task
	int occ;
	char let;
};

typedef struct node
{//holds the struct so the nodes can use the struct itself
	struct data letterO;
	node *next;
} nodes ;

typedef struct words
{//holds the pointers for the linked list
	node *head;
	node *current;
} word ;
//function prototypes
word operator+(word list1, word list2);
word fromString(string word);
void printList(word l);
void deleteList(word l);


int main()
{
	word list1;
	word list2;
	word list3;
	//defines the variables needed, top: linked lists, bottom: strings
	string entry1, entry2;
	
	cout << "Enter the first word: ";
	getline(cin, entry1);
	list1 = fromString(entry1);
	cout << "Enter the second word: ";
	getline(cin, entry2);
	list2 = fromString(entry2);//user inputs the strings here
	cout << "Letter list from word one: ";
	printList(list1);
	cout << "Letter list from word two: ";
	printList(list2);//letter list from both word print fine here
	list3 = list1 + list2;//new string inside the operator won't take all the letters from the lists
	cout << "Letter list from both words: ";
	printList(list3);//will print what is input to list3, but not all is inputted
	deleteList(list1);
	deleteList(list2);
	deleteList(list3);//deletes the memory allocated for the lists
	return 0;
}
//Description: Function will sort a string and input into the linked list
//Pre-condition: User string is input
//Post-condition: Returns linked list with occurences and letters
word fromString(string w)
{
	word word;
	nodes nodes;
	nodes.next = NULL;
	int length;
	string wordArray = w;//string is input to the word array
	for(int i = 0; i < wordArray.size(); ++i)
	{
		for(int j = 0; j < wordArray.size(); j++)
		{
			if(wordArray[i] < wordArray[j])//condition if the letter comes before the letter before it in the array, will sort the letter alphabetically
			{
				char temp = wordArray[j];
				wordArray[j] = wordArray[i];
				wordArray[i] = temp;
			}

		}
	
	}
	word.head = new node;
	word.current = word.head;
	word.current -> letterO.let = wordArray[0];
	word.current -> letterO.occ = 1;//initializes the linked list to hold the first letter and occurences once
	for(int h = 1; h < wordArray.size(); h++)
	{
		if(word.current -> letterO.let == wordArray[h])
		{
			word.current -> letterO.occ++;//adds to occurences once if the letter equals a letter before it
		}
		else
		{
			word.current -> next = new node;//create a new node after the current one
			word.current = word.current -> next;
			word.current -> letterO.let = wordArray[h];
			word.current -> letterO.occ = 1;//sets occ to one since the letter occured for the first time
			
		}
	}
	word.current -> next = NULL;//sets the last link to null
	return word;
}
//Description: Print out the letters and number of times they occur
//Pre-condition: Inputs the list
//Post-condition: Will print out the letters and occurences
void printList(word word)
{
	 word.current = word.head;
	 while(word.current != NULL)
	 {
		cout << word.current -> letterO.let << ": ";
		cout << word.current -> letterO.occ << ", ";
		word.current = word.current -> next;//outputs the letter and how many times it occurs
	}
	cout << endl;
}
void deleteList(word l)
{
	while(l.current != NULL)
	{
		l.current = l.head -> next;
		delete l.head;//deletes the list that has allocated memory
		l.head = l.current;
	}
}
//Description: Overloads the "+" operator for adding two linked lists
//Pre-condition: Both lists must be inputted into the function
//Post-condition: Returns the list made by running the letters from both lists
//into a new string which is sorted by the fromString function
word operator+(word list1, word list2)
{
	string word3, word4, wordTemp;
	int i = 0, j = 0;
	list1.current = list1.head;
	list2.current = list2.head;
	while(list1.current != NULL)
	{
		for(i; i < list1.current -> letterO.occ; ++i)
		{
			word3 += list1.current -> letterO.let;//supposed to add the letters in current however many times they occur
		}
		list1.current = list1.current -> next;//move to the next link
	}
	//FIX: individual letters will not input into the string?
	//Could not fix, not idea what's wrong
	while(list2.current != NULL)
	{
		for(j; j < list2.current -> letterO.occ; ++j)
		{
			word4 += list2.current -> letterO.let;
		}
		list2.current = list2.current -> next;
	}
	wordTemp = word4 + word3;//add the seperate strings to one string
	return fromString(wordTemp);//will sort the string and return a list
}

