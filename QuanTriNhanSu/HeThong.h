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
	void deleteAccount(string);//deleteNode;
	void PrintAccount();
	void EditAccount(string, string,string);
	void CreateAccount(Node*);
	void Search(string,string);


};

