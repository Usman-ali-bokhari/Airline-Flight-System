#include "Passport.h"


Passport::Passport() {
	type = 0;
	Visa = 0;
	IDPass = "";
	IDPerson = "";
}

void Passport::set_type(int x) { type = x; }
void Passport::set_Visa(int x) { Visa = x; }
void Passport::set_IDpass(string x) { IDPass = x; }
void Passport::set_IDperson(string x) { IDPerson = x; }
int Passport::get_type() { return type; }
int Passport::get_Visa() { return Visa; }
string Passport::get_IDpass() { return IDPass; }
string Passport::get_IDperson() { return IDPerson; }