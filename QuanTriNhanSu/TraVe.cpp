#include "TraVe.h"
#include"KetNoi.h"
#include"vector"
#include"string"
#include"iostream"
using namespace std;

KetNoi* kt4 = new KetNoi();
Connection* tv = kt4->CheckDatabase();

TraVe::TraVe() {
    this->head = NULL;
    this->tail = NULL;
}

TraVe::~TraVe() {

}

int TraVe::ReturnColumn(string tenbang)
{
    Statement* stmt;
    stmt = tv->createStatement();
    int s1 = 0;
    string CountData = "SELECT COUNT(*) AS count FROM INFORMATION_SCHEMA.COLUMNS WHERE table_schema = 'quantrinhansu' AND table_name = '" + tenbang + "';";
    ResultSet* result1 = stmt->executeQuery(CountData);
    if (result1->next()) {
        int count = result1->getInt("count");
        s1 += count;
    }
    //cout << "\nS = " << s1 << endl;
    return s1;
    return 0;
}

int TraVe::ReturnLine(string tenbang)
{
    Statement* stmt;
    stmt = tv->createStatement();
    int s1 = 0;
    string CheckData = "SELECT COUNT(*) AS count FROM BaoHiem WHERE '"+ tenbang+ "' IS NOT NULL";
    ResultSet* result = stmt->executeQuery(CheckData);
    if (result->next()) {
        int count = result->getInt("count");
        s1 += count;
    }
    //cout << "\nS = " << s1 << endl;
    return s1;
}

vector<string> TraVe::ReturnName_of_Column(string tenbang)
{
    try {
        Statement* stmt;
        vector<string> cot;
        stmt = tv->createStatement();
        string CheckData = "SELECT column_name FROM information_schema.columns WHERE table_name = '" + tenbang + "'";
        ResultSet* result = stmt->executeQuery(CheckData);
        ResultSetMetaData* res = result->getMetaData();
        int columnCount = res->getColumnCount();
        while (result->next()) {
            for (int i = 1; i <= columnCount; i++) {
                string column_name = result->getString(i);
                cot.push_back(column_name);
            }
        }
        return cot;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}


