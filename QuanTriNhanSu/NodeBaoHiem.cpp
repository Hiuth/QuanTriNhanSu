#include "NodeBaoHiem.h"

NodeBaoHiem::NodeBaoHiem(string ma, string ti, string ha)
{
	//this->TenNhanVien = ten;
	this->MaBaoHiem = ma;
	this->SoTien = ti;
	this->Han = ha;
	this->pointer = NULL;
}

NodeBaoHiem::~NodeBaoHiem()
{

}


