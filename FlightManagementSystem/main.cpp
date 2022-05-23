//============================================================================
// Name        : Q1.cpp
// Author      : Usman Ali Bokhari
// Details     : Oop Project.
// Classes     :  
// Do int times and then do booking
//============================================================================
#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "Admin.h"
#include "FlightSchedule.h"
#include "Passenger.h"
#include "Passport.h"
#include <sstream>
#include <fstream>
#include <ctime>
#include <conio.h>
using namespace std;

bool logedin = false;
bool permission = false;
void menu();
void login(Passenger, Admin);
double balance;
void signUp(Passenger, Admin);

//Add validation using files.
void signUp(Passenger A, Admin B) {
	cout << "Do you want to sign  up as: \n 1.passenger \n 2. Admin (the admin permission pass is: 1001)" << endl;
	int x;
	cin >> x;

	while (x != 1 && x != 2) {
		cout << "Invalid input: Please try again." << endl;
		cin >> x;
	}
	int per = 0;
	if (x == 2) {
		cout << "Enter admin password: ";
		cin >> x;
		while (x != 1001) {
			cin.ignore(10000, '\n');
			cout << "Error: Incorrect admin password." << endl;
			cin >> x;
		}
		per = 1;
	}


	string User, pass, CNIC, ID;
	cout << "Enter your new user name: ";
	cin >> User;
	cout << "Enter password: ";
	char ch = _getch();
	while (ch != 13) {//character 13 is enter
		pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	cout << endl;
	int v = 1;
	while (v) {
		int count1 = 0;
		int count2 = 0;
		int count3 = 0;
		int size = pass.length();
		char* passw = new char[size];
		strcpy(passw, pass.c_str());
		
		for (int i = 0; i < size; i++) {
			if (passw[i] < 90 && passw[i]>65) {
				count1++;
			}
			if (passw[i] < 122 && passw[i]>97) {
				count2++;
			}
			if (passw[i] < 47 && passw[i]>33) {
				count3++;
			}
		}
		if (count1 == 0 || count2 == 0 || count3 == 0 || size < 8) {
			cout << "Invalid input: Please try again." << endl;
			pass = "";
			int ch2 = _getch();
			while (ch2 != 13) {//character 13 is enter
				pass.push_back(ch2);
				cout << '*';
				ch2 = _getch();
			}
			cout << endl;
		}
		else {
			v = 0;
		}
	}
	string pass2;
	cout << "Please retype your password." << endl;
	int ch3 = _getch();
	while (ch3 != 13) {//character 13 is enter
		pass2.push_back(ch3);
		cout << '*';
		ch3 = _getch();
	}
	cout << endl;
	while (pass != pass2) {
		pass2 = "";
		cout << "Error: Passwords do not match. Try again." << endl;
		int ch4 = _getch();
		while (ch4 != 13) {//character 13 is enter
			pass2.push_back(ch4);
			cout << '*';
			ch4 = _getch();
		}
		cout << endl;
	}
	cout << "Enter CNIC: ";
	cin >> CNIC;
	cout << "Enter your passport ID please: ";
	cin >> ID;

	if (per == 0) {
		string User1, pass1, CNIC1;
		ifstream Info1; //opening user name file
		Info1.open("Passenger.txt");
		while ((!Info1.fail()) && (!Info1.eof())) {
			if (Info1.eof()) {
				break;
			}
			Info1 >> User1 >> pass1 >> CNIC1 >> ID;
			if (User1 == User || CNIC == CNIC1) {
				cout << "User with this name or CNIC already exists, would you like to: \n 1. Retry with new credentials. \n 2. Login to an existing user." << endl;
				int check = 0;
				cin >> check;
				while (check != 1 && check != 2) {
					cout << "Invalid input: Please try again: " << endl;
					cin >> check;
				}

				if (check == 1) {
					cout << "Redirecting....." << endl;
					signUp(A, B);
				}
				if (check == 2) {
					cout << "Redirecting....." << endl;
					login(A, B);
				}
			}
		}
		Info1.close();

		ofstream Info;
		Info.open("Passenger.txt", ios::app);
		Info << User;
		Info << " ";
		Info << pass;
		Info << " ";
		Info << CNIC;
		Info << " ";
		Info << per;
		Info << "\n";
		Info.close();

		cout << "Creating account......" << endl;
		cout << "Saving details......" << endl;
		cout << "Account created successfully, login to access values." << endl;
		cout << "Returning to menu...." << endl;
	}
	if (per == 1) {
		string User1, pass1, CNIC1;
		ifstream Info1; //opening user name file
		Info1.open("Admin.txt");
		while ((!Info1.fail()) && (!Info1.eof())) {
			if (Info1.eof()) {
				break;
			}
			Info1 >> User1 >> pass1 >> CNIC1 >> ID;
			if (User1 == User || CNIC == CNIC1) {
				cout << "User with this name or CNIC already exists, would you like to: \n 1. Retry with new credentials. \n 2. Login to an existing user." << endl;
				int check = 0;
				cin >> check;
				while (check != 1 && check != 2) {
					cout << "Invalid input: Please try again: " << endl;
					cin >> check;
				}

				if (check == 1) {
					cout << "Redirecting....." << endl;
					signUp(A, B);
				}
				if (check == 2) {
					cout << "Redirecting....." << endl;
					login(A, B);
				}
			}
		}
		Info1.close();

		ofstream Info;
		Info.open("Admin.txt", ios::app);
		Info << User;
		Info << " ";
		Info << pass;
		Info << " ";
		Info << CNIC;
		Info << " ";
		Info << per;
		Info << "\n";
		Info.close();

		cout << "Creating account......" << endl;
		cout << "Saving details......" << endl;
		cout << "Account created successfully, login to access values." << endl;
		cout << "Returning to menu...." << endl;
	}
}

double balance1(Passenger &A) {
	cout << "How much money do you have? " << endl;
	double x;
	cin >> x;
	A.payment = x;
	return x;
}


void login(Passenger A, Admin B) {

	// Taking input:
	cout << "Enter user-name and password." << endl;
	string name, pass;
	cout << "User-name: ";
	cin >> name;
	cout << "Password: ";
	char ch = _getch();
	while (ch != 13) {//character 13 is enter
		pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	cout << endl;
	
	int per;
	string User1, pass1, CNIC1;

	// Checking to see if user exists:
	//========================================================
	
	//Checking if user is an admin:
	ifstream Info1; //opening user name file
	Info1.open("Admin.txt");
	while ((!Info1.fail()) && (!Info1.eof())) {
		if (Info1.eof()) {
			break;
		}
		Info1 >> User1 >> pass1 >> CNIC1 >> per;
		if (User1 == name && pass1 == pass) {
			cout << "Fetching details...." << endl;
			logedin = true;
			permission = true;
			return;
		}
	}
	Info1.close();

	//Checking if user is a Passenger:
	ifstream Info2; //opening user name file
	Info2.open("Passenger.txt");
	while ((!Info2.fail()) && (!Info2.eof())) {
		if (Info2.eof()) {	
			break;
		}
		Info2 >> User1 >> pass1 >> CNIC1 >> per;
		if (User1 == name && pass1 == pass) {
			cout << "Fetching details...." << endl;
			logedin = true;
			permission = false;
			return;
		}
	}
	Info2.close();
	//============================================================
	cout << "User not found, would you like to:" << endl;
}


int run = 0;
void menu() {
	cout << endl;
	if (logedin == false) {
		cout << "Would you like to: \n 1. Sign up.\n 2. Login. \n 3. See Schedule. \n 7. Exit." << endl;
	}
	else if (logedin == true&& permission == false ) {
		cout << "Would you like to: \n 1. Sign up.\n 2. Login. \n 3. See Schedule.\n 4. Book a flight. \n 6. Log out \n 7. Exit. \n 8. Special flight" << endl;
	}
	else if (logedin == true && permission == true) {
		cout << "Would you like to: \n 1. Sign up.\n 2. Login. \n 3. See Schedule.\n 4. Change a flight. \n 5. Add Covid country\n 6. Log  \n 7. Exit." << endl;
	}
	
}

int main() {
	srand((unsigned) time(0));
	int choice = 0;
	menu();
	cin >> choice;
	Passenger P;
	Admin A;
	FlightSchedule F;
	F.GenSchedule();
	while (choice) {
		if (choice == 1) {
			signUp(P, A);
		}
		if (choice == 2) {
			login(P, A);
		}
		if (choice == 3) {
			F.Display();
		}
		if (choice == 4&&permission==false) {
			P.payment -= F.Booking();
			if (P.payment < 0) {
				cout << "Booking canceled!!!!!!!!\nYou do not have sufficient balance to purchase flight." << endl;
			}
			cout << "You have " << P.payment << " left in your bank account." << endl << endl;
		}
		if (choice == 4 && permission == true) {
			F.changer();//change
		}
		if (choice == 5 && permission == true) {
			F.addCovid();
			F.intGen();
		}
		if (choice == 6) {
			bool logedin = false;
			bool permission = false;
		}
		if (choice == 7) {
			return 0;
		}
		if (choice == 8) {
			if (P.payment < 222228) {
				cout << "You do not have sufficient funds for this" << endl << endl;

			}
			else {
				cout << "How many times have you been to the US?" << endl;
				int p;
				cin >> p;
				if (p > 5) {
					double  x;
					x = 222228;
					cout << "The flight date is: 30/9/2021." << endl;
					cout << "The distance is: " << 12346 << " km." << endl;
					cout << "The duration of your flight is: " << 12 << " hours." << endl;
					cout << "You have availed special flight going to America the total cost is: " << x << endl;
					cout << "Your remaining balance is: " << fixed << setprecision(1) << P.payment - x << endl << endl;
					P.payment -= x;
				}
				else {
					cout << "You have not been to the US enough times to be eligible for the special flight." << endl;
				}
			}
		}
		if (run == 0&&choice!=1) {
			balance1(P);
		}
		menu();
		cin >> choice;
		if(choice!=1)
		run++;
	}
	return 0;
}