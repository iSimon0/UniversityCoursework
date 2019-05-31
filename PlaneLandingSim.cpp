/*
	Ian Simon
	CIS 350
	Description: Land planes using the largest delta T between the landings as possible without missing the intervals given.
	The inputs are the number of test cases, the number of planes you want to land, and the intervals of when the plane can land.
	Program searches for the best time inbetween each landing to give a legal working time to land each plane.
	Note to Elenbogen: THIS PROGRAM WORKS THE EXACT SAME AS WHEN YOU SENT IT TO ME. NOTHING SIGNIFICANT WAS CHANGED
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct interval {
	double start;
	double end;
	int planeNum;
	double landingTime;
	bool operator<(const interval &a) const {
		return planeNum < a.planeNum;
	}
};//holds the data set for the intervals at which the planes can land

double findDeltaT(vector<interval>);
void outputFinalData(vector<interval>, double);
void createPlaneVector(vector<double>, vector<interval>&);
void inputPlaneIntervals(vector<double>&);

int main() {
	vector<interval> planes, bestOrder;
	vector<double> tempVec;
	
	double numCases, deltaT, bestDT = 0, temp = 0;
	bool setPrecisionFlag = false, safeLanding = false, lastState = false, tooBig, tooSmall, firstDT;
	
	//input the number of test cases
	cin >> numCases;
	for (int i = 0; i < numCases; i++) {//O(n)
		//input the number of planes landing in the test case
		planes.clear();
		tempVec.clear();
		bestOrder.clear();
		inputPlaneIntervals(tempVec);
		createPlaneVector(tempVec, planes);
		firstDT = true;
		bestDT = 0;
		do {//start with first permutation 1, 2, ... , n//O(n)
			safeLanding = true;
			planes[0].landingTime = planes[0].start;
			deltaT = findDeltaT(planes);
			temp = 0;
			setPrecisionFlag = false;
			do {//until setPrecisionFlag is true//O(n)
				tooBig = false;
				tooSmall = false;
				for (int i = 1; i < planes.size() && safeLanding; i++) {//O(n)
	 				planes[i].landingTime = std::max(planes[i - 1].landingTime + deltaT, planes[i].start);
					if (planes[i].landingTime - planes[i].end > .00001) {
						safeLanding = false;
						tooBig = true;
					}
					if (tooBig) {
						deltaT -= 0.01;
					}
					else if (tooSmall || safeLanding) {
						deltaT += 0.01;
					}
				}
				if (!firstDT) {
					if (tooBig == lastState) {
						setPrecisionFlag = false;
					}
					else {
						lastState = tooBig;
						setPrecisionFlag = true;
					}
				}
				firstDT = false;
			} while (!setPrecisionFlag);
			if (deltaT > bestDT) {//if there is a delta T better than the best one so far it will replace the delta T and order with that
				bestDT = deltaT;
				bestOrder = planes;
			}
		} while (std::next_permutation(planes.begin(), planes.end()));

		outputFinalData(bestOrder, bestDT);
	}
	return 0;
}
/*Pre-Conditions: tempVec is empty but created
Post-Conditions: tempVec is filled with the string of integers
*/
void inputPlaneIntervals(vector<double> &tempVec) {
	string inputIntervals;
	double tempInt, numPlanes;
	cin >> numPlanes;
	cin.ignore();
	//input the intervals at which the planes can land
	std::getline(cin, inputIntervals);
	istringstream ss(inputIntervals);//convert the string to a vector of integers to be held
	while (ss >> tempInt) {
		tempVec.push_back(tempInt);
	}
}
/*Pre-Conditions: planes is a vector that is already created
Post-Conditions: Returns value of last plane end time minus first plane start time divided by the size of planes - 1 and divided by 2
This should give a number around the middle of where delta T should be
*/
double findDeltaT(vector<interval> planes) {
	return ((planes[planes.size() - 1].end - planes[0].start) / (planes.size()-1)) / 2.00;
}//find delta T
/*Pre-Conditions: bestOrder is created and filled with data, bestDT is a number > deltaT's before it
Post-Conditions: both the order of the planes and the best delta T found are outputted to the screen
*/
void outputFinalData(vector<interval> bestOrder, double bestDT) {
	for (int i = 0; i < bestOrder.size(); i++) {
		cout << bestOrder[i].planeNum << " ";
	}//output the delta T and order of planes
	cout << std::fixed << std::setprecision(2) << bestDT << endl;
}
/*Pre-Conditions: tempVec is filled with the string integers and planes is initialized but empty
Post-Conditions: planes vector is filled with the start and end times of the plane, along with the plane numbers
*/
void createPlaneVector(vector<double> tempVec, vector<interval> &planes) {
	interval intrvl;
	for (int j = 0; j < tempVec.size(); j += 2) {
		intrvl.start = tempVec[j];
		intrvl.end = tempVec[j + 1];
		intrvl.planeNum = j / 2 + 1;
		planes.push_back(intrvl);
		//takes the first int from the intervals at the start of the interval
	}
}
