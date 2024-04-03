#pragma once
#include<iostream>
#include<string>
using namespace std;
class NodeChucVu
{
private:
    string MoTa;
    long  Luongchucvu;
    string  TenChucVu; //ten chuc vu 
    NodeChucVu* poiter;
public:
    NodeChucVu* getPoiter() {
        return poiter;
    }
    void setPoiter(NodeChucVu* val) {
        poiter = val;
    }
    string getMota() {
        return MoTa;
    }



    virtual ~NodeChucVu();
    NodeChucVu(string machucvu, long int luongchucvu, string mota);


    void SetMaChucVu(string tenchucvu) {
        TenChucVu = tenchucvu;
    }

    void SetLuongChucVu(long int luongchucvu) {
        Luongchucvu = luongchucvu;
    }
    long getLuongchucvu() {
        return Luongchucvu;
    }
    void SetMoTa(string mota) {
        MoTa = mota;
    }
    string getTenChucVu() {
        return TenChucVu;
    }


};

