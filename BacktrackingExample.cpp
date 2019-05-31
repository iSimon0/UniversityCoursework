/*
	Ian Simon
	CIS 350 Program 4
	Description: Takes an input of a 2 dimensional matrix of boxes held in a 2-D vector.
	The program must take as many boxes from the matrix without altering the front or side view
	of the box matrix.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct takeBox {
	int boxes;
	bool canTake;
};

void createBoxMatrix(vector<vector<takeBox>>&, int, int);
void fillBoxMatrixInput(vector<vector<takeBox>>&, int, int);
void fillFrontView(vector<int>&, vector<vector<takeBox>>&, int, int);
void fillSideView(vector<int>&, vector<vector<takeBox>>&, int, int);
bool nextFrontView(vector<int>, vector<int>, vector<vector<takeBox>>, int, int, int);
bool nextSideView(vector<int>, vector<int>, vector<vector<takeBox>>, int, int);
bool checkView(int, int);
bool checkBoxes(vector<vector<takeBox>>&, vector<int>, vector<int>, vector<int>, vector<int>, int, int, int);
int takeBoxes(vector<vector<takeBox>>&, vector<int>, vector<int>, vector<int>, vector<int>, int, int, int);

/*Pre-Conditions: Program starts
Post-Conditions: All the boxes that can be taken without altering a view of the matrix whether its front or back will be taken
*/
int main() {//TIME: O(n^2) SPACE: O(n)
	int r, c, numRows;
	cin >> r >> c;
	numRows = r;
	vector<vector<takeBox>> boxMatrix(c);
	vector<int> frontViewFinal(c);
	vector<int> sideViewFinal(r);
	vector<int> currFrontView(c);
	vector<int> currSideView(r);

	createBoxMatrix(boxMatrix, c, r);
	fillBoxMatrixInput(boxMatrix, c, r);
	fillFrontView(frontViewFinal, boxMatrix, c, r);
	fillSideView(sideViewFinal, boxMatrix, c, r);
	cout << takeBoxes(boxMatrix, currFrontView, currSideView, sideViewFinal, frontViewFinal, c, r, numRows) << endl;
	/*for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << boxMatrix[i][j].boxes << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	system("pause");
	return 0;
}
/*Pre-Conditions: Uninitialized 2-D vector with rows and columns passed through the parameters
Post-Conditions: Creates the matrix and fills the box numbers with zeroes
*/
void createBoxMatrix(vector<vector<takeBox>>& boxMatrix, int c, int r) {//TIME: O(n^2) SPACE: O(n)
	for (int i = 0; i < r; i++) {
		boxMatrix[i].resize(c);
		for (int j = 0; j < c; j++) {
			boxMatrix[i][j].boxes = 0;
		}
	}
}
/*Pre-Conditions: Initialized matrix is passed through the parameters
Post-Conditions: Asks user for the box input for the number of boxes in each row and column
Turns every point with more than one box to their bool variable true, allows program to take from their point
*/
void fillBoxMatrixInput(vector<vector<takeBox>>& boxMatrix, int c, int r) {//TIME: O(n^2) SPACE:O(1)
	int numBoxes;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> numBoxes;
			boxMatrix[i][j].boxes = numBoxes;
			if (numBoxes > 1) {
				boxMatrix[i][j].canTake = true;
			}
			else {
				boxMatrix[i][j].canTake = false;
			}
		}
	}
}
/*Pre-Conditions: Unitialized vector front and the already made boxes 2-D vector
Post-Conditions: Creates a vector with the max number of boxes in each column
*/
void fillFrontView(vector<int>& front, vector<vector<takeBox>>& boxes, int c, int r) {//TIME: O(n^2) SPACE: O(1)
	int max;
	for (int i = 0; i < c; i++) {
		max = 0;
		for (int j = 0; j < r; j++) {
			if (boxes[j][i].boxes > max) {
				max = boxes[j][i].boxes;
			}
		}
		front[i] = max;
	}
}
/*Pre-Conditions: Unitialized vector side and the already made boxes 2-D vector
Post-Conditions: Creates a vector with the max number of boxes in each row
*/
void fillSideView(vector<int>& side, vector<vector<takeBox>>& boxes, int c, int r) {//TIME: O(n^2) SPACE: O(1)
	int max;
	for (int i = 0; i < r; i++) {
		max = 0;
		for (int j = 0; j < c; j++) {
			if (boxes[i][j].boxes > max) {
				max = boxes[i][j].boxes;
			}
		}
		side[i] = max;
	}
}
/*Pre-Conditions: Takes the current view of the boxes and the view that is correct and alters the boxes in the matrix
Post-Conditions: Checks all the rows to see if a box was changed in the front view
*/
bool nextFrontView(vector<int> currView, vector<int> pastView, vector<vector<takeBox>> boxes, int c, int r, int numRows) {//TIME: O(n) SPACE: O(1)
	boxes[r][c].boxes -= 1;
	int max = 0, index;
	for (int i = 0; i < numRows; i++) {
		if (boxes[i][c].boxes > max) {
			max = boxes[i][c].boxes;
			index = i;
		}
	}
	return checkView(pastView[c], max);
}
/*Pre-Conditions: Takes the current view of the boxes and the view that is correct and alters the boxes in the matrix
Post-Conditions: Checks all the rows to see if a box was changed in the side view
*/
bool nextSideView(vector<int> currView, vector<int> pastView, vector<vector<takeBox>> boxes, int c, int r) {//TIME: O(n) SPACE: O(1)
	boxes[r][c].boxes -= 1;
	int max = 0, index;
	for (int i = 0; i < boxes[r].size(); i++) {
		if (boxes[r][i].boxes > max) {
			max = boxes[r][i].boxes;
			index = i;
		}
	}
	return checkView(pastView[r], max);
}
/*Pre-Conditions: Takes the currnt view of the front or side boxes and the beginning views
Post-Conditions: Checks the row or column to see if the number of boxes have changed
*/
bool checkView(int past, int curr) { //TIME: O(1) SPACE: O(1)
	if (past == curr) {
		return true;
	}
	else {
		return false;
	}
}
/*Pre-Conditions: Takes all variables in the program (smart, right?)
Post-Conditions: if the boxes variable can take is false, then returns false
				if the front view and side view are unaltered, returns true
				otherwise, returns false
*/
bool checkBoxes(vector<vector<takeBox>>& boxes, vector<int> currFront, vector<int> currSide, vector<int> finalSide, vector<int> finalFront, int c, int r, int numRows) {
	if (boxes[r][c].canTake == false) {//TIME: O(1) SPACE: O(1)
		return false;
	}
	else if(nextFrontView(currFront, finalFront, boxes, c, r, numRows) && nextSideView(currSide, finalSide, boxes, c, r)) {
		return true;
	}
	else {
		return false;
	}	
}
/*Pre-Conditions: takes all variables to program 
Post-Conditions: if the checkboxes function returns true, then the program will take a box from the matrix
*/
int takeBoxes(vector<vector<takeBox>>& boxes, vector<int> currFront, vector<int> currSide, vector<int> finalSide, vector<int> finalFront, int c, int r, int numRows) {
	int boxesTaken = 0;//TIME: O(n^2) SPACE: O(1)
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (checkBoxes(boxes, currFront, currSide, finalSide, finalFront, j, i, numRows)){
				while (boxes[i][j].boxes > 1) {
					boxes[i][j].boxes -= 1;
					boxesTaken++;
				}
			}
		}
	}
	return boxesTaken;
}
