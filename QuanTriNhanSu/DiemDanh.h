#pragma once
#include "NodeDiemDanh.h"
#include"vector"
using namespace std;

class DiemDanh
{
private:
	NodeDiemDanh* head;
	NodeDiemDanh* tail;
public:
	DiemDanh();
	virtual ~DiemDanh();

	NodeDiemDanh* GetHead() { return head; }
	void SetHead(NodeDiemDanh* val) { head = val; }
	NodeDiemDanh* GetTail() { return tail; }
	void SetTail(NodeDiemDanh* val) { tail = val; }

	void CreateTable();
	bool CheckNV(string);
	void Copy();
	void Input(NodeDiemDanh*);
	void Print();

	bool Find();
	vector<NodeDiemDanh> Tim();
	void PrintFind();

	vector<NodeDiemDanh> Data_of_Line();
	void DataofLine();
};

