#pragma once

#include <iostream>
#include <string>
#include "Passport.h"
using namespace std;

class Admin :public Passport 
{
public:
	int CNIC;
	string username;
	string password;
	int permissions;
	int payment;

	Admin();

	void set_CNIC(int);
	void set_username(string);
	void set_password(string);
	void set_permissions(int);
	int get_CNIC();
	string get_username();
	string get_password();
	int get_permissions();
	void login();

};

