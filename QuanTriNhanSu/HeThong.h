#pragma once
#include "Node.h"
class HeThong
{
private:
	Node* root;
public:
	HeThong();
	virtual ~HeThong();
	Node* GetRoot() { return root; }
	void SetRoot(Node* val) { root = val; }
	bool InsertNode(Node*);
	bool deleteNode(Node*);
	void PrintAccount();
};

