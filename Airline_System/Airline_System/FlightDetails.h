#pragma once
#include "DBConnect.h"
class FlightDetail {
private:
	string FlightNo;
	string FlightName;
	string FlightFrom;
	string FlightDestination;
	string FlightTime;
	string FlightAmount;
	string FlightLeave;
	string FlightArrive;
	string FlightAvailable;
public:
	void setFlightNo(string fn) {
		FlightNo = fn;
	}
	string getFlightNo() {
		return FlightNo;
	}
	void setFlightName(string fna) {
		FlightName = fna;
	}
	string getFlightName() {
		return FlightName;
	}
	void setFlightFrom(string fr) {
		FlightFrom = fr;
	}
	string getFlightFrom() {
		return FlightFrom;
	}
	void FlightDestination(string fd) {
		FlightDestination = fd;
	}
	string getFlightDestination() {
		return FlightDestination;
	}
	void setFlightTime(string ft) {
		FlightTime = ft;
	}
	string getFlightTime() {
		return  FlightTime;
	}
	void setFlightAmount(string fa) {
		FlightAmount = fa;
	}
	string getFlightAmount() {
		return FlightAmount;
	}
	void setFlightLeave(string fl) {
		FlightLeave = fl;
	}
	string getFlightLeave() {
		return FlightLeave;
	}
	void setFlightArrive(string farr) {
		FlightArrive = farr;
	}
	string getFlightArrive() {
		return FlightArrive;
	}
	void setFlightAvailable(string fav) {
		FlightAvailable = fav;
	}
	string getFlightAvailable() {
		return FlightAvailable;
	}

};