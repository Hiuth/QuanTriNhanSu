#pragma once
#include "NodeChucVu.h"
#include<vector>

class ChucVu {
private:
    NodeChucVu* head;
    NodeChucVu* tail;

public:
    ChucVu(); // Constructor
    virtual ~ChucVu(); // Destructor
    void InputPosition();
    bool checkSyntax(string);
    bool checkNamePosition(string,string);
    void InputEditPosiotion();
    void InputSearchPosition();
    void InputDetletePosition();
    void CreatePosition(NodeChucVu*);
    void PrintPosition(vector<NodeChucVu>);
    vector<NodeChucVu> TakeAllPosition();
    void EditPosition(string,string,string);
    void DeletePosition(string xoa);
    //void SearchPosition(string,string);
    vector<NodeChucVu> SearchPosition(string, string);
};

