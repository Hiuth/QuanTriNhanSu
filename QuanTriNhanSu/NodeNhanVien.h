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
	string MaNhanVien;
	string ThoiHanHopDong;
	string sdt;
	NodeNhanVien* pointer;
public:
	NodeNhanVien(string, string, string,string, string, string, string, string,string,string);
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
	NodeNhanVien* GetPointer() { return pointer; }
	void SetPointer(NodeNhanVien* val) { pointer = val; }
	string GetEmployeeID() { return MaNhanVien; }
	void SetEmployeeID(string val) { MaNhanVien = val; }
	string GetPhoneNumber() { return sdt; }
	void SetPhoneNumber(string val) { sdt = val; }
	string GetContractTerm() { return ThoiHanHopDong; }// contract term  =  thời hạn hợp đồng
	void SetContractTerm(string val) { ThoiHanHopDong = val; }
};

