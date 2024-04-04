#include "HeThong.h"
#include "KetNoi.h"
#include <vector>

KetNoi* Check = new KetNoi();
Connection* con= Check->CheckDatabase();

HeThong::HeThong() {
    this->head = NULL;
    this->tail = NULL;
}

bool HeThong::CheckAccount(string TenTaiKhoan, string MatKhau) {
    Statement* stmt;
    stmt = con->createStatement();
    string CheckData = "Select * from TaiKhoan Where TenTaiKhoan = '" + TenTaiKhoan + "' AND MatKhau = '" + MatKhau + "'";
    ResultSet* result = stmt->executeQuery(CheckData);
    while (result->next()) {
        return true;
    } return false;
}

bool HeThong::CheckAccount(string ten, string matkhau) {
    try {
        Statement* stmt;
        stmt = con->createStatement();
        string CheckData = "Select * from TaiKhoan Where TenTaiKhoan = '" + ten + "' AND " + matkhau + " = 1";
        ResultSet* result = stmt->executeQuery(CheckData);
        while (result->next()) {
            return true;
        }//return false;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

void HoTroCapNhat(Node* p, Statement* stmt) {
    string accountName;
    string password;
    string admin;
    string HRM;
    string FM;
    accountName = p->GetAccountName();
    password = p->GetPassword();
    admin = p->GetAdmin();
    HRM = p->GetHRM();
    FM = p->GetFM();
    string UpdateTableAccount = "insert into TaiKhoan Values ('" + accountName + "','" + password + "','" + admin + "', '" + HRM + "','" + FM + "');";
    stmt->execute(UpdateTableAccount);
}

void HeThong::CreateAccount(Node* p ){
    // insertNode
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
        stmt = con->createStatement();
        //kiem tra su ton tai cua bang
        string TenBang = "TaiKhoan";
        string KiemTra = "show tables like'"+TenBang +"'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next()==true) { //nếu có bảng thì result sẽ trả về true, không có thì ngược lại
            HoTroCapNhat(p, stmt);
            cout << "Du lieu da duoc cap nhat!" << endl;
        }
        else {
            string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
            string useDatabase = "Use QuanTriNhanSu";
            string CreateTableAccount = "create table if not exists TaiKhoan (""TenTaiKhoan char(10) primary key,"
                "MatKhau char(20) not null,""admin bool not null, "
                "QuanLyNhanSu bool not null, "
                "QuanLyTienLuong bool not null)"; //1 là có quyền truy cập, 0 là không có quyền truy cập vào chức năng
            stmt->execute(CreateDatabaseSQL);
            stmt->execute(useDatabase);
            stmt->execute(CreateTableAccount);
            HoTroCapNhat(p, stmt);
            cout << "Bang da duoc tao, du lieu da duoc them vao!" << endl;
        }
        delete result;
        delete stmt;
        delete p;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}
//vector<Node> HeThong::PrintAccount() {
//    vector<Node> accounts;
//    Statement* stmt;
//    stmt = con->createStatement();
//    string SelectData = "Select *from TaiKhoan";
//    ResultSet* res = stmt->executeQuery(SelectData);
//    int count = 0;
//    while (res->next()) {
//        Node account(res->getString("TenTaiKhoan"), res->getString("MatKhau"), res->getString("admin"), res->getString("QuanLyNhanSu"), res->getString("QuanLyTienLuong"));
//        accounts.push_back(account);
//    }
//    delete res;
//    delete stmt;
//    return accounts;
//
//}

void  HeThong::PrintAccount() {
    vector<Node> accounts;
    Statement* stmt;
    stmt = con->createStatement();
    string SelectData = "Select *from TaiKhoan";
    ResultSet* res = stmt->executeQuery(SelectData);
    int count = 0;
    cout << "Danh Sach cac tai khoan" << endl;
    cout << "Ten Tai Khoan " << "\t" << "Mat khau" << "\t" << "Quyen Admin" << "\t" << "Quyen quan ly nhan su" << "\t" << "Quyen quan ly tai chinh" << endl;
    while (res->next()) {
        cout << res->getString("TenTaiKhoan") << "\t" << res->getString("MatKhau") << "\t" << res->getString("admin") << "\t" << "\t" << "\t" << res->getString("QuanLyNhanSu") << "\t" << "\t" << "\t" << "\t" << res->getString("QuanLyTienLuong") << endl;
        cout << endl;
 
    }
    delete res;
    delete stmt;

}

void  HeThong::Search(string ten,string ma) {
    Statement* stmt;
    stmt = con->createStatement();
    string SelectData = "Select *from TaiKhoan where "+ten+" = '"+ ma +"'";
    ResultSet* res = stmt->executeQuery(SelectData);
    cout << endl;
    while (true) {
        if (res->next()) {
            cout << "Tai khoan co ton tai trong he thong" << endl;
            cout  << "Ten Tai Khoan " << "\t" << "Mat khau" << "\t" << "Quyen Admin" << "\t" << "Quyen quan ly nhan su" << "\t" << "Quyen quan ly tai khoan" << endl;
            cout  << res->getString("TenTaiKhoan") << "\t" << res->getString("MatKhau") << "\t" << res->getString("admin") << "\t" << "\t" << "\t" << res->getString("QuanLyNhanSu") << "\t" << "\t" << "\t" << "\t" << res->getString("QuanLyTienLuong") << endl;
            cout << endl;
            
        }
        else {
            cout << "Tai khoan khong co trong he thong." << endl;
            break;
        }
    }
    delete res;
    delete stmt;
}
//vector<Node>  HeThong::Search(string ten, string ma) {
//    vector<Node> accountFromSearch;
//    Statement* stmt;
//    stmt = con->createStatement();
//    string SelectData = "Select *from TaiKhoan where " + ten + " = '" + ma + "'";
//    ResultSet* res = stmt->executeQuery(SelectData);
//    while (res->next()) {
//        Node account(res->getString("TenTaiKhoan"), res->getString("MatKhau"), res->getString("admin"), res->getString("QuanLyNhanSu"), res->getString("QuanLyTienLuong"));
//        accountFromSearch.push_back(account);
//    }
//    delete res;
//    delete stmt;
//    return accountFromSearch;
//}

void HeThong::deleteAccount(string xoa) {
    Statement* stmt;
    stmt = con->createStatement();
    string SelectData = "Delete from TaiKhoan where TenTaiKhoan = '" + xoa + "'";
    int rows_affected = stmt->executeUpdate(SelectData);
    delete stmt;
}

void HeThong::EditAccount(string ChoCanSua, string MuonDoiThanh,string TenTk) {
    Statement* stmt;
    stmt = con->createStatement();
    string SelectData2 = "UPDATE TaiKhoan SET " + ChoCanSua + " = '"+ MuonDoiThanh + "' WHERE TenTaiKhoan = '" + TenTk + "'";
    int rows_affected = stmt->executeUpdate(SelectData2);
    delete stmt;
}

HeThong::~HeThong() {
    delete con;
    delete Check;
}

bool HeThong::CheckData(string TenTaiKhoan, string TenCot) {
    Statement* stmt;
    stmt = con->createStatement();
    string CheckData = "Select * from TaiKhoan Where TenTaiKhoan = '" + TenTaiKhoan + "' AND " + TenCot + " = 1";
    ResultSet* result = stmt->executeQuery(CheckData);
    while (result->next()) {
        return true;
    }
    return false;
}
//het cuu
