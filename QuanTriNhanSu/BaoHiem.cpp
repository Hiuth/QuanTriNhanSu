#include "BaoHiem.h"
#include"KetNoi.h"
#include"vector"
#include<iostream>
using namespace std;

KetNoi* kt1 = new KetNoi();
Connection* cd = kt1->CheckDatabase();

BaoHiem::BaoHiem()
{
    this->head = NULL;
    this->tail = NULL;
}

BaoHiem::~BaoHiem()
{
    delete kt1;
    delete cd;
}

vector<NodeBaoHiem> BaoHiem::Data_of_Line()
{
    try {
        Statement* stmt;
        stmt = cd->createStatement();
        int s1 = 0;
        vector<NodeBaoHiem> bh;
        string SelectData = "Select *from baohiem";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeBaoHiem b(res->getString("MaBaoHiem"), res->getString("SoTien"), res->getString("Han"));
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

void BaoHiem::DataofLine()
{
    vector<NodeBaoHiem> a = this->Data_of_Line();
    //cout << a.size();
    for (int i = 0; i < a.size(); i++) {
        //cout << 1;
        cout << i + 1 << "  " << a[i].GetMa() << "  " << a[i].GetSoTien() << "  " << a[i].GetHan() << endl;
    }
}

//void BaoHiem::CreateTable() {
//    try {
//        Statement* stmt;
//        stmt = cd->createStatement();
//        //kiem tra su ton tai cua bang
//        string TenBang = "BaoHiem";
//        string KiemTra = "show tables like'" + TenBang + "'";
//        ResultSet* result = stmt->executeQuery(KiemTra);
//        if (result->next() == false) {
//            string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
//            string useDatabase = "Use QuanTriNhanSu";
//            string CreateTableAccount = "create table if not exists BaoHiem (""MaBaoHiem char(10) not null ,""SoTien char(7) not null,""Han char(10) not null)";
//            stmt->execute(CreateDatabaseSQL);
//            stmt->execute(useDatabase);
//            stmt->execute(CreateTableAccount);
//            cout << "Bang da duoc tao, du lieu da duoc them vao!" << endl;
//        }
//        delete result;
//        delete stmt;
//        //this->Print();
//    }
//    catch (sql::SQLException& e) {
//        cerr << "SQL Error: " << e.what() << std::endl;
//    }
//}

void BaoHiem::Input() {
    cout << "----------NHAP BAO HIEM--------------------------\n";
    string MaBaoHiem, SoTien, Han;
    NodeBaoHiem* e;
    cout << "Ma bao Hiem: " << endl; cin >> MaBaoHiem;
    cout << "So Tien: " << endl; cin >> SoTien;
    cout << "Han: " << endl; cin >> Han;
    e = new NodeBaoHiem(MaBaoHiem, SoTien, Han);
    this->Create(e);
    this->Print();
}

void HoTroCapNhat(NodeBaoHiem* t, Statement* stmt) {
    string MaBaoHiem;
    string SoTien;
    string Han;
    string TenNhanVien;
    MaBaoHiem = t->GetMa();
    SoTien = t->GetSoTien();
    Han = t->GetHan();
    string UpdateTableAccount = "insert into BaoHiem Values ('" + MaBaoHiem + "','" + SoTien + "','" + Han + "');";
    stmt->execute(UpdateTableAccount);
}

void BaoHiem::Create(NodeBaoHiem* t) {
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
        stmt = cd->createStatement();
        string MaBaoHiem;
        string SoTien;
        string Han;
        string TenNhanVien;
        MaBaoHiem = t->GetMa();
        SoTien = t->GetSoTien();
        Han = t->GetHan();
        string UpdateTableAccount = "insert into BaoHiem Values ('" + MaBaoHiem + "','" + SoTien + "','" + Han + "');";
        stmt->execute(UpdateTableAccount);
        cout << "Du lieu da duoc cap nhat!" << endl;
        delete stmt;
        delete t;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

vector<NodeBaoHiem> BaoHiem::Tim() {
    try {
        string tim;
        cout << "Nhap ma bao hiem: "; cin >> tim;
        Statement* stmt;
        stmt = cd->createStatement();
        string CheckData = "Select * from baohiem Where MaBaoHiem = '" + tim + "'";
        ResultSet* res = stmt->executeQuery(CheckData);
        //int count;
        vector<NodeBaoHiem> a;
        while (res->next()) {
            NodeBaoHiem bh(res->getString("MaBaoHiem"), res->getString("SoTien"), res->getString("Han"));
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

bool BaoHiem::Find() {
    vector<NodeBaoHiem> a = this->Tim();
    if (a.size() != 0) return true;
    else return false;
}

void BaoHiem::PrintFind() {
    bool kt = this->Find();
    string tim;
    vector<NodeBaoHiem> a = this->Tim();
    cout << "----------TIM KIEM BAO HIEM--------------------------\n";
    Statement* stmt;
    if (kt == true) {
        cout << "Ma bao hiem" << "\t" << "So Tien" << "\t" << "Han" << endl;
        for (int i = 0; i < a.size(); i++) {
            cout << a[i].GetMa() << "  " << a[i].GetSoTien() << "  " << a[i].GetHan() << endl;
        }
    }
    else cout << "Khong thanh cong." << endl;
}


void BaoHiem::Print() {
    cout << "----------DANH SACH BAO HIEM--------------------------\n";
    vector<NodeBaoHiem> b = this->Data_of_Line();
    cout << "\nDanh sach bao hiem" << endl;
    cout << "Ma bao hiem" << "\t" << "So tien" << "\t" << "Han" << endl;
    for (int i = 0; i < b.size(); i++) {
        cout << b[i].GetMa() << "\t" << b[i].GetSoTien() << "\t" << b[i].GetHan() << endl;
    }
}



//bool BaoHiem::Find(string tim) {
//    try {
//        Statement* stmt;
//        stmt = cd->createStatement();
//        string CheckData = "Select * from BaoHiem Where MaBaoHiem = '" + tim + "'";
//        ResultSet* result = stmt->executeQuery(CheckData);
//        int count = 0;
//        while (result->next()) {
//            return true;
//        }
//        return false;
//    }
//    catch (sql::SQLException& e) {
//        cerr << "SQL Error: " << e.what() << std::endl;
//    }
//}

bool BaoHiem::Update(NodeBaoHiem* t) {

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
        bool kt = false;
        stmt = cd->createStatement();
        //kiem tra su ton tai cua bang
        string TenBang = "BaoHiem";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);

        if (result->next() == true) {
            HoTroCapNhat(t, stmt);
            //cout << 1;
            cout << "Du lieu da duoc them!" << endl;
            kt = true;

        }
        else {
            kt = false;
        }
        delete result;
        delete stmt;
        delete t;

        return kt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void BaoHiem::PrintUpdate() {
    try {
        cout << "----------CAP NHAT BAO HIEM--------------------------\n";
        string MaBaoHiem, SoTien, Han;
        NodeBaoHiem* e;
        cout << "Ma bao Hiem moi: " << endl; cin >> MaBaoHiem;
        cout << "So Tien: " << endl; cin >> SoTien;
        cout << "Han: " << endl; cin >> Han;
        e = new NodeBaoHiem(MaBaoHiem, SoTien, Han);
        //this->Create(e);
        bool kt = this->Update(e);
        if (kt == true) {
            cout << "Cap nhat thanh cong.";
            this->Print();
        }
        else cout << "Cap nhat khong thanh cong.";
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

bool BaoHiem::Delete() {
    try {
        this->Print();
        string ma;
        cout << "Ma bao hiem muon xoa: " << endl; cin >> ma;
        Statement* stmt;
        stmt = cd->createStatement();
        string SelectData = "delete from BaoHiem where MaBaoHiem = '" + ma + "'";
        int rows_affected = stmt->executeUpdate(SelectData);
        delete stmt;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void BaoHiem::PrintDelete() {
    cout << "----------XOA BAO HIEM--------------------------\n";
    bool kt = this->Delete();
    if (kt == true) {
        cout << "Xoa thanh cong.";
    }
    else cout << "Cap nhat khong thanh cong.";
}

bool BaoHiem::Edit(string ChoCanSua, string MuonDoiThanh, string ma) {
    try {
        this->Print();
        Statement* stmt;
        stmt = cd->createStatement();
        string SelectData2 = "UPDATE baohiem SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE MaBaoHiem = '" + ma + "'";
        int rows_affected = stmt->executeUpdate(SelectData2);
        delete stmt;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void BaoHiem::PrintEdit() {
    cout << "----------CHINH SUA BAO HIEM--------------------------\n";
    string ma, neww;
    int num; 
    bool kt ;
    cout << "Nhap ma nhan vien: "; cin >> ma;
    cout << "MENU\n";
    cout << "1.Ma bao hiem\n2.SoTien\n3.Han\n"; cin >> num;
    if (num == 1) {
        cout << "Ma bao hiem moi: "; cin >> neww;
        kt = this->Edit("MaBaoHiem", neww, ma);
    }
    else if (num == 2) {
        cout << "So tien bao hiem moi: "; cin >> neww;
        kt = this->Edit("SoTien", neww, ma);
    }
    else if (num == 3) {
        cout << "Han bao hiem moi: "; cin >> neww;
        kt = this->Edit("Han", neww, ma);
    }
    else kt = false;

    if (kt == true) {
        cout << "Xoa thanh cong.";
    }
    else cout << "Cap nhat khong thanh cong.";
}



