#pragma once
#include <iostream>
#include "EconomySeats.h"
#include "BussinessSeats.h"
#include "route.h"
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

class Planes
{
public:
	string Arival;
	string departure;
	EconomySeats* A;
	BussinessSeats* B;
	route R;
	int Plane_ID;
	int Ecapacity;
	int Bcapacity;
	double Atime;
	double Dtime;
	int layover;
	string layoverName;
	string* Eseats;
	string* Bseats;
	int type;
	int day;
	int month;
	int year;
	double cost;

	Planes();
	void Display();
	void DisplaySeats();
	void times();
	void IntTime();
	void LocTime();
	void PreBooked();
	double Book();
	double change(string [10],int [10]);
	double findCost();
	friend ostream& operator << (ostream& out, const Planes& c);
};