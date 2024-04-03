#pragma once
#include "NodeChucVu.h"

class ChucVu {
private:
    NodeChucVu* head;
    NodeChucVu* tail;

public:
    ChucVu(); // Constructor
    virtual ~ChucVu(); // Destructor
    void CreatePosition(NodeChucVu*);
    void PrintPosition();
    void EditPosition(string,string,string);
    void DeletePosition(string xoa);
    void SearchPosition();
};

