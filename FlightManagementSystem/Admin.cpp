#include "Admin.h"

Admin::Admin():Passport() {
    CNIC = 0;
    username = "Default";
    password = "Default";
    permissions = 0;
    payment = 0;
}

void Admin::set_CNIC(int x) { CNIC = x; }
void Admin::set_username(string s) { username = s; }
void Admin::set_password(string s) { 	password = s; }
void Admin::set_permissions(int x ) { 	permissions = x; }
int Admin::get_CNIC() { return CNIC; }
string Admin::get_username() { return username; }
string Admin::get_password() { return password; }
int Admin::get_permissions() { return permissions; }

void Admin::login() {

}