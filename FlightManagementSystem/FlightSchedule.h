#pragma once
#include "Planes.h"
#include <iostream>
using namespace std;

class FlightSchedule
   
{   
    Planes* IslamabadN;
    Planes* IslamabadS;
    Planes* LahoreN;
    Planes* LahoreS;
    Planes* KarachiN;
    Planes* KarachiS;
    Planes* QetttaN;
    Planes* QetttaS;
    Planes* PeshawarN;
    Planes* PeshawarS;
    double** TimesIslamabadN;
    double** TimesIslamabadS;
    double** TimesLahoreN;
    double** TimesLahoreS;
    double** TimesKarachiN;
    double** TimesKarachiS;
    double** TimesQetttaN;
    double** TimesQetttaS;
    double** TimesPeshawarN;
    double** TimesPeshawarS;
    string* covid;
    int* Cov;
    
public:
    FlightSchedule();
    ~FlightSchedule();
    void Display();
    double Booking();
    void GenSchedule();
    void routes();
    void intGen();
    double changer();
    void addCovid();
};

