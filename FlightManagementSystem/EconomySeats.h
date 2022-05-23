#pragma once
#include "Passenger.h"
class EconomySeats
{
    Passenger P;
    int seatNum;
public:
    EconomySeats();
    void copyPassenger(Passenger B);
    void setSeat(int);
    int getseat();
};

