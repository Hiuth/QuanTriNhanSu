#include<iostream>
#include"HeThong.h"
#include"KetNoi.h"
#include"NhanVien.h"
#include "ChucVu.h"
#include "PhongBan.h"
#include <string>
#include <vector>
using namespace std;
void check(int chon2, string quyen, string Tentk) {
	HeThong* Taikhoan = new HeThong();
	if (chon2 == 1) {
		Taikhoan->EditAccount(quyen, "1", Tentk);
	}
	else if (chon2 == 0) {
		Taikhoan->EditAccount(quyen, "0", Tentk);
	}
	else {
		cout << "Vui long chon lai!" << endl;
	}
}

using namespace std;
int main() {
	int n, chon, nhap;
	long luong;
	string tk, mk, admin, hrm, fm, ten, xoa, ma, chucvu, phongban, gioitinh, sinhnhat, cccd, diachi, manhanvien;
	HeThong* Taikhoan = new HeThong();
	Node* e;
	//cout << "Hay dang nhap vao he thong" << endl;
	//cout << "Nhap ten tai khoan: "; getline(cin, ten);
	//cout << "Nhap vao mat khau: "; getline(cin, mk);
	//if (Taikhoan->CheckAccount(ten, mk) == true) {
	//	cout << "Tai khoan co ton tai. Chao mung ban quay lai!"<<endl;
	//}
	//else {
	//	cout << "Tai khoan khong ton tai. Lien he nhan vien de " << endl;
	//}

	//cout << "so luong tai khoan muon nhap vao: "; cin >> n; //ko chấp nhận đc vẫn để là "tai khoang"
	//for (int i = 0; i < n; i++) {
	//	cout << "Tai khoan: "; cin >> tk;
	//	cout << "Mat khau: "; cin >> mk;
	//	cout << "Neu muon cap quyen thi hay bam so 1, neu khong thi bam so 0." << endl;;
	//	cout << "Quyen admin: "; cin >> admin;
	//	cout << "Quyen quan ly nhan su: "; cin >>hrm;
	//	cout << "Quyen quan ly tien luong: "; cin >> fm;
	//	e = new Node(tk, mk, admin, hrm, fm);
	//	Taikhoan->CreateAccount(e);
	//	cout << endl;
	//}
	//Taikhoan->PrintAccount();
	//cout << "1.Tim kiem theo quyen admin." << endl;
	//cout << "2.Tim kiem theo quyen quan ly nhan su." << endl;
	//cout << "3.Tim kiem theo quyen quan ly Tien Luong." << endl;
	//cout << "4.Tim kiem theo ten tai khoan." << endl;
	//cout << "Ban muon chon theo gi ? "; cin >> chon;
	//if (chon == 1) {
	//	Taikhoan->Search("admin", "1");
	//}
	//else if(chon == 2) {
	//	Taikhoan->Search("QuanLyNhanSu", "1");
	//}
	//else if (chon == 3) {
	//	Taikhoan->Search("QuanLyTienLuong", "1");
	//}
	//else if (chon == 4) {
	//	cout << "Nhap vao Ten tai khoan: "; getline(cin, ten);
	//	Taikhoan->Search("TenTaiKhoan", ten);
	//}
	//else {
	//	cout << "Khong co so ma ban da chon. Vui long nhap lai!"<<endl;
	//}
	Taikhoan->PrintAccount();
	cout << endl;
	//cout << "Nhap vao ten tai khoan can chinh sua: "; cin >> ten;
	//Taikhoan->Search("TenTaiKhoan", ten);
	//cout << "Chon che do chinh sua! " << endl;
	//cout << "1. Sua ten Tai Khoan." << endl;
	//cout << "2. Sua mat khau." << endl;
	//cout << "3. Sua cac quyen." << endl;
	//cout << "Ban muon chon gi ? "; cin >> chon;
	//if (chon == 1) {
	//	cin.ignore();
	//	cout << "Nhap vao ten muon doi: "; getline(cin, ma);
	//	cout << ten<<" "<<ma;
	//	Taikhoan->EditAccount("TenTaiKhoan", ma, ten);//Thứ tự tên tài khoản, tên muốn đổi, vị trí cần đổi
	//}
	//else if (chon == 2) {
	//	cin.ignore();
	//	cout << "Nhap vao mat khau moi: "; getline(cin, mk);
	//	Taikhoan->EditAccount("MatKhau",mk,ten);
	//}
	//else if (chon == 3) {
	//	cout << "Ban da chon che do sua cac quyen. " << endl;
	//	cout << "1. Sua quyen admin." << endl;
	//	cout << "2. Sua quyen quan ly nhan su." << endl;
	//	cout << "3. Sua quyen quan ly tien luong." << endl;
	//	cout << "Ban muon chon gi ?"; cin >> chon;
	//	cout << "Ban muon Them hay xoa quyen nay ? Neu ban muon them hay bam so 1 neu ban muon xoa thi hay bam so 0: "; cin >> nhap;
	//	if (chon == 1) {
	//		check(nhap, "admin", ten);
	//	}
	//	else if (chon == 2) {
	//		check(nhap, "QuanLyNhanSu",ten );
	//	}
	//	else if (chon == 3) {
	//		check(nhap, "QuanLyTienLuong", ten);
	//	}
	//	else {
	//		cout << "Khong co lua chon nay vui long nhap lai!!!" << endl;
	//	}
	//}
	//Taikhoan->PrintAccount();
	/*cout << "Nhap vao ten tai khoan muon xoa: "; getline(cin, xoa);
	Taikhoan->deleteAccount(xoa);*/
	Taikhoan->~HeThong();


	//Node Nhan Vien


	//NhanVien* Ktra = new NhanVien();
	//NodeNhanVien* p;
	//cout << "so luong nhan vien muon nhap vao: "; cin >> n;
	//for (int i = 0; i < n; i++) {
	//	cin.ignore();
	//	cout << "nhap vao ten nhan vien: "; getline(cin, tk);
	//	cout << "nhap vao gioi tinh: "; cin >> gioitinh;
	//	cout << "nhap vao sinh nhat: "; cin >> sinhnhat;
	//	cin.ignore();
	//	cout << "nhap vao can cuoc cong dan (cccd): "; getline(cin, cccd);
	//	cout << "nhap vao dia chi nha: ";  getline(cin, diachi);
	//	cout << "nhap vao phong ban: ";  getline(cin, phongban);
	//	cout << "nhap vao chuc vu: "; getline(cin, chucvu);
	//	cout << chucvu << endl;
	//	cout << "Nhap vao ma nhan vien: "; getline(cin, manhanvien);
	//	cout << manhanvien << endl;
	//	p = new NodeNhanVien(tk, sinhnhat, gioitinh, cccd, diachi, chucvu, phongban, manhanvien);
	//	Ktra->CreateName(p);
	//	cout << endl;
	//}
	//Ktra->PrintEmployeeInfotmation();
	//cout << "1.Tim kiem theo ten nhan vien." << endl;
	//cout << "2.Tim kiem theo gioi tinh ." << endl;
	//cout << "3.Tim kiem theo sinh nhat." << endl;
	//cout << "4.Tim kiem theo can cuoc cong dan." << endl;
	//cout << "5.Tim kiem theo phong ban." << endl;
	//cout << "6.Tim kiem theo chuc vu." << endl;
	//cout << "7.Tim kiem theo ma nhan vien." << endl;
	//cout << "Ban muon chon theo gi ? "; cin >> chon;
	//cin.ignore();
	//if (chon == 1) {
	//	cout << "nhap vao ten tai khoan: "; getline(cin, ten);
	//	Ktra->SearchEmployee("TenNhanVien", ten);
	//}
	//else if (chon == 2) {
	//	cout << "Nhap vao gioi tinh: "; cin >> gioitinh;
	//	Ktra->SearchEmployee("GioiTinh", gioitinh);
	//}
	//else if (chon == 3) {
	//	cout << "Nhap vao sinh nhat: "; cin >> sinhnhat;
	//	Ktra->SearchEmployee("SinhNhat", sinhnhat);
	//}
	//else if (chon == 4) {
	//	cout << "Nhap vao can cuoc cong dan: "; cin >> cccd;
	//	Ktra->SearchEmployee("CCCD", cccd);
	//}
	//else if (chon == 5) {
	//	cout << "Nhao vao phong ban: "; getline(cin, phongban);
	//	Ktra->SearchEmployee("PhongBan", phongban);
	//}
	//else if (chon == 6) {
	//	cout << "Nhap vao chuc vu: "; getline(cin, chucvu);
	//	Ktra->SearchEmployee("ChucVu", chucvu);
	//}
	//else if (chon == 7) {
	//	cout << "Nhap vao ma nhan vien: "; getline(cin, manhanvien);
	//	Ktra->SearchEmployee("MaNhanVien", manhanvien);
	//}
	//else {
	//	cout << "khong co so ma ban da chon. vui long nhap lai!" << endl;
	//	//}
	//	//cout << "Nhap vao ten nhan vien muon xoa: "; getline(cin, xoa);
	//	//Ktra->DeleteEmployee(xoa);

	//	cout << "Nhap vao nhan vien can chinh sua: "; getline(cin, ten);
	//	Ktra->SearchEmployee("TenNhanVien", ten);
	//	cout << "Chon che do chinh sua! " << endl;
	//	cout << "1. Sua ten nhan vien." << endl;
	//	cout << "2. Sua gioi tinh." << endl;
	//	cout << "3. Sua sinh nhat." << endl;
	//	cout << "4. Sua can cuoc cong dan." << endl;
	//	cout << "5. Sua dia chi." << endl;
	//	cout << "6. Sua phong ban." << endl;
	//	cout << "7.Sua chuc vu." << endl;
	//	cout << "8. Sua ma nhan vien." << endl;
	//	cout << "Ban muon chon gi ? "; cin >> chon;
	//	cin.ignore();
	//	if (chon == 1) {
	//		cout << "Nhap vao ten muon doi: "; getline(cin, ma);
	//		cout << ten << " " << ma;
	//		Ktra->EditInformation("TenNhanVien", ma, ten);//Thứ tự tên tài khoản, tên muốn đổi, vị trí cần đổi
	//	}
	//	else if (chon == 2) {
	//		cout << "Nhap vao gioi tinh moi: "; getline(cin, mk);
	//		Ktra->EditInformation("GioiTinh", mk, ten);
	//	}
	//	else if (chon == 3) {
	//		cout << "Nhap vao sinh nhat moi: "; getline(cin, sinhnhat);
	//		Ktra->EditInformation("SinhNhat", sinhnhat, ten);
	//	}
	//	else if (chon == 4) {
	//		cout << "Nhap vao can cuoc cong dan moi: "; getline(cin, cccd);
	//		Ktra->EditInformation("CCCD", cccd, ten);
	//	}
	//	else if (chon == 5) {
	//		cout << "Nhap vao dia chi moi: "; getline(cin, diachi);
	//		Ktra->EditInformation("DiaChi", diachi, ten);
	//	}
	//	else if (chon == 6) {
	//		cout << "Nhap vao phong ban moi: "; getline(cin, phongban);
	//		Ktra->EditInformation("PhongBan", phongban, ten);
	//	}
	//	else if (chon == 7) {
	//		cout << "Nhap vao chuc vu moi: "; getline(cin, chucvu);
	//		Ktra->EditInformation("ChucVu", chucvu, ten);
	//	}
	//	else if (chon == 8) {
	//		cout << "Nhap vao ma nhan vien moi: "; getline(cin, manhanvien);
	//		Ktra->EditInformation("MaNhanVien", manhanvien, ten);
	//	}
	//	else {
	//		cout << "Khong co so ban vua chon. Vui long nhap lai!" << endl;
	//	}
	//}

	// Node Chuc vu
	ChucVu* kt = new ChucVu();
	NodeChucVu* cv;
	//cout << "So luong chuc vu muon them vao: "; cin >> n;
	//cin.ignore();
	//for (int i = 0; i < n; i++) {
	//	cout << "Nhap vao ten chuc vu: "; getline(cin, ten);
	//	cout << "Nhap vao luong co ban: "; cin >> luong;
	//	cin.ignore();
	//	cout << "Nhap vao mo ta chuc vu: "; getline(cin, ma);
	//	cv = new NodeChucVu(ten,luong,ma);
	//	kt->CreatePosition(cv);
	//}
	/*kt->PrintPosition();
	cout << "Nhap vao chuc vu can xoa: "; getline(cin, xoa);
	kt->DeletePosition(xoa);*/
	kt->PrintPosition();
	cout << endl;
	// Phong Ban
	PhongBan* PB = new PhongBan();
	NodePhongBan* npb;
	cout << "So luong phong ban muon nhap vao: "; cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "Nhap vao ma phong ban: "; getline(cin, ma);
		cout << "Nhap vao ten phong ban: "; getline(cin, ten);
		npb = new NodePhongBan(ten, ma);
		PB->CreateDepartment(npb);
	}
	PB->PrintDepartmentInfotmation();
	cout << endl;
	cout << "Tim kiem phong ban!!!" << endl;
	cout << "1.Tim kiem theo ma phong ban." << endl;
	cout << "2.Tim kiem theo ten phong ban." << endl;
	cout << "Moi ban chon: "; cin >> chon;
	cin.ignore();
	if (chon ==1) {
		cout << "Nhap vao ma phong ban can tim: "; getline(cin, ten);
		PB->SearchDepartment("MaPhong",ten);
	}
	else if (chon == 2) {
		cout << "Nhap vao ten phong ban can tim: "; getline(cin, ten);
		PB->SearchDepartment("TenPhong",ten);
	}
	else {
		cout << "moi ban chon lai!!!";
	}
}	
