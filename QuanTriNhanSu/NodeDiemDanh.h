#pragma once
#include<string>
#include<iostream>
using namespace std;
class NodeDiemDanh
{
private:
	string MaNhanVien;
	string TenNhanVien;
	string DiemDanh;
	NodeDiemDanh* pointer;
public:
	NodeDiemDanh(string, string,string);
	virtual ~NodeDiemDanh();

	NodeDiemDanh* GetPointer() { return pointer; }
	void SetPointer(NodeDiemDanh* val) { pointer = val; }

	string GetID() { return MaNhanVien; }
	void SetID(string val) { MaNhanVien = val; }
	string GetName() { return TenNhanVien; }
	void SetName(string val) { TenNhanVien = val; }
	string GetAttendanceCheck() { return DiemDanh; }
	void SetAttendanceCheck(string val) { DiemDanh = val; }

};

