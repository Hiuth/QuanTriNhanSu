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
	void CreateName(NodeNhanVien*);
	void PrintEmployeeInfotmation();
	void SearchEmployee(string,string);
	void DeleteEmployee(string);
	void EditInformation();
};

