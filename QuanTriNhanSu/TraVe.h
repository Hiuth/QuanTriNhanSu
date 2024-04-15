#pragma once
#include"NodeTraVe.h"
#include"vector"
#include"string"
using namespace std;
class TraVe
{
	NodeTraVe* head;
	NodeTraVe* tail;
public:
	TraVe();
	virtual ~TraVe();

	int ReturnColumn(string);
	int ReturnLine(string, string);
	vector<string> ReturnName_of_Column(string);
};

