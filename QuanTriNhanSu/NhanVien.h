#pragma once
#include"NodeNhanVien.h"
class NhanVien
{
private:
	NodeNhanVien* head;
	NodeNhanVien* tail;
public:
	NhanVien();
	virtual ~NhanVien();
	NodeNhanVien* GetHead() { return head; }
	void SetHead(NodeNhanVien* val) { head = val; }
	NodeNhanVien* GetTail() { return tail; }
	void SetTail(NodeNhanVien* val) { tail = val; }
	void CreateName(Node*);
	void PrintEmployeeInfotmation();
	void EditInformation();
	void SearchEmployee();
	void DeleteEmployee();
	void EditInformation();
};

