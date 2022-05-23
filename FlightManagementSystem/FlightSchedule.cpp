#include "FlightSchedule.h"
using namespace std;

string IntDest[25] = { "USA","Australia","UK","China","Russia","Kenya","Brazil","New Zealand","Finland","Norway","Turkey","UAE","Saudi Arabia","Oman","Qatar","Singapore","Italy","Spain","Germany","South Africa","Algeria","Canada","Hungary","Japan","Sweden" };
string LocalDest[10] = { "Islamabad North","Islamabad South","Karachi North","Karachi South","Lahore North","Lahore South","Peshawar North","Peshawar South","Quetta North","Quetta South" };



FlightSchedule::FlightSchedule() {
	IslamabadN = new Planes[15];
	IslamabadS = new Planes[15];
	LahoreN = new Planes[15];
	LahoreS = new Planes[15];
	KarachiN = new Planes[15];
	KarachiS = new Planes[15];
	QetttaN = new Planes[15];
	QetttaS = new Planes[15];
	PeshawarN = new Planes[15];
	PeshawarS = new Planes[15];


	TimesIslamabadN = new double*[2];
	TimesIslamabadS = new double*[2];
	TimesLahoreN = new double*[2];
	TimesLahoreS = new double*[2];
	TimesKarachiN = new double*[2];
	TimesKarachiS = new double*[2];
	TimesQetttaN = new double*[2];
	TimesQetttaS = new double*[2];
	TimesPeshawarN = new double*[2];
	TimesPeshawarS = new double*[2];



	for (int i = 0; i < 2; i++) {
		TimesIslamabadN[i] = new double[144];
		TimesIslamabadS[i] = new double[144];
		TimesLahoreN[i] = new double[144];
		TimesLahoreS[i] = new double[144];
		TimesKarachiN[i] = new double[144];
		TimesKarachiS[i] = new double[144];
		TimesQetttaN[i] = new double[144];
		TimesQetttaS[i] = new double[144];
		TimesPeshawarN[i] = new double[144];
		TimesPeshawarS[i] = new double[144];
	}

	double x = 0;
	int count = 0;
	for (int i = 0; i < 144; i++) {
		int l = int(x);
		if (count==6) {
			x+=0.4;
			count = 0;
		}
		TimesIslamabadN[1][i] = 0;
		TimesIslamabadN[0][i] = x;
		TimesIslamabadS[1][i] = 0;
		TimesIslamabadS[0][i] = x;
		TimesLahoreN[1][i] = 0;
		TimesLahoreN[0][i] = x;
		TimesLahoreS[1][i] = 0;
		TimesLahoreS[0][i] = x;
		TimesKarachiN[1][i] = 0;
		TimesKarachiN[0][i] = x;
		TimesKarachiS[1][i] = 0;
		TimesKarachiS[0][i] = x;
		TimesQetttaN[1][i] = 0;
		TimesQetttaN[0][i] = x;
		TimesQetttaS[1][i] = 0;
		TimesQetttaS[0][i] = x;
		TimesPeshawarN[1][i] = 0;
		TimesPeshawarN[0][i] = x;
		TimesPeshawarS[1][i] = 0;
		TimesPeshawarS[0][i] = x;
		x += 0.100000;
		count++;
	}

	covid = new string[10];
	Cov = new int[10];
	for (int i = 5; i < 10; i++) {
		covid[i] = "";
		Cov[i] = -1;
	}
	int l[10];
	int y = 0;
	for (int i = 0; i < 5; i++) {
		y = rand() % 24;
		int count = 1;
		while (y == l[0] || y == l[1] || y == l[2] || y == l[3] ||y==l[4]){
			y = rand() % 24;
		}
		l[i] = y;

	}
	for (int i = 0; i < 5; i++) {
		covid[i] = IntDest[l[i]];
		Cov[i] = l[i];
	}

}

void FlightSchedule::GenSchedule() {

	int khiN = 0;
	int khiS = 0;
	int lhrN = 0;
	int lhrS = 0;
	int pshN = 0; 
	int pshS = 0; 
	int qutN = 0; 
	int qutS = 0; 
	int islN = 0; 
	int islS = 0; 

	{
		for (int i = 0; i < 15; i++) {
			IslamabadN[i].departure = LocalDest[0];
		}

		for (int i = 0; i < 15; i++) {
			IslamabadS[i].departure = LocalDest[1];
		}

		for (int i = 0; i < 15; i++) {
			KarachiN[i].departure = LocalDest[2];
		}

		for (int i = 0; i < 15; i++) {
			KarachiS[i].departure = LocalDest[3];
		}

		for (int i = 0; i < 15; i++) {
			LahoreN[i].departure = LocalDest[4];
		}

		for (int i = 0; i < 15; i++) {
			LahoreS[i].departure = LocalDest[5];
		}

		for (int i = 0; i < 15; i++) {
			PeshawarN[i].departure = LocalDest[6];
		}

		for (int i = 0; i < 15; i++) {
			PeshawarS[i].departure = LocalDest[7];
		}

		for (int i = 0; i < 15; i++) {
			QetttaN[i].departure = LocalDest[8];
		}

		for (int i = 0; i < 15; i++) {
			QetttaS[i].departure = LocalDest[9];
		}
	}
	int j;
	for (int i = 0; i < 10; i++) {
		j = rand() % 7+2;
		IslamabadN[i].Arival = LocalDest[j];
		int time = rand() % 144;

		if (j == 2&&khiN<10) {

			while (TimesKarachiN[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadN[i].Atime = TimesKarachiN[0][time];
			IslamabadN[i].Dtime = IslamabadN[i].Atime - 2;
			TimesKarachiN[1][time]++;

			KarachiN[khiN].Dtime = TimesIslamabadN[0][time] + 2.0;
			KarachiN[khiN].departure = LocalDest[j];
			KarachiN[khiN].Arival = LocalDest[0];
			KarachiN[khiN].Plane_ID = IslamabadN[i].Plane_ID;

			khiN++;
		}
		if (j == 3&&khiS<10) {

			while (TimesKarachiS[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadN[i].Atime = TimesKarachiS[0][time];
			IslamabadN[i].Dtime = IslamabadN[i].Atime - 2;
			TimesKarachiS[1][time]++;

			KarachiS[khiS].Dtime = TimesIslamabadN[0][time] + 2.0;
			KarachiS[khiS].departure = LocalDest[j];
			KarachiS[khiS].Arival = LocalDest[0];
			KarachiS[khiS].Plane_ID = IslamabadN[i].Plane_ID;

			khiS++;
		}
		if (j == 4&&lhrN<10) {

			while (TimesLahoreN[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadN[i].Atime = TimesLahoreN[0][time];
			IslamabadN[i].Dtime = IslamabadN[i].Atime - 1;
			TimesLahoreN[1][time]++;

			LahoreN[lhrN].Dtime = TimesIslamabadN[0][time] + 2.0;
			LahoreN[lhrN].departure = LocalDest[j];
			LahoreN[lhrN].Arival = LocalDest[0];
			LahoreN[lhrN].Plane_ID = IslamabadN[i].Plane_ID;

			lhrN++;
		}
		if (j == 5&&lhrS<10) {

			while (TimesLahoreS[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadN[i].Atime = TimesLahoreS[0][time];
			IslamabadN[i].Dtime = IslamabadN[i].Atime - 1;
			TimesLahoreS[1][time]++;

			LahoreS[lhrN].Dtime = TimesIslamabadN[0][time] + 2.0;
			LahoreS[lhrN].departure = LocalDest[j];
			LahoreS[lhrN].Arival = LocalDest[0];
			LahoreS[lhrN].Plane_ID = IslamabadN[i].Plane_ID;

			lhrS++;
		}
		if (j == 6&&pshN<10) {

			while (TimesPeshawarN[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadN[i].Atime = TimesPeshawarN[0][time];
			IslamabadN[i].Dtime = IslamabadN[i].Atime - 0.15;
			TimesPeshawarN[1][time]++;

			PeshawarN[pshN].Dtime = TimesIslamabadN[0][time] + 2.0;
			PeshawarN[pshN].departure = LocalDest[j];
			PeshawarN[pshN].Arival = LocalDest[0];
			PeshawarN[pshN].Plane_ID = IslamabadN[i].Plane_ID;

			pshN++;
		}
		if (j == 7&&pshS<10) {

			while (TimesPeshawarS[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadN[i].Atime = TimesPeshawarS[0][time];
			IslamabadN[i].Dtime = IslamabadN[i].Atime - 0.15;
			TimesPeshawarS[1][time]++;

			PeshawarS[pshS].Dtime = TimesIslamabadN[0][time] + 2.0;
			PeshawarS[pshS].departure = LocalDest[j];
			PeshawarS[pshS].Arival = LocalDest[0];
			PeshawarS[pshS].Plane_ID = IslamabadN[i].Plane_ID;

			pshS++;
		}
		if (j == 8&&qutN<10) {

			while (TimesQetttaN[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadN[i].Atime = TimesQetttaN[0][time];
			IslamabadN[i].Dtime = IslamabadN[i].Atime - 1.02;
			TimesQetttaN[1][time]++;

			QetttaN[qutN].Dtime = TimesIslamabadN[0][time] + 2.0;
			QetttaN[qutN].departure = LocalDest[j];
			QetttaN[qutN].Arival = LocalDest[0];
			QetttaN[qutN].Plane_ID = IslamabadN[i].Plane_ID;

			qutN++;
		}
		if (j == 9&&qutS<10) {

			while (TimesQetttaS[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadN[i].Atime = TimesQetttaS[0][time];
			IslamabadN[i].Dtime = IslamabadN[i].Atime - 1.02;
			TimesQetttaS[1][time]++;

			QetttaS[qutS].Dtime = TimesIslamabadN[0][time]+ 2.0;
			QetttaS[qutS].departure = LocalDest[j];
			QetttaS[qutS].Arival = LocalDest[0];
			QetttaS[qutS].Plane_ID = IslamabadN[i].Plane_ID;

			qutS++;
		}
		j++;
	}
	
	j = 10;


	for (int i = islS; i < 10; i++) {
		j = rand() % 7+2;
		IslamabadS[i].Arival = LocalDest[j];
		int time = rand() % 144;
		if (j == 2&&khiN<10) {

			while (TimesKarachiN[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadS[i].Atime = TimesKarachiN[0][time];
			IslamabadS[i].Dtime = IslamabadS[i].Atime - 2;
			TimesKarachiN[1][time]++;

			KarachiN[khiN].Dtime = TimesIslamabadS[0][time] + 2.0;
			KarachiN[khiN].departure = LocalDest[j];
			KarachiN[khiN].Arival = LocalDest[1];
			KarachiN[khiN].Plane_ID = IslamabadS[i].Plane_ID;

			khiN++;
		}
		if (j == 3&&khiS<10) {

			while (TimesKarachiS[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadS[i].Atime = TimesKarachiS[0][time];
			IslamabadS[i].Dtime = IslamabadS[i].Atime - 2;
			TimesKarachiS[1][time]++;

			KarachiS[khiS].Dtime = TimesIslamabadS[0][time] + 2.0;
			KarachiS[khiS].departure = LocalDest[j];
			KarachiS[khiS].Arival = LocalDest[1];
			KarachiS[khiS].Plane_ID = IslamabadS[i].Plane_ID;

			khiS++;
		}
		if (j == 4&&lhrN<10) {

			while (TimesLahoreN[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadS[i].Atime = TimesLahoreN[0][time];
			IslamabadS[i].Dtime = IslamabadS[i].Atime - 1;
			TimesLahoreN[1][time]++;

			LahoreN[lhrN].Dtime = TimesIslamabadS[0][time] + 2.0;
			LahoreN[lhrN].departure = LocalDest[j];
			LahoreN[lhrN].Arival = LocalDest[1];
			LahoreN[lhrN].Plane_ID = IslamabadS[i].Plane_ID;

			lhrN++;
		}
		if (j == 5&&lhrS<10) {

			while (TimesLahoreS[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadS[i].Atime = TimesLahoreS[0][time];
			IslamabadS[i].Dtime = IslamabadS[i].Atime - 1;
			TimesLahoreS[1][time]++;

			LahoreS[lhrS].Dtime = TimesIslamabadS[0][time] + 2.0;
			LahoreS[lhrS].departure = LocalDest[j];
			LahoreS[lhrS].Arival = LocalDest[1];
			LahoreS[lhrS].Plane_ID = IslamabadS[i].Plane_ID;

			lhrS++;
		}
		if (j == 6&&pshN<10) {

			while (TimesPeshawarN[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadS[i].Atime = TimesPeshawarN[0][time];
			IslamabadS[i].Dtime = IslamabadS[i].Atime - 0.15;
			TimesPeshawarN[1][time]++;

			PeshawarN[pshN].Dtime = TimesIslamabadS[0][time] + 2.0;
			PeshawarN[pshN].departure = LocalDest[j];
			PeshawarN[pshN].Arival = LocalDest[1];
			PeshawarN[pshN].Plane_ID = IslamabadS[i].Plane_ID;

			pshN++;
		}
		if (j == 7&&pshS<10) {

			while (TimesPeshawarS[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadS[i].Atime = TimesPeshawarS[0][time];
			IslamabadS[i].Dtime = IslamabadS[i].Atime - 0.15;
			TimesPeshawarS[1][time]++;

			PeshawarS[pshS].Dtime = TimesIslamabadS[0][time] + 2.0;
			PeshawarS[pshS].departure = LocalDest[j];
			PeshawarS[pshS].Arival = LocalDest[1];
			PeshawarS[pshS].Plane_ID = IslamabadS[i].Plane_ID;

			pshS++;
		}
		if (j == 8&&qutN<10) {

			while (TimesQetttaN[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadS[i].Atime = TimesQetttaN[0][time];
			IslamabadS[i].Dtime = IslamabadS[i].Atime - 1.02;
			TimesQetttaN[1][time]++;

			QetttaN[qutN].Dtime = TimesIslamabadS[0][time] + 2.0;
			QetttaN[qutN].departure = LocalDest[j];
			QetttaN[qutN].Arival = LocalDest[1];
			QetttaN[qutN].Plane_ID = IslamabadS[i].Plane_ID;

			qutN++;
		}
		if (j == 9&&qutS<10) {

			while (TimesQetttaS[1][time] >= 5) {
				time = rand() % 144;
			}
			IslamabadS[i].Atime = TimesQetttaS[0][time];
			IslamabadS[i].Dtime = IslamabadS[i].Atime - 1.02;
			TimesQetttaS[1][time]++;

			QetttaS[qutS].Dtime = TimesIslamabadS[0][time]+ 2.0;
			QetttaS[qutS].departure = LocalDest[j];
			QetttaS[qutS].Arival = LocalDest[1];
			QetttaS[qutS].Plane_ID = IslamabadS[i].Plane_ID;

			qutS++;
		}
		j++;
	}

	for (int i = khiN; i < 10; i++) {
		j = rand()%9;
		while(j==2||j==3)
			j = rand() % 9;
		KarachiN[i].Arival = LocalDest[j];
		int time = rand() % 144;

		if (j == 0) {

			while (TimesIslamabadN[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiN[i].Atime = TimesIslamabadN[0][time];
			KarachiN[i].Dtime = KarachiN[i].Atime - 2;
			TimesIslamabadN[1][time]++;
		}		
		if (j == 1) {

			while (TimesIslamabadS[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiN[i].Atime = TimesIslamabadS[0][time];
			KarachiN[i].Dtime = KarachiN[i].Atime - 2;
			TimesIslamabadS[1][time]++;
		}

		if (j == 4&&lhrN<10) {

			while (TimesLahoreN[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiN[i].Atime = TimesLahoreN[0][time];
			KarachiN[i].Dtime = KarachiN[i].Atime - 1.5;
			TimesLahoreN[1][time]++;

			LahoreN[lhrN].Dtime = TimesKarachiN[0][time] + 2.0;
			LahoreN[lhrN].departure = LocalDest[j];
			LahoreN[lhrN].Arival = LocalDest[2];
			LahoreN[lhrN].Plane_ID = KarachiN[i].Plane_ID;

			lhrN++;
		}
		if (j == 5&&lhrS<10) {

			while (TimesLahoreS[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiN[i].Atime = TimesLahoreS[0][time];
			KarachiN[i].Dtime = KarachiN[i].Atime - 1.5;
			TimesLahoreS[1][time]++;

			LahoreS[lhrS].Dtime = TimesKarachiN[0][time] + 2.0;
			LahoreS[lhrS].departure = LocalDest[j];
			LahoreS[lhrS].Arival = LocalDest[2];
			LahoreS[lhrS].Plane_ID = KarachiN[i].Plane_ID;

			lhrS++;
		}
		if (j == 6&&pshN<10) {

			while (TimesPeshawarN[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiN[i].Atime = TimesPeshawarN[0][time];
			KarachiN[i].Dtime = KarachiN[i].Atime - 1.6;
			TimesPeshawarN[1][time]++;

			PeshawarN[pshN].Dtime = TimesKarachiN[0][time] + 2.0;
			PeshawarN[pshN].departure = LocalDest[j];
			PeshawarN[pshN].Arival = LocalDest[2];
			PeshawarN[pshN].Plane_ID = KarachiN[i].Plane_ID;

			pshN++;
		}
		if (j == 7&&pshS<10) {

			while (TimesPeshawarS[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiN[i].Atime = TimesPeshawarS[0][time];
			KarachiN[i].Dtime = KarachiN[i].Atime - 1.6;
			TimesPeshawarS[1][time]++;

			PeshawarS[pshS].Dtime = TimesKarachiN[0][time] + 2.0;
			PeshawarS[pshS].departure = LocalDest[j];
			PeshawarS[pshS].Arival = LocalDest[2];
			PeshawarS[pshS].Plane_ID = KarachiN[i].Plane_ID;

			pshS++;
		}
		if (j == 8&&qutN<10) {

			while (TimesQetttaN[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiN[i].Atime = TimesQetttaN[0][time];
			KarachiN[i].Dtime = KarachiN[i].Atime - 1.4;
			TimesQetttaN[1][time]++;

			QetttaN[qutN].Dtime = TimesKarachiN[0][time] + 2.0;
			QetttaN[qutN].departure = LocalDest[j];
			QetttaN[qutN].Arival = LocalDest[2];
			QetttaN[qutN].Plane_ID = KarachiN[i].Plane_ID;

			qutN++;
		}
		if (j == 9&&qutS<10) {

			while (TimesQetttaS[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiN[i].Atime = TimesQetttaS[0][time];
			KarachiN[i].Dtime = KarachiN[i].Atime - 1.4;
			TimesQetttaS[1][time]++;

			QetttaS[qutS].Dtime = TimesKarachiN[0][time]+ 2.0;
			QetttaS[qutS].departure = LocalDest[j];
			QetttaS[qutS].Arival = LocalDest[2];
			QetttaS[qutS].Plane_ID = KarachiN[i].Plane_ID;

			qutS++;
		}
		j++;
	}

	for (int i = khiS; i < 10; i++) {
		j = rand() % 9;
		while (j == 2 || j == 3)
			j = rand() % 9;
		KarachiS[i].Arival = LocalDest[j];
		int time = rand() % 144;

		if (j == 0) {

			while (TimesIslamabadN[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiS[i].Atime = TimesIslamabadN[0][time];
			KarachiS[i].Dtime = KarachiS[i].Atime - 2;
			TimesIslamabadN[1][time]++;
		}
		if (j == 1) {

			while (TimesIslamabadS[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiS[i].Atime = TimesIslamabadS[0][time];
			KarachiS[i].Dtime = KarachiS[i].Atime - 2;
			TimesIslamabadS[1][time]++;
		}

		if (j == 4&&lhrN<10) {

			while (TimesLahoreN[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiS[i].Atime = TimesLahoreN[0][time];
			KarachiS[i].Dtime = KarachiS[i].Atime - 1.5;
			TimesLahoreN[1][time]++;

			LahoreN[lhrN].Dtime = TimesKarachiS[0][time] + 2.0;
			LahoreN[lhrN].departure = LocalDest[j];
			LahoreN[lhrN].Arival = LocalDest[3];
			LahoreN[lhrN].Plane_ID = KarachiS[i].Plane_ID;

			lhrN++;
		}
		if (j == 5&&lhrS<10) {

			while (TimesLahoreS[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiS[i].Atime = TimesLahoreS[0][time];
			KarachiS[i].Dtime = KarachiS[i].Atime - 1.5;
			TimesLahoreS[1][time]++;

			LahoreS[lhrS].Dtime = TimesKarachiS[0][time] + 2.0;
			LahoreS[lhrS].departure = LocalDest[j];
			LahoreS[lhrS].Arival = LocalDest[3];
			LahoreS[lhrS].Plane_ID = KarachiS[i].Plane_ID;

			lhrS++;
		}
		if (j == 6&&pshN<10) {

			while (TimesPeshawarN[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiS[i].Atime = TimesPeshawarN[0][time];
			KarachiS[i].Dtime = KarachiS[i].Atime - 1.6;
			TimesPeshawarN[1][time]++;

			PeshawarN[pshN].Dtime = TimesKarachiS[0][time] + 2.0;
			PeshawarN[pshN].departure = LocalDest[j];
			PeshawarN[pshN].Arival = LocalDest[3];
			PeshawarN[pshN].Plane_ID = KarachiS[i].Plane_ID;

			pshN++;
		}
		if (j == 7&&pshS<10) {

			while (TimesPeshawarS[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiS[i].Atime = TimesPeshawarS[0][time];
			KarachiS[i].Dtime = KarachiS[i].Atime - 1.6;
			TimesPeshawarS[1][time]++;

			PeshawarS[pshS].Dtime = TimesKarachiS[0][time] + 2.0;
			PeshawarS[pshS].departure = LocalDest[j];
			PeshawarS[pshS].Arival = LocalDest[3];
			PeshawarS[pshS].Plane_ID = KarachiS[i].Plane_ID;

			pshS++;
		}
		if (j == 8&&qutN<10) {

			while (TimesQetttaN[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiS[i].Atime = TimesQetttaN[0][time];
			KarachiS[i].Dtime = KarachiS[i].Atime - 1.15;
			TimesQetttaN[1][time]++;

			QetttaN[qutN].Dtime = TimesKarachiS[0][time] + 2.0;
			QetttaN[qutN].departure = LocalDest[j];
			QetttaN[qutN].Arival = LocalDest[3];
			QetttaN[qutN].Plane_ID = KarachiS[i].Plane_ID;

			qutN++;
		}
		if (j == 9&&qutS<10) {

			while (TimesQetttaS[1][time] >= 5) {
				time = rand() % 144;
			}
			KarachiS[i].Atime = TimesQetttaS[0][time];
			KarachiS[i].Dtime = KarachiS[i].Atime - 1.15;
			TimesQetttaS[1][time]++;

			QetttaS[qutS].Dtime = TimesKarachiS[0][time]+ 2.0;
			QetttaS[qutS].departure = LocalDest[j];
			QetttaS[qutS].Arival = LocalDest[3];
			QetttaS[qutS].Plane_ID = KarachiS[i].Plane_ID;

			qutS++;
		}
		j++;
	}

	for (int i = lhrS; i < 10; i++) {
		j = rand() %9;
		while (j == 4 || j == 5)
			j = rand() % 9;
		LahoreS[i].Arival = LocalDest[j];
		int time = rand() % 144;

		if (j == 0) {

			while (TimesIslamabadN[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreS[i].Atime = TimesIslamabadN[0][time];
			LahoreS[i].Dtime = LahoreS[i].Atime - 1;
			TimesIslamabadN[1][time]++;
		}
		if (j == 1) {

			while (TimesIslamabadS[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreS[i].Atime = TimesIslamabadS[0][time];
			LahoreS[i].Dtime = LahoreS[i].Atime - 1;
			TimesIslamabadS[1][time]++;
		}

		if (j == 2) {

			while (TimesKarachiN[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreS[i].Atime = TimesKarachiN[0][time];
			LahoreS[i].Dtime = LahoreS[i].Atime - 1.5;
			TimesKarachiN[1][time]++;
		}
		if (j == 3) {

			while (TimesKarachiS[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreS[i].Atime = TimesKarachiS[0][time];
			LahoreS[i].Dtime = LahoreS[i].Atime - 1.5;
			TimesKarachiS[1][time]++;
		}

		
		if (j == 6&&pshN<10) {

			while (TimesPeshawarN[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreS[i].Atime = TimesPeshawarN[0][time];
			LahoreS[i].Dtime = LahoreS[i].Atime - 1;
			TimesPeshawarN[1][time]++;

			PeshawarN[pshN].Dtime = TimesLahoreS[0][time] + 2.0;
			PeshawarN[pshN].departure = LocalDest[j];
			PeshawarN[pshN].Arival = LocalDest[4];
			PeshawarN[pshN].Plane_ID = LahoreS[i].Plane_ID;

			pshN++;
		}
		if (j == 7&&pshS<10) {

			while (TimesPeshawarS[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreS[i].Atime = TimesPeshawarS[0][time];
			LahoreS[i].Dtime = LahoreS[i].Atime - 1;
			TimesPeshawarS[1][time]++;

			PeshawarS[pshS].Dtime = TimesLahoreS[0][time] + 2.0;
			PeshawarS[pshS].departure = LocalDest[j];
			PeshawarS[pshS].Arival = LocalDest[4];
			PeshawarS[pshS].Plane_ID = LahoreS[i].Plane_ID;

			pshS++;
		}
		if (j == 8&&qutN<10) {

			while (TimesQetttaN[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreS[i].Atime = TimesQetttaN[0][time];
			LahoreS[i].Dtime = LahoreS[i].Atime - 1.1;
			TimesQetttaN[1][time]++;

			QetttaN[qutN].Dtime = TimesLahoreS[0][time] + 2.0;
			QetttaN[qutN].departure = LocalDest[j];
			QetttaN[qutN].Arival = LocalDest[4];
			QetttaN[qutN].Plane_ID = LahoreS[i].Plane_ID;

			qutN++;
		}
		if (j == 9&&qutS<10) {

			while (TimesQetttaS[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreS[i].Atime = TimesQetttaS[0][time];
			LahoreS[i].Dtime = LahoreS[i].Atime - 1.1;
			TimesQetttaS[1][time]++;

			QetttaS[qutS].Dtime = TimesLahoreS[0][time]+ 2.0;
			QetttaS[qutS].departure = LocalDest[j];
			QetttaS[qutS].Arival = LocalDest[4];
			QetttaS[qutS].Plane_ID = LahoreS[i].Plane_ID;

			qutS++;
		}
		j++;
	}

	for (int i = lhrN; i < 10; i++) {
		j = rand()%3+6;
		LahoreN[i].Arival = LocalDest[j];
		int time = rand() % 144;

		if (j == 0) {

			while (TimesIslamabadN[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreN[i].Atime = TimesIslamabadN[0][time];
			LahoreN[i].Dtime = LahoreN[i].Atime - 1;
			TimesIslamabadN[1][time]++;
		}
		if (j == 1) {

			while (TimesIslamabadS[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreN[i].Atime = TimesIslamabadS[0][time];
			LahoreN[i].Dtime = LahoreN[i].Atime - 1;
			TimesIslamabadS[1][time]++;
		}

		if (j == 2) {

			while (TimesKarachiN[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreN[i].Atime = TimesKarachiN[0][time];
			LahoreN[i].Dtime = LahoreN[i].Atime - 1.5;
			TimesKarachiN[1][time]++;
		}
		if (j == 3) {

			while (TimesKarachiS[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreN[i].Atime = TimesKarachiS[0][time];
			LahoreN[i].Dtime = LahoreN[i].Atime - 1.5;
			TimesKarachiS[1][time]++;
		}
		
		if (j == 6&&pshN<10) {

			while (TimesPeshawarN[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreN[i].Atime = TimesPeshawarN[0][time];
			LahoreN[i].Dtime = LahoreN[i].Atime - 1;
			TimesPeshawarN[1][time]++;

			PeshawarN[pshN].Dtime = TimesLahoreN[0][time] + 2.0;
			PeshawarN[pshN].departure = LocalDest[j];
			PeshawarN[pshN].Arival = LocalDest[5];
			PeshawarN[pshN].Plane_ID = LahoreN[i].Plane_ID;

			pshN++;
		}
		if (j == 7&&pshS<10) {

			while (TimesPeshawarS[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreN[i].Atime = TimesPeshawarS[0][time];
			LahoreN[i].Dtime = LahoreN[i].Atime - 1;
			TimesPeshawarS[1][time]++;

			PeshawarS[pshS].Dtime = TimesLahoreN[0][time] + 2.0;
			PeshawarS[pshS].departure = LocalDest[j];
			PeshawarS[pshS].Arival = LocalDest[5];
			PeshawarS[pshS].Plane_ID = LahoreN[i].Plane_ID;

			pshS++;
		}
		if (j == 8&&qutN<10) {

			while (TimesQetttaN[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreN[i].Atime = TimesQetttaN[0][time];
			LahoreN[i].Dtime = LahoreN[i].Atime - 1.1;
			TimesQetttaN[1][time]++;

			QetttaN[qutN].Dtime = TimesLahoreN[0][time] + 2.0;
			QetttaN[qutN].departure = LocalDest[j];
			QetttaN[qutN].Arival = LocalDest[5];
			QetttaN[qutN].Plane_ID = LahoreN[i].Plane_ID;

			qutN++;
		}
		if (j == 9&&qutS<10) {

			while (TimesQetttaS[1][time] >= 5) {
				time = rand() % 144;
			}
			LahoreN[i].Atime = TimesQetttaS[0][time];
			LahoreN[i].Dtime = LahoreN[i].Atime - 1.1;
			TimesQetttaS[1][time]++;

			QetttaS[qutS].Dtime = TimesLahoreN[0][time]+ 2.0;
			QetttaS[qutS].departure = LocalDest[j];
			QetttaS[qutS].Arival = LocalDest[5];
			QetttaS[qutS].Plane_ID = LahoreN[i].Plane_ID;

			qutS++;
		}
		j++;
	}

	for (int i = pshN; i < 10; i++) {

		j = rand() %9;
		while (j == 6 || j == 7)
			j = rand() % 9;
		PeshawarN[i].Arival = LocalDest[j];
		int time = rand() % 144;

		if (j == 0) {

			while (TimesIslamabadN[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarN[i].Atime = TimesIslamabadN[0][time];
			PeshawarN[i].Dtime = PeshawarN[i].Atime - 0.15;
			TimesIslamabadN[1][time]++;
		}
		if (j == 1) {

			while (TimesIslamabadS[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarN[i].Atime = TimesIslamabadS[0][time];
			PeshawarN[i].Dtime = PeshawarN[i].Atime - 0.15;
			TimesIslamabadS[1][time]++;
		}

		if (j == 2) {

			while (TimesKarachiN[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarN[i].Atime = TimesKarachiN[0][time];
			PeshawarN[i].Dtime = PeshawarN[i].Atime - 1.6;
			TimesKarachiN[1][time]++;
		}
		if (j == 3) {

			while (TimesKarachiS[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarN[i].Atime = TimesKarachiS[0][time];
			PeshawarN[i].Dtime = PeshawarN[i].Atime - 1.6;
			TimesKarachiS[1][time]++;
		}

		if (j == 4 && lhrN < 10) {

			while (TimesLahoreN[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarN[i].Atime = TimesLahoreN[0][time];
			PeshawarN[i].Dtime = PeshawarN[i].Atime - 1;
			TimesLahoreN[1][time]++;
		}
		if (j == 5 && lhrS < 10) {

			while (TimesLahoreS[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarN[i].Atime = TimesLahoreS[0][time];
			PeshawarN[i].Dtime = PeshawarN[i].Atime - 1;
			TimesLahoreS[1][time]++;

		}

		
		if (j == 8&&qutN<10) {

			while (TimesQetttaN[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarN[i].Atime = TimesQetttaN[0][time];
			PeshawarN[i].Dtime = PeshawarN[i].Atime - 0.5;
			TimesQetttaN[1][time]++;

			QetttaN[qutN].Dtime = TimesPeshawarN[0][time] + 2.0;
			QetttaN[qutN].departure = LocalDest[j];
			QetttaN[qutN].Arival = LocalDest[6];
			QetttaN[qutN].Plane_ID = PeshawarN[i].Plane_ID;

			qutN++;
		}
		if (j == 9&&qutS<10) {

			while (TimesQetttaS[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarN[i].Atime = TimesQetttaS[0][time];
			PeshawarN[i].Dtime = PeshawarN[i].Atime - 0.5;
			TimesQetttaS[1][time]++;

			QetttaS[qutS].Dtime = TimesPeshawarN[0][time]+ 2.0;
			QetttaS[qutS].departure = LocalDest[j];
			QetttaS[qutS].Arival = LocalDest[6];
			QetttaS[qutS].Plane_ID = PeshawarN[i].Plane_ID;

			qutS++;
		}
		j++;
	}
	
	for (int i = pshS; i < 10; i++) {

		j = rand() % 9;
		while (j == 6 || j == 7)
			j = rand() % 9;
		PeshawarS[i].Arival = LocalDest[j];
		int time = rand() % 144;

		if (j == 0) {

			while (TimesIslamabadN[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarS[i].Atime = TimesIslamabadN[0][time];
			PeshawarS[i].Dtime = PeshawarS[i].Atime - 0.15;
			TimesIslamabadN[1][time]++;
		}
		if (j == 1) {

			while (TimesIslamabadS[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarS[i].Atime = TimesIslamabadS[0][time];
			PeshawarS[i].Dtime = PeshawarS[i].Atime - 0.15;
			TimesIslamabadS[1][time]++;
		}

		if (j == 2) {

			while (TimesKarachiN[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarS[i].Atime = TimesKarachiN[0][time];
			PeshawarS[i].Dtime = PeshawarS[i].Atime - 1.6;
			TimesKarachiN[1][time]++;
		}
		if (j == 3) {

			while (TimesKarachiS[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarS[i].Atime = TimesKarachiS[0][time];
			PeshawarS[i].Dtime = PeshawarS[i].Atime - 1.6;
			TimesKarachiS[1][time]++;
		}

		if (j == 4 && lhrN < 10) {

			while (TimesLahoreN[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarS[i].Atime = TimesLahoreN[0][time];
			PeshawarS[i].Dtime = PeshawarS[i].Atime - 1;
			TimesLahoreN[1][time]++;
		}
		if (j == 5 && lhrS < 10) {

			while (TimesLahoreS[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarS[i].Atime = TimesLahoreS[0][time];
			PeshawarS[i].Dtime = PeshawarS[i].Atime - 1;
			TimesLahoreS[1][time]++;

		}
		
		if (j == 8&&qutN<10) {

			while (TimesQetttaN[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarS[i].Atime = TimesQetttaN[0][time];
			PeshawarS[i].Dtime = PeshawarS[i].Atime - 0.5;
			TimesQetttaN[1][time]++;

			QetttaN[qutN].Dtime = TimesPeshawarS[0][time] + 2.0;
			QetttaN[qutN].departure = LocalDest[j];
			QetttaN[qutN].Arival = LocalDest[0];
			QetttaN[qutN].Plane_ID = PeshawarS[i].Plane_ID;

			qutN++;
		}
		if (j == 9&&qutS<10) {

			while (TimesQetttaS[1][time] >= 5) {
				time = rand() % 144;
			}
			PeshawarS[i].Atime = TimesQetttaS[0][time];
			PeshawarS[i].Dtime = PeshawarS[i].Atime - 0.5;
			TimesQetttaS[1][time]++;

			QetttaS[qutS].Dtime = TimesPeshawarS[0][time]+ 2.0;
			QetttaS[qutS].departure = LocalDest[j];
			QetttaS[qutS].Arival = LocalDest[0];
			QetttaS[qutS].Plane_ID = PeshawarS[i].Plane_ID;

			qutS++;
		}
		j++;
	}

	for (int i = qutN; i < 10; i++) {

		j = rand() %7;
		QetttaN[i].Arival = LocalDest[j];
		int time = rand() % 144;

		if (j == 0) {

			while (TimesIslamabadN[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaN[i].Atime = TimesIslamabadN[0][time];
			QetttaN[i].Dtime = QetttaN[i].Atime - 1.1;
			TimesIslamabadN[1][time]++;
		}
		if (j == 1) {

			while (TimesIslamabadS[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaN[i].Atime = TimesIslamabadS[0][time];
			QetttaN[i].Dtime = QetttaN[i].Atime - 1.1;
			TimesIslamabadS[1][time]++;
		}

		if (j == 2) {

			while (TimesKarachiN[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaN[i].Atime = TimesKarachiN[0][time];
			QetttaN[i].Dtime = QetttaN[i].Atime - 1.15;
			TimesKarachiN[1][time]++;
		}
		if (j == 3) {

			while (TimesKarachiS[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaN[i].Atime = TimesKarachiS[0][time];
			QetttaN[i].Dtime = QetttaN[i].Atime - 1.15;
			TimesKarachiS[1][time]++;
		}

		if (j == 4 && lhrN < 10) {

			while (TimesLahoreN[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaN[i].Atime = TimesLahoreN[0][time];
			QetttaN[i].Dtime = QetttaN[i].Atime - 1.1;
			TimesLahoreN[1][time]++;
		}
		if (j == 5 && lhrS < 10) {

			while (TimesLahoreS[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaN[i].Atime = TimesLahoreS[0][time];
			QetttaN[i].Dtime = QetttaN[i].Atime - 1.1;
			TimesLahoreS[1][time]++;

		}

		if (j == 6 && pshN < 10) {

			while (TimesPeshawarN[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaN[i].Atime = TimesPeshawarN[0][time];
			QetttaN[i].Dtime = QetttaN[i].Atime - 0.5;
			TimesPeshawarN[1][time]++;
		}
		if (j == 7 && pshS < 10) {

			while (TimesPeshawarS[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaN[i].Atime = TimesPeshawarS[0][time];
			QetttaN[i].Dtime = QetttaN[i].Atime - 0.5;
			TimesPeshawarS[1][time]++;
		}
		
	}

	for (int i = qutS; i < 10; i++) {

		j = rand() % 7;
		QetttaS[i].Arival = LocalDest[j];
		int time = rand() % 144;

		if (j == 0) {

			while (TimesIslamabadN[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaS[i].Atime = TimesIslamabadN[0][time];
			QetttaS[i].Dtime = QetttaS[i].Atime - 1.1;
			TimesIslamabadN[1][time]++;
		}
		if (j == 1) {

			while (TimesIslamabadS[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaS[i].Atime = TimesIslamabadS[0][time];
			QetttaS[i].Dtime = QetttaS[i].Atime - 1.1;
			TimesIslamabadS[1][time]++;
		}

		if (j == 2) {

			while (TimesKarachiN[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaS[i].Atime = TimesKarachiN[0][time];
			QetttaS[i].Dtime = QetttaS[i].Atime - 1.1;
			TimesKarachiN[1][time]++;
		}
		if (j == 3) {

			while (TimesKarachiS[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaS[i].Atime = TimesKarachiS[0][time];
			QetttaS[i].Dtime = QetttaS[i].Atime - 1.1;
			TimesKarachiS[1][time]++;
		}

		if (j == 4 && lhrN < 10) {

			while (TimesLahoreN[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaS[i].Atime = TimesLahoreN[0][time];
			QetttaS[i].Dtime = QetttaS[i].Atime - 1;
			TimesLahoreN[1][time]++;
		}
		if (j == 5 && lhrS < 10) {

			while (TimesLahoreS[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaS[i].Atime = TimesLahoreS[0][time];
			QetttaS[i].Dtime = QetttaS[i].Atime - 1.1;
			TimesLahoreS[1][time]++;

		}

		if (j == 6 && pshN < 10) {

			while (TimesPeshawarN[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaS[i].Atime = TimesPeshawarN[0][time];
			QetttaS[i].Dtime = QetttaS[i].Atime - 0.5;
			TimesPeshawarN[1][time]++;
		}
		if (j == 7 && pshS < 10) {

			while (TimesPeshawarS[1][time] >= 5) {
				time = rand() % 144;
			}
			QetttaS[i].Atime = TimesPeshawarS[0][time];
			QetttaS[i].Dtime = QetttaS[i].Atime - 0.5;
			TimesPeshawarS[1][time]++;
		}

	}

	intGen();	


	for (int i = 0; i < 10; i++) {
		IslamabadN[i].times();
		IslamabadS[i].times();
		LahoreN[i].times();
		LahoreS[i].times();
		KarachiN[i].times();
		KarachiS[i].times();
		QetttaN[i].times();
		QetttaS[i].times();
		PeshawarN[i].times();
		PeshawarS[i].times();
	}

	//-----------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------
	
	for (int i = 0; i < 15; i++) {
		IslamabadN[i].IntTime();
		IslamabadS[i].IntTime();
		LahoreN[i].IntTime();
		LahoreS[i].IntTime();
		KarachiN[i].IntTime();
		KarachiS[i].IntTime();
		QetttaN[i].IntTime();
		QetttaS[i].IntTime();
		PeshawarN[i].IntTime();
		PeshawarS[i].IntTime();
		IslamabadN[i].PreBooked();
		IslamabadS[i].PreBooked();
		LahoreN[i].PreBooked();
		LahoreS[i].PreBooked();
		KarachiN[i].PreBooked();
		KarachiS[i].PreBooked();
		QetttaN[i].PreBooked();
		QetttaS[i].PreBooked();
		PeshawarN[i].PreBooked();
		PeshawarS[i].PreBooked();

		IslamabadN[i].LocTime();
		IslamabadS[i].LocTime();
		LahoreN[i].LocTime();
		LahoreS[i].LocTime();
		KarachiN[i].LocTime();
		KarachiS[i].LocTime();
		QetttaN[i].LocTime();
		QetttaS[i].LocTime();
		PeshawarN[i].LocTime();
		PeshawarS[i].LocTime();
	}


}

void FlightSchedule::intGen() {

	int j = 10;
	for (int i = 0; i < 5; i++) {
		int x = rand() % 24;
		while (x == Cov[0] || x == Cov[1] || x == Cov[2] || x == Cov[3] || x == Cov[4] || x == Cov[5] || x == Cov[6] || x == Cov[7] || x == Cov[8] || x == Cov[9]) {
			x = rand() % 24;
		}
		IslamabadN[j].Arival = IntDest[x];
		int q = rand() % 24;
		int r = rand() % 2;
		if (r == 1) {
			while (q == x && (q == Cov[0] || q == Cov[1] || q == Cov[2] || q == Cov[3] || q == Cov[4] || q == Cov[5] || q == Cov[6] || q == Cov[7] || q == Cov[8] || q == Cov[9])) {
				q = rand() % 24;
			}
			IslamabadN[j].layoverName = IntDest[q];
			IslamabadN[j].layover = q;
		}
		int time = rand() % 144;
		IslamabadN[j].Dtime = TimesQetttaS[0][time];
		IslamabadN[j].type = 1;
		j++;
	}
	j = 10;
	for (int i = 0; i < 5; i++) {
		int x = rand() % 24;
		while (x == Cov[0] || x == Cov[1] || x == Cov[2] || x == Cov[3] || x == Cov[4] || x == Cov[5] || x == Cov[6] || x == Cov[7] || x == Cov[8] || x == Cov[9]) {
			x = rand() % 24;
		}
		IslamabadS[j].Arival = IntDest[x];
		int q = rand() % 24;
		int r = rand() % 2;
		if (r == 1) {
			while (q == x && (q == Cov[0] || q == Cov[1] || q == Cov[2] || q == Cov[3] || q == Cov[4] || q == Cov[5] || q == Cov[6] || q == Cov[7] || q == Cov[8] || q == Cov[9])) {
				q = rand() % 24;
			}
			IslamabadS[j].layoverName = IntDest[q];
			IslamabadS[j].layover = q;
		}
		int time = rand() % 144;
		IslamabadS[j].Dtime = TimesQetttaS[0][time];
		IslamabadS[j].type = 1;
		j++;
	}

	j = 10;
	for (int i = 0; i < 5; i++) {
		int q = 0;
		int x = rand() % 24;
		while (x == Cov[0] || x == Cov[1] || x == Cov[2] || x == Cov[3] || x == Cov[4] || x == Cov[5] || x == Cov[6] || x == Cov[7] || x == Cov[8] || x == Cov[9]) {
			x = rand() % 24;
		}
		KarachiN[j].Arival = IntDest[x];
		q = rand() % 24;
		int r = rand() % 2;
		if (r == 1) {
			while (q == x && (q == Cov[0] || q == Cov[1] || q == Cov[2] || q == Cov[3] || q == Cov[4] || q == Cov[5] || q == Cov[6] || q == Cov[7] || q == Cov[8] || q == Cov[9])) {
				q = rand() % 24;
			}
			KarachiN[j].layoverName = IntDest[q];
			KarachiN[j].layover = q;
		}

		int time = rand() % 144;
		KarachiN[j].Dtime = TimesQetttaS[0][time];
		KarachiN[j].type = 1;
		j++;
	}

	j = 10;
	for (int i = 0; i < 5; i++) {
		int x = rand() % 24;
		while (x == Cov[0] || x == Cov[1] || x == Cov[2] || x == Cov[3] || x == Cov[4] || x == Cov[5] || x == Cov[6] || x == Cov[7] || x == Cov[8] || x == Cov[9]) {
			x = rand() % 24;
		}
		KarachiS[j].Arival = IntDest[x];
		int q = rand() % 24;
		int r = rand() % 2;
		if (r == 1) {
			while (q == x && (q == Cov[0] || q == Cov[1] || q == Cov[2] || q == Cov[3] || q == Cov[4] || q == Cov[5] || q == Cov[6] || q == Cov[7] || q == Cov[8] || q == Cov[9])) {
				q = rand() % 24;
			}
			KarachiS[j].layoverName = IntDest[q];
			KarachiS[j].layover = q;
		}
		int time = rand() % 144;
		KarachiS[j].Dtime = TimesQetttaS[0][time];
		KarachiS[j].type = 1;
		j++;
	}

	j = 10;
	for (int i = 0; i < 5; i++) {
		int x = rand() % 24;
		while (x == Cov[0] || x == Cov[1] || x == Cov[2] || x == Cov[3] || x == Cov[4] || x == Cov[5] || x == Cov[6] || x == Cov[7] || x == Cov[8] || x == Cov[9]) {
			x = rand() % 24;
		}
		LahoreN[j].Arival = IntDest[x];
		int q = rand() % 24;
		int r = rand() % 2;
		if (r == 1) {
			while (q == x && (q == Cov[0] || q == Cov[1] || q == Cov[2] || q == Cov[3] || q == Cov[4] || q == Cov[5] || q == Cov[6] || q == Cov[7] || q == Cov[8] || q == Cov[9])) {
				q = rand() % 24;
			}
			LahoreN[j].layoverName = IntDest[q];
			LahoreN[j].layover = q;
		}
		int time = rand() % 144;
		LahoreN[j].Dtime = TimesQetttaS[0][time];
		LahoreN[j].type = 1;
		j++;
	}

	j = 10;
	for (int i = 0; i < 5; i++) {
		int x = rand() % 24;
		while (x == Cov[0] || x == Cov[1] || x == Cov[2] || x == Cov[3] || x == Cov[4] || x == Cov[5] || x == Cov[6] || x == Cov[7] || x == Cov[8] || x == Cov[9]) {
			x = rand() % 24;
		}
		LahoreS[j].Arival = IntDest[x];
		int q = rand() % 24;
		int r = rand() % 2;
		if (r == 1) {
			while (q == x && (q == Cov[0] || q == Cov[1] || q == Cov[2] || q == Cov[3] || q == Cov[4] || q == Cov[5] || q == Cov[6] || q == Cov[7] || q == Cov[8] || q == Cov[9])) {
				q = rand() % 24;
			}
			LahoreS[j].layoverName = IntDest[q];
			LahoreS[j].layover = q;
		}
		int time = rand() % 144;
		LahoreS[j].Dtime = TimesQetttaS[0][time];
		LahoreS[j].type = 1;
		j++;
	}

	j = 10;
	for (int i = 0; i < 5; i++) {
		int x = rand() % 24;
		while (x == Cov[0] || x == Cov[1] || x == Cov[2] || x == Cov[3] || x == Cov[4] || x == Cov[5] || x == Cov[6] || x == Cov[7] || x == Cov[8] || x == Cov[9]) {
			x = rand() % 24;
		}
		PeshawarN[j].Arival = IntDest[x];
		int q = rand() % 24;
		int r = rand() % 2;
		if (q == 1) {
			while (q == x && (q == Cov[0] || q == Cov[1] || q == Cov[2] || q == Cov[3] || q == Cov[4] || q == Cov[5] || q == Cov[6] || q == Cov[7] || q == Cov[8] || q == Cov[9])) {
				q = rand() % 24;
			}
			PeshawarN[j].layoverName = IntDest[q];
			PeshawarN[j].layover = q;
		}
		int time = rand() % 144;
		PeshawarN[j].Dtime = TimesQetttaS[0][time];
		PeshawarN[j].type = 1;
		j++;
	}

	j = 10;
	for (int i = 0; i < 5; i++) {
		int x = rand() % 24;
		while (x == Cov[0] || x == Cov[1] || x == Cov[2] || x == Cov[3] || x == Cov[4] || x == Cov[5] || x == Cov[6] || x == Cov[7] || x == Cov[8] || x == Cov[9]) {
			x = rand() % 24;
		}
		PeshawarS[j].Arival = IntDest[x];
		int q = rand() % 24;
		int r = rand() % 2;
		if (r == 1) {
			while (q == x && (q == Cov[0] || q == Cov[1] || q == Cov[2] || q == Cov[3] || q == Cov[4] || q == Cov[5] || q == Cov[6] || q == Cov[7] || q == Cov[8] || q == Cov[9])) {
				q = rand() % 24;
			}
			PeshawarS[j].layoverName = IntDest[q];
			PeshawarS[j].layover = q;
		}
		int time = rand() % 144;
		PeshawarS[j].Dtime = TimesQetttaS[0][time];
		PeshawarS[j].type = 1;
		j++;
	}

	j = 10;
	for (int i = 0; i < 5; i++) {
		int x = rand() % 24;
		while (x == Cov[0] || x == Cov[1] || x == Cov[2] || x == Cov[3] || x == Cov[4] || x == Cov[5] || x == Cov[6] || x == Cov[7] || x == Cov[8] || x == Cov[9]) {
			x = rand() % 24;
		}
		QetttaN[j].Arival = IntDest[x];
		int q = rand() % 24;
		int r = rand() % 2;
		if (r == 1) {
			while (q == x && (q == Cov[0] || q == Cov[1] || q == Cov[2] || q == Cov[3] || q == Cov[4] || q == Cov[5] || q == Cov[6] || q == Cov[7] || q == Cov[8] || q == Cov[9])) {
				q = rand() % 24;
			}
			QetttaN[j].layoverName = IntDest[q];
			QetttaN[j].layover = q;
		}
		int time = rand() % 144;
		QetttaN[j].Dtime = TimesQetttaS[0][time];
		QetttaN[j].type = 1;
		j++;
	}

	j = 10;
	for (int i = 0; i < 5; i++) {
		int x = rand() % 24;
		while (x == Cov[0] || x == Cov[1] || x == Cov[2] || x == Cov[3] || x == Cov[4] || x == Cov[5] || x == Cov[6] || x == Cov[7] || x == Cov[8] || x == Cov[9]) {
			x = rand() % 24;
		}
		QetttaS[j].Arival = IntDest[x];
		int q = rand() %24;
		int r = rand() % 2;
		if (r == 1) {
			while (q == x && (q == Cov[0] || q == Cov[1] || q == Cov[2] || q == Cov[3] || q == Cov[4] || q == Cov[5] || q == Cov[6] || q == Cov[7] || q == Cov[8] || q == Cov[9])) {
				q = rand() % 24;
			}
			QetttaN[j].layoverName = IntDest[q];
			QetttaN[j].layover = q;
		}
		int time = rand() % 144;
		QetttaS[j].Dtime = TimesQetttaS[0][time];
		QetttaS[j].type = 1;
		j++;
	}

	
}

void FlightSchedule::routes()
{
	for (int i = 10; i < 15; i++) {
		;
	}
}


FlightSchedule::~FlightSchedule() {

	delete[] IslamabadN;
	delete[] IslamabadS;
	delete[] LahoreN;
	delete[] LahoreS;
	delete[] KarachiN;
	delete[] KarachiS;
	delete[] QetttaN;
	delete[] QetttaS;
	delete[] PeshawarN;
	delete[] PeshawarS;

	IslamabadN = NULL;
	IslamabadS = NULL;
	LahoreN = NULL;
	LahoreS = NULL;
	KarachiN = NULL;
	KarachiS = NULL;
	QetttaN = NULL;
	QetttaS = NULL;
	PeshawarN = NULL;
	PeshawarS = NULL;



	for (int i = 0; i < 2; i++) {
		delete[] TimesIslamabadN[i];
		delete[] TimesIslamabadS[i];
		delete[] TimesLahoreN[i];
		delete[] TimesLahoreS[i];
		delete[] TimesKarachiN[i];
		delete[] TimesKarachiS[i];
		delete[] TimesQetttaN[i];
		delete[] TimesQetttaS[i];
		delete[] TimesPeshawarN[i];
		delete[] TimesPeshawarS[i];
	}
	


	delete[] TimesIslamabadN;
	delete[] TimesIslamabadS;
	delete[] TimesLahoreN;
	delete[] TimesLahoreS;
	delete[] TimesKarachiN;
	delete[] TimesKarachiS;
	delete[] TimesQetttaN;
	delete[] TimesQetttaS;
	delete[] TimesPeshawarN;
	delete[] TimesPeshawarS;

	TimesIslamabadN = NULL;
	TimesIslamabadS = NULL;
	TimesLahoreN = NULL;
	TimesLahoreS = NULL;
	TimesKarachiN = NULL;
	TimesKarachiS = NULL;
	TimesQetttaN = NULL;
	TimesQetttaS = NULL;
	TimesPeshawarN = NULL;
	TimesPeshawarS = NULL;

}

void FlightSchedule::Display()
{
	cout << "========================================================================" << endl;
	cout << "=================================Schedule:==============================" << endl;
	cout << " ";
	cout << left << setfill(' ');
	cout << "Islamabad North airport: " << endl;
	cout << " Plane ID:    Dep Airport:      Arr Airport:" << endl << endl;
	for (int i = 0; i < 15; i++)
		IslamabadN[i].Display();
	cout << "    ----------------------------------------------------------------------" << endl << endl;
	cout << " Islamabad south airport: " << endl;
	cout << " Plane ID:    Dep Airport:      Arr Airport:" << endl << endl;
	for (int i = 0; i < 15; i++)
		IslamabadS[i].Display();
	cout << "    ----------------------------------------------------------------------" << endl << endl;
	cout << " Lahore North Airport:" << endl;
	cout << " Plane ID:    Dep Airport:      Arr Airport:" << endl << endl;
	for (int i = 0; i < 15; i++)
		LahoreN[i].Display();
	cout << "    ----------------------------------------------------------------------" << endl << endl;
	cout << " Lahore South Airport:" << endl;
	cout << " Plane ID:    Dep Airport:      Arr Airport:" << endl << endl;
	for (int i = 0; i < 15; i++)
		LahoreS[i].Display();
	cout << "    ----------------------------------------------------------------------" << endl << endl;
	cout << " Karachi North Airport:" << endl;
	cout << " Plane ID:    Dep Airport:      Arr Airport:" << endl << endl;
	for (int i = 0; i < 15; i++)
		KarachiN[i].Display();
	cout << "    ----------------------------------------------------------------------" << endl << endl;
	cout << " Karachi South Airport: " << endl;
	cout << " Plane ID:    Dep Airport:      Arr Airport:" << endl << endl;
	for (int i = 0; i < 15; i++)
		KarachiS[i].Display();
	cout << "    ----------------------------------------------------------------------" << endl << endl;
	cout << " Quetta North Airport: " << endl;
	cout << " Plane ID:    Dep Airport:      Arr Airport:" << endl << endl;
	for (int i = 0; i < 15; i++)
		QetttaN[i].Display();
	cout << "    ----------------------------------------------------------------------" << endl << endl;
	cout << " Quetta South Airport:" << endl;
	cout << " Plane ID:    Dep Airport:      Arr Airport:" << endl << endl;
	for (int i = 0; i < 15; i++)
		QetttaS[i].Display();
	cout << "    ----------------------------------------------------------------------" << endl << endl;
	cout << " Peshawar North Airport:" << endl;
	cout << " Plane ID:    Dep Airport:      Arr Airport:" << endl << endl;
	for (int i = 0; i < 15; i++)
		PeshawarN[i].Display();
	cout << "    ----------------------------------------------------------------------" << endl << endl;
	cout << " Peshawar South Airport:" << endl;
	cout << " Plane ID:    Dep Airport:      Arr Airport:" << endl << endl;
	for (int i = 0; i < 15; i++)
		PeshawarS[i].Display();
	cout << "    ----------------------------------------------------------------------" << endl << endl;

	cout << endl;
	cout << " Covid effected countries: " << endl;
	for (int i = 0; i < 10; i++) {
		if (covid[i] != "") {
			cout << " ";
			cout << covid[i] << " ";
			
		}
	}
	cout << endl;
}

double FlightSchedule::Booking() {
	double price = 0;
	cout << "For what airport would you like to book a flight for?" << endl;
	for (int i = 0; i < 10; i++) {
		cout << i + 1 << ". " << LocalDest[i] << endl;
	}
	int x;
	cin >> x;
	cout << LocalDest[x] << endl;
	cout << " Plane ID:    Dep Airport:      Arr Airport:" << endl << endl;
	if (x == 1) {
		for (int i = 0; i < 15; i++)
			IslamabadN[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (IslamabadN[i].Plane_ID == l) {
				price = IslamabadN[i].Book();
			}
		}
	}
	else if (x == 2) {
		for (int i = 0; i < 15; i++)
			IslamabadS[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (IslamabadS[i].Plane_ID == l) {
				price = IslamabadS[i].Book();
			}
		}
	}
	else if (x == 3) {
		for (int i = 0; i < 15; i++)
			KarachiN[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (KarachiN[i].Plane_ID == l) {
				price = KarachiN[i].Book();
			}
		}
	}
	else if (x == 4) {
		for (int i = 0; i < 15; i++)
			KarachiS[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (KarachiS[i].Plane_ID == l) {
				price = KarachiS[i].Book();
			}
		}
	}
	else if (x == 5) {
		for (int i = 0; i < 15; i++)
			LahoreN[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (LahoreN[i].Plane_ID == l) {
				price = LahoreN[i].Book();
			}
		}
	}
	else if (x == 6) {
		for (int i = 0; i < 15; i++)
			LahoreS[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (LahoreS[i].Plane_ID == l) {
				price = LahoreS[i].Book();
			}
		}
	}
	if (x == 7) {
		for (int i = 0; i < 15; i++)
			PeshawarN[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (PeshawarN[i].Plane_ID == l) {
				price = PeshawarN[i].Book();
			}
		}
	}
	else if (x == 8) {
		for (int i = 0; i < 15; i++)
			PeshawarS[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (PeshawarS[i].Plane_ID == l) {
				price = PeshawarS[i].Book();
			}
		}
	}
	else if (x == 9) {
		for (int i = 0; i < 15; i++)
			QetttaN[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (QetttaN[i].Plane_ID == l) {
				price = QetttaN[i].Book();
			}
		}
	}
	else if (x == 10) {
		for (int i = 0; i < 15; i++)
			QetttaS[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (QetttaS[i].Plane_ID == l) {
				price = QetttaS[i].Book();
			}
		}
	}
	cout << "    ----------------------------------------------------------------------" << endl << endl;
	return price;
}

double FlightSchedule::changer() {
	double price;
	cout << "For what airport would you like to change?" << endl;
	for (int i = 0; i < 10; i++) {
		cout << i + 1 << ". " << LocalDest[i] << endl;
	}
	int x;
	cin >> x;
	cout << LocalDest[x] << endl;
	cout << " Plane ID:    Dep Airport:      Arr Airport:" << endl << endl;
	if (x == 1) {
		for (int i = 0; i < 15; i++)
			IslamabadN[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (IslamabadN[i].Plane_ID == l) {
				price=IslamabadN[i].change(covid,Cov);
				cout << IslamabadN[i];
			}
		}
	}
	else if (x == 2) {
		for (int i = 0; i < 15; i++)
			IslamabadS[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (IslamabadS[i].Plane_ID == l) {
				price = IslamabadS[i].change(covid, Cov);
				cout << IslamabadS[i];
			}
		}
	}
	else if (x == 3) {
		for (int i = 0; i < 15; i++)
			KarachiN[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (KarachiN[i].Plane_ID == l) {
				price = KarachiN[i].change(covid, Cov);
				cout << KarachiN[i];
			}
		}
	}
	else if (x == 4) {
		for (int i = 0; i < 15; i++)
			KarachiS[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (KarachiS[i].Plane_ID == l) {
				price = KarachiS[i].change(covid, Cov);
				cout << KarachiS[i];
			}
		}
	}
	else if (x == 5) {
		for (int i = 0; i < 15; i++)
			LahoreN[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (LahoreN[i].Plane_ID == l) {
				price = LahoreN[i].change(covid, Cov);
				cout << LahoreN[i];
			}
		}
	}
	else if (x == 6) {
		for (int i = 0; i < 15; i++)
			LahoreS[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (LahoreS[i].Plane_ID == l) {
				price = LahoreS[i].change(covid, Cov);
				cout << LahoreS[i];
			}
		}
	}
	if (x == 7) {
		for (int i = 0; i < 15; i++)
			PeshawarN[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (PeshawarN[i].Plane_ID == l) {
				price = PeshawarN[i].change(covid, Cov);
				cout << PeshawarN[i];
			}
		}
	}
	else if (x == 8) {
		for (int i = 0; i < 15; i++)
			PeshawarS[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (PeshawarS[i].Plane_ID == l) {
				price = PeshawarS[i].change(covid, Cov);
				cout << PeshawarS[i];
			}
		}
	}
	else if (x == 9) {
		for (int i = 0; i < 15; i++)
			QetttaN[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (QetttaN[i].Plane_ID == l) {
				price = QetttaN[i].change(covid, Cov);
				cout << QetttaN[i];
			}
		}
	}
	else if (x == 10) {
		for (int i = 0; i < 15; i++)
			QetttaS[i].Display();
		cout << "Which flight would you like to book (enter flight num): ";
		int l;
		cin >> l;
		for (int i = 0; i < 15; i++) {
			if (QetttaS[i].Plane_ID == l) {
				price = QetttaS[i].change(covid, Cov);
				cout << QetttaS[i];
			}
		}
	}
	cout << "    ----------------------------------------------------------------------" << endl << endl;
	return price;
}

void FlightSchedule::addCovid()
{
	int x;
	cout << "What country would you like to add to the Covid list?" << endl;
	for (int i = 0; i < 25; i++) {
		if (i == Cov[0] || i == Cov[1] || i == Cov[2] || i == Cov[3] || i == Cov[4] || i == Cov[5] || i == Cov[6] || i == Cov[7] || i == Cov[8] || i == Cov[9]) {
			continue;
		}
		else
			cout << i + 1 << ". " << IntDest[i] << endl;
	}
	cin >> x;
	x--;
	while ((x < 0 || x>25) && (x == Cov[0] || x == Cov[1] || x == Cov[2] || x == Cov[3] || x == Cov[4] || x == Cov[5] || x == Cov[6] || x == Cov[7] || x == Cov[8] || x == Cov[9])) {
		cout << "Invalid input: Try again." << endl;
		cin >> x;
		x--;
	}
	for (int i = 0; i < 10; i++) {
		if (Cov[i] == -1) {
			Cov[i] = x;
			covid[i] = IntDest[x];
			i = 10;
			break;
		}
	}
}