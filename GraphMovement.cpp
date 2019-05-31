/*
	Ian Simon
	CIS 350
	Description: Creates a cave input system from user input. Edward and Jacob are trying to find Bella in a certain cave and will move 
	counter-clockwise and clockwise respectively. Once one of them find her in a cave, the program ends and Bella marries whoever saved her.
	If neither of them reach her after 100 turns, the program will end and they all die.
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void createMatrix(vector<vector<int>>&, int);//O(n^2)
void matrixInput(vector<vector<int>>&, vector<int>&, int);//O(n^2)
int movement(vector<vector<int>>&, vector<int>&, int, int, int&, int&);//O(n^2)
/*Pre-Conditions: Nothing is set except function prototypes
Post-Conditions: Matrix and item vector is made and filled. Caves are set for ed, bella and jacob. 
Then the movement is made and the output is sent according to what happened in the movement function.
*/
int main() {
	int bellaCave = 1, edCave = 1, jacobCave = 1, numCaves = 1, numTurns;
	bool endProgram = false;
	while (!endProgram) {//O(n)
		cin >> numCaves >> bellaCave >> jacobCave >> edCave; //takes the first line of input
		if (numCaves != 0 && bellaCave != 0 && jacobCave != 0 && edCave != 0) {
			vector<vector<int>> caveMatrix(numCaves);
			vector<int> itemsInCave(numCaves);
			for (int i = 0; i < numCaves; i++) {//O(n)
				itemsInCave[i] = 0;
			}
			createMatrix(caveMatrix, numCaves);//makes the initial matrix of caves
			matrixInput(caveMatrix, itemsInCave, numCaves);//creates the cave system based on user input
			numTurns = movement(caveMatrix, itemsInCave, numCaves, bellaCave, jacobCave, edCave);//numTurns is the number of turns it took
			//conditional statements for the output after movement has completed
			if (edCave == bellaCave && jacobCave == bellaCave) {
				cout << "Everyone dies in " << numTurns << " moves" << endl;
			}
			else if (edCave == bellaCave) {
				cout << "Bella marries Edward in " << numTurns << " moves" << endl;
			}
			else if (jacobCave == bellaCave) {
				cout << "Bella marries Jacob in " << numTurns << " moves" << endl;
			}
			else {
				cout << "Everyone dies in 101 moves" << endl;
			}
			caveMatrix.clear();//clear the matrix and item vector for next vector
			itemsInCave.clear();
		}
		else {
			endProgram = true;
		}
	}
	system("pause");
	return 0;
}
/*Pre-Conditions: The matrix has been started but only half
Post-Conditions: The entire matrix is created but filled with zeroes to simplify the process
*/
void createMatrix(vector<vector<int>>& caveMatrix, int numCaves) {
	for (int i = 0; i < numCaves; i++) {//O(n)
		caveMatrix[i].resize(numCaves);//change the size of the matrix to whatever the input is
		for (int j = 0; j < numCaves; j++) {//O(n)
			caveMatrix[i][j] = 0; //fill the empty matrix with zeroes
		}//O(n^2)
	}
}
/*Pre-Conditions: Matrix is created with all zeroes and the items vector is made here
Post-Conditions: Both the cave system and the items vector are created and filled here, items vector has 1's and -1's according to the input
and the matrix is filled by the input 
*/
void matrixInput(vector<vector<int>>& caveMatrix, vector<int>& itemsInCave, int numCaves) {
	int badItem, numAdj, adjCave;
	for (int i = 0; i < numCaves; i++) {
		cin >> badItem >> numAdj;
		itemsInCave[i] = badItem;//inserts a -1 for garlic and 1 for wolf's bane
		for (int j = 0; j < numAdj; j++) {
			cin >> adjCave;//makes the cave matrix for the user input
			caveMatrix[adjCave - 1][i] = 1;
			caveMatrix[i][adjCave - 1] = 1;
		}//O(n^2)
	}
}
/*Pre-Conditions: The matrix, item vector, number of caves, caves bella, edward, and jacob are set also
Post-Conditions: Edward is moved to the lowest adjacent possible and jacob is moved to highest adjacent cave possible on first move.
Then Edward moves to the highest adjacent cave that he hadn't travelled to prior and jacob the same way but lowest cave. This continues
until either one of them finds bella, both find bella, or 100 turns have passed.
*/
int movement(vector<vector<int>>& caveMatrix, vector<int>& itemsInCave, int numCaves, int bellaCave, int& jacobCave, int& edCave) {
	bool endLoop = false;
	int numTurns = 0, edHighAdjCave = 0, jacLowAdjCave = 0, edLowAdjCave = 0, jacHighAdjCave = 0, edPast = 0, jacPast = 0, beenHereCount = 0;
	set<int> edPastCaves, jacPastCaves;
	vector<int> availableCaves, newCaves;
	//cout << "ED: " << edCave << endl;
	for (int i = 0; i < numCaves; i++) {//O(n)
		if (caveMatrix[i][edCave - 1] == 1 && itemsInCave[i] != 1) {
			edHighAdjCave = i + 1;//if the cave allows ed to move to it as the highest cave available, he will move on first turn
		}
	}
	edPast = edCave;
	edCave = edHighAdjCave;
	for (int i = numCaves - 1; i >= 0; i--) {//O(n)
		if (caveMatrix[i][jacobCave - 1] == 1 && itemsInCave[i] != 1) {
			jacLowAdjCave = i + 1;//if the cave allows jacob to move to it as the lowest cave available, he will move on first turn
		}
	}
	jacPast = jacobCave;
	jacobCave = jacLowAdjCave;
	edPastCaves.insert(edPast);//pass the past caves into a set to keep track of new caves
	jacPastCaves.insert(jacPast);
	//cout << "Ed: " << edCave << endl;
	while (!endLoop) {//O(n)
		numTurns++;
		if (edCave == bellaCave || jacobCave == bellaCave) {
			endLoop = true;//if either of them reach the cave, program ends
		}
		else if(numTurns > 100) {
			endLoop = true;//if the program is on it's 101st pass, the program ends
		}
		else {
			edPastCaves.insert(edPast);
			jacPastCaves.insert(jacPast);
			for (int i = numCaves - 1; i >= 0; i--) {//O(n)
				if (caveMatrix[i][edCave - 1] == 1 && itemsInCave[i] != -1) {
					availableCaves.push_back(i + 1);//makes a vector of available caves
					edLowAdjCave = i + 1;//lowest adjacent cave available in case all other caves visited
				}
			}
			//for (int i = 0; i < availableCaves.size(); i++) {
			//	cout << availableCaves[i] << " ";
			//}//DELETE THIS NEPHEW
			//cout << endl;
			for (int i = 0; i < availableCaves.size(); i++) {//O(n)
				for (auto x : edPastCaves) {//checks the past caves and counts how many have been visited out of the available caves vector
					if (availableCaves[i] == x) {//O(n)
						beenHereCount++;
						break;
					}//O(n^2)
				}
			}
			/*cout << "been here count: " << beenHereCount << endl;
			cout << "availableCaves size " << availableCaves.size() << endl;*/
			if (beenHereCount == availableCaves.size()) {//if have visited all caves
				if (availableCaves[0] == edPast) {//if the lowest cave available is the last cave visited
					for (int i = 1; i < availableCaves.size(); i++) {//O(n)
						if (availableCaves[i] != edPast) {//find the lowest cave available that isnt the last cave visited
							edPast = edCave;
							edCave = availableCaves[i];
							break;
						}
					}
				}
				else {
					edPast = edCave;//just pick the first cave LOL
					edCave = availableCaves[0];
				}
			}
			else if (beenHereCount > 0) {//otherwise if it's more than 0
				for (auto x : edPastCaves) {
					for (int i = 0; i < availableCaves.size(); i++) {
						if (x == availableCaves[i]) {//erase all caves that have already been visited
							availableCaves.erase(availableCaves.begin() + i);
							break;
						}//O(n^2)
					}
				}
				if (availableCaves[0] == edPast) {//same thing as the last time
					for (int i = 1; i < availableCaves.size(); i++) {
						if (availableCaves[i] != edPast) {
							edPast = edCave;
							edCave = availableCaves[i];
							break;
						}
					}
				}
				else {
					edPast = edCave;
					edCave = availableCaves[0];
				}
			}
			else {//otherwise just pick the lowest adjacent cave
				edPast = edCave;
				edCave = edLowAdjCave;
			}
			//cout << "Ed: " << edCave << endl;
			beenHereCount = 0;
			availableCaves.clear();
			for (int i = numCaves - 1; i >= 0; i--) {//this is the same thing as the top just with jacob's conditions
				if (caveMatrix[i][jacobCave - 1] == 1 && itemsInCave[i] != 1) {
					availableCaves.push_back(i + 1);
					jacHighAdjCave = i + 1;
				}
			}
			for (int i = 0; i < availableCaves.size(); i++) {
				for (auto x : jacPastCaves) {
					if (availableCaves[i] == x) {
						beenHereCount++;
						break;
					}
				}
			}
			if (beenHereCount == availableCaves.size()) {
				if (availableCaves[0] == jacPast) {
					for (int i = 1; i < availableCaves.size(); i++) {
						if (availableCaves[i] != jacPast) {
							jacPast = jacobCave;
							jacobCave = availableCaves[i];
							break;
						}
					}
				}
				else {
					jacPast = jacobCave;
					jacobCave = availableCaves[0];
				}
			}
			else if (beenHereCount > 0) {
				for (auto x : jacPastCaves) {
					for (int i = 0; i < availableCaves.size(); i++) {
						if (x == availableCaves[i]) {
							availableCaves.erase(availableCaves.begin() + i);
							break;
						}
					}
				}
				if (availableCaves[0] == jacPast) {
					for (int i = 1; i < availableCaves.size(); i++) {
						if (availableCaves[i] != jacPast) {
							jacPast = jacobCave;
							jacobCave = availableCaves[i];
							break;
						}
					}
				}
				else {
					jacPast = jacobCave;
					jacobCave = availableCaves[0];
				}
			}
			else {
				jacPast = jacobCave;
				jacobCave = jacHighAdjCave;
			}
			beenHereCount = 0;
			availableCaves.clear();
		}
	}
	return numTurns;
}