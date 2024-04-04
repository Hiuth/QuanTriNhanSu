#include "KetNoi.h"
#include "NodePhongBan.h"


class PhongBan {
private:
    NodePhongBan* head;
    NodePhongBan* tail; // Thêm thành viên connection vào lớp PhongBan
public:
    PhongBan(); // Constructor
    virtual ~PhongBan(); // Destructor
    void CreateDepartment(NodePhongBan* p); // Tạo mới phòng ban
    void PrintDepartmentInfotmation(); // In thông tin phòng ban
    void SearchDepartment(string ten, string ma); // Tìm kiếm phòng ban
    void DeleteDepartment(string xoa); // Xóa phòng ban
    void EditDepartment(string ChoCanSua, string MuonDoiThanh, string TenPB); // Sửa thông tin phòng ban
};

