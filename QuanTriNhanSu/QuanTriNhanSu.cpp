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
	string tenSql, mkSql;
	HeThong* Taikhoan = new HeThong();
	NhanVien* Ktra = new NhanVien();
	ChucVu* kt = new ChucVu();
	PhongBan* PB = new PhongBan();
	KetNoi* kn = new KetNoi();
	//Taikhoan->InputSearch();
	//Taikhoan->InputEdit();
	Taikhoan->PrintAccount(Taikhoan->TakeAllAccount());
	cout << endl;
	Ktra->PrintEmployeeInfotmation(Ktra->TakeAllEmployee());
	cout << endl;
	kt->PrintPosition(kt->TakeAllPosition());
	cout << endl;
	kt->PrintPosition(kt->TakeAllPosition());
	cout << endl;
	Taikhoan->Input();
	Taikhoan->InputEdit();
	//Taikhoan->PrintAccount(Taikhoan->TakeAllAccount());
	//if (Taikhoan->DangNhap()) {
	//	cout << "Chao mung ban tro lai!!!"<<endl;
	//	//Chuc vu
	//	kt->InputPosition();
	//kt->InputDetletePosition();
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
		cout << endl;
		//PB->InputDepartment();
		cout << endl;
		PB->PrintDepartmentInfotmation(PB->TakeAllDepartment());
		cout << endl;
		//PB->InputEditDepartment();
		

	//}
	//else {
	//	cout << "Mat khau hoac tai khoan bi loi!!" << endl;
	//}
	
	//Ktra->InputEmployee();
	//Ktra->PrintEmployeeInfotmation();
}	
