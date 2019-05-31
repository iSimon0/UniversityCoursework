#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>

#define SIZE 40

using namespace std;

int setIntArray(char);
void addition(int[], int[], int[]);
bool subtraction(int[], int[], int[]);
void convertToHexArray(int[], char[]);
void multiplication(int[], int[], int[]);
int division(int[], int[], int[]);
void power(int[], int[], int[]);
int findTotalInt(int[]);
bool termZero(int[]);

int main()
{
	ifstream fileName;
	ofstream ofs;
	string n;
	string sum;
	int length1;
	int length2;
	int rem;
	char ops;
	char op1CharArray[40];
	char op2CharArray[40];
	char finalCharArray[40];
	int op1IntArray[40];
	int op2IntArray[40];
	int finalIntArray[40];
	for(int i = 0; i < 40; i++)
	{
		op1CharArray[i] = '0';
		op2CharArray[i] = '0';
		finalCharArray[i] = '0';
		op1IntArray[i] = 0;
		op2IntArray[i] = 0;
		finalIntArray[i] = 0;
	}

	fileName.open("TestData.txt");
	ofs.open("Output.txt");

	while(getline(fileName, n))
	{
		for(int i = 0; i < 40; i++)
		{
			op1CharArray[i] = '0';
			op2CharArray[i] = '0';
			finalCharArray[i] = '0';
			op1IntArray[i] = 0;
			op2IntArray[i] = 0;
			finalIntArray[i] = 0;
		}
		char fullString[n.length()];
		strcpy(fullString, n.c_str());
		for(int i = 0; i < n.length(); i++)
		{
			if(fullString[i] == '+' || fullString[i] == '-' || fullString[i] == '*' || fullString[i] == '/' || fullString[i] == '$')
			{
				ops = fullString[i];
				int lengthOfOp1 = i;
				int h = 0;
				for(int j = 40 - i; j < 40; j++)
				{
					op1CharArray[j] = fullString[h];
					h++;
				}
				for(int f = 0; f < 40; f++)
				{
					if(op1CharArray[f] != '0')
					{
						for(int y = f; y < 40; y++)
						{
							cout << op1CharArray[y];
							ofs << op1CharArray[y];
						}
						break;
					}
				}
				int lengthOfOp2 = n.length() - i - 1;
				i += 1;
				cout << " " << ops << " ";
				ofs << " " << ops << " ";
				for(int k = 40 - lengthOfOp2; k < 40; k++)
				{
					op2CharArray[k] = fullString[i];
					i++;
				}
				for(int f = 0; f < 40; f++)
				{
					if(op2CharArray[f] != '0')
					{
						for(int y = f; y < 40; y++)
						{
							cout << op2CharArray[y];
							ofs << op2CharArray[y];
						}
						break;
					}
				}
				cout << " = ";
				ofs << " = ";
				length1 = lengthOfOp1;
				length2 = lengthOfOp2;
				for(int c = 40 - length1; c < 40; c++)
				{
					op1IntArray[c] = setIntArray(op1CharArray[c]);
					//cout << op1IntArray[c] << " ";
				}
				cout << endl;
				for(int f = 40 - length2; f < 40; f++)
				{
					op2IntArray[f] = setIntArray(op2CharArray[f]);
					//cout << op2IntArray[f] << " ";
				}
				cout << endl;
				if(ops == '+')
				{
					addition(op1IntArray, op2IntArray, finalIntArray);
					convertToHexArray(finalIntArray, finalCharArray);
					cout << endl;
					for(int f = 0; f < 40; f++)
					{
						if(finalCharArray[f] != '0')
						{
							for(int y = f; y < 40; y++)
							{
								cout << finalCharArray[y];
								ofs << finalCharArray[y];
							}
							break;
						}
					}
				}
				else if(ops == '-')
				{
					subtraction(op1IntArray, op2IntArray, finalIntArray);
					convertToHexArray(finalIntArray, finalCharArray);
					cout << endl;
					for(int f = 0; f < 40; f++)
					{
						if(finalCharArray[f] != '0')
						{
							for(int y = f; y < 40; y++)
							{
								cout << finalCharArray[y];
								ofs << finalCharArray[y];
							}
							break;
						}
					}
				}
				else if(ops == '*')
				{
					multiplication(op1IntArray, op2IntArray, finalIntArray);
					convertToHexArray(finalIntArray, finalCharArray);
					cout << endl;
					for(int f = 0; f < 40; f++)
					{
						if(finalCharArray[f] != '0')
						{
							for(int y = f; y < 40; y++)
							{
								cout << finalCharArray[y];
								ofs << finalCharArray[y];
							}
							break;
						}
					}
				}
				else if(ops == '/')
				{
					rem = division(op1IntArray, op2IntArray, finalIntArray);
					convertToHexArray(finalIntArray, finalCharArray);
					cout << endl;
					for(int f = 0; f < 40; f++)
					{
						if(finalCharArray[f] != '0')
						{
							for(int y = f; y < 40; y++)
							{
								cout << finalCharArray[y];
								ofs << finalCharArray[y];
							}
							cout << " Remainder = " << rem;
							ofs << " Remainder = " << rem;
							break;
						}
					}
				}
				else if(ops == '$')
				{
					power(op1IntArray, op2IntArray, finalIntArray);
					convertToHexArray(finalIntArray, finalCharArray);
					cout << endl;
					for(int f = 0; f < 40; f++)
					{
						if(finalCharArray[f] != '0')
						{
							for(int y = f; y < 40; y++)
							{
								cout << finalCharArray[y];
								ofs << finalCharArray[y];
							}
							break;
						}
					}
				}
			}
		}
		cout << endl;
		ofs << endl;
	}
	return 0;
}

bool termZero(int op[])
{
	bool zeroMark = true;
	for (int i = 39; i >= 0; i--)
	{
		if (op[i] != 0)
		{
			zeroMark = false;
			break;
		}
	}
	return zeroMark;
}

void addition(int op1[], int op2[], int finalArray[])
{
	int carryTerm = 0;
	int temp;
	for(int i = 39; i >= 0; i--)
	{
		temp = op1[i] + op2[i] + carryTerm;
		carryTerm = 0;
		if(temp >= 16)
		{
			finalArray[i] = temp - 16;
			carryTerm = 1;
		}
		else
		{
			finalArray[i] = temp;
		}
	}
}

bool subtraction(int op1[], int op2[], int finalArray[])
{
	int borrowTerm = 0;
	int temp;
	bool isNeg;
	for(int i = 39; i >= 0; i--)
	{
		temp = op1[i] - op2[i] - borrowTerm;
		borrowTerm = 0;
		if(op1[i] >= op2[i])
		{
			finalArray[i] = temp;
		}
		else if(op1[i] < op2[i])
		{
			finalArray[i] = temp + 16;
			borrowTerm = 1;
		}
	}
	isNeg = (borrowTerm) ? true : false;
	return isNeg;
}

void multiplication(int op1[], int op2[], int finalArray[])
{
	bool zeroMark = termZero(op2);
	int counterDec[40], counter[40];
	for (int i = 39; i >= 0; i--)
	{
		counterDec[i] = 0;
		counter[i] = op2[i];
	}
	counterDec[39] = 1;
	while(!zeroMark)
	{
		subtraction(counter, counterDec, counter);
		addition(op1, finalArray, finalArray);
		zeroMark = termZero(counter);
	}
}

int division(int op1[], int op2[], int finalArray[])
{
	int opp1 = 0, opp2 = 0, fOp = 0, rem = 0;
	int arr1[40], arr2[40];
	for(int i = 0; i < 40; i++)
	{
		arr1[i] = 0;
		arr2[i] = 0;
	}
	cout << endl;
	opp1 = findTotalInt(op1);
	opp2 = findTotalInt(op2);
	fOp = opp1 / opp2;
	arr1[39] = fOp;
	addition(arr1, arr2, arr1);
	for(int y = 0; y < 40; y++)
	{
		finalArray[y] = arr1[y];
	}
	rem = opp1 - (fOp * opp2);
	return rem;
}

void power(int op1[], int op2[], int finalArray[])
{
	bool zeroMark = termZero(op2);
	int value[40], temp[40];
	for (int i = 39; i >= 0; i--)
	{
		value[i] = 0;
		temp[i] = 0;
	}
	value[39] = 1;
	temp[39] = 1;
	while(!zeroMark)
	{
		subtraction(op2, value, op2);
		multiplication(finalArray, op1, temp);
		for(int i = 0; i < 40; i++)
		{
			finalArray[i] = temp[i];
			temp[i] = 0;
		}
		zeroMark = termZero(op2);
	}
}

void convertToHexArray(int op[], char finalCharArray[])
{
	for(int i = 0; i < 40; i++)
	{
		switch(op[i])
		{
			case 0:
				finalCharArray[i] = '0';
				break;
			case 1:
				finalCharArray[i] = '1';
				break;
			case 2:
				finalCharArray[i] = '2';
				break;
			case 3:
				finalCharArray[i] = '3';
				break;
			case 4:
				finalCharArray[i] = '4';
				break;
			case 5:
				finalCharArray[i] = '5';
				break;
			case 6:
				finalCharArray[i] = '6';
				break;
			case 7:
				finalCharArray[i] = '7';
				break;
			case 8:
				finalCharArray[i] = '8';
				break;
			case 9:
				finalCharArray[i] = '9';
				break;
			case 10:
				finalCharArray[i] = 'A';
				break;
			case 11:
				finalCharArray[i] = 'B';
				break;
			case 12:
				finalCharArray[i] = 'C';
				break;
			case 13:
				finalCharArray[i] = 'D';
				break;
			case 14:
				finalCharArray[i] = 'E';
				break;
			case 15:
				finalCharArray[i] = 'F';
				break;
		}
	}
}

int setIntArray(char op)
{
		switch(op)
		{
			case '0':
				return 0;
			case '1':
				return 1;
			case '2':
				return 2;
			case '3':
				return 3;
			case '4':
				return 4;
			case '5':
				return 5;
			case '6':
				return 6;
			case '7':
				return 7;
			case '8':
				return 8;
			case '9':
				return 9;
			case 'A':
				return 10;
			case 'B':
				return 11;
			case 'C':
				return 12;
			case 'D':
				return 13;
			case 'E':
				return 14;
			case 'F':
				return 15;
			};
}

int findTotalInt(int op[])
{
	int totalHexSum = 0;;
	int h = 39;
	for(int i = 0; i < 40; i++)
	{
		totalHexSum += op[i]*(pow(16, h));
		h--;
	}
	return totalHexSum;
}
