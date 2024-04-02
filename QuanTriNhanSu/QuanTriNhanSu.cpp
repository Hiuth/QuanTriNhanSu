#include<iostream>
#include"HeThong.h"
#include"KetNoi.h"
#include"NhanVien.h"
#include <string>

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
	int n,chon,nhap;
	string tk, mk, admin, hrm, fm,ten,xoa,ma,chucvu,phongban,gioitinh,sinhnhat,cccd,diachi;
	HeThong* Taikhoan = new HeThong();
	Node* e;
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
	NhanVien* Ktra = new NhanVien();
	NodeNhanVien* p;
	//cout << "So luong nhan vien muon nhap vao: "; cin >> n;
	//for (int i = 0; i < n; i++) {
	//	cin.ignore();
	//	cout << "Nhap vao ten nhan vien: "; getline(cin, tk); 
	//	cout << tk << endl;
	//	cout << "Nhap vao gioi tinh: "; cin>>gioitinh; 
	//	cout << gioitinh << endl;
	//	cout << "Nhap vao sinh nhat: "; cin >> sinhnhat;
	//	cout << sinhnhat << endl;
	//	cin.ignore();
	//	cout << "Nhap vao can cuoc cong dan (CCCD): "; getline(cin,cccd);
	//	cout << cccd << endl;
	//	cout << "Nhap vao dia chi nha: ";  getline(cin,diachi); 
	//	cout << diachi << endl;
	//	cout << "Nhap vao phong ban: ";  getline(cin,phongban);
	//	cout << phongban << endl;
	//	cout << "Nhap vao chuc vu: "; getline(cin,chucvu);
	//	cout << chucvu << endl;
	//	p = new NodeNhanVien(tk,sinhnhat,gioitinh,cccd,diachi,chucvu,phongban);
	//	Ktra->CreateName(p);
	//	cout << endl;
	//}
	Ktra->PrintEmployeeInfotmation();
	cout << "1.Tim kiem theo ten nhan vien." << endl;
	cout << "2.Tim kiem theo gioi tinh ." << endl;
	cout << "3.Tim kiem theo sinh nhat." << endl;
	cout << "4.Tim kiem theo can cuoc cong dan." << endl;
	cout << "5.Tim kiem theo phong ban." << endl;
	cout << "6.Tim kiem theo chuc vu." << endl;
	cout << "Ban muon chon theo gi ? "; cin >> chon;
	cin.ignore();
	if (chon == 1) {
		cout << "nhap vao ten tai khoan: "; getline(cin, ten);
		Ktra->SearchEmployee("TenNhanVien", ten);
	}
	else if(chon == 2) {
		cout << "Nhap vao gioi tinh: "; cin >> gioitinh;
		Ktra->SearchEmployee("GioiTinh",gioitinh);
	}
	else if (chon == 3) {
		cout << "Nhap vao sinh nhat: "; cin >> sinhnhat;
		Ktra->SearchEmployee("SinhNhat",sinhnhat);
	}
	else if (chon == 4) {
		cout << "Nhap vao can cuoc cong dan: "; cin >> cccd;
		Ktra->SearchEmployee("CCCD",cccd);
	}
	else if (chon ==5) {
		cout << "Nhao vao phong ban: "; getline(cin, phongban);
		Ktra->SearchEmployee("PhongBan",phongban);
	}
	else if (chon == 6) {
		cout << "Nhap vao chuc vu: "; getline(cin, chucvu);
		Ktra->SearchEmployee("ChucVu",chucvu);
	}
	else {
		cout << "khong co so ma ban da chon. vui long nhap lai!"<<endl;
	}
}
