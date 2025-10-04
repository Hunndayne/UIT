#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class cNhanVienSX {
private:
    int maNV;
    string HoTen;
    int ngaySinh, thangSinh, namSinh;
    int Tuoi;
    int soSanPham;
    int DonGia;
    int Luong;

public:

    cNhanVienSX() {
        maNV = 0;
        HoTen = "";
        ngaySinh = 0;
        thangSinh = 0;
        namSinh = 0;
        Tuoi = 0;
        soSanPham = 0;
        DonGia = 0;
        Luong = 0;
    }

    cNhanVienSX(int ma, string hoten, int ns, int ts, int nams, int sp, int dg) {
        maNV = ma;
        HoTen = hoten;
        ngaySinh = ns;
        thangSinh = ts;
        namSinh = nams;
        soSanPham = sp;
        DonGia = dg;
        tinhTuoi();
        tongLuong();
    }

    int getmaNV() {
        
        return maNV;
    }
    string getHoTen() {
        return HoTen;
    }
    int getNgaySinh() {
        return ngaySinh; 
    }
    int getThangSinh() {
        return thangSinh; 
    }
    int getNamSinh() {
        return namSinh; 
    }
    int getTuoi() {
        
        return Tuoi;
    }
    int getSoSanPham() {
        return soSanPham;
    }
    int getDonGia() {
        return DonGia; 
    }
    int getLuong() {
        return Luong; 
    }

    void setmaNV(int n) {
        maNV = n; 
    }
    void setHoTen(string H) {
        HoTen = H;
    }
    void setNgaySinh(int NS) {
        ngaySinh = NS; 
    }
    void setThangSinh(int TS) {
        thangSinh = TS;
    }
    void setNamSinh(int NamS) {
        namSinh = NamS; 
        tinhTuoi(); 
    }
    void setSoSanPham(int sp) {
        soSanPham = sp;
        tongLuong();
    }
    void setDonGia(int dg) {
        DonGia = dg;
        tongLuong();
    }

    void tongLuong() {
        Luong = soSanPham * DonGia;
    }

    void tinhTuoi() {
        int namHienTai = 2025;
        Tuoi = namHienTai - namSinh;
    }

    friend istream& operator>>(istream& is, cNhanVienSX& nv) {
        cout << "Nhap ma nhan vien: ";
        is >> nv.maNV;
        cin.ignore();
        cout << "Nhap Ho va Ten: ";
        getline(is, nv.HoTen);
        cout << "Nhap ngay sinh: ";
        is >> nv.ngaySinh;
        cout << "Nhap thang sinh: ";
        is >> nv.thangSinh;
        cout << "Nhap nam sinh: ";
        is >> nv.namSinh;
        cout << "So san pham: ";
        is >> nv.soSanPham;
        cout << "Don gia san pham: ";
        is >> nv.DonGia;

        nv.tinhTuoi();
        nv.tongLuong();
        return is;
    }

    friend ostream& operator<<(ostream& os, const cNhanVienSX& nv) {
        os << "Ma nhan vien: " << nv.maNV
            << "\nHo va ten: " << nv.HoTen
            << "\nNgay sinh: " << nv.ngaySinh << "/" << nv.thangSinh << "/" << nv.namSinh
            << "\nTuoi: " << nv.Tuoi
            << "\nSo san pham: " << nv.soSanPham
            << "\nDon gia san pham: " << nv.DonGia
            << "\nLuong nhan vien: " << nv.Luong;
        return os;
    }
};

class DScNhanVienSX {
private:
    vector<cNhanVienSX> ds;

public:
    void themNhanVien(const cNhanVienSX& nv) {
        ds.push_back(nv);
    }

    friend istream& operator>>(istream& is, DScNhanVienSX& dsnv) {
        int n;
        cout << "Nhap so luong nhan vien: ";
        is >> n;

        for (int i = 0; i < n; i++) {
            cout << "\nNhap thong tin nhan vien thu " << (i + 1) << "\n";
            cNhanVienSX nv;
            is >> nv;
            dsnv.ds.push_back(nv);
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const DScNhanVienSX& dsnv) {
        if (dsnv.ds.empty()) {
            os << "Danh sach trong\n";
            return os;
        }

        for (int i = 0; i < dsnv.ds.size(); i++) {
            os << "\nNhan vien thu " << (i + 1) << "\n";
            os << dsnv.ds[i] << "\n";
        }
        return os;
    }

    void lowestLuong() {
        if (ds.empty()) {
            cout << "Danh sach trong\n";
            return;
        }

        int minLuong = ds[0].getLuong();
        int viTri = 0;

        for (int i = 1; i < ds.size(); i++) {
            if (ds[i].getLuong() < minLuong) {
                minLuong = ds[i].getLuong();
                viTri = i;
            }
        }

        cout << "\nnhan vien co luong thap nhat:\n";
        cout << ds[viTri] << "\n";
    }

    double tongLuong() {
        if (ds.empty()) {
            cout << "Danh sach trong\n";
            return 0;
        }

        double tong = 0;
        for (int i = 0; i < ds.size(); i++) {
            tong += ds[i].getLuong();
        }

        cout << "\nTong luong cong ty phai tra: " << tong << " VND\n";
        return tong;
    }

    void highestTuoi() {
        if (ds.empty()) {
            cout << "Danh sach trong!\n";
            return;
        }

        int maxTuoi = ds[0].getTuoi();
        int viTri = 0;

        for (int i = 1; i < ds.size(); i++) {
            if (ds[i].getTuoi() > maxTuoi) {
                maxTuoi = ds[i].getTuoi();
                viTri = i;
            }
        }

        cout << "\nNHAN VIEN CO TUOI CAO NHA\n";
        cout << ds[viTri] << "\n";
    }

    void sapxepLuong() {
        if (ds.empty()) {
            cout << "Danh sach trong!\n";
            return;
        }

        for (int i = 0; i < ds.size() - 1; i++) {
            for (int j = 0; j < ds.size() - i - 1; j++) {
                if (ds[j].getLuong() > ds[j + 1].getLuong()) {
                    cNhanVienSX temp = ds[j];
                    ds[j] = ds[j + 1];
                    ds[j + 1] = temp;
                }
            }
        }
    }

    bool isEmpty() {
        return ds.empty();
    }
};



int main() {
    DScNhanVienSX danhSach;
    cout << "Nhap danh sach: \n";
    cin >> danhSach;
    cout << "\n Danh sach:" << danhSach;
     danhSach.lowestLuong();
    cout << "\nTong luong phai tra: "<< danhSach.tongLuong();
    danhSach.highestTuoi();
    danhSach.sapxepLuong();
    cout << "\nDanh sach sau khi sap xep: " << danhSach;
    return 0;
}