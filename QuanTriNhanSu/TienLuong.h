#pragma once
#include "NodeLuong.h"
#include"vector"
#include<iostream>
using namespace std;
class TienLuong
{
private:
	NodeLuong* head;
	NodeLuong* tail;
public:
	TienLuong();
	virtual ~TienLuong();

	NodeLuong* GetHead() { return head; }
	void SetHead(NodeLuong* val) { head = val; }
	NodeLuong* GetTail() { return tail; }
	void SetTail(NodeLuong* val) { tail = val; }

	void CreateTable();
	void Print();

	void Create();
	bool CheckNV(string);
	bool CreateData(NodeLuong*);

	bool Delete();
	void PrintDelete();

	bool Find();
	vector<NodeLuong> Tim();
	void PrintFind();

	vector<NodeLuong> Data_of_Line();
	void DataofLine();
};

