#pragma once
#include "Node.h"
#include<vector>

class HeThong
{
private:
	Node* head;
	Node* tail;
public:
	HeThong();
	virtual ~HeThong();
	bool CheckSpacebar(string);
	bool CheckAccount(string, string);
	void Input();
	void InputSearch();
	void InputEdit();
	void InputDeleteAccount();
	bool DangNhap();
	Node* GetHead() { return head; }
	void SetHead(Node* val) { head = val; }
	Node* GetTail() { return tail; }
	void SetTail(Node* val) { tail = val; }
	void deleteAccount(string);
	void PrintAccount(vector<Node>);
	vector<Node> TakeAllAccount();
	void EditAccount(string, string,string);
	void CreateAccount(Node*);
	vector<Node> Search(string, string);
	//void Search(string,string);
	bool CheckData(string, string);
	// loi ngu vl
};

