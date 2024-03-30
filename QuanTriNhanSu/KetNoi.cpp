#include "KetNoi.h"
const char* UserName = "root";
const char* Link = "tcp://localhost:3306";
const char* Password = "21122004";
Connection* KetNoi::CheckDatabase() {
	MySQL_Driver* driver;
	Connection* con;
	driver = mysql::get_mysql_driver_instance();
	con = driver->connect(Link, UserName, Password);
	con->setSchema("quantrinhansu");
	if (con) {
		return con;
	}
	else {
		return con;
	}
}