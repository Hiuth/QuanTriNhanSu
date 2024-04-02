#include "NodeNhanVien.h"

NodeNhanVien::NodeNhanVien(string TenNhanVien, string SinhNhat,string GioiTinh, string CCCD, string DiaChi, string ChucVu, string PhongBan,string MaNhanVien) {
	this->TenNhanVien = TenNhanVien;
	this->SinhNhat = SinhNhat;
	this->CCCD = CCCD;
	this->DiaChi = DiaChi;
	this->ChucVu = ChucVu;
	this->PhongBan = PhongBan;
	this->GioiTinh = GioiTinh;
	this->MaNhanVien = MaNhanVien;
	this->pointer = NULL;
}

NodeNhanVien::~NodeNhanVien() {

}