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
	bool Admin;
	bool QuanLyNhanSu;
	bool QuanLyTienLuong;

	//
	Node* pointer;
public:
	Node(string,string,bool,bool,bool);

	virtual ~Node();
	Node* GetPointer() { return pointer; }
	void SetPointer(Node* val) { pointer = val; }
	//Tai khoan
	string GetAccountName() { return TenTaiKhoan; }
	void SetAccountName(string val) { TenTaiKhoan = val; }
	string GetPassword() { return MatKhau; }
	void SetPassword(string val) { MatKhau = val; }
	bool GetAdmin() { return Admin; }
	void SetAdmin(bool val) { Admin = val; }
	bool GetHRM() { return QuanLyNhanSu; }
	void SetHRM(bool val) { QuanLyNhanSu = val; }
	bool GetFM() { return QuanLyTienLuong; }//financial management
	void SetFM(bool val) { QuanLyTienLuong = val; }
	//
protected:
};

