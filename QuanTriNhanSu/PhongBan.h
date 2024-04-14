#include "KetNoi.h"
#include "NodePhongBan.h"
#include<vector>

class PhongBan {
private:
    NodePhongBan* head;
    NodePhongBan* tail; // Thêm thành viên connection vào lớp PhongBan
public:
    PhongBan(); // Constructor
    virtual ~PhongBan(); // Destructor
    bool checkDepartment(string,string);
    void InputDepartment();
    void InputEditDepartment();
    void InputSearchDepartment();
    void InputDeleteDepartment();
    void CreateDepartment(NodePhongBan* p); // Tạo mới phòng ban
    void PrintDepartmentInfotmation(vector<NodePhongBan>); // In thông tin phòng ban
    vector<NodePhongBan> SearchDepartment(string ten, string ma); // Tìm kiếm phòng ban
    vector<NodePhongBan> TakeAllDepartment();
    void DeleteDepartment(string xoa); // Xóa phòng ban
    void EditDepartment(string ChoCanSua, string MuonDoiThanh, string TenPB); // Sửa thông tin phòng ban
};

