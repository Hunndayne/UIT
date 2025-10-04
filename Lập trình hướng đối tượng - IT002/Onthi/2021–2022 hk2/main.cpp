#include <iostream>
#include <string>
#include <limits>
using namespace std;

class sach {
protected:
    int masach;
    string tensach;
    string nhaxuatban;
    int soluong;
    double dongia;
    double thanhtien;

public:
    sach() {
        masach = 0;
        tensach = "";
        nhaxuatban = "";
        soluong = 0;
        dongia = 0.0;
        thanhtien = 0.0;
    }

    virtual ~sach() {}

    double getThanhtien() const {
        return thanhtien;
    }

    string getnhaxuatban() const {
        return nhaxuatban;
    }

    virtual bool laSachGiaoKhoa() const {
        return false;
    }

    virtual void nhap() {
        cout << "Ma sach: ";
        cin >> masach;
        cin.ignore();

        cout << "Ten sach: ";
        getline(cin, tensach);

        cout << "Nha xuat ban: ";
        getline(cin, nhaxuatban);

        cout << "So luong: ";
        cin >> soluong;

        cout << "Don gia: ";
        cin >> dongia;
    }

    virtual void xuat() const {
        cout << "Ma sach: " << masach << '\n';
        cout << "Ten sach: " << tensach << '\n';
        cout << "NXB: " << nhaxuatban << '\n';
        cout << "So luong: " << soluong << '\n';
        cout << "Don gia: " << dongia << '\n';
        cout << "Thanh tien: " << thanhtien << '\n';
    }

    virtual void tinhThanhTien() = 0;
};

class sachGiaoKhoa : public sach {
private:
    bool tinhtrang; // 0: cu, 1: moi

public:
    sachGiaoKhoa() : sach(), tinhtrang(false) {}

    bool laSachGiaoKhoa() const override {
        return true;
    }

    void nhap() override {
        cout << "\n=== Nhap SACH GIAO KHOA ===\n";
        sach::nhap();
        cout << "Tinh trang sach (0: cu - 1: moi): ";
        int tt;
        cin >> tt;
        tinhtrang = (tt != 0);
        tinhThanhTien();
    }

    void tinhThanhTien() override {
        if (tinhtrang) {
            thanhtien = soluong * dongia;
        } else {
            thanhtien = soluong * dongia * 0.5;
        }
    }

    void xuat() const override {
        cout << "\n[Sach giao khoa]\n";
        sach::xuat();
        cout << "Tinh trang: " << (tinhtrang ? "Moi" : "Cu") << '\n';
    }
};

class sachThamKhao : public sach {
private:
    double thue;

public:
    sachThamKhao() : sach(), thue(0.0) {}

    bool laSachGiaoKhoa() const override {
        return false;
    }

    void nhap() override {
        cout << "\n=== Nhap SACH THAM KHAO ===\n";
        sach::nhap();
        cout << "Tien thue: ";
        cin >> thue;
        tinhThanhTien();
    }

    void tinhThanhTien() override {
        thanhtien = soluong * dongia + thue;
    }

    void xuat() const override {
        cout << "\n[Sach tham khao]\n";
        sach::xuat();
        cout << "Thue: " << thue << '\n';
    }
};

class thuVien {
private:
    sach *arr[200];
    int sl;

public:
    thuVien() : sl(0) {}

    ~thuVien() {
        for (int i = 0; i < sl; i++) {
            delete arr[i];
        }
    }

    void nhap() {
        int n;
        cout << "Nhap so luong sach: ";
        cin >> n;
        if (n < 0) n = 0;
        if (n > 200) n = 200;

        for (int i = 0; i < n; i++) {
            int luachon;
            cout << "\nNhap lua chon (1 - sach giao khoa, 2 - sach tham khao): ";
            cin >> luachon;

            sach *p = nullptr;
            if (luachon == 1) {
                p = new sachGiaoKhoa();
            } else {
                p = new sachThamKhao();
            }
            p->nhap();
            arr[sl++] = p;
        }
    }

    void xuatDanhSach() const {
        if (sl == 0) {
            cout << "Danh sach rong.\n";
            return;
        }
        cout << "\n=== DANH SACH SACH ===\n";
        for (int i = 0; i < sl; i++) {
            arr[i]->xuat();
        }
    }

    void tongTienVaMin() const {
        if (sl == 0) {
            cout << "Danh sach rong.\n";
            return;
        }

        double tongSGK = 0.0;
        double tongSTK = 0.0;
        for (int i = 0; i < sl; i++) {
            if (arr[i]->laSachGiaoKhoa()) {
                tongSGK += arr[i]->getThanhtien();
            } else {
                tongSTK += arr[i]->getThanhtien();
            }
        }

        cout << "\n=== TONG THANH TIEN ===\n";
        cout << "Tong tien sach giao khoa: " << tongSGK << '\n';
        cout << "Tong tien sach tham khao: " << tongSTK << '\n';

        // tìm giá trị nhỏ nhất
        double minVal = arr[0]->getThanhtien();
        for (int i = 1; i < sl; i++) {
            if (arr[i]->getThanhtien() < minVal) {
                minVal = arr[i]->getThanhtien();
            }
        }

        cout << "\n=== CAC SACH CO THANH TIEN NHO NHAT (" << minVal << ") ===\n";
        for (int i = 0; i < sl; i++) {
            if (arr[i]->getThanhtien() == minVal) {
                arr[i]->xuat();
            }
        }
    }

    void timThongTin() const {
        if (sl == 0) {
            cout << "Danh sach rong.\n";
            return;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nhap nha xuat ban (tim SGK): ";
        string nxb;
        getline(cin, nxb);

        bool found = false;
        cout << "\n=== KET QUA TIM SGK THEO NXB: " << nxb << " ===\n";
        for (int i = 0; i < sl; i++) {
            if (arr[i]->laSachGiaoKhoa() && arr[i]->getnhaxuatban() == nxb) {
                arr[i]->xuat();
                found = true;
            }
        }
        if (!found) {
            cout << "Khong tim thay SGK thuoc NXB \"" << nxb << "\".\n";
        }
    }

    void menu() {
        int luachon;
        cout << "\nNhap lua chon: "
             << "(1: xuat danh sach - 2: tong tien tung loai + sach min - 3: tim SGK theo NXB): ";
        cin >> luachon;
        if (luachon == 1) {
            xuatDanhSach();
        } else if (luachon == 2) {
            tongTienVaMin();
        } else if (luachon == 3) {
            timThongTin();
        } else {
            cout << "Lua chon khong hop le.\n";
        }
    }
};

int main() {
    thuVien x;
    x.nhap();
    x.menu();
    return 0;
}
