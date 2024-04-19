﻿#include "KetNoi.h"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

const char* Link = "tcp://localhost:3306";
//const char* Password = "21122004";
//const char* UserName = "root";

void createTableHeThonng(Connection* con) {
	Statement* stmt;
	stmt = con->createStatement();
	string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
	string useDatabase = "Use QuanTriNhanSu";
	string CreateTableAccount = "create table if not exists TaiKhoan (""TenTaiKhoan char(10) primary key,"
		"MatKhau char(20) not null,""admin bool not null, "
		"QuanLyNhanSu bool not null, "
		"QuanLyTienLuong bool not null)"; //1 là có quyền truy cập, 0 là không có quyền truy cập vào chức năng
	stmt->execute(CreateDatabaseSQL);
	stmt->execute(useDatabase);
	stmt->execute(CreateTableAccount);
}

void createTableNhanVien(Connection* con) {
	Statement* stmt;
	stmt = con->createStatement();
	string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
	string useDatabase = "Use QuanTriNhanSu";
	string CreateTableAccount = "create table if not exists NhanVien ("
		"TenNhanVien char(30) not null,"
		"GioiTinh char(10) not null,"
		"SinhNhat char(10) not null,"
		"MaNhanVien char(12) primary key not null,"
		"SoDienThoai LONGTEXT not null,"
		"CCCD char(12) not null,"
		"DiaChi char(100) not null,"
		"PhongBan char(20) not null,"
		"ChucVu char(100) not null,"
		"ThoiHanHopDong char(30) not null);";

	//1 là có quyền truy cập, 0 là không có quyền truy cập vào chức năng
	stmt->execute(CreateDatabaseSQL);
	stmt->execute(useDatabase);
	stmt->execute(CreateTableAccount);
}

void createTableChucVu(Connection* con) {
	Statement* stmt;
	stmt = con->createStatement();
	string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
	string useDatabase = "Use QuanTriNhanSu";
	string CreateTableAccount = "CREATE TABLE IF NOT EXISTS ChucVu (""TenChucVu CHAR(100) not null PRIMARY KEY,"
		"LuongChucVu LONGTEXT not null, "
		"MoTaChucVu CHAR(100) not null)";
	stmt->execute(CreateDatabaseSQL);
	stmt->execute(useDatabase);
	stmt->execute(CreateTableAccount);
}

void createTablePhongBan(Connection* con) {
	Statement* stmt;
	stmt = con->createStatement();
	string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
	string useDatabase = "Use QuanTriNhanSu";
	string CreateTableAccount = "create table if not exists  PhongBan (TenPhong char(100) not null, MaPhong char(10) primary key not null);";
	stmt->execute(CreateDatabaseSQL);
	stmt->execute(useDatabase);
	stmt->executeUpdate(CreateTableAccount);
}

void createTableTienLuong(Connection* con) {
	Statement* stmt;
	stmt = con->createStatement();
		string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
		string useDatabase = "Use QuanTriNhanSu";
		string CreateTableAccount = "CREATE TABLE IF NOT EXISTS BangLuong ("
			"MaNhanVien CHAR(12) NOT NULL, "
			"TenNhanVien CHAR(30) NOT NULL, "
			"SoNgayDiLam INT(3) NOT NULL, "
			"TienCongNgay INT(10) NOT NULL, "
			"KhoanKhenThuong INT(10) NOT NULL, "
			"KhoanKyLuat INT(10) NOT NULL, "
			"BaoHiem INT(10) NOT NULL, "
			"TongCong TEXT NOT NULL"
			");";
		stmt->execute(CreateDatabaseSQL);
		stmt->execute(useDatabase);
		stmt->execute(CreateTableAccount);
}

void createTableBaoHiem(Connection* con) {
	Statement* stmt;
	stmt = con->createStatement();
	string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
	string useDatabase = "Use QuanTriNhanSu";
	string CreateTableAccount = "create table if not exists BaoHiem (""MaBaoHiem char(10) not null ,""SoTien char(7) not null,""Han char(10) not null)";
	stmt->execute(CreateDatabaseSQL);
	stmt->execute(useDatabase);
	stmt->execute(CreateTableAccount);
}

void createTableKTKL(Connection* con) {
	Statement* stmt;
	stmt = con->createStatement();
	string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
	string useDatabase = "Use QuanTriNhanSu";
	string CreateTableAccount = "CREATE TABLE IF NOT EXISTS KhenThuongKyLuat ("
		"MaNhanVien CHAR(30) NOT NULL, "
		"TenNhanVien CHAR(30) NOT NULL, "
		"Thuong CHAR(10) NOT NULL, "
		"Phat CHAR(10) NOT NULL, "
		"NoiDungThuong CHAR(30) NOT NULL, "
		"NoiDungPhat CHAR(30) NOT NULL"
		")";
	stmt->execute(CreateDatabaseSQL);
	stmt->execute(useDatabase);
	stmt->execute(CreateTableAccount);
}

void createTableDiemDanh(Connection* con) {
	Statement* stmt;
	stmt = con->createStatement();
	string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
	string useDatabase = "Use QuanTriNhanSu";
	string CreateTableAccount = "create table if not exists BangDiemDanh (""MaNhanVien char(10) not null ,""TenNhanVien char(10) not null ,""DiemDanh char(3) not null)";
	stmt->execute(CreateDatabaseSQL);
	stmt->execute(useDatabase);
	stmt->execute(CreateTableAccount);
}



Connection* KetNoi::CheckDatabase() {
	const char* User{};
	const char* Pass{};
	string tenfile = "MySql.txt";
	ifstream file(tenfile);
	if (file.is_open()) {
		// Đọc dữ liệu từ file và lưu vào các biến User và Pass
		string userStr, passStr;
		file >> userStr >> passStr;

		// Sao chép dữ liệu từ std::string sang const char*
		User = _strdup(userStr.c_str());
		Pass = _strdup(passStr.c_str());
		file.close();
	}
	else {
		std::cerr << "Không thể mở tệp: " << "MySql" << std::endl;
	}
	KetNoi check{};
	MySQL_Driver* driver;
	Connection* con;
	driver = mysql::get_mysql_driver_instance();
	con = driver->connect(Link,User ,Pass);
	Statement* stmt = con->createStatement();
	stmt->execute("CREATE SCHEMA IF NOT EXISTS quantrinhansu");

	con->setSchema("quantrinhansu");
	if (con) {
		createTableHeThonng(con);
		createTableNhanVien(con);
		createTableChucVu(con);
		createTablePhongBan(con);
		createTableTienLuong(con);
		createTableBaoHiem(con);
		createTableKTKL(con);
		createTableDiemDanh(con);
		return con;
	}
	else {
		return con;
	}
}

