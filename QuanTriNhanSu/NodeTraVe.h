#pragma once
#include"iostream"
using namespace std;
class NodeTraVe
{
	string tenbang;
	NodeTraVe* p;
public:
	NodeTraVe(string);
	virtual ~NodeTraVe();

	string getTenBang() { return tenbang; }
	void setTenBang(string val) { tenbang = val; }

	NodeTraVe* getP() { return p; }
	void setP(NodeTraVe* val) { p = val; }
};

