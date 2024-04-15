#include "KetNoi.h"
const char* UserName = "root";
const char* Link = "tcp://localhost:3306";
const char* Password = "02012004";
Connection* KetNoi::CheckDatabase() {
	MySQL_Driver* driver;
	Connection* con;
	driver = mysql::get_mysql_driver_instance();
	con = driver->connect(Link, UserName, Password);

	Statement* stmt = con->createStatement();
	stmt->execute("CREATE SCHEMA IF NOT EXISTS quantrinhansu");

	con->setSchema("quantrinhansu");
	if (con) {
		return con;
	}
	else {
		return con;
	}
}