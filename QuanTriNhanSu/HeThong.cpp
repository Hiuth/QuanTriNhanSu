#include "HeThong.h"
#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/statement.h> 
#include <iostream> 
#include <mysql_connection.h> 
#include <mysql_driver.h> 
#include <iostream>
using namespace std;
using namespace sql;
using namespace mysql;

void HeThong::CreateAccount() {
    Node* p;
    MySQL_Driver* driver;
    Connection* con;
    driver = get_mysql_driver_instance();
    con = driver->connect("tcp://localhost::3306", "root", "21122004");
    con->setSchema("QuanTriNhanSu");//Ten cua database
    Statement* stmt;
    stmt = con->createStatement();
    //Tao bang
    string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
    string useDatabase = "Use QuanTriNhanSu";
    string CreateTableAccount = "create table if not exits TaiKhoan (""TenTaiKhoan int not null primary key,""MatKhau int not null,""admin int not null, ""QuanLyNhanSu int not null, ""QuanLyTienLuong int not null)";
    string InsertTableAccount = "insert into TaiKhoan Values ('') "
}
    //try {
    //    sql::mysql::MySQL_Driver* driver;
    //    sql::Connection* con;

    //    driver = sql::mysql::get_mysql_driver_instance();
    //    con = driver->connect("tcp://localhost:3306",
    //        "root", "21122004");

    //    con->setSchema("quanlisv"); // your database name 

    //    sql::Statement* stmt;
    //    stmt = con->createStatement();

    //    // SQL query to create a table 
    //    //string createTableSQL
    //    //    = "CREATE TABLE IF NOT EXISTS GFGCourses (""id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,""courses VARCHAR(255) NOT NULL"
    //    //    ")";

    ///*    stmt->execute(createTableSQL);*/

    //   /* string insertDataSQL
    //        = "INSERT INTO GFGCourses (courses) VALUES "
    //        "('DSA'),('C++'),('JAVA'),('PYTHON')";*/

    //        /*stmt->execute(insertDataSQL);*/

    //        // SQL query to retrieve data from the table 
    //    string selectDataSQL = "SELECT * FROM Subject";

    //    sql::ResultSet* res
    //        = stmt->executeQuery(selectDataSQL);

    //    // Loop through the result set and display data 
    //    int count = 0;
    //    while (res->next()) {
    //        cout << "SubjectName " << ++count << ": "
    //            << res->getString("SubjectName") << endl;
    //    }

    //    delete res;
    //    delete stmt;
    //    delete con;
    //}
    //catch (sql::SQLException& e) {
    //    std::cerr << "SQL Error: " << e.what() << std::endl;
    //}

    //return 0;