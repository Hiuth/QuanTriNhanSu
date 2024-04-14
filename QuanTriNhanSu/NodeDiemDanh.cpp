#include "NodeDiemDanh.h"


NodeDiemDanh::NodeDiemDanh(string id,string nv, string dd)
{
	this->MaNhanVien = id;
	this->TenNhanVien = nv;
	this->DiemDanh = dd;
	this->pointer = NULL;
}

NodeDiemDanh::~NodeDiemDanh() {

}
