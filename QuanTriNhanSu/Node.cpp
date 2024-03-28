#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(string TenTk, string MatKhau,string admin, string HRM, string FM) {//financial management
	this->TenTaiKhoan = TenTk;
	this->MatKhau = MatKhau;
	this->Admin = admin;
	this->QuanLyNhanSu = HRM;
	this->QuanLyTienLuong = FM;
	this->pointer = NULL;
}

Node::~Node() {

}