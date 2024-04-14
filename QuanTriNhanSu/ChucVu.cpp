#include "ChucVu.h"
#include "KetNoi.h"
KetNoi* KtraData = new KetNoi();
Connection* connection = KtraData->CheckDatabase();
ChucVu::ChucVu() {
    this->tail = NULL;
    this->head = NULL;
}

ChucVu::~ChucVu() {
    delete connection;
    delete KtraData;
}

int choose;
long luong;
string TenCv, mota;
ChucVu* kt = new ChucVu();
NodeChucVu* cv;

void ChucVu::InputPosition() {

       cout << "So luong chuc vu muon them vao: "; cin >> choose;
    cin.ignore();
    for (int i = 0; i < choose; i++) {
	    cout << "Nhap vao ten chuc vu: "; getline(cin, TenCv);
	    cout << "Nhap vao luong co ban: "; cin >> luong;
	    cin.ignore();
	    cout << "Nhap vao mo ta chuc vu: "; getline(cin, mota);
	    cv = new NodeChucVu(TenCv,luong,mota);
	    kt->CreatePosition(cv);
    }

}

void ChucVu::InputDetletePosition() {
    cout << "Nhap vao chuc vu can xoa: "; getline(cin, TenCv);
    kt->DeletePosition(TenCv);
}

void HoTroCapNhat(NodeChucVu* p, Statement* stmt) {
    string tenchucvu;
    long  luongchucvu;
    string mota;
    tenchucvu = p->getTenChucVu();
    luongchucvu = p->getLuongchucvu();
    mota = p->getMota();
    string UpdateTableAccount = "insert into ChucVu Values ('" + tenchucvu + "','" + to_string(luongchucvu) + "','" + mota + "');";
    stmt->execute(UpdateTableAccount);
}

void ChucVu::CreatePosition(NodeChucVu* p) {
    if (this->head == NULL) {
        this->head = this->tail = p;
    }
    else {
        p->setPoiter(this->head);
        this->head = p;
    }
    try {
        p = this->head;
        Statement* stmt;
        stmt = connection->createStatement();
        //kiem tra su ton tai cua bang
        string TenBang = "ChucVu";
        string KiemTra = "show tables like'" + TenBang + "'";
        ResultSet* result = stmt->executeQuery(KiemTra);
        if (result->next() == true) { //nếu có bảng thì result sẽ trả về true, không có thì ngược lại
            HoTroCapNhat(p, stmt);
            cout << "Du lieu da duoc cap nhat!" << endl;
        }
        else {
            string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
            string useDatabase = "Use QuanTriNhanSu";
            string CreateTableAccount = "CREATE TABLE IF NOT EXISTS ChucVu (""TenChucVu CHAR(100) not null PRIMARY KEY,"
                "LuongChucVu LONGTEXT not null, "
                "MoTaChucVu CHAR(100) not null)";
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
//void ChucVu::PrintPosition() {
//    Statement* stmt;
//    stmt = connection->createStatement();
//    string SelectData = "Select *from ChucVu";
//    ResultSet* res = stmt->executeQuery(SelectData);
//    cout << "Danh sach cac chuc vu: " << endl;
//    int count = 0;
//    cout << "STT" << "\t" << "Ten chuc vu " << "\t" << "\t" << "Luong co bang " << "\t" << "\t" << "Mo ta" << endl;
//    while (res->next()) {
//        cout << ++count << "\t" << res->getString("TenChucVu") << "\t" << "\t" << res->getString("LuongChucVu") << "\t" << "\t" << res->getString("MoTaChucVu") << endl;
//    }
//    delete stmt;
//    delete res;
//}

void ChucVu::PrintPosition(vector<NodeChucVu> Inchucvu) {

}

vector<NodeChucVu> ChucVu::TakeAllPosition(){
    vector<NodeChucVu>  Data;
    Statement* stmt;
    stmt = connection->createStatement();
    string SelectData = "Select *from ChucVu";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        long num = stol(res->getString("LuongCoBan"));
        NodeChucVu info(res->getString("TenChucVu"), num, res->getString("MoTaChucVu"));
        Data.push_back(info);
    }
    delete stmt;
    return Data;
}

void ChucVu::DeletePosition(string xoa) {
    Statement* stmt;
    stmt = connection->createStatement();
    string SelectData = "Delete from ChucVu where TenChucVu = '" + xoa + "'";
    stmt->executeUpdate(SelectData);
    delete stmt;
}

void ChucVu::EditPosition(string ChoCanSua,string MuonDoiThanh,string TenTk) {
    Statement* stmt;
    stmt = connection->createStatement();
    string SelectData2 = "UPDATE ChucVu SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE TenChucVu = '" + TenTk + "'";
    int rows_affected = stmt->executeUpdate(SelectData2);
    delete stmt;
}

//void ChucVu::SearchPosition(string ten,string ma) {
//    Statement* stmt;
//    stmt = connection->createStatement();
//    string SelectData = "Select *from ChucVu where " + ten + " = '" + ma + "'";
//    ResultSet* res = stmt->executeQuery(SelectData);
//    cout << endl;
//    while (true) {
//        if (res->next()) {
//            cout << "Chuc vu co ton tai trong he thong" << endl;
//            cout << "Ten chuc vu " << "\t" << "\t" << "Luong co bang " << "\t" << "\t" << "Mo ta" << endl;
//            cout << res->getString("TenChucVu") << "\t" << "\t" << res->getString("LuongChucVu") << " trieu dong" << "\t" << "\t" << res->getString("MoTaChucVu") << endl;
//        }
//        else {
//            cout << "Chuc vu khong co trong he thong." << endl;
//            break;
//        }
//    }
//    delete res;
//    delete stmt;
//}

vector<NodeChucVu> ChucVu::SearchPosition(string ten, string ma){
    vector<NodeChucVu>  SearchData;
    Statement* stmt;
    stmt = connection->createStatement();
    string SelectData = "Select *from ChucVu where " + ten + " = '" + ma + "'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        long num = stol(res->getString("LuongCoBan"));
        NodeChucVu info( res->getString("TenChucVu"), num, res->getString("MoTaChucVu"));
        SearchData.push_back(info);
    }
    delete stmt;
    return SearchData;
}

