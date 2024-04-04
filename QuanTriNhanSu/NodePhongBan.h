#pragma once
#include<string>
#include<iostream>
using namespace std;
class NodePhongBan {
private:
    string name;
    string id;
    NodePhongBan* next; // Con trỏ đến nút tiếp theo trong danh sách
public:

    NodePhongBan(string, string);
    virtual ~NodePhongBan();
    string GetName() {
        return name;
    }

    void SetName(string val) {
        name = val;
    }

    string GetID() {
        return id;
    }

    void SetID(string val) {
        id = val;
    }

    NodePhongBan* GetNext() {
        return next;
    }


    void SetNext(NodePhongBan* nextNode) {
        next = nextNode;
    }
};
