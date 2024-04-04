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
	bool CheckAccount(string, string);
	Node* GetHead() { return head; }
	void SetHead(Node* val) { head = val; }
	Node* GetTail() { return tail; }
	void SetTail(Node* val) { tail = val; }
	void deleteAccount(string);
	void PrintAccount();
	void EditAccount(string, string,string);
	void CreateAccount(Node*);
	void Search(string,string);
<<<<<<< HEAD
	bool CheckAccount(string,string);
=======
	bool CheckData(string, string);
	// loi ngu vl
>>>>>>> 5c8eb2ce7c524a02ead7ffb2f2772b9cea89af39
};

