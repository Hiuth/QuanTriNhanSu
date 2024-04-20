#include "HeThong.h"
#include "KetNoi.h"
#include <vector>
#include<string>
#include <cctype>

KetNoi* Check = new KetNoi();
Connection* con= Check->CheckDatabase();
HeThong::HeThong() {
    this->head = NULL;
    this->tail = NULL;
}

int n,nhap;
bool admin, hrm, fm;
string tk, mk, ten, xoa, ma;
HeThong* TaiKhoan = new HeThong();
Node* e;


bool HeThong::DangNhap() {
    cout << "hay dang nhap vao he thong" << endl;
    cout << "nhap ten tai khoan: "; getline(cin, ten);
    cout << "nhap vao mat khau: "; getline(cin, mk);
    if (TaiKhoan->CheckAccount(ten, mk) == true) {
        return true;
    }
    else {
        return false;
    }
}

void HeThong::InputDeleteAccount() {
     cout << "Nhap vao ten tai khoan muon xoa: "; getline(cin, xoa);
    TaiKhoan->deleteAccount(xoa);
}

void HeThong::Input() {
    cout << "so luong tai khoan muon nhap vao: "; cin >> n; //ko chấp nhận đc vẫn để là "tai khoang"
    for (int i = 0; i < n; i++) {
        bool Ktra = false;
        while (!Ktra) {
            cin.ignore();
            cout << "tai khoan: "; getline(cin,tk);
            cout << "mat khau: "; getline(cin,mk);
            cout << "neu muon cap quyen thi hay bam so 1, neu khong thi bam so 0." << endl;;
            cout << "quyen admin: "; cin >> admin;
            cout << "quyen quan ly nhan su: "; cin >> hrm;
            cout << "quyen quan ly tien luong: "; cin >> fm;
            if (!tk.empty()&&CheckSpacebar(tk) && !mk.empty()&&check6Number(mk) && checkSytax(mk)) {
                Ktra = true;
            }
            else {
                cout << "Cu phap ban nhap khong hop le! Tai khoan va mat khau khong duoc co khoang cach trang va mat khau khong duoc nho hon 6!" << endl;
            }
        }
        e = new Node(tk, mk, admin, hrm, fm);
        TaiKhoan->CreateAccount(e);
        cout << endl;
    }

}

void HeThong::InputSearch() {
    cout << "1.tim kiem theo quyen admin." << endl;
    cout << "2.tim kiem theo quyen quan ly nhan su." << endl;
    cout << "3.tim kiem theo quyen quan ly tien luong." << endl;
    cout << "4.tim kiem theo ten tai khoan." << endl;
    cout << "ban muon chon theo gi ? "; cin >> n;
    if (n == 1) {
        TaiKhoan->PrintAccount(TaiKhoan->Search("admin", "1"));
    }
    else if(n == 2) {
        TaiKhoan->PrintAccount(TaiKhoan->Search("quanlynhansu", "1"));
    }
    else if (n == 3) {
        TaiKhoan->PrintAccount(TaiKhoan->Search("quanlytienluong", "1"));
    }
    else if (n == 4) {
        cin.ignore();
    	cout << "nhap vao ten tai khoan: "; getline(cin, ten);
        TaiKhoan->PrintAccount(TaiKhoan->Search("tentaikhoan", ten));
    }
    else {
    	cout << "khong co so ma ban da chon. vui long nhap lai!"<<endl;
    }
}

void check(int chon2, string quyen, string Tentk) {
    HeThong* Taikhoan = new HeThong();
    if (chon2 == 1) {
        Taikhoan->EditAccount(quyen, "1", Tentk);
    }
    else if (chon2 == 0) {
        Taikhoan->EditAccount(quyen, "0", Tentk);
    }
    else {
        cout << "Vui long chon lai!" << endl;
    }
}
bool HeThong::checkName(string ten, string ma) {
    Statement* stmt;
    stmt = con->createStatement();
    string SelectData = "Select *from TaiKhoan where " + ten + " = '" + ma + "'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        return true;
    }
    return false;
    delete res;
    delete stmt;
}

bool HeThong::checkSytax(string Pass)
{
    for (char c : Pass) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

void HeThong::InputEdit() {
    cout << "Nhap vao ten tai khoan can chinh sua: "; cin >> ten;
    if (TaiKhoan->checkName("TenTaiKhoan", ten)) {
        cout << "Chon che do chinh sua! " << endl;
        cout << "1. Sua ten Tai Khoan." << endl;
        cout << "2. Sua mat khau." << endl;
        cout << "3. Sua cac quyen." << endl;
        cout << "Ban muon chon gi ? "; cin >> n;
        if (n == 1) {
            cin.ignore();
            cout << "Nhap vao ten muon doi: "; getline(cin, ma);
            TaiKhoan->EditAccount("TenTaiKhoan", ma, ten);//Thứ tự tên tài khoản, tên muốn đổi, vị trí cần đổi
        }
        else if (n == 2) {
            cin.ignore();
            cout << "Nhap vao mat khau moi: "; getline(cin, mk);
            TaiKhoan->EditAccount("MatKhau", mk, ten);
        }
        else if (n == 3) {
            cout << "Ban da chon che do sua cac quyen. " << endl;
            cout << "1. Sua quyen admin." << endl;
            cout << "2. Sua quyen quan ly nhan su." << endl;
            cout << "3. Sua quyen quan ly tien luong." << endl;
            cout << "Ban muon chon gi ?"; cin >> n;
            cout << "Ban muon Them hay xoa quyen nay ? Neu ban muon them hay bam so 1 neu ban muon xoa thi hay bam so 0: "; cin >> nhap;
            if (n == 1) {
                check(nhap, "admin", ten);
            }
            else if (n == 2) {
                check(nhap, "QuanLyNhanSu", ten);
            }
            else if (n == 3) {
                check(nhap, "QuanLyTienLuong", ten);
            }
            else {
                cout << "Khong co lua chon nay vui long nhap lai!!!" << endl;
            }
        }
    }
    else {
        cout << "Khong co tai khoan co ten nhu vay trong he thong." << endl;;
    }
  
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




void HeThong::PrintAccount(vector<Node> check) {
    cout << "Ten Tai Khoan " << "\t" << "Mat khau" << "\t" << "Quyen Admin" << "\t" << "Quyen quan ly nhan su" << "\t" << "Quyen quan ly tai khoan" << endl;
    for (size_t i = 0; i < check.size(); i++) {
        cout << check[i].GetAccountName() << "\t" << check[i].GetPassword() << "\t" "\t" << check[i].GetAdmin() << "\t" "\t" << check[i].GetFM() <<"\t" "\t" "\t" << check[i].GetHRM() << endl;
    }
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
            string accountName;
            string password;
            string admin;
            string HRM;
            string FM;
            accountName = p->GetAccountName();
            password = p->GetPassword();
            admin = to_string(p->GetAdmin());
            HRM = to_string(p->GetHRM());// ép kiểu là hết lỗi ảo chưa =))) bên trong bảng có là kiểu gì đi chăng nữa thì nhập từ c++ vào cx phải là string
            //vô bảng nó tự trả kiểu lại. siuuuuuuuuuuuuuuuuuuuu
            FM = to_string(p->GetFM());
            string UpdateTableAccount = "insert into TaiKhoan Values ('" + accountName + "','" + password + "','" + admin + "', '" + HRM + "','" + FM + "');";
            stmt->execute(UpdateTableAccount);
            cout << "Du lieu da duoc cap nhat!" << endl;
        }
        else {
            cout << "Vui long kiem tra lai du lieu. " << endl;
        }
        delete result;
        delete stmt;
        delete p;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}

vector<Node> HeThong::TakeAllAccount() {
    vector<Node> accounts;
    Statement* stmt;
    stmt = con->createStatement();
    string SelectData = "Select *from TaiKhoan";
    ResultSet* res = stmt->executeQuery(SelectData);
    int count = 0;
    while (res->next()) {
        string str1 = res->getString("admin");
        bool a = static_cast<bool>(stoi(str1));
        string str2 = res->getString("QuanLyNhanSu");
        bool b = static_cast<bool>(stoi(str2));
        string str3 = res->getString("QuanLyTienLuong");
        bool c = static_cast<bool>(stoi(str3));
        Node account(res->getString("TenTaiKhoan"), res->getString("MatKhau"), a,b,c );
        accounts.push_back(account);
    }
    delete res;
    delete stmt;
    return accounts;

}


vector<Node> HeThong::Search(string ten, string ma) {
    vector<Node> accountFromSearch;
    Statement* stmt;
    stmt = con->createStatement();
    string SelectData = "Select *from TaiKhoan where " + ten + " = '" + ma + "'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        string str1 = res->getString("admin");
        bool a = static_cast<bool>(stoi(str1));
        string str2 = res->getString("QuanLyNhanSu");
        bool b = static_cast<bool>(stoi(str2));
        string str3 = res->getString("QuanLyTienLuong");
        bool c = static_cast<bool>(stoi(str3));
        Node account(res->getString("TenTaiKhoan"), res->getString("MatKhau"), a, b, c);
         accountFromSearch.push_back(account);
    }
    delete res;
    delete stmt;
    return accountFromSearch;
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

HeThong::~HeThong() {
    delete con;
    delete Check;
}

bool HeThong::CheckSpacebar(string NameAcc)
{
    for (char c : NameAcc) {
        if (isspace(c)) {// nếu có khoảng cách trắng thì trả về false
            return false;
        }
    }
    return true;
}

bool HeThong::check6Number(string Pass)
{
    if (Pass.size() < 6) {
        return false;
    }
    return true;
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
