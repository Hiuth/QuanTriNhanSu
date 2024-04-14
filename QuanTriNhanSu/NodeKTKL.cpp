#include "NodeKTKL.h"

NodeKTKL::NodeKTKL(string v1, string v2, string v3, string v4, string v5, string v6)
{
	this->MaNhanVien = v1;
	this->TenNhanVien = v2;
	this->Thuong = v3;
	this->Phat = v4;
	this->NDT = v5;
	this->NDP = v6;
	this->pointer = NULL;
}

NodeKTKL::~NodeKTKL() {

}
