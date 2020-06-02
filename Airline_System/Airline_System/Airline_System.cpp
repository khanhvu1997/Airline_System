// Airline_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
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

void EditFlight() {
	cout << "Edit Flight." << endl;
	int queryEdit;
	int id = 0;
	string no;
	string name;
	string from;
	string destination;
	string time;
	string amount;
	string available;
	do {
		cout << "Enter the id: \n";
		cin >> id;
		if (!checkId(id)) {
			cout << " Id not exist. Please choise!\n";
		}
	} while (!checkId(id));
	cout << "Id Exist. Edit Data!\n";
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
	std::string s = std::to_string(id);
	char const *pchar = s.c_str();
	string query = "UPDATE flightdetails_tb SET ";
	query.append("f_no ='").append(no).append("',")
		.append("f_name ='").append(name).append("',")
		.append("f_from ='").append(from).append("',")
		.append("f_destination ='").append(destination).append("',")
		.append("f_time ='").append(time).append("',")
		.append("f_amount ='").append(amount).append("',")
		.append("f_available ='").append(available).append("'")
		.append("WHERE f_id =").append(pchar).append(";");
	cout << "Update successful!\n" << endl;
	cout << "Query: " << query.c_str() << endl;
	const char* q = query.c_str();
	queryEdit = mysql_query(conn, q);
	if (queryEdit != 0) {
		cout << mysql_error(conn) << endl;
	}
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
void flightLeaveArrive() {
	cout << "Flight Leave And Arrive." << endl;
	int queryLA;
	int id = 0;
	string leave;
	string arrive;
	string available;
	do {
		cout << "Enter the id: \n";
		cin >> id;
		if (!checkId(id)) {
			cout << " Id not exist. Please choise!\n";
		}
	} while (!checkId(id));
	cout << "Id Exist. Edit Data!\n";
	cout << "Enter the Leave: ";
	cin >> leave;
	cout << "Enter the Arrive: ";
	cin >> arrive;
	cout << "Enter the Available: ";
	cin >> available;
	std::string s = std::to_string(id);
	char const *pchar = s.c_str();
	string query = "UPDATE flightdetails_tb SET ";
	query
		.append("f_leave ='").append(leave).append("',")
		.append("f_arrive ='").append(arrive).append("',")
		.append("f_available ='").append(available).append("'")
		.append("WHERE f_id =").append(pchar).append(";");
	cout << "Update successful!\n" << endl;
	cout << "Query: " << query.c_str() << endl;
	const char* q = query.c_str();
	queryLA = mysql_query(conn, q);
	if (queryLA != 0) {
		cout << mysql_error(conn) << endl;
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
			EditFlight();
		}
		if (input == 3) {
			cout << "Delete Flight." << endl;
			flightDelete();
		}
		if (input == 4) {
			flightLeaveArrive();
		}
		if (input == 5) {
			cout << "Back To Menu" << endl;
			return;
		}
	}
}
void flightSchedule() {
	cout << "Flights Schedule." << endl;
	int qstate;
	string query = "Select f_no,f_name,f_from,f_destination,f_leave,f_arrive from flightdetails_tb where f_available = 'A';";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	if (qstate == 0)
	{
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res)) {
			cout << "\n*****";
			cout << "\nNo: " << row[0];
			cout << "\nName: " << row[1];
			cout << "\nFrom: " << row[2];
			cout << "\nDestination: " << row[3];
			cout << "\nLeave: " << row[4];
			cout << "\nArrive: " << row[5] << "\n";
		}
	}
	else {
		cout << "Query failed" << mysql_error(conn) << endl;
	}
}
void ReserveSeat() {
	cout << "Reserve Seat." << endl;
	int fNo;
	int querySeat;
	string name;
	string phone;
	string passport;
	string ticket;
	string flightNo;
	string address;
	cout << "Enter the Name: \n";
	cin >> name;
	cout << "Enter the Phone: \n";
	cin >> phone;
	cout << "Enter the Passport: \n";
	cin >> passport;
	cout << "Enter the Ticket: \n";
	cin >> ticket;
	cout << "Choise Flight No! \n";
	string query = "Select f_no from flightdetails_tb ";
	vector<string> flightNoTemp;
	const char* q = query.c_str();
	fNo = mysql_query(conn, q);
	if (fNo == 0) {
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res)) {
			cout << "\n*****";
			flightNoTemp.push_back(row[0]);
			cout << "\nFlightNo: " << row[0] << "\n";
		}
	NoAgain:do {
		cout << "Enter the FlightNo: \n";
		cin >> flightNo;
		if (count(flightNoTemp.begin(), flightNoTemp.end(), flightNo)) {
			cout << "Flight No Ok!\n";
			cout << "Enter the Address: \n";
			cin >> address;
			string query = "INSERT INTO userreservation_tb (u_name,u_phone,u_passportno,u_ticket,u_flightno,u_address) VALUES ( ";
			query.append("'").append(name).append("',")
				.append("'").append(phone).append("',")
				.append("'").append(passport).append("',")
				.append("'").append(ticket).append("',")
				.append("'").append(flightNo).append("',")
				.append("'").append(address).append("');");
			cout << "Insert Reserve Seat Successful!\n" << endl;
			const char* q = query.c_str();
			querySeat = mysql_query(conn, q);
			if (querySeat != 0) {
				cout << mysql_error(conn) << endl;
			}
		}
		else {
			cout << "Flight No not a valid!\n";
			goto NoAgain;
		}
	} while (!(count(flightNoTemp.begin(), flightNoTemp.end(), flightNo)));
	}

}
void UserTicket() {
	cout << "User Ticket." << endl;
	int queryTicket;
	string ticket;
	cout << "Enter the Ticket: \n";
	cin >> ticket;
	string query = "Select * from userreservation_tb Where ";
	query.append("u_ticket like ").append("'%").append(ticket).append("%';");
	const char* q = query.c_str();
	queryTicket = mysql_query(conn, q);
	if (queryTicket == 0) {
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res)) {
			cout << "Info User Ticket.\n" << endl;
			cout << "\n*****";
			cout << "\nName: " << row[1];
			cout << "\nPhone: " << row[2];
			cout << "\nPassport: " << row[3];
			cout << "\nTicket: " << row[4];
			cout << "\nFlightNo: " << row[5];
			cout << "\nAddress: " << row[6] << "\n";
		}
		if (!(row = mysql_fetch_row(res))) {
			cout << "Ticket not exist!" << endl;
		}
	}
}
int main() {
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
			ReserveSeat();
		}
		if (input == 2) {
			UserTicket();
		}
		if (input == 3) {
			flightSchedule();
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
