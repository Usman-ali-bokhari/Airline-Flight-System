#pragma once
#include <iostream>
using namespace std;

class Passport
{
public:
	int type;
	int Visa;
	string IDPass;
	string IDPerson; 

	Passport();

	void set_type(int);
	void set_Visa(int);
	void set_IDpass(string);
	void set_IDperson(string);
	int get_type();
	int get_Visa();
	string get_IDpass();
	string get_IDperson();
};

