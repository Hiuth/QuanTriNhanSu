#include<iostream>
#include"HeThong.h"
#include"KetNoi.h"
using namespace std;
int main() {
	int n,chon;
	string tk, mk, admin, hrm, fm,ten,xoa,ma;
	HeThong* Taikhoan = new HeThong();
	Node* e;
	//cout << "so luong tai khoang muon nhap vao: "; cin >> n;
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
	Taikhoan->PrintAccount();
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
	
	cout << endl;
	cout << "Nhap vao ten tai khoan can chinh sua: "; cin >> ten;
	Taikhoan->Search("TenTaiKhoan", ten);
	cout << "Chon che do chinh sua! " << endl;
	cout << "1. Sua ten Tai Khoan." << endl;
	cout << "2. Sua cac quyen." << endl;
	cout << "Ban muon chon gi ?"; cin >> chon;
	if (chon == 1) {
		cin.ignore();
		cout << "Nhap vao ten muon doi: "; getline(cin, ma);
		cout << ten<<" "<<ma;
		Taikhoan->EditAccount("TenTaiKhoan", ma, ten);//Thứ tự tên tài khoản, tên muốn đổi, vị trí cần đổi
	}
	Taikhoan->PrintAccount();
	/*cout << "Nhap vao ten tai khoan muon xoa: "; getline(cin, xoa);
	Taikhoan->deleteAccount(xoa);*/
}
