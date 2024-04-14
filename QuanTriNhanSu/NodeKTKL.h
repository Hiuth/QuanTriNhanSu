#pragma once
#include<iostream>
#include <string>
using namespace std;
class NodeKTKL {
private:
	string MaNhanVien;
	string TenNhanVien;
	string Thuong;
	string Phat;
	string NDT;
	string NDP;
	NodeKTKL* pointer;
public:
	NodeKTKL(string, string, string, string, string, string);
	virtual ~NodeKTKL();

	string getTen() { return TenNhanVien; }
	void setTen(string val) { TenNhanVien = val; }
	string getMa() { return MaNhanVien; }
	void setMa(string val) { MaNhanVien = val; }

	string getT() { return Thuong; }
	void setT(string val) { Thuong = val; }
	string getP() { return Phat; }
	void setP(string val) { Phat = val; }

	string getNDT() { return NDT; }
	void setNDT(string val) { NDT = val; }
	string getNDP() { return NDP; }
	void setNDP(string val) { NDP = val; }

	NodeKTKL* getPointer() { return pointer; }
	void setPointer(NodeKTKL* val) { pointer = val; }
};