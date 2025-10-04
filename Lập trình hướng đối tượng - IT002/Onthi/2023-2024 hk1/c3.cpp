
#include <iostream>
#include <string>
#define  MAX  30
using namespace std;

class danhmuc {
protected:
    int sotietnghiencuu;
    public:
    danhmuc() {
        sotietnghiencuu = 0;
    }
    danhmuc(int sotiet) {
        sotietnghiencuu = sotiet;
    }
    virtual void nhap() {
        cin>>sotietnghiencuu;
    }
    virtual int getSotiet() {
        return sotietnghiencuu;
    }
    virtual void setSotiet(int sotiet) {
        sotietnghiencuu = sotiet;
    }
    virtual void kiemtraloai() const = 0;
    virtual ~danhmuc() {}
};
class danhmuctapchi :public danhmuc {
private:
    string Loai ; // ISI, Scopus, Non-Index
public:
    danhmuctapchi() {
        Loai = "";
    }
    danhmuctapchi(string L) {
        this->Loai = L;
        kiemtraloai();
    }
    void kiemtraloai() {
        if (Loai=="ISI") {
            sotietnghiencuu=5000;
        }else if (Loai=="Scopus") {
            sotietnghiencuu=2500;
        }else if (Loai=="Non-Index") {
            sotietnghiencuu=1000;
        }
    }

};
class danhmuchoinghi :public danhmuc {
private:
    bool core_ranking; //Core ranking, non Core ranking
    public:
    danhmuchoinghi() {
        core_ranking = false;
    }
    danhmuchoinghi(bool L) {
        core_ranking = L;
    }
    void kiemtraloai() {
        if (core_ranking==true) {
            sotietnghiencuu=1000;
        }else if (core_ranking==false) {
            sotietnghiencuu=500;
        }
    }
};
class baibaokhoahoc {
protected:
    int maBaiBao;
    string DOI;
    int namXuatban;
    string tacgiachinh;
    string dongtacgia[MAX];
    danhmuc* dm;
};

class detainghiencuu{
private:
    baibaokhoahoc *bb[MAX];
    int madetai;
    string tendetai;
    int ngaydangky;
    int thoigianthuchien;
    int ngaynghiemthu;
    int soluongbaibaothuocdanhmuctapchivahoinghi;
};
class tacgia {
private:
    int magiangvien;
    string tengiangvien;
    string chuyennganh;
    int sodienthoai;
    int sotietnghiencuu;
};