#pragma once
#include<iostream>
using namespace std;
class NodeBaoHiem
{
private:
	//string TenNhanVien;
	string MaBaoHiem;
	string SoTien;
	string Han;
	NodeBaoHiem* pointer;
public:
	NodeBaoHiem(string, string, string);
	virtual ~NodeBaoHiem();

	NodeBaoHiem* GetPointer() { return pointer; }
	void SetPointer(NodeBaoHiem* val) { pointer = val; }

	/*string GetTen() { return TenNhanVien; }
	void SetTen(string val) { TenNhanVien = val; }*/
	string GetMa() { return MaBaoHiem; }
	void SetMa(string val) { MaBaoHiem = val; }
	string GetSoTien() { return SoTien; }
	void SetSoTien(string val) { SoTien = val; }
	string GetHan() { return Han; }
	void SetHan(string val) { Han = val; }
};

