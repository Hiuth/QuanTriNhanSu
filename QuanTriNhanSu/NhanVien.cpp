#include "NhanVien.h"
#include"KetNoi.h"

KetNoi* Check2 = new KetNoi();
Connection* con2 = Check2->CheckDatabase();

NhanVien::NhanVien() {
	this->tail = NULL;
	this->head = NULL;
}

void HoTroCapNhat(NodeNhanVien* p, Statement* stmt) {
    string TenNhanVien;
    string SinhNhat;
    string CCCD;
    string DiaChi;
    string PhongBan;
    string GioiTinh;
    string ChucVu;

    TenNhanVien = p->GetName();
    SinhNhat = p->GetBirthday();
    CCCD = p->GetIDCard();
    DiaChi = p->GetAddress();
    PhongBan = p->GetDepartment();
    GioiTinh = p->GetSex();
    ChucVu = p->GetPost();
    
    string UpdateTableAccount = "insert into NhanVien Values ('"+TenNhanVien+"','"+GioiTinh+"','"+SinhNhat+"','"+CCCD+"','"+DiaChi+"','"+PhongBan+"','"+ChucVu+"');";
    stmt->execute(UpdateTableAccount);
}

void NhanVien::CreateName(NodeNhanVien* p) {
    if (this->head == NULL) {
        this->head = this->tail = p;
    }
    else {
        p->SetPointer(this->head);
        this->head = p;
    }
    try {
        p = this->head;
        Statement* stmt;
        stmt = con2->createStatement();
        //kiem tra su ton tai cua bang
        string TenBang = "NhanVien";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == true) { //nếu có bảng thì result sẽ trả về true, không có thì ngược lại
            HoTroCapNhat(p, stmt);
            cout << "Du lieu da duoc cap nhat!" << endl;
        }
        else {
            string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
            string useDatabase = "Use QuanTriNhanSu";
            string CreateTableAccount = "create table if not exists NhanVien (""TenNhanVien char(30) not null,""GioiTinh char(10) not null,""SinhNhat char(10) not null,""CCCD char(12) primary key,""DiaChi char(100) not null,""PhongBan char(20) not null,""ChucVu char(20) not null)";
         //1 là có quyền truy cập, 0 là không có quyền truy cập vào chức năng
            stmt->execute(CreateDatabaseSQL);
            stmt->execute(useDatabase);
            stmt->execute(CreateTableAccount);
            HoTroCapNhat(p, stmt);
            cout << "Bang da duoc tao"<< endl;
        }
        delete result;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void NhanVien::PrintEmployeeInfotmation() {
    Statement* stmt;
    stmt = con2->createStatement();
    string SelectData = "Select * from NhanVien";
    ResultSet* res = stmt->executeQuery(SelectData);
    int count = 0;
    cout << "Danh Sach cac nhan vien" << endl;
    cout << "STT" << "\t" << "Ten Nhan Vien"<<"\t" << "\t" << "\t" << "Gioi Tinh" << "\t" << "Sinh Nhat" << "\t" << "Can cuoc cong dan" << "\t" << "Dia chi" << "\t" << "\t" << "\t" << "Phong ban" << " " << "\t" << "\t" << "Chuc vu" << endl;
    while (res->next()) {
        cout << ++count << "\t" << res->getString("TenNhanVien") <<"\t" << "\t" << "\t" << res->getString("GioiTinh") << "\t" << "\t" << res->getString("SinhNhat") << "\t" << res->getString("CCCD") << "\t" << "\t" << res->getString("DiaChi") << "\t" << "\t" << "\t" << res->getString("PhongBan") << "\t" << "\t"<<"\t" << res->getString("ChucVu") << endl;
        cout << endl;
    }
    delete res;
    delete stmt;

}

void NhanVien::EditInformation() {

}


NhanVien::~NhanVien() {
    delete con2;
    delete Check2;
}