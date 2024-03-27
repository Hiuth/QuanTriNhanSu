#include "Node.h"
#include <iostream>
Node::Node() {
	this->TenTaiKhoan = 0;
	this->QuanLyNhanSu = 0;
	this->QuanLyTienLuong = 0;
	this->MatKhau = 0;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

Node::Node(long TenTk, int MatKhau,int admin, int HRM, int FM) {//financial management
	this->TenTaiKhoan = TenTk;
	this->MatKhau = MatKhau;
	this->Admin = admin;
	this->QuanLyNhanSu = HRM;
	this->QuanLyTienLuong = FM;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

Node::~Node() {

}