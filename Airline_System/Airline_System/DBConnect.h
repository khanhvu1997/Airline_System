#pragma once
#include <stdlib.h>
#include <iostream>
#include "mysql.h"
using namespace std;
#define  IP  "127.0.0.1"
#define  USERNAME  "root"
#define  PASSWORD  "1997"
#define  DB_NAME  "cpp_airlinereservation_db"
class DBConnect
{

public:

	static MYSQL* initConnect()
	{
		MYSQL* conn = new MYSQL();
		conn = mysql_init(0);
		if (conn)
		{
			cout << "Database Connected" << endl;
			cout << "Press any key to continue..." << endl;
			system("cls");
		}
		else
			cout << "Failed To Connect!" << mysql_errno(conn) << endl;
		conn = mysql_real_connect(conn, IP, USERNAME, PASSWORD, DB_NAME, 0, NULL, 0);
		if (conn)
		{
			cout << "Database Connected To MySql" << conn << endl;
			cout << "Press any key to continue..." << endl;
			system("cls");
		}
		else
			cout << "Failed To Connect!" << mysql_errno(conn) << endl;
		return conn;
	}
};
