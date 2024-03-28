#pragma once
#include<iostream>
class Node
{
private:
	long TenTaiKhoan;
	int MatKhau;
	int Admin;
	int QuanLyNhanSu;
	int QuanLyTienLuong;
	Node* pointer;
public:
	Node();
	Node(long, int, int, int, int);
	virtual ~Node();
	Node* GetPointer() { return pointer; }
	void SetPointer(Node* val) { pointer = val; }
	void SetPointer(Node* val) { pointer = val; }
	long GetAccountName() { return TenTaiKhoan; }
	void SetAccountName(long val) { TenTaiKhoan = val; }
	int GetPassword() { return MatKhau; }
	void SetPassword(int val) { MatKhau = val; }
	int GetAdmin() { return Admin; }
	void SetAdmin(int val) { Admin = val; }
	int GetHRM() { return QuanLyNhanSu; }
	void SetHRM(int val) { QuanLyNhanSu = val; }
	int GetFM() { return QuanLyTienLuong; }//financial management
	void SetFM(int val) { QuanLyTienLuong = val; }

protected:
};

