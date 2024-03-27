#pragma once
class Node
{
private:
	int key;
	Node* left;
	Node* right;
	Node* parent;
public:
	Node();
	Node(int);
	virtual ~Node();
	Node* GetLeft() { return left; }
	Node* GetRight() { return right; }
	void SetLeft(Node* val) { left = val; }
	void SetRight(Node* val) { right = val; }
	Node* GetParent() { return parent; }
	void SetParent(Node* val) { parent = val; }
	int GetKey() { return key; }
	void SetKey(int val) { key = val; }
protected:
};

