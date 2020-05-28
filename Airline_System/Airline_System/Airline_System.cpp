// Airline_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdlib.h>
#include <iostream>
#include "mysql.h"
#include "DBConnect.h"
MYSQL* conn;
MYSQL_RES *res;
MYSQL_ROW row;
int checkIn(int low, int high) {
	int input;
	while (true) {
		cin >> input;
		if (input < low || input > high) {
			cout << "Gia tri khong hop le. Vui long nhap lai!\n";
		}
		else
			break;
	}
	return input;
}
int main() 
{
	conn = DBConnect::initConnect();
	system("cls");
	system("title Airlines Reservation System Program");
	system("color 0f");
	int input;
	while (true) {
		cout << "------------Welcome To Airlines Reservation System------------" << endl;
		cout << "------------Airlines Reservation System Menu------------" << endl;
		cout << "1. Reserve Seat.\n";
		cout << "2. User Ticket\n";
		cout << "3. Flights Schedule.\n";
		cout << "4. Display Passenger.\n";
		cout << "5. Flight Details.\n";
		cout << "6. Exit Program.\n";
		cout << "Choose One:";
		input = checkIn(1, 6);
		if (input == 1) {
			cout << "Reserve Seat." << endl;
		}
		if (input == 2) {
			cout << "User Ticket." << endl;
		}
		if (input == 3) {
			cout << "Flights Schedule." << endl;
		}
		if (input == 4) {
			cout << "Display Passenger." << endl;
		}
		if (input == 5) {
			while (true) {
				cout << "------------Welcome To Airlines Reservation System------------\n";
				cout << "------------Airlines Reservation System Menu------------\n";
				cout << "1. Add Flight.\n";
				cout << "2. Edit Flight.\n";
				cout << "3. Delete Flight..\n";
				cout << "4. Flight Leave And Arrive.\n";
				cout << "5. Back To Menu.\n";
				cout << "Choose One:";
				input = checkIn(1, 5);
				if (input == 1) {
					cout << "Add Flight." << endl;
				}
				if (input == 2) {
					cout << "Edit Flight." << endl;
				}
				if (input == 3) {
					cout << "Delete Flight." << endl;
				}
				if (input == 4) {
					cout << "Flight Leave And Arrive." << endl;
				}
				if (input == 5) {
					cout << "Back To Menu" << endl;
				}
			}
		}
		if (input == 6) {
			cout << "Exit Program." << endl;
		}

	}

	return 0;
}
