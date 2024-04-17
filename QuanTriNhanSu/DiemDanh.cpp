#include "DiemDanh.h"
#include "KetNoi.h"
#include<iostream>
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int GetRandom(int min, int max) {
    return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

KetNoi* kt3 = new KetNoi();
Connection* dd = kt3->CheckDatabase();

DiemDanh::DiemDanh()
{
    this->head = NULL;
    this->tail = NULL;
}

DiemDanh::~DiemDanh() {
    delete kt3;
    delete dd;
}

void DiemDanh::DataofLine()
{
    vector<NodeDiemDanh> a = this->Data_of_Line();
    //cout << a.size();
    for (int i = 0; i < a.size(); i++) {
        //cout << 1;
        cout << i + 1 << "  " << a[i].GetID() << "  " << a[i].GetName() << "  " << a[i].GetAttendanceCheck() << endl;
    }
}

vector<NodeDiemDanh> DiemDanh::Data_of_Line()
{
    try {
        Statement* stmt;
        stmt = dd->createStatement();
        int s1 = 0;
        vector<NodeDiemDanh> bh;
        string SelectData = "Select *from bangdiemdanh";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeDiemDanh b(res->getString("MaNhanVien"), res->getString("TenNhanVien"), res->getString("DiemDanh"));
            bh.push_back(b);
        }
        return bh;
        delete stmt;
        delete res;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

//void DiemDanh::CreateTable() {
//    try {
//        Statement* stmt;
//        stmt = dd->createStatement();
//        //kiem tra su ton tai cua bang
//        string TenBang = "BangDiemDanh";
//        string KiemTra = "show tables like'" + TenBang + "'";
//        ResultSet* result = stmt->executeQuery(KiemTra);
//        if (result->next() == false) {
//            string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
//            string useDatabase = "Use QuanTriNhanSu";
//            string CreateTableAccount = "create table if not exists BangDiemDanh (""MaNhanVien char(10) not null ,""TenNhanVien char(10) not null ,""DiemDanh char(3) not null)";
//            stmt->execute(CreateDatabaseSQL);
//            stmt->execute(useDatabase);
//            stmt->execute(CreateTableAccount);
//            cout << "Bang da duoc tao, du lieu da duoc them vao!" << endl;
//        }
//        delete result;
//        delete stmt;
//    }
//    catch (sql::SQLException& e) {
//        cerr << "SQL Error: " << e.what() << std::endl;
//    }
//}

void DiemDanh::Copy() {
    Statement* stmt;
    stmt = dd->createStatement();
    string SelectData = "Select * from NhanVien";
    ResultSet* res = stmt->executeQuery(SelectData);
    int count = 0;
    vector<string> a;
    vector<string> b;
    while (res->next()) {
        a.push_back(res->getString("MaNhanVien"));
        b.push_back(res->getString("TenNhanVien"));
        count++;
    }
    /*for (int i = 0; i < count; i++) {
        cout << "Ma : " << a[i] << endl;
        cout << "Ten: " << b[i] << endl;
    }*/
    vector<string> dd(count);
    srand((unsigned int)time(NULL));

    for (int i = 0; i < count; i++) {
        int r = GetRandom(27, 31);
        string d = to_string(r);
        dd[i] = d;
        //cout << dd[i];
    }

    /*for (int i = 0; i < count; i++) {
        cout << dd[i] << " ";
    }
    cout << endl;*/

    NodeDiemDanh* t;
    for (int i = 0; i < count; i++) {
        bool kt = this->CheckNV(a[i]);
        if (kt == false) {
            t = new NodeDiemDanh(a[i],b[i] ,dd[i]);
            this->Input(t);
            /*cout << "a: " << a[i] << endl;
            cout << "b: " << b[i] << endl;
            cout << "dd: " << dd[i] << endl;*/
        }
        else continue;
    }

    delete stmt;
    delete res;
    //delete t;
}

bool DiemDanh::CheckNV(string ten) {
    try {
        Statement* stmt;
        bool kt = false;
        stmt = dd->createStatement();
        string CheckData = "Select * from BangDiemDanh Where MaNhanVien = '" + ten + "'";
        ResultSet* result = stmt->executeQuery(CheckData);
        int count = 0;
        while (result->next()) {
            kt = true;
        }
        //cout << kt;
        return kt;
        
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void HoTroCapNhat(NodeDiemDanh* t, Statement* stmt) {
    string MaNhanVien;
    string TenNhanVien;
    string DiemDanh;
    MaNhanVien = t->GetID();
    TenNhanVien = t->GetName();
    DiemDanh = t->GetAttendanceCheck();
    /*string deleteTable = "delete from BangDiemDanh";
    int rows_affected = stmt->executeUpdate(deleteTable);*/
    string UpdateTableAccount = "insert into BangDiemDanh Values ('" + MaNhanVien + "','" + TenNhanVien + "','" + DiemDanh + "');";
    stmt->execute(UpdateTableAccount);
}

void DiemDanh::Input(NodeDiemDanh* t) {
    
    if (this->head == NULL) {
        this->head = this->tail = t;
    }
    else {
        t->SetPointer(this->head);
        this->head = t;
    }
    try {
        t = this->head;
        Statement* stmt;
        stmt = dd->createStatement();
        HoTroCapNhat(t, stmt);
        cout << "Du lieu da duoc cap nhat!" << endl;
        delete stmt;
        delete t;
        
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void DiemDanh::Print() {

    try {
        Statement* stmt;
        stmt = dd->createStatement();
        string selectData = "select * from BangDiemDanh";
        ResultSet* res = stmt->executeQuery(selectData);
        cout << "Danh sach diem danh" << endl;
        cout << "Ma nhan vien" << "\t" << "Ten nhan vien" << "\t" << "Diem danh" << endl;
        while (res->next()) {
            cout << res->getString("MaNhanVien") << "\t" << res->getString("TenNhanVien") << "\t" << res->getString("DiemDanh") << endl;
        }
        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

vector<NodeDiemDanh> DiemDanh::Tim() {
    try {
        string tim;
        cout << "Nhap ma nhan vien: "; cin >> tim;
        Statement* stmt;
        stmt = dd->createStatement();
        string CheckData = "Select * from bangDiemDanh Where MaNhanVien = '" + tim + "'";
        ResultSet* res = stmt->executeQuery(CheckData);
        //int count;
        vector<NodeDiemDanh> a;
        while (res->next()) {
            NodeDiemDanh bh(res->getString("MaNhanVien"), res->getString("TenNhanVien"), res->getString("DiemDanh"));
            a.push_back(bh);
        }
        return a;
        delete stmt;
        delete res;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

bool DiemDanh::Find() {
    vector<NodeDiemDanh> a = this->Tim();
    if (a.size() != 0) return true;
    else return false;
}

void DiemDanh::PrintFind() {
    bool kt = this->Find();
    string tim;
    vector<NodeDiemDanh> a = this->Tim();
    cout << "----------TIM KIEM DiemDanh--------------------------\n";
    Statement* stmt;
    if (kt == true) {
        cout << "Ma nhan vien" << "\t" << "Ten nhan vien" << "\t" << "Diem danh" << endl;
        for (int i = 0; i < a.size(); i++) {
            cout << a[i].GetID() << "  " << a[i].GetName() << "  " << a[i].GetAttendanceCheck() << endl;
        }
    }
    else cout << "Khong thanh cong." << endl;
}





