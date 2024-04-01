#pragma once
#include "Node.h"
class NodeNhanVien
{
private:
	string TenNhanVien;
	string SinhNhat;
	string CCCD;
	string DiaChi;
	string GioiTinh;
	string ChucVu;
	string PhongBan;
public:
	NodeNhanVien(string, string, string, string, string, string, string);
	virtual ~NodeNhanVien();
	string GetName() { return TenNhanVien; }
	void SetName(string val) { TenNhanVien = val; }
	string GetBirthday() { return SinhNhat; }
	void SetBirthday(string val) { SinhNhat = val; }
	string GetAddress() { return DiaChi; }
	void SetAddress(string val) { DiaChi = val; }
	string GetSex() { return GioiTinh; }
	void SetSex(string val) { GioiTinh = val; }
	string GetIDCard() { return CCCD; }
	void SetIDCard(string val) { CCCD = val; }
	string GetDepartment() { return PhongBan; }
	void SetDepartment(string val) { PhongBan = val; }
	string GetPost() { return ChucVu; }//post = chức vụ
	void SetPost(string val) { ChucVu = val; }
};

