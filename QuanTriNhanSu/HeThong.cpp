#include "HeThong.h"
#include "KetNoi.h"

KetNoi* Check = new KetNoi();
Connection* con= Check->CheckDatabase();
HeThong::HeThong() {
    this->head = NULL;
    this->tail = NULL;
}

HeThong::~HeThong() {


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
            string CreateTableAccount = "create table if not exists TaiKhoan (""TenTaiKhoan char(10) primary key,""MatKhau char(20) not null,""admin char(1) not null, ""QuanLyNhanSu char(1) not null, ""QuanLyTienLuong char(1) not null)";
            string insertTableAccount = "insert into TaiKhoan Values (1111111111,1111111111,1,1,1);"; //1 là có quyền truy cập, 0 là không có quyền truy cập vào chức năng
            stmt->execute(CreateDatabaseSQL);
            stmt->execute(useDatabase);
            stmt->execute(CreateTableAccount);
            stmt->execute(insertTableAccount);
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

void HeThong::PrintAccount() {
    Statement* stmt;
    stmt = con->createStatement();
    string SelectData = "Select *from TaiKhoan";
    ResultSet* res = stmt->executeQuery(SelectData);
    int count = 0;
    cout << "Danh Sach cac tai khoan" << endl;
    cout <<"STT"<<"\t" << "Ten Tai Khoan " << "\t" << "Mat khau" << "\t" << "Quyen Admin" << "\t" << "Quyen quan ly nhan su" << "\t" << "Quyen quan ly tai khoan" << endl;
    while (res->next()) {
        cout<<++count<<"\t" << res->getString("TenTaiKhoan") << "\t" << res->getString("MatKhau") << "\t" << res->getString("admin") << "\t" << "\t" << "\t" << res->getString("QuanLyNhanSu") << "\t" << "\t" << "\t" << "\t" << res->getString("QuanLyTienLuong") << endl;
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
            cout << "Tai khoan khog co trong he thong." << endl;
            break;
        }
    }
    delete res;
    delete stmt;
}

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