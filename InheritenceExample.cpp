//Program Name: Vehicle Class Set
//Programmer Name: Ian Simon
//Description: Program receives input from user to create a round trip with a certain vehicle
//Date Created: 10/21/17
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class vehicle
{//declares the class vehicle
	private:
		int age;//vehicle age
		float price;//vehicle price
		int speed;
		int fuel;
		string direction;
		bool engineStatus;
	public:
		vehicle()
		{
			age = 0;
			price = 0;//intialize values in class set to their starting values
			speed = 0;
			fuel = 100;
			direction = "xxxxx";
			engineStatus = false;
		}
		void setAge(int a)
		{
			if(a > 0)
			{
				age = a;//sets age variable to the input
			}
			else
			{
				cout << "Invalid age." << endl;//if age is 0 or less
			}
		}
		void setPrice(float p)
		{
			if(p > 0)
			{
				price = p;//sets price variable to p
			}
			else
			{
				cout << "Invalid price." << endl;//if price is 0 or less
			}
		}
		void setSpeed(int s)
		{
			if(s >= 0)//cannot be a negative speed
			{
				speed = s;
			}
			else
			{//too fast or too slow
				cout << "Invalid speed!" << endl;
			}
		}
		void setFuel(int f)
		{
			if(f <= 100 && f > 0)
			{//100% full or no gas
				fuel = f;
			}
			else
			{
				cout << "Fuel amount not valid." << endl;
			}
		}
		void setDirection(string d)
		{
			direction = d;
		}
		void setEngineStatus(bool eS)
		{
			engineStatus = eS;
		}
		int getAge()
		{
			return age;
		}
		float getPrice()//functions to receive data from set members
		{
			return price;
		}
		int getSpeed()
		{
			return speed;
		}
		int getFuel()
		{
			return fuel;
		}
		string getDirection()
		{
			return direction;
		}
		bool getEngineStatus()
		{
			return engineStatus;
		}
	};
class landVehicle : public vehicle
{
	private:
		int numPass;
		string gear;
		float mileage;
	public:
		landVehicle()
		{
			numPass = 0;
			gear = "Park";
			mileage = 0;
		}
		void setNumPass(int n)
		{
			if(n > 0 && n <= 6)
			{//max of 6 seats in the vehicle
				numPass = n;
			}
			else
			{
				cout << "Invalid number of passengers." << endl;
			}
		}
		void setGear(string g)
		{
			gear = g;
		}
		void setMileage(float m)
		{
			if(m > 0)
			{//car must have some amount of miles on it
				mileage = m;
			}
			else
			{
				cout << "Invalid mileage." << endl;
			}
		}
		int getNumPass()
		{
			return numPass;
		}
		string getGear()
		{
			return gear;
		}
		int getMileage()
		{
			return mileage;
		}
	};
class car : public landVehicle//uses publice functions from vehicle class
{//declares the car class
	private:
		bool raceCarStatus;//tells if the car is of a race car type
		string driveType;
		bool tireStatus;
	public:
		car()
		{
			raceCarStatus = false;
			driveType = "xxxxxxx";
			tireStatus = true;
		}
		void setRaceCarStatus(char rCS)
		{
			if(rCS == 'Y')
			{//sets the value of race car status
				raceCarStatus = true;
			}
			else if(rCS == 'N')
			{
				raceCarStatus = false;
			}
			else
			{
				cout << "Invalid character." << endl;
			}
		}
		void setDriveType(string d)
		{
			driveType = d;
		}
		void setTireStatus(char ts)
		{
			if(ts == 'G')
			{//G for good tires
				tireStatus = true;
			}
			else if(ts == 'B')
			{//b for bad tires
				cout << "Recommended to change tires." << endl;
				tireStatus = false;
			}
			else
			{
				cout << "Invalid character." << endl;
			}
		}
		bool getRaceCarStatus()
		{
			return raceCarStatus;
		}
		bool getTireStatus()
		{
			return tireStatus;
		}
		string getDriveType()
		{
			return driveType;
		}
	};
class truck : public landVehicle//uses public member functions of class type vehicle
{//declares truck class
	private:
		bool dieselTypeStatus;//tells if the truck uses diesel fuel
		int numWheels;
	public:
		truck()
		{
			dieselTypeStatus = false;
			numWheels = 4;
		}
		void setDieselTypeStatus(bool dTS)
		{
			dieselTypeStatus = dTS;
		}
		void setNumWheels(int r)
		{
			if(r >= 4 && r <= 18 && r % 2 == 0)
			{//must have 4 wheels, less than 18 and an even number
				numWheels = r;
			}
			else
			{
				cout << "Invalid number of wheels." << endl;
			}
		}
		int getNumWheels()
		{
			return numWheels;
		}
		bool getDieselTypeStatus()
		{
			return dieselTypeStatus;
		}
	};
class plane : public vehicle
{
	private:
		float altitude;
		string planeType;
	public:
		plane()
		{
			altitude = 0;
			planeType = "xxxxxx";
		}
		void setAltitude(float a)
		{
			if(a >= 0)
			{//can be moving on the ground, but not below it
				altitude = a;
			}
			else
			{
				cout << "Invalid altitude." << endl;
			}
		}
		void setPlaneType(string p)
		{
			planeType = p;
		}
		float getAltitude()
		{
			return altitude;
		}
		string getPlaneType()
		{
			return planeType;
		}
	};
class boat: public vehicle
{
	private:
		float windSpeed;
		int waveHeight;
	public:
		boat()
		{
			windSpeed = 0.0;
			waveHeight = 0;
		}
		void setWindSpeed(float w)
		{
			if(w >= 0 && w < 10)
			{//recommended wind speed for safe boating
				windSpeed = w;
			}
			else if(w >= 10)
			{//warning message
				cout << "WARNING: High winds, proceed with caution." << endl;
				windSpeed = w;
			}
			else
			{
				cout << "Invalid wind speed." << endl;
			}
		}
		void setWaveHeight(int h)
		{
			if(h >= 0 && h < 5)
			{//recommended wave height
				waveHeight = h;
			}
			else if(h >= 5)
			{//warning message
				cout << "WARNING: High waves, proceed with caution." << endl;
				waveHeight = h;
			}
			else
			{
				cout << "Invalid wave height." << endl;
			}
		}
		float getWindSpeed()
		{
			return windSpeed;
		}
		int getWaveHeight()
		{
			return waveHeight;
		}
	};

int main()
{
	int userChoice;
	int a, p, f;
	string d;
	ofstream ofs;
	
	cout << "What vehicle would you like you take?" << endl;
	cout << "1 - Car" << endl;
	cout << "2 - Truck" << endl;
	cout << "3 - Boat" << endl;
	cout << "4 - Plane" << endl;
	cin >> userChoice;
	
	if(userChoice == 1)
	{
		ofs.open("CarTripReport.txt");
	}
	else if(userChoice == 2)
	{
		ofs.open("TruckTripReport.txt");
	}
	else if(userChoice == 3)
	{
		ofs.open("BoatTripReport.txt");
	}
	else if(userChoice == 4)
	{
		ofs.open("PlaneTripReport.txt");
	}
	
	cout << "How old is the vehicle?" << endl;
	cin >> a;
	cout << "How expensive is the vehicle?" << endl;
	cin >> p;
	cout << "How much fuel is left in the tank?" << endl;
	cin >> f;
	cout << "Set your starting direction. (North, South, East, West)" << endl;
	cin >> d;
	
	if(userChoice == 1)
	{
		car trip;
		int np, s, miles = 0;
		float m;
		char rc, ts, stopGas;
		string dt, gear;
		cout << "How many people will join you?" << endl;
		cin >> np;//set number of passengers
		trip.setNumPass(np);
		ofs << trip.getNumPass() << " passengers" << endl;
		cout << "Set the mileage on the car." << endl;
		cin >> m;//initial mileage on the car
		trip.setMileage(m);
		ofs << trip.getMileage() << " miles on the car before the trip" << endl;
		cout << "Is the car a race car? (Y or N)" << endl;
		cin >> rc;
		trip.setRaceCarStatus(rc);
		cout << "Set the drive type. (AWD, FWD, or RWD)" << endl;
		cin >> dt;//drive type
		trip.setDriveType(dt);
		ofs << trip.getDriveType() << endl;
		cout << "Set the tire status. (G or B)" << endl;
		cin >> ts;
		trip.setTireStatus(ts);
		trip.setAge(a);
		trip.setPrice(p);
		trip.setFuel(f);
		trip.setDirection(d);
		cout << "Select your action: " << endl;
		cout << "1 - Start engine." << endl;
		cout << "2 - Set your speed." << endl;
		cout << "3 - Change direction." << endl;
		cout << "4 - Check fuel tank." << endl;
		cout << "5 - Change the gear. (P, R, N, D)" << endl;
		cout << "6 - End trip." << endl;
		int driveChoice;
		cin >> driveChoice;
		if(driveChoice != 1 && driveChoice != 0)
		{
			do
			{
				cout << "Must start engine before you begin." << endl;
				cin >> driveChoice;//catch if the engine hasn't started in the vehicle
			}while(driveChoice != 1);
		}
		if(driveChoice != 5)
			{
				do{
				cout << "Must put the car in drive before you move." << endl;
				cin >> driveChoice;//the gear must be out of park to move
				}while(driveChoice != 5);
			}
		while(driveChoice != 6)
		{
			switch(driveChoice)
			{
				case 1:
					cout << "Engine Started." << endl;
					ofs << "Engine Started." << endl;
					break;
				case 2:
					cout << "Current Speed: " << endl;
					cout << trip.getSpeed() << " MPH" << endl;
					cout << "What speed would you like to go?" << endl;
					cin >> s;//set a new speed
					trip.setSpeed(s);
					ofs << "Moving at " << trip.getSpeed() << " MPH" << endl;
					break;
				case 3:
					cout << "Currently facing " << endl;
					cout << trip.getDirection() << endl;
					if(trip.getSpeed() > 0 && trip.getSpeed() < 30)
					{//cannot change direction if you are not moving
						cout << "Which direction would you like to go?" << endl;
						cin >> d;
						trip.setDirection(d);
						ofs << "Currently facing " << trip.getDirection() << endl;
					}
					else if(trip.getSpeed() == 0)
					{
						cout << "Car is not moving, please set your initial speed." << endl;
						cin >> s;//set new speed
						trip.setSpeed(s);
						cout << "Which direction would you like to go?" << endl;
						cin >> d;
						trip.setDirection(d);
						ofs << "Currently facing " << trip.getDirection() << endl;
					}
					else if(trip.getSpeed() > 30)
					{
						do{
						cout << "Car is moving too fast to turn. Slow down your speed here ( < 30 MPH): " << endl;
						cin >> s;
						trip.setSpeed(s);
						cout << "Which direction would you like to go?" << endl;
						cin >> d;
						trip.setDirection(d);
						ofs << "Currently facing " << trip.getDirection() << endl;
						}while(trip.getSpeed() > 30);
					}
					break;
				case 4:
					cout << "Current fuel level: " << endl;
					cout << trip.getFuel() << "%" << endl;
					cout << "Would you like to stop for gas? (Y or N)" << endl;
					cin >> stopGas;
					if(stopGas == 'Y')
					{//if stop for gas, tank filled to 100%
						if(trip.getSpeed() == 0)
						{
							if(trip.getGear() != "P" && trip.getGear() != "Park")
							{
								cout << "Set your vehicle to park before filling the tank." << endl;
								cin >> gear;
								trip.setGear(gear);
							}
							trip.setFuel(100);
							cout << "Fuel tank filled to 100%" << endl;
							ofs << "Stopped for gas. Gas tank to 100%." << endl;
						}
						else
						{
							do{
							cout << "Must stop your vehicle before you get gas." << endl;
							cin >> s;
							trip.setSpeed(s);
							}while(trip.getSpeed() != 0);
							if(trip.getGear() != "P" && trip.getGear() != "Park")
							{
								cout << "Set your vehicle to park before filling the tank." << endl;
								cin >> gear;
								trip.setGear(gear);
							}
							trip.setFuel(100);
							cout << "Fuel tank filled to 100%" << endl;
							ofs << "Stopped for gas. Gas tank to 100%." << endl;
							}
						}
					else
					{
						cout << "Gas station passed." << endl;
						ofs << "Gas station passed." << endl;
					}
					break;
				case 5:
					cout << "What gear would you like to be in?" << endl;
					cin >> gear;
					trip.setGear(gear);
					break;
			}
			cout << "Select your next action: ";
			cin >> driveChoice;
			cout << endl;
			trip.setFuel(trip.getFuel() - 5);//fuel is used by increments of 5% as you take actions
			if(trip.getFuel() <= 20)
			{//low fuel warning
				cout << "Fuel warning, < 20% remaining!" << endl;
				ofs << "Fuel warning, less than 20% remaining." << endl;
			}
			miles += trip.getSpeed() / 10;//miles taken during the trip
		}
		if(trip.getGear() != "P" && trip.getGear() != "Park")
			{//if they want to end the trip they must the car back to park
				do{
				cout << "Set the gear to Park or P" << endl;
				cin >> gear;
				trip.setGear(gear);
				}while(trip.getGear() != "P" && trip.getGear() != "Park");
			}
		cout << "Trip Report: " << endl;
		cout << "Miles travelled: " << miles << endl;
		cout << "Fuel Remaining: " << trip.getFuel() << "%" << endl;
		cout << "Car mileage: " << trip.getMileage() + miles << endl;
		cout << "Tire Status: ";
		if(trip.getTireStatus() == true)
		{
			cout << "Good" << endl;
		}
		else
		{
			cout << "Bad" << endl;
		}
		ofs << "Trip Report: " << endl;
		ofs << "Miles travelled: " << miles << endl;
		ofs << "Fuel Remaining: " << trip.getFuel() << "%" << endl;
		ofs << "Car mileage: " << trip.getMileage() + miles << endl;
		ofs << "Tire Status: ";
		if(trip.getTireStatus() == true)
		{
			ofs << "Good" << endl;
		}
		else
		{
			ofs << "Bad" << endl;
		}
		ofs << "Number of Passengers: " << trip.getNumPass() << endl;
	}
	else if(userChoice == 2)
	{//the same thing as the userChoice = 1
		truck trip;
		int np, s, miles = 0, wheels;
		float m;
		char dt, ts, stopGas;
		string gear;
		cout << "How many people will join you?" << endl;
		cin >> np;
		trip.setNumPass(np);
		ofs << trip.getNumPass() << " passengers." << endl;
		cout << "Set the mileage on the truck." << endl;
		cin >> m;
		trip.setMileage(m);
		ofs << "Initial mileage at " << trip.getMileage() << " miles" << endl;
		cout << "Is the truck a diesel type? (Y or N)" << endl;
		cin >> dt;//set if the truck takes diesel fuel
		trip.setDieselTypeStatus(dt);
		cout << "Set the number of wheels on the truck." << endl;
		cin >> wheels;
		trip.setNumWheels(wheels);
		ofs << "Number of wheels: " << trip.getNumWheels() << endl;
		trip.setAge(a);
		trip.setPrice(p);
		trip.setFuel(f);
		trip.setDirection(d);
		cout << "Select your action: " << endl;
		cout << "1 - Start engine." << endl;
		cout << "2 - Set your speed." << endl;
		cout << "3 - Change direction." << endl;
		cout << "4 - Check fuel tank." << endl;
		cout << "5 - Change the gear. (P, R, N, D)" << endl;
		cout << "6 - End trip." << endl;
		int driveChoice;
		cin >> driveChoice;
		if(driveChoice != 1 && driveChoice != 0)
		{
			do
			{
				cout << "Must start engine before you begin." << endl;
				cin >> driveChoice;
			}while(driveChoice != 1);
		}
		if(driveChoice != 5)
			{
				do{
				cout << "Must put the truck in drive before you move." << endl;
				cin >> driveChoice;
				}while(driveChoice != 5);
			}
		while(driveChoice != 6)
		{
			switch(driveChoice)
			{
				case 1:
					cout << "Engine Started." << endl;
					ofs << "Engine Started." << endl;
					break;
				case 2:
					cout << "Current Speed: " << endl;
					cout << trip.getSpeed() << " MPH" << endl;
					cout << "What speed would you like to go?" << endl;
					cin >> s;
					trip.setSpeed(s);
					ofs << "Currently going " << trip.getSpeed() << " MPH" << endl;
					break;
				case 3:
					cout << "Currently facing " << endl;
					cout << trip.getDirection() << endl;
					if(trip.getSpeed() > 0 && trip.getSpeed() < 30)
					{
						cout << "Which direction would you like to go?" << endl;
						cin >> d;
						trip.setDirection(d);
						ofs << "Currently facing " << trip.getDirection() << endl;
					}
					else if(trip.getSpeed() == 0)
					{
						cout << "Truck is not moving, please set your initial speed." << endl;
						cin >> s;
						trip.setSpeed(s);
						cout << "Which direction would you like to go?" << endl;
						cin >> d;
						trip.setDirection(d);
						ofs << "Currently facing " << trip.getDirection() << endl;
					}
					else if(trip.getSpeed() > 30)
					{
						do{
						cout << "Truck is moving too fast to turn. Slow down your speed here ( < 30 MPH): " << endl;
						cin >> s;
						trip.setSpeed(s);
						cout << "Which direction would you like to go?" << endl;
						cin >> d;
						trip.setDirection(d);
						ofs << "Currently facing " << trip.getDirection() << endl;
						}while(trip.getSpeed() > 30);
					}
					break;
				case 4:
					cout << "Current fuel level: " << endl;
					cout << trip.getFuel() << "%" << endl;
					cout << "Would you like to stop for gas? (Y or N)" << endl;
					cin >> stopGas;
					if(stopGas == 'Y')
					{//if stop for gas, tank filled to 100%
						if(trip.getSpeed() == 0)
						{
							if(trip.getGear() != "P" && trip.getGear() != "Park")
							{
								cout << "Set your vehicle to park before filling the tank." << endl;
								cin >> gear;
								trip.setGear(gear);
							}
							trip.setFuel(100);
							cout << "Fuel tank filled to 100%" << endl;
							ofs << "Stopped for gas. Gas tank to 100%." << endl;
						}
						else
						{
							do{
							cout << "Must stop your vehicle before you get gas." << endl;
							cin >> s;
							trip.setSpeed(s);
							}while(trip.getSpeed() != 0);
							if(trip.getGear() != "P" && trip.getGear() != "Park")
							{
								cout << "Set your vehicle to park before filling the tank." << endl;
								cin >> gear;
								trip.setGear(gear);
							}
							trip.setFuel(100);
							cout << "Fuel tank filled to 100%" << endl;
							ofs << "Stopped for gas. Gas tank to 100%." << endl;
							}
						}
					break;
				case 5:
					cout << "What gear would you like to be in?" << endl;
					cin >> gear;
					trip.setGear(gear);
					break;
			}
			cout << "Select your next action: ";
			cin >> driveChoice;
			cout << endl;
			trip.setFuel(trip.getFuel() - 10);
			if(trip.getFuel() <= 20)
			{
				cout << "Fuel warning, < 20% remaining!" << endl;
				ofs << "Fuel warning, < 20% remaining." << endl;
			}
			miles += trip.getSpeed() / 10;
		}
		if(trip.getGear() != "P" && trip.getGear() != "Park")
			{
				do{
				cout << "Set the gear to Park or P" << endl;
				cin >> gear;
				trip.setGear(gear);
				}while(trip.getGear() != "P" && trip.getGear() != "Park");
			}
		cout << "Trip Report: " << endl;
		cout << "Miles travelled: " << miles << endl;
		cout << "Fuel Remaining: " << trip.getFuel() << "%" << endl;
		cout << "Truck mileage: " << trip.getMileage() + miles << endl;
		cout << "Number of Passengers: " << trip.getNumPass() << endl;
		ofs << "Trip Report: " << endl;
		ofs << "Miles travelled: " << miles << endl;
		ofs << "Fuel Remaining: " << trip.getFuel() << "%" << endl;
		ofs << "Truck mileage: " << trip.getMileage() + miles << endl;
		ofs << "Number of Passengers: " << trip.getNumPass() << endl;
	}
	else if(userChoice == 3)
	{//same thing as above
		boat trip;
		int s, miles = 0;//miles set to zero for the trip
		float m, w;
		char stopGas;
		cout << "Set the wave height of the lake." << endl;
		cin >> s;//user input wave height
		trip.setWaveHeight(s);
		ofs << "Wave height: " << trip.getWaveHeight() << " ft." << endl;
		cout << "Set the wind speed on the lake." << endl;
		cin >> w;//user input wind speed
		trip.setWindSpeed(w);
		ofs << "Wind speed: " << trip.getWindSpeed() << " MPH" << endl;
		trip.setAge(a);
		trip.setPrice(p);
		trip.setFuel(f);
		trip.setDirection(d);
		cout << "Select your action: " << endl;
		cout << "1 - Start engine." << endl;
		cout << "2 - Set your speed." << endl;
		cout << "3 - Change direction." << endl;
		cout << "4 - Check fuel tank." << endl;
		cout << "5 - Change the wave height." << endl;
		cout << "6 - End trip." << endl;
		int driveChoice;
		cin >> driveChoice;
		if(driveChoice != 1 && driveChoice != 0)
		{
			do
			{
				cout << "Must start engine before you begin." << endl;
				cin >> driveChoice;
			}while(driveChoice != 1);
		}
		while(driveChoice != 6)
		{
			switch(driveChoice)
			{
				case 1:
					cout << "Engine Started." << endl;
					ofs << "Engine Started." << endl;
					break;
				case 2:
					cout << "Current Speed: " << endl;
					cout << trip.getSpeed() << " MPH" << endl;
					if(trip.getWaveHeight() <= 5)
					{
						cout << "What speed would you like to go?" << endl;
						cin >> s;
						trip.setSpeed(s);
						ofs << "Current speed: " << trip.getSpeed() << " MPH" << endl;
					}
					else
					{
						do{
						cout << "High waves, move slowly ( < 20 MPH)" << endl;
						cin >> s;
						trip.setSpeed(s);
						}while(trip.getSpeed() > 20);
					}
					break;
				case 3:
					cout << "Currently facing " << endl;
					cout << trip.getDirection() << endl;
					cout << "Which direction would you like to go?" << endl;
					cin >> d;
					trip.setDirection(d);
					ofs << "Currently facing " << trip.getDirection() << endl;
					break;
				case 4:
					cout << "Current fuel level: " << endl;
					cout << trip.getFuel() << "%" << endl;
					cout << "Would you like to stop for gas? (Y or N)" << endl;
					cin >> stopGas;
					if(stopGas == 'Y')
					{//if stop for gas, tank filled to 100%
						if(trip.getSpeed() == 0)
						{
							trip.setFuel(100);
							cout << "Fuel tank filled to 100%" << endl;
							ofs << "Stopped for gas. Gas tank to 100%." << endl;
						}
						else
						{
							do{
							cout << "Must stop your vehicle before you get gas." << endl;
							cin >> s;
							trip.setSpeed(s);
							}while(trip.getSpeed() != 0);
							trip.setFuel(100);
							cout << "Fuel tank filled to 100%" << endl;
							ofs << "Stopped for gas. Gas tank to 100%." << endl;
							}
						}
					break;
				case 5:
					cout << "What is the new wave height?" << endl;
					cin >> s;//ability to record the new wave height on the seas
					trip.setWaveHeight(s);
					cout << "New wave height is ";
					cout << trip.getWaveHeight() << " ft." << endl;
					ofs << "New wave height is ";
					ofs << trip.getWaveHeight() << " ft." << endl;
					break;
			}
			cout << "Select your next action: ";
			cin >> driveChoice;
			cout << endl;
			trip.setFuel(trip.getFuel() - 10);//boat burns through more fuel than a car
			if(trip.getFuel() <= 20)
			{
				cout << "Fuel warning, < 20% remaining!" << endl;
				ofs << "Fuel warning, < 20% remaining." << endl;
			}
   			miles += trip.getSpeed() / 10;
		}
		cout << "Trip Report: " << endl;
		cout << "Miles travelled: " << miles << endl;
		cout << "Fuel Remaining: " << trip.getFuel() << "%" << endl;
		ofs << "Trip Report: " << endl;
		ofs << "Miles travelled: " << miles << endl;
		ofs << "Fuel Remaining: " << trip.getFuel() << "%" << endl;
	}
	else if(userChoice == 4)
	{
		plane trip;
		int s, miles = 0;
		float t;
		char stopGas;
		string pt;
		cout << "Set the plane type." << endl;
		cin >> pt;//commercial, private, etc...
		trip.setPlaneType(pt);
		ofs << "Plane type: " << trip.getPlaneType() << endl;
		trip.setAge(a);
		trip.setPrice(p);
		trip.setFuel(f);
		trip.setDirection(d);
		cout << "Select your action: " << endl;
		cout << "1 - Start engine." << endl;
		cout << "2 - Set your speed." << endl;
		cout << "3 - Change direction." << endl;
		cout << "4 - Check fuel tank." << endl;
		cout << "5 - Change your altitude." << endl;
		cout << "6 - End trip." << endl;
		int driveChoice;
		cin >> driveChoice;
		if(driveChoice != 1 && driveChoice != 0)
		{
			do
			{
				cout << "Must start engine before you begin." << endl;
				cin >> driveChoice;//same catch statement as before
			}while(driveChoice != 1);
		}
		while(driveChoice != 6)
		{
			switch(driveChoice)
			{
				case 1:
					cout << "Engine Started." << endl;
					ofs << "Engine Started." << endl;
					break;
				case 2:
					cout << "Current Speed: " << endl;
					cout << trip.getSpeed() << " MPH" << endl;
					cout << "What speed would you like to go?" << endl;
					cin >> s;
					trip.setSpeed(s);
					cout << "Current Speed: " << trip.getSpeed() << endl;
					break;
				case 3:
					cout << "Currently facing " << endl;
					cout << trip.getDirection() << endl;
					cout << "Which direction would you like to go?" << endl;
					cin >> d;
					trip.setDirection(d);
					ofs << "Currently facing: " << trip.getDirection() << endl;
					break;
				case 4:
					cout << "Current fuel level: " << endl;
					cout << trip.getFuel() << "%" << endl;
					cout << "Would you like to fill the tank? (Y or N)" << endl;
					cin >> stopGas;
					if(stopGas == 'Y')
					{
						trip.setFuel(100);
						cout << "Fuel tank filled to 100%" << endl;
						ofs << "Fuel tank filled to 100%" << endl;
					}
					else
					{
						cout << "No gas added." << endl;
						ofs << "No gas added." << endl;
					}
					break;
				case 5:
					cout << "Current altitude is ";
					cin >> t;//change altitude mid-flight
					trip.setAltitude(t);
					cout << "New altitude is ";
					cout << trip.getAltitude() << " ft." << endl;
					ofs << "Current altitude: " << trip.getAltitude() << " ft." << endl;
					break;
			}
			cout << "Select your next action: ";
			cin >> driveChoice;
			cout << endl;
			trip.setFuel(trip.getFuel() - 10);
			if(trip.getFuel() <= 20)
			{
				cout << "Fuel warning, < 20% remaining!" << endl;
				ofs << "Fuel warning, < 20% remaining." << endl;
			}
			miles += trip.getSpeed() / 10;
		}
		if(trip.getAltitude() > 0)
		{//must be on the ground before you can land
			do{
			cout << "The plane is still in the sky! Please set back to zero ft." << endl;
			cin >> t;
			trip.setAltitude(t);
			}while(t != 0);
		}
		cout << "Trip Report: " << endl;
		cout << "Miles travelled: " << miles << endl;
		cout << "Fuel Remaining: " << trip.getFuel() << "%" << endl;
		ofs << "Trip Report: " << endl;
		ofs << "Miles travelled: " << miles << endl;
		ofs << "Fuel Remaining: " << trip.getFuel() << "%" << endl;
	}
	return 0;
}
