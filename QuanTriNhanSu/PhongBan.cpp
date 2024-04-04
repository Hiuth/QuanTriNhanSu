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
void PhongBan::PrintDepartmentInfotmation() {
	try {
		Statement* stmt = connection1->createStatement();
		string SelectData = "SELECT * FROM PhongBan";
		ResultSet* res = stmt->executeQuery(SelectData);
		cout << "Danh sach cac phong ban" << endl;
		cout << "STT\tTen phong ban\t\t\tMa phong" << endl;
		int count = 0;
		while (res->next()) {
			cout << ++count << "\t" << res->getString("TenPhong") << "\t\t" << res->getString("MaPhong") << endl;
		}

		delete res;
		delete stmt;
	}
	catch (sql::SQLException& e) {
		cerr << "SQL Error: " << e.what() << endl;
	}
}
void PhongBan::SearchDepartment(string ten, string ma) {
	try {
		Statement* stmt = connection1->createStatement();
		string SelectData = "SELECT * FROM PhongBan WHERE " + ten + " = '" + ma + "'";
		ResultSet* res = stmt->executeQuery(SelectData);

		if (res->next()) {
			cout << "Phòng ban ton tai trong he thong!" << endl;
			cout << "Ten phong ban\t\t\tMa phong" << endl;
			cout << res->getString("TenPhong") << "\t\t" << res->getString("MaPhong") << endl;
		}
		else {
			cout << "Kh!" << endl;
		}

		delete res;
		delete stmt;
	}
	catch (sql::SQLException& e) {
		cerr << "SQL Error: " << e.what() << endl;
	}
}

void PhongBan::EditDepartment(string ChoCanSua, string MuonDoiThanh, string TenPB) {
	Statement* stmt;
	stmt = connection1->createStatement();
	string SelectData2 = "UPDATE PhongBan SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE TenPhongBan = '" + TenPB + "'";
	int rows_affected = stmt->executeUpdate(SelectData2);
	delete stmt;
}