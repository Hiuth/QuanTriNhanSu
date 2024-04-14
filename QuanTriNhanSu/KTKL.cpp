#include"KTKL.h"
#include"KetNoi.h"
#include<iostream>
#include"string"
#include"vector"
#include <sstream>
using namespace std;

KetNoi* kn = new KetNoi();
Connection* k = kn->CheckDatabase();

KTKL::KTKL() {
    this->head = NULL;
    this->tail = NULL;
}

KTKL::~KTKL() {

}

vector<NodeKTKL> KTKL::Data_of_Line()
{
    try {
        Statement* stmt;
        stmt = k->createStatement();
        int s1 = 0;
        vector<NodeKTKL> bh;
        string SelectData = "Select *from khenthuongkyluat";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeKTKL b(res->getString("MaNhanVien"), res->getString("TenNhanVien"), res->getString("Thuong"), res->getString("Phat"), res->getString("NoiDungThuong"), res->getString("NoiDungPhat"));
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

void KTKL::DataofLine()
{
    vector<NodeKTKL> a = this->Data_of_Line();
    //cout << a.size();
    for (int i = 0; i < a.size(); i++) {
        //cout << 1;
        cout << i + 1 << "  " << a[i].getMa() << "  " << a[i].getTen() << "  " << a[i].getT() << "  " << a[i].getP() << "  " << a[i].getNDT() << "  " << a[i].getNDP() << endl;
    }
}

void KTKL::CreateTable() {
    try {
        Statement* stmt;
        stmt = k->createStatement();
        //kiem tra su ton tai cua bang
        string TenBang = "KhenThuongKyLuat";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == false) {
            string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
            string useDatabase = "Use QuanTriNhanSu";
            string CreateTableAccount = "CREATE TABLE IF NOT EXISTS KhenThuongKyLuat ("
                "MaNhanVien CHAR(30) NOT NULL, "
                "TenNhanVien CHAR(30) NOT NULL, "
                "Thuong CHAR(10) NOT NULL, "
                "Phat CHAR(10) NOT NULL, "
                "NoiDungThuong CHAR(30) NOT NULL, "
                "NoiDungPhat CHAR(30) NOT NULL"
                ")";
            stmt->execute(CreateDatabaseSQL);
            stmt->execute(useDatabase);
            stmt->execute(CreateTableAccount);
            cout << "Bang da duoc tao!" << endl;
        }
        delete result;
        delete stmt;
        //this->Print();
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void KTKL::Print() {
    try {
        //int s = 0, s1 = 0;
        Statement* stmt;
        stmt = k->createStatement();
        string selectData = "select * from KhenThuongKyLuat";
        ResultSet* res = stmt->executeQuery(selectData);
        cout << "----------DANH SACH KHEN THUONG KY LUAT--------------------------\n";
        cout << "Ma nhan vien" << "\t" << "Ten nhan vien" << "\t" << "Tien Thuong""\t" << "Tien Phat""\t" << "Noi dung thuong""\t" << "Noi dung phat" << endl;
        while (res->next()) {
            cout << res->getString("MaNhanVien") << "\t" << res->getString("TenNhanVien") << "\t" << res->getInt("Thuong") << "\t" << res->getString("Phat") << "\t" << res->getString("NoiDungThuong") << "\t" << res->getString("NoiDungPhat") << endl;
        }
        /*string CheckData = "SELECT COUNT(*) AS count FROM KhenThuongKyLuat WHERE TenNhanVien IS NOT NULL";
        ResultSet* result = stmt->executeQuery(CheckData);
        if (result->next()) {
            int count = result->getInt("count");
            s += count;
        }
        cout << "Count = " << s;
        string CountData = "SELECT COUNT(*) AS count FROM INFORMATION_SCHEMA.COLUMNS WHERE table_schema = 'quantrinhansu' AND table_name = 'khenthuongkyluat';";
        ResultSet* result1 = stmt->executeQuery(CountData);
        if (result1->next()) {
            int count = result1->getInt("count");
            s1 += count;
        }
        cout << "\nS = " << s1 << endl;*/
        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

bool KTKL::CreateData(NodeKTKL* t) {
    if (this->head == NULL) {
        this->head = this->tail = t;
    }
    else {
        t->setPointer(this->head);
        this->head = t;
    }
    try {
        t = this->head;
        Statement* stmt;
        stmt = k->createStatement();
        string MaNhanVien,TenNhanVien, NDT, NDP, Thuong, Phat;
        MaNhanVien = t->getMa();
        TenNhanVien = t->getTen();
        Thuong = t->getT();
        Phat = t->getP();
        NDT = t->getNDT();
        NDP = t->getNDP();
        string UpdateTableAccount = "insert into KhenThuongKyLuat Values ('" + MaNhanVien + "' ,'" + TenNhanVien + "' ,'" + Thuong + "','" + Phat + "','" + NDT + "','" + NDP + "');";
        stmt->execute(UpdateTableAccount);
        cout << "Du lieu da duoc cap nhat!" << endl;
        delete stmt;
        delete t;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}


int Extra(string ten, bool luachon, string ex) {
    try {
        Statement* stmt;
        stmt = k->createStatement();
        string select = "select*from KhenThuongKyLuat where MaNhanVien = '" + ten + "'";
        ResultSet* res1 = stmt->executeQuery(select);
        int d;
        if (luachon == true) {
            while (res1->next()) {
                d = res1->getInt("Thuong");
            }
        }
        else {
            while (res1->next()) {
                d = res1->getInt("Phat");
            }
        }
        int num = stoi(ex);
        int sum = num + d;
        return sum;
        delete res1;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}


bool Check(string tim) {
    try {
        Statement* stmt;
        bool kt = false;
        stmt = k->createStatement();
        string CheckData = "Select * from NhanVien Where MaNhanVien = '" + tim + "'";
        ResultSet* result = stmt->executeQuery(CheckData);
        int count = 0;
        while (result->next()) {
            kt = true;
        }
        return kt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void KTKL::Create() {
    this->Print();

    int luachon = 0;
    string ten, ma;
    string MaNhanVien, TenNhanVien, NDT, NDP;
    string Thuong, Phat;
    NodeKTKL* t;

    cout << "----------NHAP/THEM KHEN THUONG, KY LUAT--------------------------\n";
    cout << "MENU\n";
    cout << "Chon 1 trong 2 tuy chon:\n1. Khen thuong\n2.Ky Luat\n" << endl;
    cin >> luachon;
    cout << "Nhap ma nhan vien: " << endl; cin >> ten;
    cout << "Nhap ten nhan vien: " << endl; cin >> ma;
    bool ktnv = Check(ten); // kiem tra co nhan vien A co trong bang nhan vien kh
    bool ktdl;
    bool ktnvktkl = this->CheckKTKL(ten); // kiem tra nhan vien A co trong bang khen thuong ky luat kh
    if (ktnv == true) { // kiem tra co nhan vien A co trong bang nhan vien kh
        if (ktnvktkl == true) { // kt nhan vien co trong bang ktkl kh
            if (luachon == 1) {
                ktdl = this->CheckData(ten, "Thuong"); // kiem tra co du lieu trong cot tien thuong kh
                if (ktdl == false) { // nghia la co du lieu trong cot tien thuong nen cong don so tien moi nhap vao
                    cout << "Nhap tien thuong: \n"; cin >> Thuong;
                    cout << "Nhap noi dung thuong: \n"; cin >> NDT;
                    bool luachon = true;
                    int e = Extra(ten, luachon, Thuong);
                    Thuong = to_string(e);
                    //cout << "Thuong = " << Thuong << endl;
                    this->EditData("Thuong", Thuong, ten);
                    this->EditData("NoiDungThuong", NDT, ten);
                    cout << "Them thanh cong.\n";
                }
                else { // nghia la kh co du lieu trong cot tien thuong nen them moi vao
                    cout << "Nhap tien thuong: \n"; cin >> Thuong;
                    cout << "Nhap noi dung thuong: \n"; cin >> NDT;
                    this->EditData("Thuong", Thuong, ten);
                    this->EditData("NoiDungThuong", NDT, ten);
                    cout << "Nhap thanh cong.\n";
                }
            }
            else if (luachon == 2) {
                ktdl = this->CheckData(ten, "Phat");
                if (ktdl == false) { // nghia la co du lieu trong cot tien thuong nen cong don so tien moi nhap vao
                    cout << "Nhap tien phat: \n"; cin >> Phat;
                    cout << "Nhap noi dung phat: \n"; cin >> NDP;
                    bool luachon = false;
                    int e = Extra(ten, luachon, Phat);
                    Phat = to_string(e);
                    this->EditData("Phat", Phat, ten);
                    this->EditData("NoiDungPhat", NDP, ten);
                    cout << "Them thanh cong.\n";
                }
                else { // nghia la kh co du lieu trong cot tien thuong nen them moi vao
                    cout << "Nhap tien thuong: \n"; cin >> Phat;
                    cout << "Nhap noi dung thuong: \n"; cin >> NDP;
                    this->EditData("Phat", Phat, ten);
                    this->EditData("NoiDungPhat", NDP, ten);
                    cout << "Nhap thanh cong.\n";
                }
            }
            else cout << "Khong co lua chon nay.";
        }
        else { // khong co nhan vien A trong bang ktkl nen nhap moi vao
            if (luachon == 1) {
                cout << "Nhap tien thuong: \n"; cin >> Thuong;
                cout << "Nhap noi dung thuong: \n"; cin >> NDT;
                t = new NodeKTKL(ten, ma, Thuong, "", NDT, "");
                this->CreateData(t);
            }
            else if (luachon == 2) {
                cout << "Nhap tien phat: \n"; cin >> Phat;
                cout << "Nhap noi dung phat: \n"; cin >> NDP;
                t = new NodeKTKL(ten, ma, "", Phat, "", NDP);
                this->CreateData(t);
            }
            else cout << "Khong co lua chon nay.\n";
        }
    }
    else cout << "Khong co nhan vien nay.\n";
}

bool KTKL::CheckKTKL(string tim) {
    try {
        Statement* stmt;
        bool kt = false;
        stmt = k->createStatement();
        string CheckData = "Select * from KhenThuongKyLuat Where MaNhanVien = '" + tim + "'";
        ResultSet* result = stmt->executeQuery(CheckData);
        int count = 0;
        while (result->next()) {
            kt = true;
        }
        return kt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

bool KTKL::CheckData(string tim, string tuychon) {
    try {
        Statement* stmt;
        bool kt = false;
        stmt = k->createStatement();
        string CheckData = "SELECT COUNT(*) AS count FROM KhenThuongKyLuat WHERE MaNhanVien =  '" + tim + "' and '" + tuychon + "' = ''";
        ResultSet* result = stmt->executeQuery(CheckData);
        if (result->next()) {
            int count = result->getInt("count");
            if (count > 0) {
                kt = true;
            }
        }
        return kt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

//void KTKL::Delete() {
//    this->Print();
//    bool kt = false;
//    int luachon;
//    string ten ,ma;
//    string Thuong, Phat, NDT, NDP;
//
//    cout << "----------XOA KHEN THUONG, KY LUAT--------------------------\n";
//    cout << "Nhap ma nhan vien: " << endl; cin >> ten;
//    bool ktdl;
//    bool ktnvktkl = this->CheckKTKL(ten); // kiem tra nhan vien A co trong bang khen thuong ky luat kh
//    if (ktnvktkl == true) {
//        kt = this->DeleteData(ten);
//        if (kt == true) cout << "Xoa thanh cong.\n";
//        else cout << "Xoa khong thanh cong.\n";
//    }
//    else {
//        cout << "Khong co du lieu de xoa.";
//    }
//}

//bool KTKL::DeleteData(string xoa) {
//    Statement* stmt;
//    stmt = k->createStatement();
//    string SelectData = "Delete from KhenThuongKyLuat where MaNhanVien = '" + xoa + "'";
//    int rows_affected = stmt->executeUpdate(SelectData);
//    delete stmt;
//    return true;
//    this->Print();
//}

vector<NodeKTKL> KTKL::Tim() {
    try {
        string tim;
        cout << "Nhap ma nhan vien: "; cin >> tim;
        Statement* stmt;
        stmt = k->createStatement();
        string CheckData = "Select * from khenthuongkyluat Where MaNhanVien = '" + tim + "'";
        ResultSet* res = stmt->executeQuery(CheckData);
        //int count;
        vector<NodeKTKL> a;
        while (res->next()) {
            NodeKTKL bh(res->getString("MaNhanVien"), res->getString("TenNhanVien"), res->getString("Thuong"), res->getString("Phat"), res->getString("NoiDungThuong"), res->getString("NoiDungPhat"));
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

bool KTKL::Find() {
    vector<NodeKTKL> a = this->Tim();
    if (a.size() != 0) return true;
    else return false;
}

void KTKL::PrintFind() {
    bool kt = this->Find();
    string tim;
    vector<NodeKTKL> a = this->Tim();
    cout << "----------TIM KIEM KTKL--------------------------\n";
    Statement* stmt;
    if (kt == true) {
        cout << "Ma nhan vien" << "\t" << "Ten nhan vien" << "\t" << "Tien Thuong""\t" << "Tien Phat""\t" << "Noi dung thuong""\t" << "Noi dung phat" << endl;
        for (int i = 0; i < a.size(); i++) {
            cout << a[i].getMa() << "  " << a[i].getTen() << "  " << a[i].getT() << "  " << a[i].getP() << "  " << a[i].getNDT() << "  " << a[i].getNDP() << endl;
        }
    }
    else cout << "Khong thanh cong." << endl;
}

bool KTKL::Delete() {
    try {
        this->Print();
        string ma;
        cout << "Ma nhan vien muon xoa: " << endl; cin >> ma;
        Statement* stmt;
        stmt = k->createStatement();
        string SelectData = "delete from khenthuongkyluat where MaNhanVien = '" + ma + "'";
        int rows_affected = stmt->executeUpdate(SelectData);
        delete stmt;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void KTKL::PrintDelete() {
    cout << "----------XOA BAO HIEM--------------------------\n";
    bool kt = this->Delete();
    if (kt == true) {
        cout << "Xoa thanh cong.";
    }
    else cout << "Cap nhat khong thanh cong.";
}

void KTKL::Edit() {
    this->Print();

    int luachon;
    string ten;
    string Thuong, Phat, NDT, NDP;

    cout << "----------CHINH SUA KHEN THUONG, KY LUAT--------------------------\n";
    cout << "MENU\n";
    cout << "Chon 1 trong 2 tuy chon:\n1. Khen thuong\n2.Ky Luat\n" << endl;
    cin >> luachon;
    cout << "Nhap ma nhan vien: " << endl; cin >> ten;
    bool ktdl;
    bool ktnvktkl = this->CheckKTKL(ten); // kiem tra nhan vien A co trong bang khen thuong ky luat kh
    if (ktnvktkl == true) {
        if (luachon == 1) {
            ktdl = this->CheckData(ten, "Thuong"); // kiem tra co du lieu trong cot tien thuong kh
            if (ktdl == false) { // nghia la co du lieu trong cot tien thuong nen cong don so tien moi nhap vao
                cout << "Nhap tien thuong: \n"; cin >> Thuong;
                cout << "Nhap noi dung thuong: \n"; cin >> NDT;
                this->EditData("Thuong", Thuong, ten);
                this->EditData("NoiDungThuong", NDT, ten);
                cout << "Them thanh cong.\n";
            }
            else {
                cout << "Khong co du lieu de chinh sua.\n";
            }
        }
        else if (luachon == 2) {
            ktdl = this->CheckData(ten, "Phat");
            if (ktdl == false) { // nghia la co du lieu trong cot tien thuong nen cong don so tien moi nhap vao
                cout << "Nhap tien phat: \n"; cin >> Phat;
                cout << "Nhap noi dung phat: \n"; cin >> NDP;
                this->EditData("Phat", Phat, ten);
                this->EditData("NoiDungPhat", NDP, ten);
                cout << "Them thanh cong.\n";
            }
            else { // nghia la kh co du lieu trong cot tien thuong nen them moi vao
                cout << "Khong co du lieu de chinh sua.\n";
            }
        }
        else cout << "Khong co lua chon nay.\n";
    }
    else {
        cout << "Khong co du lieu de chinh sua.";
    }
}

bool KTKL::EditData(string ChoCanSua, string MuonDoiThanh, string ten) {
    try {
        Statement* stmt;
        stmt = k->createStatement();
        string SelectData2 = "UPDATE KhenThuongKyLuat SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE MaNhanVien = '" + ten + "'";
        int rows_affected = stmt->executeUpdate(SelectData2);
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}