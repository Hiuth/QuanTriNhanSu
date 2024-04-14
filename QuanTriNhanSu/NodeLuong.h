#pragma once
#include<string>
#include<iostream>
using namespace std;
class NodeLuong
{
private:
	string MaNhanVien;
	string TenNhanVien;
	int DiemDanh;
	int TienCong;
	int KhenThuong;
	int KyLuat;
	int BaoHiem;
	long long TongCong;
	NodeLuong* pointer;
public:
	NodeLuong(string, string, int, int,int,int,int,long long);
	virtual ~NodeLuong();

	NodeLuong* GetPointer() { return pointer; }
	void SetPointer(NodeLuong* val) { pointer = val; }

	string GetID() { return MaNhanVien; }
	void SetID(string val) { MaNhanVien = val; }

	string GetName() { return TenNhanVien; }
	void SetName(string val) { TenNhanVien = val; }

	int GetDD() { return DiemDanh; }
	void SetDD(int val) { DiemDanh = val; }

	int GetTC() { return TienCong; }
	void SetTC(int val) { TienCong = val; }

	int GetKT() { return KhenThuong; }
	void SetKT(int val) { KhenThuong = val; }

	int GetKL() { return KyLuat; }
	void SetKKL(int val) { KyLuat = val; }

	int GetBH() { return BaoHiem; }
	void SetBH(int val) { BaoHiem = val; }

	long long GetTongCong() { return TongCong; }
	void SetTongCong(int val) { TongCong = val; }
};

