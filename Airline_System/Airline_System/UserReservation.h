#pragma once
#include "DBConnect.h"
class UserReservation {
private:
	string UserName;
	string UserPhone;
	string UserPassport;
	string UserTicket;
	string UserFlight;
	string UserAddress;
public:
	void setUserName(string un) {
		UserName = un;
	}
	string getUserName() {
		return UserName;
	}
	void setUserPhone(string up) {
		UserPhone = up;
	}
	string getUserPhone() {
		return UserPhone;
	}
	void setUserPassport(string upa) {
		UserPassport = upa;
	}
	string getUserPassport() {
		return UserPassport;
	}
	void setUserTicket(string ut) {
		UserTicket = ut;
	}
	string getUserTicket() {
		return UserTicket;
	}
	void setUserFlight(string uf) {
		UserFlight = uf;
	}
	string getUserFlight() {
		return UserFlight;
	}
	void setUserAddress(string ua) {
		UserAddress = ua;
	}
	string getUserAddress() {
		return UserAddress;
	}
};