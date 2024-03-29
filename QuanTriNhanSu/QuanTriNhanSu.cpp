#include<iostream>
#include"HeThong.h"
using namespace std;
int main() {
	int n,chon;
	string tk, mk, admin, hrm, fm,ten,xoa,ma;
	HeThong* Taikhoan = new HeThong();
	Node* e;
	/*cout << "so luong tai khoang muon nhap vao: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Tai khoan: "; cin >> tk;
		cout << "Mat khau: "; cin >> mk;
		cout << "Neu muon cap quyen thi hay bam so 1, neu khong thi bam so 0." << endl;;
		cout << "Quyen admin: "; cin >> admin;
		cout << "Quyen quan ly nhan su: "; cin >>hrm;
		cout << "Quyen quan ly tien luong: "; cin >> fm;
		e = new Node(tk, mk, admin, hrm, fm);
		Taikhoan->CreateAccount(e);
		cout << endl;
	}*/
	Taikhoan->PrintAccount();
	cout << "1.Tim kiem theo quyen admin." << endl;
	cout << "2.Tim kiem theo quyen quan ly nhan su." << endl;
	cout << "3.Tim kiem theo quyen quan ly Tien Luong." << endl;
	cout << "4.Tim kiem theo ten tai khoan." << endl;
	cout << "Ban muon chon theo gi ? "; cin >> chon;
	if (chon == 1) {
		ten = "admin";
		ma = "1";
		Taikhoan->Search(ten,ma);
	}
	else if(chon == 2) {
		ten = "QuanLyNhanSu";
		ma = "1";
		Taikhoan->Search(ten,ma);
	}
	else if (chon == 3) {
		ten = "QuanLyTienLuong";
		ma = "1";
		Taikhoan->Search(ten, ma);
	}
	else if (chon == 4) {
		ten = "TenTaiKhoan";
		cin.ignore();
		cout << "Nhap vao Ten tai khoan: "; getline(cin, ma);
		Taikhoan->Search(ten, ma);
	}
	else {
		cout << "Khong co so ma ban da chon. Vui long nhap lai!"<<endl;
	}
	
	
	/*cout << "Nhap vao ten tai khoan muon xoa: "; getline(cin, xoa);
	Taikhoan->deleteAccount(xoa);*/
}
