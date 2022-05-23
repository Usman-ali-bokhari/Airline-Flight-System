#include "EconomySeats.h"

EconomySeats::EconomySeats() {
	seatNum = 0;
}

void EconomySeats::copyPassenger(Passenger B) {
	P = B;
}

void EconomySeats::setSeat(int x) {
	seatNum = x;
}

int EconomySeats::getseat() {
	return seatNum;
}