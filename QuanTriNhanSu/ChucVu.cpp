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

bool ChucVu::checkSyntax(string syntax)
{
    for (char c : syntax) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

bool ChucVu::checkNamePosition(string ten, string ma)
{
    Statement* stmt;
    stmt = connection->createStatement();
    string SelectData = "Select *from ChucVu where " + ten + " = '" + ma + "'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        return true;
    }return false;
    delete res;
    delete stmt;
 
}



void ChucVu::InputEditPosiotion()
{
    cout << "Nhap vao ten chuc vu can sua: "; getline(cin, TenCv);
    if (checkNamePosition("TenChucVu", TenCv)) {
        cout << "1. Sua ten chuc vu." << endl;
        cout << "2. Sua luong chuc vu." << endl;
        cout << "3.Sua mo ta chuc vu." << endl;
        cout << "Chon chuc nang ban can sua "; cin >> choose;
        if (choose ==1) {
            cin.ignore();
            cout << "Nhap vao ten chuc vu moi: "; getline(cin, mota);
            kt->EditPosition("TenChucVu", mota, TenCv);
        }
        else if (choose ==2 ) {
            cin.ignore();
            cout << "Nhap vao muc luong moi: "; cin >> luong;
            kt->EditPosition("LuongChucVu", to_string(luong), TenCv);
        }
        else if (choose == 3) {
            cin.ignore();
            cout << "Nhap vao mo ta moi: "; getline(cin, mota);
            kt->EditPosition("MoTaChucVu",mota, TenCv);
        }
    }
}

void ChucVu::InputSearchPosition()
{
    cout << "1.Tim theo ten chuc vu." << endl;
    cout << "2.Tim theo muc luong." << endl;
    cout << "Ban chon che do nao? "; cin >> choose;
    if (choose == 1) {
        cout << "Nhap vao ten chuc vu can tim: "; getline(cin, TenCv);
       kt->PrintPosition(kt->SearchPosition("TenChucVu", TenCv));
    }
    else if (choose == 2) {
        cout << "Nhap vao muc luong can tim: "; cin >> luong;
        kt->PrintPosition(kt->SearchPosition("LuongChucVu", to_string(luong)));
    }
    else {
        cout << "Moi ban chon lai!" << endl;
    }
   
    
}


void ChucVu::InputDetletePosition() {
    cout << "Nhap vao chuc vu can xoa: "; getline(cin, TenCv);
    kt->DeletePosition(TenCv);
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
            string tenchucvu;
            long  luongchucvu;
            string mota;
            tenchucvu = p->getTenChucVu();
            luongchucvu = p->getLuongchucvu();
            mota = p->getMota();
            string UpdateTableAccount = "insert into ChucVu Values ('" + tenchucvu + "','" + to_string(luongchucvu) + "','" + mota + "');";
            stmt->execute(UpdateTableAccount);
            cout << "Du lieu da duoc cap nhat!" << endl;
        }
        else {
            cout << "Bang khong ton tai. Vui long kiem tra lai!!!"<<endl;
        }
        delete result;
        delete stmt;
        delete p;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }


}


void ChucVu::PrintPosition(vector<NodeChucVu> Inchucvu) {
    for (size_t i = 0; i < Inchucvu.size(); i++) {
        cout << Inchucvu[i].getTenChucVu() << "\t" << Inchucvu[i].getLuongchucvu() << "\t" << Inchucvu[i].getMota() << endl;
    }
}

vector<NodeChucVu> ChucVu::TakeAllPosition(){
    vector<NodeChucVu>  Data;
    Statement* stmt;
    stmt = connection->createStatement();
    string SelectData = "Select *from ChucVu";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        string number = res->getString("LuongChucVu");
        long num = stoi(number);
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


vector<NodeChucVu> ChucVu::SearchPosition(string ten, string ma){
    vector<NodeChucVu>  SearchData;
    Statement* stmt;
    stmt = connection->createStatement();
    string SelectData = "Select *from ChucVu where " + ten + " = '" + ma + "'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        string number = res->getString("LuongChucVu");
        long num = stoi(number);
        NodeChucVu info( res->getString("TenChucVu"), num, res->getString("MoTaChucVu"));
        SearchData.push_back(info);
    }
    delete stmt;
    return SearchData;
}

