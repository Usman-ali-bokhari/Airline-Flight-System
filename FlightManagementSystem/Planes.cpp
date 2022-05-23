#include "Planes.h"

string IntDest2[25] = { "USA","Australia","UK","China","Russia","Kenya","Brazil","New Zealand","Finland","Norway","Turkey",
	"UAE","Saudi Arabia","Oman","Qatar","Singapore","Italy","Spain","Germany","South Africa","Algeria","Canada","Hungry","Japan","Sweden" };

string LocalDest2[10] = { "Islamabad North","Islamabad South","Karachi North","Karachi South","Lahore North","Lahore South",
	"Peshawar North","Peshawar South","Quetta North","Quetta South" };

int Dist[25][25] = { 12300, 15000,6900,11600,8900,13700,7300,12500,7800,7200,10200,12500,12100,12800,12300,15300,8600,7600,7900,14400,8800,2300,8700,10100,7700,12300, 15000, 6900, 11600, 8900, 13700, 7300, 12500, 7800, 7200, 10200, 12500, 12100, 12800, 12300, 15300, 8600, 7600, 7900, 14400, 8800, 2300, 8700, 10100, 7700, 15000, 9200, 15000, 7500, 10000, 10600, 15600, 4163, 13400, 14400, 12500, 12000, 11000, 9900, 10500, 4400, 14400, 15700, 14400, 10500, 15300, 14200, 14000, 6800, 13800 ,6900, 15000, 6300, 7800, 5600, 7200, 9000, 18400, 1900, 1200, 3400, 5500, 5300, 5900, 5500, 11000, 1900, 7500, 1000, 9100, 1700, 5900, 1800, 9300, 1500 , 11700, 7500, 7800, 3300, 1800, 7900, 16600, 11200, 6000, 6900, 6000, 4800, 5800, 5000, 5200, 3800, 7600, 8800, 7300, 11300, 9300, 9400, 6900, 3000, 6400 ,8500, 14300, 2600, 3000, 4400, 6000, 9000, 14000, 2400, 2200, 3500, 5000, 4800, 4700, 4500, 6200, 2100, 2500, 3000, 9000, 3200, 7800, 2950, 8250, 2800,6900, 15000, 6300, 7800, 5600, 7200, 9000, 18400, 1900, 1200, 3400, 5500, 5300, 5900, 5500, 3300, 1800, 7900, 16600, 11200, 6000, 6900, 6000, 4800, 5800 ,7800, 5600, 7200, 9000, 18400, 1900, 1200, 3400, 5500, 5300, 5900, 5500, 3300, 1800, 7900, 16600, 11200, 6000, 6900, 15000, 6300, 7800, 5600, 7200, 9000,
12300, 15000, 6900, 11600, 8900, 13700, 7300, 12500, 7800, 7200, 10200, 12500, 12100, 12800, 12300, 15300, 8600, 7600, 7900, 14400, 8800, 2300, 8700, 10100, 7700, 6900, 15000, 6300, 7800, 5600, 7200, 9000, 18400, 1900, 1200, 3400, 5500, 5300, 5900, 5500, 11000, 1900, 7500, 1000, 9100, 1700, 5900, 1800, 9300, 1500 , 6900, 15000, 6300, 7800, 5600, 7200, 9000, 18400, 1900, 1200, 3400, 5500, 5300, 5900, 5500, 11000, 1900, 7500, 1000, 9100, 1700, 5900, 1800, 9300, 1500 , 7800, 5600, 7200, 9000, 18400, 1900, 1200, 3400, 5500, 5300, 5900, 5500, 3300, 1800, 7900, 16600, 11200, 6000, 6900, 15000, 6300, 7800, 5600, 7200, 9000,
9000, 12000, 4000, 3300, 4600, 3000, 5000, 11000, 6700, 5500, 5300, 5900, 5500, 3300, 1800, 7900, 16600, 11200, 6000, 6900, 15000, 6300, 7800, 5600, 5600 ,9000, 12000, 4000, 3300, 4600, 3000, 5000, 11000, 6700, 5500, 5300, 5900, 5500, 3300, 1800, 7900, 16600, 11200, 6000, 6900, 15000, 6300, 7800, 5600, 5600 , 9000, 12000, 4000, 3300, 4600, 3000, 5000, 11000, 6700, 5500, 5300, 5900, 5500, 3300, 1800, 7900, 16600, 11200, 6000, 6900, 15000, 6300, 7800, 5600, 5600 ,9000, 12000, 4000, 3300, 4600, 3000, 5000, 11000, 6700, 5500, 5300, 5900, 5500, 3300, 1800, 7900, 16600, 11200, 6000, 6900, 15000, 6300, 7800, 5600, 5600 ,
6900, 15000, 6300, 7800, 5600, 7200, 9000, 18400, 1900, 1200, 3400, 5500, 5300, 5900, 5500, 11000, 1900, 7500, 1000, 9100, 1700, 5900, 1800, 9300, 1500, 6900, 15000, 6300, 7800, 5600, 7200, 9000, 18400, 1900, 1200, 3400, 5500, 5300, 5900, 5500, 11000, 1900, 7500, 1000, 9100, 1700, 5900, 1800, 9300, 1500 , 6900, 15000, 6300, 7800, 5600, 7200, 9000, 18400, 1900, 1200, 3400, 5500, 5300, 5900, 5500, 11000, 1900, 7500, 1000, 9100, 1700, 5900, 1800, 9300, 1500 , 6900, 15000, 6300, 7800, 5600, 7200, 9000, 18400, 1900, 1200, 3400, 5500, 5300, 5900, 5500, 11000, 1900, 7500, 1000, 9100, 1700, 5900, 1800, 9300, 1500,
6900, 15000, 6300, 7800, 5600, 7200, 9000, 18400, 1900, 1200, 3400, 5500, 5300, 5900, 5500, 3300, 1800, 7900, 16600, 11200, 6000, 6900, 6000, 4800, 5800 , 6900, 15000, 6300, 7800, 5600, 7200, 9000, 18400, 1900, 1200, 3400, 5500, 5300, 5900, 5500, 11000, 1900, 7500, 1000, 9100, 1700, 5900, 1800, 9300, 1500,
6900, 15000, 6300, 7800, 5600, 7200, 9000, 18400, 1900, 1200, 3400, 5500, 5300, 5900, 5500, 11000, 1900, 7500, 1000, 9100, 1700, 5900, 1800, 9300, 1500 , 12300, 15000, 6900, 11600, 8900, 13700, 7300, 12500, 7800, 7200, 10200, 12500, 12100, 12800, 12300, 15300, 8600, 7600, 7900, 14400, 8800, 2300, 8700, 10100, 7700,
6900, 15000, 6300, 7800, 5600, 7200, 9000, 18400, 1900, 1200, 3400, 5500, 5300, 5900, 5500, 11000, 1900, 7500, 1000, 9100, 1700, 5900, 1800, 9300, 1500 };

Planes::Planes() {
	day = 21;
	month = 6;
	year = 2021;
	Arival = "";
	departure = "";
	A = new EconomySeats[50];
	B = new BussinessSeats[10];
	Plane_ID = rand()%999+1;
	Ecapacity = 25;
	Bcapacity = 5;
	Atime = 0.00;
	Dtime = 0.00;
	layover = -1;
	layoverName = "";
	Eseats = new string[50];
	Bseats = new string[10];
	type = 0;
}

void Planes::Display()
{
	const char separator = '-';
	const int nameWidth = 16;
	const int numWidth = 20;
	cout<<"    ";
	cout << left << "| " << setfill(' ');
	cout<<Plane_ID;
	if (Plane_ID < 10)
		cout << setw(5) << "";
	else if (Plane_ID>=100)
		cout << setw(3) << "";
	else
		cout << setw(4) << "";

	cout <<departure;
	const int s =departure.length();
	cout << setw(20 - s) << "";
	cout << Arival;
	const int f = Arival.length();
	cout << setw(20 - f) << "";
	cout << setprecision(3) <<"Arrival time: " << Atime;
	cout << endl;
	cout << setw(52) << "";
	cout << setprecision(3) <<"Departure time: " << Dtime;
	if (layover != -1) {
		cout << endl;
		cout << setw(52) << "";
		cout << "Layover: " << layoverName;
	}
	cout << endl;
	cout << setw(52) << "";
	cout << day << "/" << month << "/" << year << endl;
	cout << left << endl << endl;

}

void Planes::DisplaySeats()
{
	int p = 0;
	for (int i = 0; i < 8; i++) {
		cout << "\t|  ";
		for (int j = 0; j < 6; j++) {
			cout << Eseats[p] << " ";
			p++;
		}
		cout << "  |";
		cout<<endl;
	}
	cout << "\t|      " << Eseats[48] << "  " << Eseats[49] << "     |" << endl;
	cout << "  -----------------Business-----------------" << endl;

	for (int i = 0; i < 2; i++) {
		cout << "\t|  ";
		for (int j = i * 4; j < 4 + (i * 4); j++) {
			cout << Bseats[j] << "  ";
		}
		cout << "  |";
		cout << endl;
	}
	cout << "\t|      " << Bseats[8] << "  " << Bseats[9] << "     |" << endl;
}

void Planes::times() {
	if (Dtime == 0) {
		Dtime = Atime - 2;
	}
	if (Atime == 0) {
		Atime = Dtime + 2;
	}

	if (Atime > 24) {
		Atime -= 4;
		Dtime -= 4;
	}
	if (Dtime < 0) {
		Atime += 4;
		Dtime += 4;
	}
}

void Planes::IntTime() {
	int distance = 0;
	int l = 0;
	for (int i = 0; i < 25; i++) {
		if (layover != -1) {
			if (IntDest2[i] == layoverName) {
				distance += Dist[i][i];
				l = i;
			}
		}
		if (IntDest2[i] == Arival) {
			if(l!=0)
			distance += Dist[l][i];
			else {
				distance += Dist[i][i];
			}
			
		}
	}
	Atime = Dtime+(distance / 1000);
	if (Arival == "Hungry") {
		Atime += 6;
	}

}

void Planes::LocTime()
{
	if (departure == "Islamabad North"|| departure == "Islamabad South") {
		if (Arival == "Karachi North" || Arival == "Karachi South") {
			Atime = Dtime + 1.5;
		}
		else if (Arival == "Lahore North" || Arival == "Lahore South") {
			Atime = Dtime + 1;
		}
		else if (Arival == "Peshawar North" || Arival == "Peshawar South") {
			Atime = Dtime + 0.15;
		}
		else if (Arival == "Quetta North" || Arival == "Quetta South") {
			Atime = Dtime + 1.4;
		}
	}
	else if (departure == "Karachi North" || departure == "Karachi South") {
		if (Arival == "Islamabad North" || Arival == "Islamabad South") {
			Atime = Dtime + 1.5;
		}
		else if (Arival == "Lahore North" || Arival == "Lahore South") {
			Atime = Dtime + 1;
		}
		else if (Arival == "Peshawar North" || Arival == "Peshawar South") {
			Atime = Dtime + 1.4;
		}
		else if (Arival == "Quetta North" || Arival == "Quetta South") {
			Atime = Dtime + 1.2;
		}
	}
	else if (departure == "Lahore North" || departure == "Lahore South") {
		if (Arival == "Islamabad North" || Arival == "Islamabad South") {
			Atime = Dtime + 1;
		}
		else if (Arival == "Karachi North" || Arival == "Karachi South") {
			Atime = Dtime + 1;
		}
		else if (Arival == "Peshawar North" || Arival == "Peshawar South") {
			Atime = Dtime + 1.2;
		}
		else if (Arival == "Quetta North" || Arival == "Quetta South") {
			Atime = Dtime + 1.4;
		}
	}
	else if (departure == "Peshawar North" || departure == "Peshawar South") {
		if (Arival == "Islamabad North" || Arival == "Islamabad South") {
			Atime = Dtime + 0.15;
		}
		else if (Arival == "Karachi North" || Arival == "Karachi South") {
			Atime = Dtime + 1.5;
		}
		else if (Arival == "Lahore North" || Arival == "Lahore South") {
			Atime = Dtime + 1;
		}
		else if (Arival == "Quetta North" || Arival == "Quetta South") {
			Atime = Dtime + 1.4;
		}
	}
	else if (Arival == "Quetta North" || Arival == "Quetta South") {
		if (Arival == "Islamabad North" || Arival == "Islamabad South") {
			Atime = Dtime + 1.2;
		}
		else if (Arival == "Karachi North" || Arival == "Karachi South") {
			Atime = Dtime + 1.2;
		}
		else if (Arival == "Lahore North" || Arival == "Lahore South") {
			Atime = Dtime + 1;
		}
		else if (departure == "Peshawar North" || departure == "Peshawar South") {
			Atime = Dtime + 1.4;
		}
	}

	if (Atime > 24) {
		day++;
		Atime = Atime - 24;
		if (Dtime > 24) {
			Dtime = Dtime - 24;
		}
	}
}

void Planes::PreBooked() {
	int x = rand() %5+10;
	for (int i = 0; i < 50; i++) {
		Eseats[i] = to_string(i);
	}
	for (int i = 0; i < 50; i++) {
		if(i%2!=0)
			Eseats[i] = "*";
	}
	for (int i = 0; i < x; i++) {
		int c = rand() % 50;
		while (Eseats[c]=="*"||Eseats[c]=="x")
		{
			c = rand() % 50;
		}
		Eseats[c] = "x";
	}

	x = rand() % 5;
	for (int i = 0; i < 10; i++) {
		Bseats[i] = to_string(i + 50);
	}
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
			Bseats[i] = "*";
	}
	for (int i = 0; i < x; i++) {
		int c = rand() % 9;
		while (Bseats[c] == "*" || Bseats[c] == "x")
		{
			c = rand() % 9;
		}
		Bseats[c] = "x";
	}
}

double Planes::Book()
{
	DisplaySeats();
	cout << "Which flight would you like to book: ";
	int x;
	cin >> x;
	while (x) {
		if ((Eseats[x] == "x" || Eseats[x] == "*") || (x >= 50 && (Bseats[x] == "x" || Bseats[x] == "*")) ) {
			cout << "This seat is not available for booking... Please try another one: ";
			cin >> x;
		}
		else {
			cout << "Booking your seat........" << endl;
			cout << "Seat Booked." << endl;
			if (x >= 50) {
				x -= 50;
				Bseats[x] = "x";
			}
			else
			Eseats[x] = "x";

			x = 0;
		}
	}
	cout << "Seats after Booking: " << endl << endl;
	DisplaySeats();
	cout << "The total cost of your flight will be: " <<fixed << setprecision(6)<< findCost() << endl;
	return findCost();
}



double Planes::change(string Covid[10],int cov[10])
{
	cout << "Where would you like this plane to go?" << endl;
	int x;
	if (type == 0) {
		cout << "Since this is a local flying plane, select a local flight to re-route this to: " << endl;
		for (int i = 0; i < 10; i++) {
			cout << i + 1 << ". " << LocalDest2[i] << endl;
		}
		cin >> x;
		while (x < 0 || x>10) {
			cout << "Invalid input: Try again." << endl;
			cin >> x;
		}
		Arival = IntDest2[x];
		cout << "Please set departure time (in the format 1.10 for 1:10 am and 14.20 for 2:20 pm): ";
		cin >> Dtime;
		LocTime();
	}
	else {
		cout << "Since this is a International flying plane, select a International flight to re-route this to: " << endl;
		for (int i = 0; i < 25; i++) {
			if (i == cov[0] || i == cov[1] || i == cov[2] || i == cov[3] || i == cov[4] || i == cov[5] || i == cov[6] || i == cov[7] || i == cov[8] || i == cov[9]) {
				continue;
			}
			else
				cout << i + 1 << ". " << IntDest2[i] << endl;
		}
		cin >> x;
		x--;
		while ((x < 0 || x>25)&&( x == cov[0] || x == cov[1] || x == cov[2] || x == cov[3] || x == cov[4] || x == cov[5] || x == cov[6] || x == cov[7] || x == cov[8] || x == cov[9])) {
			cout << "Invalid input: Try again." << endl;
			cin >> x;
			x--;
		}
		Arival = IntDest2[x];
		cout << "Would you like to add a layover or not?(Y/N)" << endl;
		char cha;
		cin >> cha;
		while (cha != 'Y' && cha != 'y' && cha != 'N' && cha != 'n') {
			cin.ignore(10000, '\n');
			cout << "Invalid input: enter either y or n" << endl;
			cin >> cha;
		}
		if (cha == 'y' || cha == 'Y') {
			cout << "Select layover country: " << endl;
			for (int i = 0; i < 25; i++) {
				if (i == cov[0] || i == cov[1] || i == cov[2] || i == cov[3] || i == cov[4] || i == cov[5] || i == cov[6] || i == cov[7] || i == cov[8] || i == cov[9]) {
					continue;
				}
				else
					cout << i + 1 << ". " << IntDest2[i] << endl;
			}
			int g;
			cin >> g;
			g--;
			layoverName = IntDest2[g];
			layover = g;
		}
		cout << "Please set departure time (in the format 1.10 for 1:10 am and 14.20 for 2:20 pm): ";
		cin >> Dtime;
		IntTime();
	}

	cout << "Flight set!!" << endl;
	Display();
	return findCost();
}

double Planes::findCost()
{
	double coster=0;
	double x = 0;
	if (day > 21) {
		x = Atime + 24 - Dtime;
	}
	else {
		x = Atime - Dtime;
	}

	if (type == 0) {
		coster = x * 10000 * 0.95;
	}
	else if (type == 1) {
		coster = x * 20000 * 0.9;
	}
	cost = coster;
	return coster;
}

ostream& operator<<(ostream& out, const Planes& c)
{
	out << "Your total cost was: ";
	out << c.cost;
	return out;
}
