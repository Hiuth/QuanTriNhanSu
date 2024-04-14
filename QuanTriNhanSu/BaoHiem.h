#pragma once
#include"NodeBaoHiem.h"
#include"vector"
using namespace std;

class BaoHiem
{
private:
	NodeBaoHiem* head;
	NodeBaoHiem* tail;
public:
	BaoHiem();
	virtual ~BaoHiem();

	NodeBaoHiem* GetHead() { return head; }
	void SetHead(NodeBaoHiem* val) { head = val; }
	NodeBaoHiem* GetTail() { return tail; }
	void SetTail(NodeBaoHiem* val) { tail = val; }

	void CreateTable();
	void Input();
	void Create(NodeBaoHiem*);
	vector<NodeBaoHiem> Tim(string);

	void Print();

	bool Find();
	vector<NodeBaoHiem> Tim();
	void PrintFind();

	bool Update(NodeBaoHiem*);
	void PrintUpdate();
	
	bool Delete();
	void PrintDelete();

	bool Edit(string, string, string);
	void PrintEdit();

	vector<NodeBaoHiem> Data_of_Line();
	void DataofLine();
};

