#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(string TenTk, string MatKhau,bool admin, bool HRM, bool FM) {//financial management
	this->TenTaiKhoan = TenTk;
	this->MatKhau = MatKhau;
	this->Admin = admin;
	this->QuanLyNhanSu = HRM;
	this->QuanLyTienLuong = FM;
	this->pointer = NULL;
}


Node::~Node() {

}