#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class cNhanVienVP {
private:
    int maNhanVien;
    string tenNhanVien;
    int tuoi;
    double luong;
public:

    cNhanVienVP() {
        maNhanVien = 0;
        tenNhanVien = "";
        tuoi = 0;
        luong = 0.0;
    }

    cNhanVienVP(int ma, string ten, int tuoinv, double luongnv) {
        maNhanVien = ma;
        tenNhanVien = ten;
        tuoi = tuoinv;
        luong = luongnv;
    }

    int getMaNhanVien() const {
        return maNhanVien;
    }
    string getTenNhanVien() const {
        return tenNhanVien;
    }
    int getTuoi() const {
        return tuoi;
    }
    double getLuong() const {
        return luong;
    }

    void setMaNhanVien(int ma) {
        maNhanVien = ma;
    }
    void setTenNhanVien(string ten) {
        tenNhanVien = ten;
    }
    void setTuoi(int t) {
        tuoi = t;
    }
    void setLuong(double l) {
        luong = l;
    }

    friend istream& operator>>(istream& is, cNhanVienVP& nv) {
        cout << "Nhap ma nhan vien: ";
        is >> nv.maNhanVien;
        is.ignore();
        cout << "Nhap ten nhan vien: ";
        getline(is, nv.tenNhanVien);
        cout << "Nhap tuoi: ";
        is >> nv.tuoi;
        cout << "Nhap luong: ";
        is >> nv.luong;
        return is;
    }

    friend ostream& operator<<(ostream& os, const cNhanVienVP& nv) {
        os << "Ma nhan vien: " << nv.maNhanVien << endl
            << "Ten nhan vien: " << nv.tenNhanVien << endl
            << "Tuoi: " << nv.tuoi << endl
            << "Luong: " << nv.luong << endl;
        return os;
    }
};

class DSNhanVien {
private:
    vector<cNhanVienVP> ds;
public:
    void themNhanVien(const cNhanVienVP& nv) {
        ds.push_back(nv);
    }

    friend istream& operator>>(istream& is, DSNhanVien& dsnv) {
        int n;
        cout << "Nhap so luong nhan vien: ";
        is >> n;

        for (int i = 0; i < n; i++) {
            cout << "\nNhap thong tin nhan vien thu " << (i + 1) << "\n";
            cNhanVienVP nv;
            is >> nv;
            dsnv.ds.push_back(nv);
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const DSNhanVien& dsnv) {
        if (dsnv.ds.empty()) {
            os << "Danh sach trong!\n";
            return os;
        }
        for (int i = 0; i < dsnv.ds.size(); i++) {
            os << "\nNhan vien thu " << (i + 1) << ":\n";
            os << dsnv.ds[i] << endl;
        }
        return os;
    }

    double tongLuong() const {
        double tong = 0;
        for (const auto& nv : ds) {
            tong += nv.getLuong();
        }
        return tong;
    }

    void sapxep() {
        sort(ds.begin(), ds.end(), [](const cNhanVienVP& a, const cNhanVienVP& b) {
            return a.getLuong() < b.getLuong();
            });
    }

    void highestTuoi() const {
        if (ds.empty()) {
            cout << "Danh sach trong!\n";
            return;
        }

        auto maxTuoi = max_element(ds.begin(), ds.end(),
            [](const cNhanVienVP& a, const cNhanVienVP& b) {
                return a.getTuoi() < b.getTuoi();
            });

        cout << *maxTuoi << endl;
    }

    void highestLuong() const {
        if (ds.empty()) {
            cout << "Danh sach trong!\n";
            return;
        }

        auto maxLuong = max_element(ds.begin(), ds.end(),
            [](const cNhanVienVP& a, const cNhanVienVP& b) {
                return a.getLuong() < b.getLuong();
            });


        cout << *maxLuong << endl;
    }
};

int main() {
    DSNhanVien ds;
    cin >> ds;
    cout << ds;
    cout << "Luong cao nhat:\n";
    ds.highestLuong();
    cout << "Tuoi cao nhat:\n";
    ds.highestTuoi();
    cout << "Tong luong:\n";
    cout<<ds.tongLuong();
    cout << "Sap xep tang dan theo luong:\n";
    ds.sapxep();
    cout << ds;
    return 0;
}