//Program Name: Assignment #4, array of pointers to use populate with bank accounts
//Programmer Name: Ian Simon
//Description: ALlows user to add and remove accounts, change the balance, compute interest on said account
//Date Created: 11/25-11/28
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class account
{
	private:
		int acctNum;
		double balance;
	public:
		account()
		{//initial constructor
			acctNum = 0;
			balance = 1000 + 10*acctNum;
		}
		int getAcct()
		{
			return acctNum;
		}
		double getBalance()
		{
			return balance;
		}
		//Description: Sets the account number
		//Pre-condition: if the account number is not less than 0
		//Post-condition: Sets the account number
		void setAcct(int acct)
		{
			try
			{
				if(acct < 0)
				{
					throw acct;
				}
				else
				{
					acctNum = acct;
				}
			}
			catch(int acct)
			{//if the account number is less than zero
				cout << "Exception Caught." << acct << " is an invalid account number." << endl;
				cout << "Re-enter the new account number ";
				cin >> acct;
				setAcct(acct);
			}
		}
//Description: Sets the balance of the account
//Pre-condition: Balance of user input
//Post-condition: Sets the balance
		void setBalance(double bal)
		{
			try
			{
				if(bal < 0)
				{
					throw bal;
				}
				else
				{
					balance = bal;
				}
			}
			catch(double bal)
			{//if the balance is negative
				cout << "Exception Caught." << bal << " is an invalid balance." << endl;
				cout << "Re-enter the balance here: ";
				cin >> bal;
				setBalance(bal);
			}
		}
		void toString()
		{//outputs the account info
			cout << "Account #" << acctNum << ", Balance: $" << balance << endl;
		}
		double computeIntr(int years);
		~account()
		{
		}
	};
	
class checking: public account
{
	private:
		int minIntBalance;
		int intRate;
	public:
		checking()
		{//intiial constructor
			minIntBalance = 0;
			intRate = 0;
		}
		//Description: Sets the minimum balance that can gain interest
		//Pre-condition: User enters lowest balance
		//Post-condition: Sets lowest balance
		void setMinIntBalance(int lowestBalance)
		{
			try
			{
				if(lowestBalance < 0)
				{//invalid number
					throw lowestBalance;
				}
				else
				{
					lowestBalance = minIntBalance;
				}
			}
			catch(int lowestBalance)
			{//catch exception here
				cout << "Exception Caught." << lowestBalance << " is not a valid minimum interest balance." << endl;
				cout << "Re-enter your value here: ";
				cin >> lowestBalance;
				setMinIntBalance(lowestBalance);
			}
		}
		int getMinIntBalance()
		{
			return minIntBalance;
		}
		//Description: Sets the interest rate on the account
		//Pre-condition: If the balance is not less than the minimum balance and if the rate is positive
		//Post-condition:Sets the interest rate
		void setRate(int rate)
		{
			try
			{
				if(getBalance() < minIntBalance)
				{//if the balance is not above the min balance
					throw rate;
				}
				try
				{
					if(rate < 0)
					{
						throw rate;
					}
					else
					{
						intRate = rate;
					}
				}
				catch(int rate)
				{//if the interest rate is negative
					cout << "Invalid rate. Must be a positive number." << endl;
					cin >> rate;
					setRate(rate);
				}
			}
			catch(int rate)
			{//if min balance is above the balance on the account
				cout << "Exception Caught. Balance does not meet the minimum balance allowed to have interest on it." << endl;
			}
		}
		int getRate()
		{
			return intRate;
		}
		//Description: Computes the interest gained over certain number of years
		//Pre-condition: Years cannot be negative
		//Post-condition: Sets the interest rate on the account
		double computeInt(int years)
		{
			try
			{
				if(years < 0)
				{
					throw years;
				}
				else
				{//interest rate equation
					return ((intRate*0.01) * getBalance()) * years;
				}
			}
			catch(int years)
			{//if years is invalid
				cout << "Exception Caught." << years << " is an invalid number of years." << endl;
				cout << "Re-enter your values here: ";
				cin >> years;
				computeInt(years);
			}
		}
		void toString()
		{//displays info for the account
			cout << "Account #" << getAcct() << ", Balance: $" << getBalance() << endl;
		}
	};
class savings: public account
{
	private:
		double intRate;
	public:
		savings()
		{
			intRate = 0;
		}
		double getRate()
		{
			return intRate;
		}
		//Description: Sets interest rate on the account
		//Pre-condition: Interest rate is not negative
		//Post-condition: Sets the interest rate on the acct
		void setRate(double rate)
		{
			try
			{
				if(rate < 0)
				{//negative interest rate
					throw rate;
				}
				else
				{
					intRate = rate;
				}
			}
			catch(double rate)
			{//catch exception here
				cout << "Exception Caught. " << intRate << " is an invalid interest rate." << endl;
				cout << "Re-enter your value here: ";
				cin >> rate;
				setRate(rate);
			}
		}
		//Description: Computes interest over certain number of years
		//Pre-condition: Years is not negative
		//Post-condition: Returns value of balance over number of years
		double computeInt(int years)
		{
			try
			{
				if(years < 0)
				{//negative years is invalid
					throw years;
				}
				else
				{
					return (pow((1 + (intRate * 0.01)), years) * getBalance()) - getBalance();
				}
			}
			catch(int years)
			{//exception caught here
				cout << "Exception Caught." << years << " is an invalid number of years." << endl;
			}
		}
		void toString()
		{//displays account info
			cout << "Account #" << getAcct() << ", Balance: $" << getBalance() << endl;
		}
	};
	
int main()
{
	char userChoice;
	char acc;
	int acctNum, years;
	float b, i, lb, w, d;

	int cCount = 0;
	int sCount = 0;
	
	checking *cArr[50];//create 50 pointer array elements of class checking
	checking *cPtr;//pointer to point to specific elements in array
	savings *sArr[50];//create 50 pointer array elements of class savings
	savings *sPtr;//pointer to point to specific elements in array

	savings s;
	checking c;
	cout << "C++ ATM PROGRAM" << endl;
	cout << "A - ADD NEW ACCOUNT" << endl;
	cout << "(CHECKING ACCOUNTS MUST BE NAMED IN ORDER 100, 101, 102...)" << endl;
	cout << "(SAVINGS ACCOUNT MUST BE NAMED IN ORDER 200, 201, 202...)" << endl;
	cout << "R - REMOVE ACCOUNT" << endl;
	cout << "G - SWITCH ACCOUNTS" << endl;
	cout << "W - WITHDRAW FROM ACCOUNT" << endl;
	cout << "F - DEPOSIT TO ACCOUNT" << endl;
	cout << "B - CHANGE BALANCE" << endl;
	cout << "I - SET INTEREST" << endl;
	cout << "D - DISPLAY ACCOUNT INFO" << endl;
	cout << "C - INTEREST GAINED OVER CERTAIN NUMBER OF YEARS" << endl;
	cout << "Q - QUIT PROCESSING" << endl;
	cin >> userChoice;//user choice in initial menu
	do
	{
		switch(userChoice)
		{
			case 'A':
			case 'a':
				cout << "Would you like to add a checking or saving account? (c or s)" << endl;
				cin >> acc;
				try
				{
					if(acc == 'c')
					{
						cArr[cCount] = new checking;//creates new memory for the pointer
						cout << "Set the account number." << endl;
						cin >> acctNum;
						acctNum -= 100;
						cPtr = cArr[acctNum];//sets the pointer to the index in the array
						acctNum += 100;
						cPtr -> setAcct(acctNum);//point to checking account setAcct()
						cout << "New checking account created #" << cPtr -> getAcct();
						cout << endl;
						cCount++;//keeps spot in dynamic array
					}
					else if(acc == 's')
					{
						sArr[sCount] = new savings;//creates new memory for the pointer
						cout << "Set the account number." << endl;
						cin >> acctNum;
						acctNum -= 200;
						sPtr = sArr[acctNum];//points to savings account pointer in array
						acctNum += 200;
						sPtr -> setAcct(acctNum);
						cout << "New savings account created #" << sPtr -> getAcct();
						cout << endl;
						sCount++;//keeps track of dynamic array
					}
					else
					{//if char is invalid
						throw acctNum;
					}
				}
				catch(int acctNum)
				{//catch exception for invalid char
					cout << "Exception caught. " << acc << " is an invalid char.";
				}
				break;
			case 'R':
			case 'r':
				cout << "Which account would you like to remove?" << endl;
				cin >> acctNum;
				if(acctNum > 99 && acctNum < 200)
				{
					acctNum -= 100;
					delete cArr[acctNum];//deletes the array element
					acctNum += 100;
					cout << "Account successfully removed." << endl;
				}
				else if(acctNum >= 200)
				{
					acctNum -= 200;
					delete cArr[acctNum];//deletes the array element
					acctNum += 200;
					cout << "Account successfully removed" << endl;
				}
				else
				{
					cout << "INVALID ACCOUNT NUMBER." << endl;
				}
				break;
			case 'G':
			case 'g':
				cout << "Which account would you like to use?" << endl;
				cin >> acctNum;
				if(acctNum > 99 && acctNum < 200)
				{
					acctNum -= 100;
					cPtr = cArr[acctNum];//points to user input account
					acctNum += 100;
				}
				else if(acctNum >= 200)
				{
					acctNum -= 200;
					sPtr = sArr[acctNum];//points to user input account
					acctNum += 200;
				}
				break;
			case 'B':
			case 'b':
				cout << "Set the balance: " << endl;
				cin >> b;
				if(acctNum > 99 && acctNum < 200)
				{
					cPtr -> setBalance(b);//sets the balance of the checking account
					cout << "The balance is now: $" << cPtr -> getBalance();
				}
				else if(acctNum >= 200)
				{
					sPtr -> setBalance(b);//sets the balance of the savings account
					cout << "The balance is now: $" << sPtr -> getBalance();
				}
				break;
			case 'D':
			case 'd':
				if(acctNum > 99 && acctNum < 200)
				{
					cPtr -> toString();//displays the acct info from checking account
				}
				else if(acctNum >= 200)
				{
					sPtr -> toString();//displays info from savings account
				}
				break;
			case 'I':
			case 'i':
				cout << "Set the interest rate on this account: ";
				cin >> i;
				if(acctNum > 99 && acctNum < 200)
				{
					cout << "What's the minimum balance allowed to gain interest?" << endl;
					cin >> lb;//lowest amount allowed to gain interest on
					cPtr -> setMinIntBalance(lb);
					cPtr -> setRate(i);//sets the rate
				}
				else if(acctNum >= 200)
				{
					sPtr -> setRate(i);//sets the rate
				}
				break;
			case 'C':
			case 'c':
				try
				{
					cout << "How many years would you like to calculate over?" << endl;
					cin >> years;
					if(acctNum > 99 && acctNum < 200)
					{
						if(cPtr -> getRate() == 0 )
						{//cannot calculate interest if interest is not set
							throw years;
						}
						try
						{
							if(years < 0)
							{//invalid number of years
								throw years;
							}
							else
							{
								cout << "The balance after " << years << " years is " << cPtr -> computeInt(years) << endl;
							}
						}
						catch(int years)
						{
							cout << "Exception Caught. " << years << " is an invalid number of years." << endl;
						}
					}
					else if(acctNum >= 200)
					{
						if(sPtr -> getRate() == 0)
						{//invalid rate given
							throw years;
						}
						try
						{
							if(years < 0)
							{//invalid number of years
								throw years;
							}
							else
							{
								cout << "The balance after " << years << " years is " << sPtr -> computeInt(years) << endl;
							}
						}
						catch(int years)
						{//inside exception caught
							cout << "Exception Caught. " << years << " is an invalid number of years." << endl;
						}
					}
				}
				catch(int years)
				{//first exception caught
					cout << "Interest rate not set. Set interest rate before computing interest." << endl;
				}
				break;
			case 'W':
			case 'w':
				cout << "How much money would you like to withdraw?" << endl;
				cin >> w;
				if(acctNum > 99 && acctNum < 200)
				{
					try
					{
						if(w < 0)
						{//canot withdraw negative money
							throw w;
						}
						else
						{
							try
							{
								if(w > cPtr -> getBalance())
								{//cannot overdraw
									throw w;
								}
								else
								{//money taken from the account
									cPtr -> setBalance(cPtr -> getBalance() - w);
									cout << "$" << w << " was successfully withdrawn from your account" << endl;
								}
							}
							catch(float w)
							{//cannot take that much money out of account
								cout << "Not enough money to withdraw from account." << endl;
							}
						}
					}
					catch(float w)
					{
						cout << "Invalid withdraw amount." << endl;
					}
				}
				else if(acctNum >= 200)
				{
					try
					{
						if(w < 0)
						{//negative withdraw amount
							throw w;
						}
						else
						{
							try
							{
								if(w > sPtr -> getBalance())
								{//not enough money to withdraw
									throw w;
								}
								else
								{//withdraw money
									sPtr -> setBalance(sPtr -> getBalance() - w);
									cout << "$" << w << " was successfully withdrawn from your account" << endl;
								}
							}
							catch(float w)
							{
								cout << "Cannot withdraw amount, balance too low." << endl;
							}
						}
					}
					catch(float w)
					{
						cout << "Withdraw amount not valid." << endl;
					}
				}
				break;
			case 'F':
			case 'f':
				cout << "How much money would you like to deposit?" << endl;
				cin >> d;
				if(acctNum > 99 && acctNum < 200)
				{
					try
					{
						if(d < 0)
						{//negative deposit amount
							throw d;
						}
						else
						{//money depositted to account
							cPtr -> setBalance(cPtr -> getBalance() + d);
							cout << "$" << w << " was successfully deposited to your account" << endl;
						}
					}
					catch(float d)
					{
						cout << "Deposit amount not valid." << endl;
					}
				}
				else if(acctNum >= 200)
				{
					sPtr -> setBalance(sPtr -> getBalance() + d);
					cout << "$" << w << " was successfully deposited to your account" << endl;
				}
				break;
			}
			cout << endl;
			cout << "Select your next action." << endl;
			cin >> userChoice;
		}while(userChoice != 'Q' && userChoice != 'q');
		//exit program
		cout << "Thank you for using this program." << endl;
		return 0;
	}
