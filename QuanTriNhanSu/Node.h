#pragma once
#include<iostream>
#include<string>
using namespace std;
class Node
{
private:
	//Tai khoan
	string TenTaiKhoan;
	string MatKhau;
	string Admin;
	string QuanLyNhanSu;
	string QuanLyTienLuong;

	//
	Node* pointer;
public:
	Node(string,string,string,string,string);

	virtual ~Node();
	Node* GetPointer() { return pointer; }
	void SetPointer(Node* val) { pointer = val; }
	//Tai khoan
	string GetAccountName() { return TenTaiKhoan; }
	void SetAccountName(string val) { TenTaiKhoan = val; }
	string GetPassword() { return MatKhau; }
	void SetPassword(string val) { MatKhau = val; }
	string GetAdmin() { return Admin; }
	void SetAdmin(string val) { Admin = val; }
	string GetHRM() { return QuanLyNhanSu; }
	void SetHRM(string val) { QuanLyNhanSu = val; }
	string GetFM() { return QuanLyTienLuong; }//financial management
	void SetFM(string val) { QuanLyTienLuong = val; }
	//
protected:
};

