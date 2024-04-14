#include "NodeNhanVien.h"

NodeNhanVien::NodeNhanVien(string TenNhanVien, string SinhNhat,string GioiTinh,string sdt, string CCCD, string DiaChi, string ChucVu, string PhongBan,string MaNhanVien, string ThoiHanHopDong) {
	this->TenNhanVien = TenNhanVien;
	this->SinhNhat = SinhNhat;
	this->CCCD = CCCD;
	this->sdt = sdt;
	this->DiaChi = DiaChi;
	this->ChucVu = ChucVu;
	this->PhongBan = PhongBan;
	this->GioiTinh = GioiTinh;
	this->MaNhanVien = MaNhanVien;
	this->ThoiHanHopDong = ThoiHanHopDong;
	this->pointer = NULL;
}

NodeNhanVien::~NodeNhanVien() {

}