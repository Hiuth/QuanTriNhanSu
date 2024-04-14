#include "PhongBan.h"
#include "KetNoi.h"

KetNoi * KtraData1 = new KetNoi();
Connection* connection1 = KtraData1->CheckDatabase();
PhongBan::PhongBan() {
	this->tail = NULL;
	this->head = NULL;
}

PhongBan::~PhongBan() {
	delete connection1;
	delete KtraData1;
}



PhongBan* PB = new PhongBan();
NodePhongBan* npb;
string maPB, TenPB,TenPB2;
int them;

bool checkDepartment(string ten, string ma) {//nó là hàm search như trả về true hoặc false
	Statement* stmt = connection1->createStatement();
	string SelectData = "SELECT * FROM PhongBan WHERE " + ten + " = '" + ma + "'";
	ResultSet* res = stmt->executeQuery(SelectData);

	while (res->next()) {
		return true;
	}return false;
	delete res;
	delete stmt;
}

void PhongBan::InputDepartment() {
	cout << "So luong phong ban muon nhap vao: "; cin >> them;
	cin.ignore();
	for (int i = 0; i < them; i++) {
		cout << "Nhap vao ma phong ban: "; getline(cin,maPB );
		cout << "Nhap vao ten phong ban: "; getline(cin, TenPB);
		npb = new NodePhongBan(TenPB, maPB);
		PB->CreateDepartment(npb);
	}
}

void PhongBan::InputEditDepartment() {
	cout << "Nhap vao ten phong ban can sua: "; getline(cin, TenPB);
	if (checkDepartment("TenPhong",TenPB)) {
		cout << "1. Sua ten phong ban." << endl;
		cout << "2. Sua ma phong ban." << endl;
		cout << "Moi ban chon che do sua."; cin >> them;
		if (them == 1) {
			cin.ignore();
			cout << "Nhap vao ten phong ban moi: "; getline(cin, TenPB2);
			PB->EditDepartment("TenPhong",TenPB2, TenPB);
		}
		else if (them == 2) {
			cout << "Nhap vao ma phong ban moi: "; getline(cin, maPB);
			PB->EditDepartment("MaPhong",maPB,TenPB);
		}
		else {
			cout << "Loi! moi ban chon lai!!!" << endl;
		}
	}
	else {
		cout << "Khong co ten phong ban nao nhu vay!!!" << endl;
	}
}

void PhongBan::InputSearchDepartment()
{
	cout << "Tim kiem phong ban!!!" << endl;
	cout << "1.Tim kiem theo ma phong ban." << endl;
	cout << "2.Tim kiem theo ten phong ban." << endl;
	cout << "Moi ban chon: "; cin >> them;
	cin.ignore();
	if (them == 1) {
		cout << "Nhap vao ma phong ban can tim: "; getline(cin, TenPB);
		PB->SearchDepartment("MaPhong", TenPB);
	}
	else if (them == 2) {
		cout << "Nhap vao ten phong ban can tim: "; getline(cin, TenPB);
		PB->SearchDepartment("TenPhong", TenPB);
	}
	else {
		cout << "moi ban chon lai!!!";
	}
}

void PhongBan::CreateDepartment(NodePhongBan* p) {
	if (this->head == NULL) {
		this->head = this->tail = p;
	}
	else {
		p->SetNext(this->head);
		this->head = p;
	}
	try {
		Statement* stmt = connection1->createStatement();

		string TenBang = "PhongBan";
		string KiemTra = "SHOW TABLES LIKE '" + TenBang + "'";
		ResultSet* result = stmt->executeQuery(KiemTra);
		if (result->next()) {
			string TenPhong = p->GetName();
			string MaPhong = p->GetID();
			string InsertTable = "insert into PhongBan values ('" + TenPhong + "', '" + MaPhong + "');";
			stmt->execute(InsertTable);
		}
		else {
			string TenPhong = p->GetName();
			string MaPhong = p->GetID();
			string CreateDatabaseSQL = "CREATE DATABASE IF NOT EXISTS QuanTriNhanSu;";
			string useDatabase = "Use QuanTriNhanSu";
			string CreateTableAccount = "create table if not exists  PhongBan (TenPhong char(100) not null, MaPhong char(10) primary key not null);";
			string InsertTable = "insert into PhongBan values ('" + TenPhong + "', '" + MaPhong + "');";
			stmt->executeUpdate(CreateTableAccount);
			stmt->execute(InsertTable);
			cout << "Bang da duoc tao phong ban da duoc them moi" << endl;
		}
		delete result;
		delete stmt;
	}
	catch (sql::SQLException& e) {
		cerr << "SQL Error: " << e.what() << endl;
	}
}
void PhongBan::PrintDepartmentInfotmation(vector<NodePhongBan> phongban) {
	for (size_t i = 0; i < phongban.size(); i++) {
		cout << phongban[i].GetName() << "\t" << phongban[i].GetID() << endl;
	}
}


vector<NodePhongBan> PhongBan::TakeAllDepartment() {
	vector<NodePhongBan> phongban;
	Statement* stmt = connection1->createStatement();
	string SelectData = "SELECT * FROM PhongBan";
	ResultSet* res = stmt->executeQuery(SelectData);
	while (res->next()) {
		NodePhongBan pb( res->getString("TenPhong"),res->getString("MaPhong"));
		phongban.push_back(pb);
	}
	delete res;
	delete stmt;
	return phongban;
}

vector<NodePhongBan> PhongBan::SearchDepartment(string ten, string ma) {
	vector<NodePhongBan> phongban;
	Statement* stmt = connection1->createStatement();
	string SelectData = "SELECT * FROM PhongBan WHERE " + ten + " = '" + ma + "'";
	ResultSet* res = stmt->executeQuery(SelectData);

	while (res->next()) {
		NodePhongBan pb(res->getString("TenPhong"), res->getString("MaPhong"));
		phongban.push_back(pb);
	}
		delete res;
		delete stmt;
		return phongban;
}

void PhongBan::EditDepartment(string ChoCanSua, string MuonDoiThanh, string TenPB) {
	Statement* stmt;
	stmt = connection1->createStatement();
	string SelectData2 = "UPDATE PhongBan SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE TenPhong = '" + TenPB + "'";
	int rows_affected = stmt->executeUpdate(SelectData2);
	delete stmt;
}