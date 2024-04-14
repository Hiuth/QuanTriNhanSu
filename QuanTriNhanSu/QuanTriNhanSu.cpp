#include<iostream>
#include"HeThong.h"
#include"KetNoi.h"
#include"NhanVien.h"
#include "ChucVu.h"
#include "PhongBan.h"
#include <string>
#include <vector>
using namespace std;

int main() {
	HeThong* Taikhoan = new HeThong();
	NhanVien* Ktra = new NhanVien();
	ChucVu* kt = new ChucVu();
	PhongBan* PB = new PhongBan();
	//Taikhoan->InputSearch();
	//Taikhoan->InputEdit();
	Taikhoan->PrintAccount(Taikhoan->TakeAllAccount());
	cout << endl;
	Ktra->PrintEmployeeInfotmation(Ktra->TakeAllEmployee());
//	Taikhoan->Input();
	//if (Taikhoan->DangNhap()) {
	//	cout << "Chao mung ban tro lai!!!"<<endl;
	//	//Chuc vu
	//	kt->InputPosition();
	////	kt->InputDetletePosition();
	//	kt->PrintPosition();
	//	cout << endl;
	//	//Phong ban
	//	PB->InputDepartment();
	//	PB->PrintDepartmentInfotmation();
	//	//He Thong
	//	Taikhoan->Input();
	//	Taikhoan->InputSearch();
	//	Taikhoan->InputEdit();
	//	Taikhoan->PrintAccount();
	//	Taikhoan->~HeThong();
	//	cout << endl;
	//	//Nhan vien
	//	Ktra->InputEmployee();
	//	Ktra->InputSearchEmployee();
	//	Ktra->InputEditEmployee();
	//	cout << endl;

	//}
	//else {
	//	cout << "Mat khau hoac tai khoan bi loi!!" << endl;
	//}
	
	//Ktra->InputEmployee();
	//Ktra->PrintEmployeeInfotmation();
}	
