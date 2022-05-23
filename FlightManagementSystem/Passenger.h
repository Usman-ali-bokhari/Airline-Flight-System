#pragma once
#include "Passport.h"
#include <iostream>
using namespace std;

class Passenger :
    public Passport
{
public:
    int CNIC;
    string username;
    string password;
    int permissions;
    string* bookings;
    int payment;

    Passenger();
    

    void set_CNIC(int);
    void set_username(string);
    void set_password(string);
    void set_permissions(int);
    void set_Booking(int,int);
    int get_CNIC();
    string get_username();
    string get_password();
    int get_permissions();
};

