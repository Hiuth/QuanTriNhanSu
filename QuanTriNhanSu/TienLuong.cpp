#include "TienLuong.h"
#include "KetNoi.h"
#include"DiemDanh.h"
#include<iostream>
#include <iomanip>
#include<vector>
#include <cstdlib>
#include"string"
#include <ctime>
using namespace std;

DiemDanh* DD = new DiemDanh();

KetNoi* kt = new KetNoi();
Connection* ma = kt->CheckDatabase();

TienLuong::TienLuong()
{
    this->head = NULL;
    this->tail = NULL;
}

TienLuong::~TienLuong() {
    delete kt;
    delete ma;
}

vector<NodeLuong> TienLuong::Data_of_Line()
{
    try {
        Statement* stmt;
        stmt = ma->createStatement();
        int s1 = 0;
        vector<NodeLuong> bh;
        string SelectData = "Select *from bangluong";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeLuong b(res->getString("MaNhanVien"), res->getString("TenNhanVien"), res->getInt("SoNgayDiLam"), res->getDouble("TienCongNgay"),
                res->getInt("KhoanKhenThuong"), res->getInt("KhoanKyLuat"), res->getInt("BaoHiem"), res->getDouble("TongCong"));
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

void TienLuong::DataofLine()
{
    vector<NodeLuong> a = this->Data_of_Line();
    //cout << a.size();
    for (int i = 0; i < a.size(); i++) {
        //cout << 1;
        cout << i + 1 << "  " << a[i].GetID() << "  " << a[i].GetName() << "  " << a[i].GetDD() << "  " << a[i].GetTC() << "  " << a[i].GetKT()
            << "  " << a[i].GetKL() << "  " << a[i].GetBH() << "  " << a[i].GetTongCong() << endl;
    }
}

void TienLuong::CreateTable() {
    try {
        Statement* stmt;
        stmt = ma->createStatement();
        string TenBang = "BangLuong";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == false) {
            string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
            string useDatabase = "Use QuanTriNhanSu";
            string CreateTableAccount = "CREATE TABLE IF NOT EXISTS BangLuong ("
                "MaNhanVien CHAR(12) NOT NULL, "
                "TenNhanVien CHAR(30) NOT NULL, "
                "SoNgayDiLam INT(3) NOT NULL, "
                "TienCongNgay INT(10) NOT NULL, "
                "KhoanKhenThuong INT(10) NOT NULL, "
                "KhoanKyLuat INT(10) NOT NULL, "
                "BaoHiem INT(10) NOT NULL, "
                "TongCong TEXT NOT NULL"
                ");";
            stmt->execute(CreateDatabaseSQL);
            stmt->execute(useDatabase);
            stmt->execute(CreateTableAccount);
            cout << "Bang da duoc tao, du lieu da duoc them vao!" << endl;
        }
        delete result;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void TienLuong::Print() {
    try {
        Statement* stmt;
        stmt = ma->createStatement();
        string selectData = "select * from BangLuong";
        ResultSet* res = stmt->executeQuery(selectData);
        cout << "\n--------------------------BANG LUONG-------------------------------------------" << endl;
        cout << "Ma nhan vien" << "\t" << "Ten nhan vien" << "\t" << "So ngay di lam" << "\t" << "Tien cong 1 ngay"
            << "\t" << "Khen Thuong" << "\t" << "Ky Luat" << "\t" << "Bao Hiem" << "\t" << "Tong cong" << endl;
        while (res->next()) {
            cout << res->getString("MaNhanVien") << "\t" << res->getString("TenNhanVien") << "\t" << res->getString("SoNgayDiLam")
                << "\t" << res->getString("TienCongNgay") << "\t" << res->getString("KhoanKhenThuong") << "\t" << res->getString("KhoanKyLuat")
                << "\t" << res->getString("BaoHiem") << "\t" << res->getString("TongCong") << endl;
        }
        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void TienLuong::Create() {
    DD->Copy();
    Statement* stmt;
    stmt = ma->createStatement();
    string SelectData = "Select * from BangDiemDanh";
    ResultSet* res = stmt->executeQuery(SelectData);
    int count = 0;
    vector<string> manv;
    vector<string> tennv;
    vector<string> chucvu;
    vector<int> dd;
    vector<double> tien;
    vector<int> khenthuong;
    vector<int> kyluat;
    vector<int> baohiem;
    vector<long> tong;
    while (res->next()) {
        manv.push_back(res->getString("MaNhanVien"));
        tennv.push_back(res->getString("TenNhanVien"));
        dd.push_back(res->getInt("DiemDanh"));
        count++;
    }
    
    for (int i = 0; i < count; i++) {
        string SelectNhanVien = "select * from NhanVien where MaNhanVien = '"+manv[i]+"'";
        ResultSet* res1 = stmt->executeQuery(SelectNhanVien);
        while (res1->next()) {
            chucvu.push_back(res1->getString("ChucVu"));
            //cout << chucvu[i] << endl;
            //cout << res1->getString("ChucVu");
        }
        
    }

    /*for (int i = 0; i < count; i++) {
        cout << "ma: " << manv[i] << endl;
        cout << "ten: " << tennv[i] << endl;
        cout << "dd: " << dd[i] << endl;
        cout << "chuc vu: " << chucvu[i] << endl;
    }*/
    for (int i = 0; i < count; i++) {
        string SelectChucvu = "select * from ChucVu where TenChucvu = '" + chucvu[i] + "'";
        ResultSet* res2 = stmt->executeQuery(SelectChucvu);
        while (res2->next()) {
            double luong = res2->getDouble("LuongChucVu");
            luong = double(luong / 30.0);
            //cout << fixed << setprecision(2) << luong << endl;
            tien.push_back(luong);
            //cout << res2->getDouble("LuongChucVu")<<endl;
        }
    }
    /*for (int i = 0; i < count; i++) {
        cout << "luong chuc vu: " << tien[i] << endl;
    }*/

    for (int i = 0; i < count; i++) {
        string SelectChucvu = "select * from KhenThuongKyLuat where MaNhanVien = '" + manv[i] + "'";
        ResultSet* res3 = stmt->executeQuery(SelectChucvu);
        while (res3->next()) {
            khenthuong.push_back(res3->getInt("Thuong"));
            kyluat.push_back(res3->getInt("Phat"));
        }
    }
    /*for (int i = 0; i < count; i++) {
        cout << "ma: " << manv[i] << endl;
        cout << "khen thuong: " << khenthuong[i] << endl;
        cout << "ky luat: " << kyluat[i] << endl;
    }*/
    int s=0;string SelectChucvu = "select COUNT(*) as count from BaoHiem";
    ResultSet* res4 = stmt->executeQuery(SelectChucvu);
    while (res4->next()) {
        int count = res4->getInt("count");
        s += count;
    }
    for (int i = 0; i < s; i++) {
        string SelectChucvu = "select * from BaoHiem ";
        ResultSet* res5 = stmt->executeQuery(SelectChucvu);
        while (res5->next()) {
            baohiem.push_back(res5->getInt("SoTien"));
        }
    }
    for (int i = 0; i < count; i++) {
        baohiem[i] = baohiem[s - 1];
    }
    
    long tongcong = 0;
    for (int i = 0; i < count; i++) {
        tongcong = tien[i]* dd[i] + khenthuong[i] - kyluat[i] - baohiem[i];
        tong.push_back(tongcong);
    }
    /*for (int i = 0; i < count; i++) {
        cout << "ma: " << manv[i] << endl;
        cout << "ten: " << tennv[i] << endl;
        cout << "dd: " << dd[i] << endl;
        cout << "chuc vu: " << chucvu[i] << endl;
        cout << "khen thuong: " << khenthuong[i] << endl;
        cout << "ky luat: " << kyluat[i] << endl;
        cout << "Tien cong: "<< fixed << setprecision(5) << tien[i] << endl;
        cout << "bao hiem: " << baohiem[i] << endl;
        cout <<"TONG CONG: " << fixed << setprecision(2) << tong[i] << endl;
        cout << endl;
    }*/
    bool kt1;
    for (int i = 0; i < count; i++) {
        bool kt = this->CheckNV(manv[i]);
        if (kt == false) {
            NodeLuong* l = new NodeLuong(manv[i], tennv[i], dd[i], tien[i], khenthuong[i], kyluat[i], baohiem[i], tong[i]);
            kt1 = this->CreateData(l);
        }
        else continue;
    }
    delete stmt;
    delete res;
}

bool TienLuong::CheckNV(string ten) {
    try {
        Statement* stmt;
        bool kt = false;
        stmt = ma->createStatement();
        string CheckData = "Select * from bangluong Where MaNhanVien = '" + ten + "'";
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

bool TienLuong::CreateData(NodeLuong* t)
{
    if (this->head == NULL) {
        this->head = this->tail = t;
    }
    else {
        t->SetPointer(this->head);
        this->head = t;
    }
    try {
        bool kt = false;
        t = this->head;
        Statement* stmt;
        stmt = ma->createStatement();
        string MaNhanVien, TenNhanVien;
        int DD, Tien, KT, KL, BH;
        long Tong;
        MaNhanVien = t->GetID();
        TenNhanVien = t->GetName();
        DD = t->GetDD();
        Tien = t->GetTC();
        KT = t->GetKT();
        KL = t->GetKL();
        BH = t->GetBH();
        Tong = t->GetTongCong();
        string UpdateTableAccount = "insert into BangLuong Values ('" + MaNhanVien + "' ,'" 
            + TenNhanVien + "' , '" + to_string(DD) + "'  ,' " + to_string(Tien) + " ','" + to_string(KT)+
            "','" + to_string(KL) + "','" + to_string(BH) + "','" + to_string(Tong)+"');";
        stmt->execute(UpdateTableAccount);
        cout << "Du lieu da duoc cap nhat!" << endl;
        kt = true;
        delete stmt;
        delete t;
        return kt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

vector<NodeLuong> TienLuong::Tim() {
    try {
        string tim;
        cout << "Nhap ma bao hiem: "; cin >> tim;
        Statement* stmt;
        stmt = ma->createStatement();
        string CheckData = "Select * from Bangluong Where MaNhanVien = '" + tim + "'";
        ResultSet* res = stmt->executeQuery(CheckData);
        //int count;
        vector<NodeLuong> a;
        while (res->next()) {
            NodeLuong bh(res->getString("MaNhanVien"), res->getString("TenNhanVien"), res->getInt("SoNgayDiLam"), res->getDouble("TienCongNgay"),
                res->getInt("KhoanKhenThuong"), res->getInt("KhoanKyLuat"), res->getInt("BaoHiem"), res->getDouble("TongCong"));
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

bool TienLuong::Find() {
    vector<NodeLuong> a = this->Tim();
    if (a.size() != 0) return true;
    else return false;
}

void TienLuong::PrintFind() {
    bool kt = this->Find();
    string tim;
    vector<NodeLuong> a = this->Tim();
    cout << "----------TIM KIEM BAO HIEM--------------------------\n";
    Statement* stmt;
    if (kt == true) {
        cout << "Ma nhan vien" << "\t" << "Ten nhan vien" << "\t" << "So ngay di lam" << "\t" << "Tien cong 1 ngay"
            << "\t" << "Khen Thuong" << "\t" << "Ky Luat" << "\t" << "Bao Hiem" << "\t" << "Tong cong" << endl;
        for (int i = 0; i < a.size(); i++) {
            cout << a[i].GetID() << "  " << a[i].GetName() << "  " << a[i].GetDD() << "  " << a[i].GetTC() << "  " << a[i].GetKT()
                << "  " << a[i].GetKL() << "  " << a[i].GetBH() << "  " << a[i].GetTongCong() << endl;
        }
    }
    else cout << "Khong thanh cong." << endl;
}

bool TienLuong::Delete() {
    try {
        this->Print();
        string manv;
        cout << "Ma nhan vien muon xoa: " << endl; cin >> manv;
        Statement* stmt;
        stmt = ma->createStatement();
        string SelectData = "delete from bangluong where MaNhanVien = '" + manv + "'";
        int rows_affected = stmt->executeUpdate(SelectData);
        delete stmt;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void TienLuong::PrintDelete() {
    cout << "----------XOA LUONG--------------------------\n";
    bool kt = this->Delete();
    if (kt == true) {
        cout << "Xoa thanh cong.";
    }
    else cout << "Cap nhat khong thanh cong.";
}
