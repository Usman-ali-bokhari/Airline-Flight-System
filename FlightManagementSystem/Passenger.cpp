#include "Passenger.h"


Passenger::Passenger():Passport() {
    CNIC = 0;
    username = "Default";
    password = "Default";
    permissions = 0;
    bookings = new string[100];
    payment = 0;

}

void Passenger::set_CNIC(int x) { CNIC = x; }
void Passenger::set_username(string s) { username = s; }
void Passenger::set_password(string s) { password = s; }
void Passenger::set_permissions(int x) { permissions = x; }
void Passenger::set_Booking(int x,int i) { bookings[i] = x; }
int Passenger::get_CNIC() { return CNIC; }
string Passenger::get_username() { return username; }
string Passenger::get_password() { return password; }
int Passenger::get_permissions() { return permissions; }
