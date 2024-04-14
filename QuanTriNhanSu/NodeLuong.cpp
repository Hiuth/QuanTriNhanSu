#include "NodeLuong.h"


NodeLuong::NodeLuong(string ma, string ten, int dd, int tien, int kt, int kl, int bh, long long tongcong)
{
	this->MaNhanVien = ma;
	this->TenNhanVien = ten;
	this->DiemDanh = dd;
	this->TienCong = tien;
	this->KhenThuong = kt;
	this->KyLuat = kl;
	this->BaoHiem = bh;
	this->TongCong = tongcong;
	this->pointer = NULL;
}

NodeLuong::~NodeLuong() {

}
