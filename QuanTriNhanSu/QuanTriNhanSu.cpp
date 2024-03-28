#include<iostream>
#include"HeThong.h"
using namespace std;
int main() {
	int n;
	string tk, mk, admin, hrm, fm,ten,xoa;
	HeThong* Taikhoan = new HeThong();
	Node* e;
	//cout << "so luong tai khoang muon nhap vao: "; cin >> n;
	//for (int i = 0; i < n; i++) {
	//	cout << "Tai khoan: "; cin >> tk;
	//	cout << "Mat Khau: "; cin >> mk;
	//	cout << "Neu muon cap quyen thi hay bam so 1, neu khong thi bam so 0." << endl;;
	//	cout << "Quyen admin: "; cin >> admin;
	//	cout << "Quyen quan ly nhan su: "; cin >>hrm;
	//	cout << "Quyen quan ly tien luong: "; cin >> fm;
	//	e = new Node(tk, mk, admin, hrm, fm);
	//	Taikhoan->CreateAccount(e);
	//	cout << endl;
	//}
	Taikhoan->PrintAccount();
	//cout << "Nhap ten tai khoan can tim: "; getline(cin, ten);
	//Taikhoan->Search(ten);
	/*cout << "Nhap vao ten tai khoan muon xoa: "; getline(cin, xoa);
	Taikhoan->deleteAccount(xoa);*/
	Taikhoan->PrintAccount();
}
