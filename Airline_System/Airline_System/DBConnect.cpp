#include "DBConnect.h"

void DbConn() {
	int qstate;
	MYSQL* conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "127.0.0.1", "root", "1997", "cpp_airlinereservation_db", 3306, NULL, 0);
	if (conn) {
		puts("Successfull connection to database!");
		qstate = mysql_query(conn, "Select * from flightdetails_tb");
		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res)) {
				printf("Id: %s,No: %s,Name: %s,From: %s,Destination: %s,Time: %s,Amount: %s,Leave: %s,Arrive: %s,Available: %s \n",
					row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9]);
			}
		}
		else {
			cout << "Query failed" << mysql_error(conn) << endl;
		}
	}
	else {
		puts("Connection to database failded!");
	}
}
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