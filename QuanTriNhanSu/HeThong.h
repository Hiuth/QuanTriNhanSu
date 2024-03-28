#pragma once
#include "Node.h"
class HeThong
{
private:
	Node* head;
	Node* tail;
public:
	HeThong();
	virtual ~HeThong();
	Node* GetHead() { return head; }
	void SetHead(Node* val) { head = val; }
	Node* GetTail() { return tail; }
	void SetTail(Node* val) { tail = val; }
	bool InsertNode(Node*);
	bool deleteAccount(Node*);//deleteNode;
	void PrintAccount();
	void CheckAccount(Node*);
	void EditAccount(Node*);
	void CreateAccount(Node*);


};

