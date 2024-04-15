#include "NhanVien.h"
#include"KetNoi.h"
KetNoi* Check2 = new KetNoi();
Connection* con2 = Check2->CheckDatabase();

NhanVien::NhanVien() {
	this->tail = NULL;
	this->head = NULL;
}

int  chon;
string name,id, matkhau,chucvu,sdt, phongban, gioitinh, sinhnhat, cccd, diachi, manhanvien,thoihanhopdong;
NhanVien* Ktra = new NhanVien();
NodeNhanVien* p;

bool NhanVien::CheckNumber(string number) { // hàm kiểm tra xem chuỗi có phải số hay không
    for (char c : number) {
        if (!isdigit(c)) { //nếu có kí tự không phải là số thì nó sẽ trả về fasle
            return false;
        }
    }
    return true;
}

bool NhanVien::CheckSyntax(string syntax) {
    for (char c : syntax) {
        if (!isalpha(c)&& c!=' ') {
            return false;
        }
    }
    return true;
}

void NhanVien::InputEmployee() {
    cout << "so luong nhan vien muon nhap vao: "; cin >> chon;

    for (int i = 0; i < chon; i++) {
        bool KiemTra = false;
        while (!KiemTra) {
            cin.ignore();
            cout << "nhap vao ten nhan vien: "; getline(cin, name);
            cout << "nhap vao gioi tinh: "; cin >> gioitinh;
            cout << "nhap vao sinh nhat: "; cin >> sinhnhat;
            cout << "Nhap vao so dien thoai: "; cin >> sdt;
            cin.ignore();
            cout << "nhap vao can cuoc cong dan (cccd): "; getline(cin, cccd);
            cout << "nhap vao dia chi nha: ";  getline(cin, diachi);
            cout << "nhap vao phong ban: ";  getline(cin, phongban);
            cout << "nhap vao chuc vu: "; getline(cin, chucvu);
            cout << "Nhap vao ma nhan vien: "; getline(cin, manhanvien);
            cout << "Nhap vao thoi han hop dong: "; getline(cin, thoihanhopdong);
            if (!name.empty() && CheckSyntax(name) && !gioitinh.empty() && CheckSyntax(gioitinh) && !sinhnhat.empty() && !sdt.empty() && 
                CheckNumber(sdt) && !cccd.empty() && CheckNumber(cccd) && !diachi.empty() && !phongban.empty() && CheckSyntax(phongban) && 
                !chucvu.empty() && CheckSyntax(chucvu) && !manhanvien.empty() && !thoihanhopdong.empty() ){ // tên không được để trống
                KiemTra = true;
            }
            else {
                cout << "Ban da nhap sai!!! Vui long nhap lai";
            }
        }
        p = new NodeNhanVien(name, sinhnhat, gioitinh, sdt, cccd, diachi, chucvu, phongban, manhanvien, thoihanhopdong);
        Ktra->CreateName(p);
        cout << endl;
    }
}

void NhanVien::InputSearchEmployee() {
    cout << "1.Tim kiem theo ten nhan vien." << endl;
    cout << "2.Tim kiem theo gioi tinh ." << endl;
    cout << "3.Tim kiem theo sinh nhat." << endl;
    cout << "4.Tim kiem theo can cuoc cong dan." << endl;
    cout << "5.Tim kiem theo phong ban." << endl;
    cout << "6.Tim kiem theo chuc vu." << endl;
    cout << "7.Tim kiem theo ma nhan vien." << endl;
    cout << "8. Tim kiem theo so dien thoai. " << endl;
    cout << "9.Tim kiem theo thoi han hop dong." << endl;
    cout << "Ban muon chon theo gi ? "; cin >> chon;
    cin.ignore();
    if (chon == 1) {
        cout << "nhap vao ten tai khoan: "; getline(cin, name);
        Ktra->PrintEmployeeInfotmation(Ktra->SearchEmployee("TenNhanVien", name));
    }
    else if (chon == 2) {
        cout << "Nhap vao gioi tinh: "; cin >> gioitinh;
        Ktra->PrintEmployeeInfotmation(Ktra->SearchEmployee("GioiTinh", gioitinh));
    }
    else if (chon == 3) {
        cout << "Nhap vao sinh nhat: "; cin >> sinhnhat;
        Ktra->PrintEmployeeInfotmation(Ktra->SearchEmployee("SinhNhat", sinhnhat));
    }
    else if (chon == 4) {
        cout << "Nhap vao can cuoc cong dan: "; cin >> cccd;
        Ktra->PrintEmployeeInfotmation(Ktra->SearchEmployee("CCCD", cccd));
    }
    else if (chon == 5) {
        cout << "Nhao vao phong ban: "; getline(cin, phongban);
        Ktra->PrintEmployeeInfotmation(Ktra->SearchEmployee("PhongBan", phongban));
    }
    else if (chon == 6) {
        cout << "Nhap vao chuc vu: "; getline(cin, chucvu);
        Ktra->PrintEmployeeInfotmation(Ktra->SearchEmployee("ChucVu", chucvu));
    }
    else if (chon == 7) {
        cout << "Nhap vao ma nhan vien: "; getline(cin, manhanvien);
        Ktra->PrintEmployeeInfotmation(Ktra->SearchEmployee("MaNhanVien", manhanvien));
    }
    else if (chon == 8) {
        cout << "Nhap vao so dien thoai: "; cin >> sdt;
        Ktra->PrintEmployeeInfotmation(Ktra->SearchEmployee("SoDienThoai", sdt));
    }
    else if (chon == 9) {
        cout << "Nhap vao thoi han hop dong: "; getline(cin, thoihanhopdong);
        Ktra->PrintEmployeeInfotmation(Ktra->SearchEmployee("ThoiHanHopDong", thoihanhopdong));
    }
    else {
    	cout << "khong co so ma ban da chon. vui long nhap lai!" << endl;
    }
}

bool NhanVien::checkNameEmployee(string ten, string ma) {
    Statement* stmt;
    stmt = con2->createStatement();
    string SelectData = "Select *from NhanVien where " + ten + " = '" + ma + "'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        return true;
    }return false;
    delete res;
    delete stmt;
}

void NhanVien::InputEditEmployee() {
    cout << "Nhap vao nhan vien can chinh sua: "; getline(cin, name);
    if (Ktra->checkNameEmployee("TenNhanVien", name)) {
        cout << "Chon che do chinh sua! " << endl;
        cout << "1. Sua ten nhan vien." << endl;
        cout << "2. Sua gioi tinh." << endl;
        cout << "3. Sua sinh nhat." << endl;
        cout << "4. Sua can cuoc cong dan." << endl;
        cout << "5. Sua dia chi." << endl;
        cout << "6. Sua phong ban." << endl;
        cout << "7. Sua chuc vu." << endl;
        cout << "8. Sua ma nhan vien." << endl;
        cout << "9. Sua thoi han hop dong." << endl;
        cout << "Ban muon chon gi ? "; cin >> chon;
        cin.ignore();
        if (chon == 1) {
            cout << "Nhap vao ten muon doi: "; getline(cin, id);
            cout << name << " " << id;
            Ktra->EditInformation("TenNhanVien", id, name);//Thứ tự tên tài khoản, tên muốn đổi, vị trí cần đổi
        }
        else if (chon == 2) {
            cout << "Nhap vao gioi tinh moi: "; getline(cin, matkhau);
            Ktra->EditInformation("GioiTinh", matkhau, name);
        }
        else if (chon == 3) {
            cout << "Nhap vao sinh nhat moi: "; getline(cin, sinhnhat);
            Ktra->EditInformation("SinhNhat", sinhnhat, name);
        }
        else if (chon == 4) {
            cout << "Nhap vao can cuoc cong dan moi: "; getline(cin, cccd);
            Ktra->EditInformation("CCCD", cccd, name);
        }
        else if (chon == 5) {
            cout << "Nhap vao dia chi moi: "; getline(cin, diachi);
            Ktra->EditInformation("DiaChi", diachi, name);
        }
        else if (chon == 6) {
            cout << "Nhap vao phong ban moi: "; getline(cin, phongban);
            Ktra->EditInformation("PhongBan", phongban, name);
        }
        else if (chon == 7) {
            cout << "Nhap vao chuc vu moi: "; getline(cin, chucvu);
            Ktra->EditInformation("ChucVu", chucvu, name);
        }
        else if (chon == 8) {
            cout << "Nhap vao ma nhan vien moi: "; getline(cin, manhanvien);
            Ktra->EditInformation("MaNhanVien", manhanvien, name);
        }
        else if (chon == 9) {
            cout << "Nhao vao thoi han hop dong moi: "; getline(cin, thoihanhopdong);
            Ktra->EditInformation("ThoiHanHopDong", thoihanhopdong, name);
        }
        else {
            cout << "Khong co so ban vua chon. Vui long nhap lai!" << endl;
        }
    }
    else {
        cout << "Khong co ten nhan vien nay trong he thong." << endl;
    }
	
}


void NhanVien::InputDeleteEmployee() {
    cout << "Nhap vao ten nhan vien muon xoa: "; getline(cin, name);
  	Ktra->DeleteEmployee(name);
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
            string TenNhanVien;
            string SinhNhat;
            string CCCD;
            string DiaChi;
            string PhongBan;
            string GioiTinh;
            string ChucVu;
            string MaNhanVien;
            string SoDienThoai;
            string ThoiHanHopDong;
            TenNhanVien = p->GetName();
            SinhNhat = p->GetBirthday();
            CCCD = p->GetIDCard();
            DiaChi = p->GetAddress();
            PhongBan = p->GetDepartment();
            GioiTinh = p->GetSex();
            ChucVu = p->GetPost();
            MaNhanVien = p->GetEmployeeID();
            SoDienThoai = p->GetPhoneNumber();
            ThoiHanHopDong = p->GetContractTerm();
            string UpdateTableAccount = "insert into NhanVien Values ('" + TenNhanVien + "','" + GioiTinh + "','" + SinhNhat + "','" + MaNhanVien + "','" + SoDienThoai + "','" + CCCD + "', '" + DiaChi + "', '" + PhongBan + "', '" + ChucVu + "','" + ThoiHanHopDong + "'); ";
            stmt->execute(UpdateTableAccount);
            cout << "Du lieu da duoc cap nhat!" << endl;
        }
        else {
            cout << "Ban chua duoc tao." << endl;
        }
        delete result;
        delete stmt;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL Error: " << e.what() << std::endl;
    }
}



void NhanVien::PrintEmployeeInfotmation(vector<NodeNhanVien> print) {
    for (size_t i = 0; i < print.size(); i++) {
        cout << print[i].GetName()<<"\t" << print[i].GetSex() << "\t" << print[i].GetBirthday() << "\t" << print[i].GetPhoneNumber() << "\t" << print[i].GetEmployeeID() << "\t" << print[i].GetIDCard() << "\t" << print[i].GetDepartment() << "\t" << print[i].GetPost() << "\t" << print[i].GetContractTerm() << endl;
    }
}


vector<NodeNhanVien> NhanVien::TakeAllEmployee() {
        Statement* stmt;
        vector<NodeNhanVien> employees;
        stmt = con2->createStatement();
        string SelectData = "Select * from NhanVien";
        ResultSet* res = stmt->executeQuery(SelectData);
        while (res->next()) {
            NodeNhanVien Ktra(res->getString("TenNhanVien"), res->getString("SinhNhat"), res->getString("GioiTinh"), res->getString("SoDienThoai"), res->getString("CCCD"), res->getString("DiaChi"), res->getString("ChucVu"), res->getString("PhongBan"), res->getString("MaNhanVien")  , res->getString("ThoiHanHopDong") );
            employees.push_back(Ktra);
        }
    delete res;
    delete stmt;
    return employees;
}

vector<NodeNhanVien> NhanVien::SearchEmployee(string ten, string ma) {
    vector<NodeNhanVien> Search;
    Statement* stmt;
    stmt = con2->createStatement();
    string SelectData = "Select *from NhanVien where " + ten + " = '" + ma + "'";
    ResultSet* res = stmt->executeQuery(SelectData);
    while (res->next()) {
        NodeNhanVien Ktra(res->getString("TenNhanVien"), res->getString("SinhNhat"), res->getString("GioiTinh"), res->getString("SoDienThoai"), res->getString("CCCD"), res->getString("DiaChi"), res->getString("ChucVu"), res->getString("PhongBan"), res->getString("MaNhanVien"), res->getString("ThoiHanHopDong"));
        Search.push_back(Ktra);
    }
    delete res;
    delete stmt;
    return Search;
}



void NhanVien::DeleteEmployee(string xoa) {
    Statement* stmt;
    stmt = con2->createStatement();
    string SelectData = "Delete from NhanVien where TenNhanVien = '" + xoa + "'";
    int rows_affected = stmt->executeUpdate(SelectData);
    delete stmt;
}

void NhanVien::EditInformation(string ChoCanSua,string MuonDoiThanh,string TenTk) {
    Statement* stmt;
    stmt = con2->createStatement();
    string SelectData2 = "UPDATE NhanVien SET " + ChoCanSua + " = '" + MuonDoiThanh + "' WHERE TenNhanVien = '" + TenTk + "'";
    int rows_affected = stmt->executeUpdate(SelectData2);
    delete stmt;
}


NhanVien::~NhanVien() {
    delete con2;
    delete Check2;
}