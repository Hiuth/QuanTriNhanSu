#pragma once
#include"NodeNhanVien.h"
#include<vector>
class NhanVien
{
private:
	NodeNhanVien* head;
	NodeNhanVien* tail;
public:
	NhanVien();
	virtual ~NhanVien();
	bool CheckNumber(string);
	bool CheckSyntax(string);
	void InputEmployee();
	void InputSearchEmployee();
	void InputEditEmployee();
	void InputDeleteEmployee();
	NodeNhanVien* GetHead() { return head; }
	void SetHead(NodeNhanVien* val) { head = val; }
	NodeNhanVien* GetTail() { return tail; }
	void SetTail(NodeNhanVien* val) { tail = val; }
	void CreateName(NodeNhanVien*);
	void PrintEmployeeInfotmation(vector<NodeNhanVien>);
	vector<NodeNhanVien> SearchEmployee(string,string);
	void DeleteEmployee(string);
	void EditInformation(string,string,string);
	vector<NodeNhanVien> TakeAllEmployee();
};

