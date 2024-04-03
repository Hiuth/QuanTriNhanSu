#include "NodeChucVu.h"
NodeChucVu::NodeChucVu(string tenchucvu, long luongchucvu, string mota) {
	this->TenChucVu = tenchucvu;
	this->Luongchucvu = luongchucvu;
	this->MoTa = mota;
	this->poiter = NULL;
}

NodeChucVu::~NodeChucVu() {

}
