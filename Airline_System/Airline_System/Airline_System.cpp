// Airline_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdlib.h>
#include <iostream>
#include "mysql.h"
#include "DBConnect.h"
using namespace std;
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
void Insert() {
	cout << "Add Flight." << endl;
	int queryState;
	string no;
	string name;
	string from;
	string destination;
	string time;
	string amount;
	string available;
	cout << "Enter the No: ";
	cin >> no;
	cout << "Enter the Name: ";
	cin >> name;
	cout << "Enter the From: ";
	cin >> from;
	cout << "Enter the Destination: ";
	cin >> destination;
	cout << "Enter the Time: ";
	cin >> time;
	cout << "Enter the Amount: ";
	cin >> amount;
	cout << "Enter the Available: ";
	cin >> available;
	string query = "INSERT INTO flightdetails_tb (f_no,f_name,f_from,f_destination,f_time,f_amount,f_available) VALUES (";
	query.append("'").append(no).append("',")
		.append("'").append(name).append("',")
		.append("'").append(from).append("',")
		.append("'").append(destination).append("',")
		.append("'").append(time).append("',")
		.append("'").append(amount).append("',")
		.append("'").append(available).append("');");
	cout << "Insert successful!\n" << endl;
	cout << "Query: " << query.c_str() << endl;
	const char* q = query.c_str();
	queryState = mysql_query(conn, q);
	if (queryState != 0) {
		cout << mysql_error(conn) << endl;
	}
}
bool checkId(int id) {
	int check;
	std::string s = std::to_string(id);
	char const *pchar = s.c_str();
	string query = "Select f_id from flightdetails_tb Where ";
	query.append("f_id = ").append(pchar).append(";");
	const char* q = query.c_str();
	check = mysql_query(conn, q);
	if (!check)
	{
		res = mysql_store_result(conn);
		if (row = mysql_fetch_row(res)) {
			return true;
		}
	}
	return false;
}
void flightDelete() {
	int queryDelete;
	int id = 0;
	char available[10] = "A";
	do {
		cout << "Enter the id: \n";
		cin >> id;
		if (!checkId(id)) {
			cout << " Id not exist. Please choise!\n";
		}
	} while (!checkId(id));
	cout << "Id Exist. Delete Data!\n";
	std::string s = std::to_string(id);
	char const *pchar = s.c_str();
	int checkDelete;
	string query1 = "Select f_available from flightdetails_tb Where ";
	query1.append("f_id = ").append(pchar).append(";");
	cout << "Query: " << query1.c_str() << endl;
	const char* q1 = query1.c_str();
	checkDelete = mysql_query(conn, q1);
	if (checkDelete == 0) {
		res = mysql_store_result(conn);
		if (row = mysql_fetch_row(res)) {
			if (strcmp(row[0], available) == 0) {
				string query = "DELETE FROM flightdetails_tb WHERE ";
				query.append("f_id = ").append(pchar).append(" and ").append(" f_available = 'A';");
				cout << "Query: " << query.c_str() << endl;
				const char* q = query.c_str();
				queryDelete = mysql_query(conn, q);
				cout << "Delete Susccessful!\n" << endl;
			}
			else {
				cout << "Delete UnSusccessful!\n" << endl;
			}
		}
	}
}
void flightDetails() {
	while (true) {
		cout << "------------Welcome To Airlines Reservation System------------\n";
		cout << "------------Airlines Reservation System Menu------------\n";
		cout << "1. Add Flight.\n";
		cout << "2. Edit Flight.\n";
		cout << "3. Delete Flight.\n";
		cout << "4. Flight Leave And Arrive.\n";
		cout << "5. Back To Menu.\n";
		cout << "Choose One:";
		int input;
		input = checkIn(1, 5);
		if (input == 1) {
			Insert();
		}
		if (input == 2) {
			cout << "Edit Flight." << endl;
		}
		if (input == 3) {
			cout << "Delete Flight." << endl;
			flightDelete();
		}
		if (input == 4) {
			cout << "Flight Leave And Arrive." << endl;
		}
		if (input == 5) {
			cout << "Back To Menu" << endl;
			return;
		}
	}
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
			flightDetails();
		}
		if (input == 6) {
			cout << "Exit Program." << endl;
			exit(0);
		}

	}

	return 0;
}
