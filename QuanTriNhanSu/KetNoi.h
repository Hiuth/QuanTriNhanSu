#pragma once
#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/statement.h> 
#include <mysql_connection.h> 
#include <mysql_driver.h> 
#include <iostream>
using namespace std;
using namespace sql;
using namespace mysql;
class KetNoi
{
public:
	Connection* CheckDatabase();
};

