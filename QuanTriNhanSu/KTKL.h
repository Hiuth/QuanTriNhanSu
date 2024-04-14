#pragma once
#include"NodeKTKL.h"
#include"vector"
using namespace std;

class KTKL {
	NodeKTKL* head;
	NodeKTKL* tail;
public:
	KTKL();
	virtual ~KTKL();

	NodeKTKL* getHead() { return head; }
	void setHead(NodeKTKL* val) { head = val; }
	NodeKTKL* getTail() { return tail; }
	void setTail(NodeKTKL* val) { tail = val; }

	vector<NodeKTKL> Data_of_Line();
	void DataofLine();

	void Print();

	//B1*:Tao bang khen thuong ky luat voi 5 thuoc tinh: Ten nhan vien, Tien thuong, Tien phat, Noi dung Thuong, Noi dung phat (BAT BUOC).
	void CreateTable();

	//B2: Tao cac chinh nang chinh.

		//B2.1: Nhap/Them khen thuong/ ky luat cho nhan vien A.
	void Create();
	bool CheckKTKL(string);		//Kiem tra su ton tai cua nhan vien A.
	bool CheckData(string, string);		//Kiem tra nhan vien A da co khoan khen thuong/ ky luat nao chua.
	//Neu chua -> Them du lieu vao cho nhan vien A.
	//Neu roi -> Cong don khoan khen thuong/ ky luat moi vao du lieu cu.
//bool CreateData(NodeKTKL*,bool,string);	//Chon 1 trong 2: 1.Khen Thuong, 2.Ky Luat;
	bool CreateData(NodeKTKL*);						//Tien hanh nhap/them. 
	//Thanh cong -> In ket qua.
	//Khong thanh cong -> Thong bao "Khong thanh cong" ra man hinh.

//B2.2: Chinh sua khen thuong/ky luat cho nhan vien A.
	void Edit();
	//bool CheckNV();			//Kiem tra su ton tai cua nhan vien A.
	//bool CheckData();			//Kiem tra su ton tai cua du lieu.
	/*bool Edit();
	void PrintEdit();*/										//Neu chua co -> Bao ra man hinh "Nhan vien A khong co du lieu de chinh sua."
									//Neu co -> Tiep tuc.
	bool EditData(string, string, string);			//Chon 1 trong 4 muc chinh sua: Tien thuong, Tien phat, Noi dung thuong, Noi dung phat.
	//Tien hanh chinh sua.
		//Thanh cong -> In ket qua.
		//Khong thanh cong -> Thong bao "Khong thanh cong" ra man hinh.

//B2.3: Xoa khen thong/ky luat cua nhan vien A.
	//void Delete();
	//bool CheckNV();			//Kiem tra su ton tai cua nhan vien A.
	//bool CheckData();			//Kiem tra su ton tai cua du lieu.
	bool Delete();
	void PrintDelete();								//Neu chua co -> Bao ra man hinh "Nhan vien A khong co du lieu de xoa."
									//Neu co -> Tiep tuc.
	//bool DeleteData(string);			//Chon 1 trong 2: 1.Xoa thuoc tinh, 2.Xoa tat ca thuoc tinh cua nhan vien A.
	//Tien hanh chinh sua.
		//Thanh cong -> In ket qua.
		//Khong thanh cong -> Thong bao "Khong thanh cong" ra man hinh.
	bool Find();
	vector<NodeKTKL> Tim();
	void PrintFind();
};