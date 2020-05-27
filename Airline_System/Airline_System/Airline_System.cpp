// Airline_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdlib.h>
#include <iostream>
#include "mysql.h"

/*#define SERVER "localhost"
#define USER "root"
#define PASSWORD "1997"
#define DATABASE "cpp_airlinereservation_db" */
using namespace std;
int qstate;
int main() 
{
    cout << "Hello World!\n";
	system("pause");
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "127.0.0.1", "root", "1997", "cpp_airlinereservation_db",3306,NULL,0);
	if( conn) { 
		puts("Successfull connection to database!");
		
		/*string query = "Select * from flightdetails_tb";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res)) {
				printf("Id: %s,No: %s,Name: %s,From: %s,Destination: %s,Time: %s,Amount: %s,Leave: %s,Arrive: %s,available: %s \n", 
					row[0],row[1],row[2],row[3],row[4],row[5],row[6],row[7],row[8],row[9]);
			}
		}
		else {
			cout << "Query failed" << mysql_error(conn) << endl;
		}*/
	}
	else {
		puts("Connection to database failded!");
	}

	return 0;
}
