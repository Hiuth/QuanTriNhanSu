#include "Node.h"
#include <iostream>
Node::Node() {
	this->key = 0;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

Node::Node(int x) {
	this->key = x;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

Node::~Node() {

}