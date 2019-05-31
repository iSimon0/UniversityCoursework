#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

#define LABEL_INDEX 0
#define OPERATION_INDEX 9
#define OPERAND_INDEX 19
#define COMMENT_INDEX 39
/*#define COLUMN_WIDTH 10
#define OPERAND_WIDTH 20
#define TOTAL_WIDTH 40*/

using namespace std;

string findSymbol(string str)
{
	return str.substr(LABEL_INDEX, LABEL_INDEX+5);
}

string findInstruction(string str)
{
	return str.substr(OPERATION_INDEX, OPERATION_INDEX);
}

int findOpLength(string str)
{
	for(int i = OPERAND_INDEX; i <= str.size() - OPERAND_INDEX; i++)
	{
		if(str.at(i) == ' ')
		{
			return i - OPERAND_INDEX;
		}
	}
}

string findOperand(string str, int length)
{
	return str.substr(OPERAND_INDEX, OPERAND_INDEX);
}

string findLeft(string str)
{
	string op = "";
	for(int i = 0; i < str.size(); i++)
	{
		if(str.at(i) == ',')
		{
			break;
		}
		op += str.at(i);
	}
	return op;
}

string findRight(string str)
{
	string op = "";
	for(int i = 0; i < str.size(); i++)
	{
		if(str.at(i) == ',')
		{
			for(int h = i + 1; h < str.size(); h++)
			{
				op += str.at(h);
			}
		}
	}
	return op;
}

string rightTrim(string str) {
	int spaceIndex = -1;
	for (unsigned int i = 0; i < str.size(); i++) {
		if (str.at(i) == ' ') {
			spaceIndex = i;
			break;
		}
	}
	if (spaceIndex >= 0)
		str = str.substr(0, spaceIndex);
	return str;
}

int main()
{
	ifstream ifs;
	ofstream ofs;
	string InputLine, symbol, instr, leftOp, rightOp, Op;
	vector<string> symbolVec, instrVec, leftVec, rightVec;
	vector<string> finalSymbol, finalInstr, finalAdd, finalOp1, finalOp2;
	vector<int> machineCode, address, finalSymAdd;
	int codeLines = 0;
	int opLength, currentAdd;
	
	ifs.open("InputCode.txt");
	ofs.open("output.txt");
	
	while(getline(ifs, InputLine))
	{
		symbol = findSymbol(InputLine);
		instr = findInstruction(InputLine);
		opLength = findOpLength(InputLine);
		Op = findOperand(InputLine, opLength);
		leftOp = findLeft(Op);
		rightOp = findRight(Op);
		
		symbol = rightTrim(symbol);
		symbolVec.push_back(symbol);
		
		instr = rightTrim(instr);
		instrVec.push_back(instr);
		
		leftOp = rightTrim(leftOp);
		leftVec.push_back(leftOp);
		
		rightOp = rightTrim(rightOp);
		rightVec.push_back(rightOp);
		
		//cout << leftOp << " ";
		
		codeLines += 1;
	}
	cout << endl;
	if(instrVec[0].at(0) == 'O')
	{
		int k;
		leftOp = leftVec[0];
		for(int i = 0; i < leftOp.size(); i++)
		{
			if(leftOp.at(i) != '$' && leftOp.at(i) != '0')
			{
				k = i;
				break;
			}
		}
		leftOp = leftOp.substr(k, 3);
		currentAdd = stoi(leftOp, nullptr, 16);
	}
	
	for(int i = 0; i < codeLines; i++)
	{
		symbol = symbolVec[i];
		address.push_back(currentAdd);
		if(symbol == "LOOP" || symbol == "LOOP2")
		{
			finalSymbol.push_back(symbol);
			finalSymAdd.push_back(currentAdd);
		}
		if(instrVec[i] == "MOVE")
		{
			leftOp = leftVec[i];
			rightOp = rightVec[i];
			if(leftOp.at(0) == '#')
			{
				finalOp1.push_back(leftOp.substr(1, leftOp.size()));
				if(rightOp.at(0) == '$')
				{
					finalOp2.push_back(rightOp.substr(1, rightOp.size()));
					machineCode.push_back(0x33FC);
					currentAdd += 8;
				}
				else
				{
					finalOp2.push_back("0");
					machineCode.push_back(0x303C);
					currentAdd += 4;
				}
			}
			else if(leftOp.at(0) == '$')
			{
				finalOp1.push_back(leftOp.substr(1, leftOp.size()));
				finalOp2.push_back("0");
				machineCode.push_back(0x3039);
				currentAdd += 6;
			}
			else
			{
				finalOp1.push_back(rightOp.substr(1, rightOp.size()));
				finalOp2.push_back("0");
				machineCode.push_back(0x33C0);
				currentAdd += 6;
			}
		}
		else if(instrVec[i] == "TRAP")
		{
			currentAdd += 2;
			leftOp = leftVec[i];
			//cout << "leftOp = " << leftOp << " i = " << i << " ";
			if(leftOp == "#0")
			{
				machineCode.push_back(0x4E40);
			}
			else if(leftOp == "#1")
			{
				machineCode.push_back(0x4E41);
			}
			else if(leftOp == "#2")
			{
				machineCode.push_back(0x4E42);
			}
			else
			{
				machineCode.push_back(0);
			}
		}
		else if(instrVec[i] == "ADD")
		{
			currentAdd += 6;
			leftOp = leftVec[i];
			rightOp = rightVec[i];
			if(leftOp.at(0) == '$')
			{
				finalOp1.push_back(leftOp.substr(1, leftOp.size()));
				finalOp2.push_back("0");
				machineCode.push_back(0xD079);
			}
			else
			{
				finalOp1.push_back(rightOp.substr(1, rightOp.size()));
				finalOp2.push_back("0");
				machineCode.push_back(0xD179);
			}
		}
		else if(instrVec[i] == "ADDI")
		{
			leftOp = leftVec[i];
			rightOp = rightVec[i];
			finalOp1.push_back(leftOp.substr(1, leftOp.size()));
			if(leftOp.at(0) == '$')
			{
				finalOp2.push_back(rightOp.substr(1, rightOp.size()));
				machineCode.push_back(0x0679);
				currentAdd += 8;
			}
			else
			{
				finalOp2.push_back("0");
				machineCode.push_back(0x0640);
				currentAdd += 4;
			}
		}
		else if(instrVec[i] == "END")
		{
			finalOp1.push_back("0");
			finalOp2.push_back("0");
			machineCode.push_back(0);
		}
	}
	ofs << "ADDRESS" << "       " << "MACHINE CODE" << "        " << "OPERANDS" << "        " << "INSTRUCTION" << endl;
	ofs << "_______" << "       " << "____________" << "        " << "________" << "        " << "____________" << endl;
	for(int i = 0; i < codeLines; i++)
	{
		//cout << hex << machineCode[i] << " ";
		if (machineCode[i] == 0x303C || machineCode[i] == 0x0640 || machineCode[i] == 0x0440)
		{
			ofs << hex << uppercase << "00000" << address[i] << "       	0" << machineCode[i] << "        ";
			ofs << setw(4) << finalOp1[i] << "        	" <<  instrVec[i] << "		" << leftVec[i] << "," << rightVec[i] << endl;
		}
		else if (machineCode[i] == 0x33FC || machineCode[i] == 0x0679 || machineCode[i] == 0x0479)
		{
			ofs << hex << uppercase << "00000" << address[i] << "       	" << machineCode[i] << "         ";
			ofs << finalOp1[i] << "," << finalOp2[i] << "        " << instrVec[i] << "		" << leftVec[i] << "," << rightVec[i] << endl;
		}

		else if (machineCode[i] == 0x4E40 || machineCode[i] == 0x4E41 || machineCode[i] == 0x4E42)
		{
			ofs << hex << uppercase << "00000" << address[i] << "       	" << machineCode[i] << "         ------------        ";
			ofs << instrVec[i] << "		" <<  leftVec[i] << "," << rightVec[i] << endl;
		}

		else if (machineCode[i] != 0)
		{
			ofs << hex << uppercase << "00000" << address[i] << "       	" << machineCode[i] << "         ";
			ofs << setw(8) << finalOp1[i] << "            " << instrVec[i] << "		" << leftVec[i] << "," << rightVec[i] << endl;
		}
	}
	ofs << endl << "SYMBOL TABLE" << endl;
	ofs << "NAME    |   ADDRESS" << endl;
	ofs << "________|__________" << endl;
	for(int i = 0; i < finalSymbol.size(); i++)
	{
		ofs << finalSymbol[i] << "	00000" << finalSymAdd[i] << endl;
	}
}
