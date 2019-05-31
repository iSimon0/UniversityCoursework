/*
	Ian Simon
	CIS 350
	Description: This program will control each hire and fire by the president and keep track of the hierarchy or seniority in the white house.
	*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*struct Node {
	vector<Node*> children;
	Node *parent;
	string name;
	int rank;
};*/
		
class Org {
	public:
		vector<Org*> children;
		//Org *parent = nullptr;
		string name;
		int rank;
		string readAction(string input) {
			string h = "hires";
			string f = "Fire";
			string p = "Print";
			string q = "Quit";
			size_t hireFound = input.find(h);
			size_t fireFound = input.find(f);
			size_t printFound = input.find(p);
			size_t quitFound = input.find(q);
			if(hireFound != std::string::npos) {
				return h;
			}
			if(fireFound != std::string::npos) {
				return f;
			}
			if(printFound != std::string::npos) {
				return p;
			}
			if(quitFound != std::string::npos) {
				return q;
			}
		}
		string FindBoss(string input) {
			string boss;
			for(int i = 0; i < input.size(); i++) {
				if(input[i] != ' ') {
					boss += input[i];
				}
				else {
					break;
				}
			}
			return boss;
		}
		string FindSubToHire(string input) {
			string sub;
			int temp = 0;
			for(int i = 0; i < input.size(); i++) {
				if(input[i] == ' ') {
					temp++;
				}
				if(temp == 2) {
					sub += input[i+1];
				}
			}
			return sub;
		}
		string FindSubToFire(string input) {
			string sub;
			int temp = 0;
			for(int i = 0; i < input.size(); i++) {
				if(input[i] == ' ') {
					temp++;
				}
				if(temp == 1) {
					sub += input[i+1];
				}
			}
			return sub;
		}
		Org* find(string emp, Org* ptr) {
			if(ptr == nullptr) {
				return nullptr;
			}
			else if(ptr -> name == emp) {
				return ptr;
			}
			else if(find(emp, ptr -> children[rank]) != nullptr) {
				for(int i = 0; i < ptr -> children.size(); i++) {
					if(ptr -> children[i] -> name == emp) {
						return ptr;
					}
				}
				return find(emp, ptr -> children[rank]);
			}
			else {
				return nullptr;
			}
		}
		void print() {
			for(int i = 0; i < rank; i++) {
				cout << "+";
			}
			cout << name << endl;
		}
		void hire(string boss, string sub);
		void fire(string sub);
	};

int main() {
	string input = " ";
	string boss, sub;
	Org first;
	Org org;
	Org* top = new Org();
	
	bool isFirstAppt = true;
	int rank = 0;
	
	while(1) {
		Org* temp = new Org();
		Org* s = new Org();
		getline(cin, input);
		if(isFirstAppt) {
			boss = first.FindBoss(input);
			sub = first.FindSubToHire(input);
			top -> name = boss;
			top -> rank = rank;
			s -> name = sub;
			s -> rank = top -> rank + 1;
			top -> children.push_back(s);
			isFirstAppt = false;
		}
		else if(org.readAction(input) == "hires") {
			boss = org.FindBoss(input);
			sub = org.FindSubToHire(input);
			temp = top -> find(boss, top);
			s -> name = sub;
			s -> rank = temp -> rank + 1;
			temp -> children.push_back(s);
		}
		else if(org.readAction(input) == "Fire") {
			sub = org.FindSubToFire(input);
		}
		else if(org.readAction(input) == "Print") {
			top -> print();
			for(int i = 0; i < top -> children.size(); i++) {
				top -> children[i] -> print();
			}
		}
		else if(org.readAction(input) == "Quit") {
			break;
		}

	}
	
	return 0;
}

/*
Trump hires Sessions
Trump hires Devos
Print
*/
