#include <iostream>
#include <string>

using namespace std;

class HoangTu {
public:
    int soTien;
    int triTue;
    int sucManh;

    HoangTu(int tien = 0, int tri = 0, int suc = 0) {
        soTien = tien;
        triTue = tri;
        sucManh = suc;
    }

    void nhapThongTin() {
        cout << "Nhap so tien cua Hoang Tu: ";
        cin >> soTien;
        cout << "Nhap chi so tri tue cua Hoang Tu: ";
        cin >> triTue;
        cout << "Nhap chi so suc manh cua Hoang Tu: ";
        cin >> sucManh;
    }

    void hienThiThongTin() const {
        cout << "Hoang Tu hien co: Tien = " << soTien
             << ", Tri Tue = " << triTue
             << ", Suc Manh = " << sucManh << endl;
    }
};

class cong {
public:
    virtual ~cong() {}
    virtual void nhap() = 0;
    virtual bool quaCong(HoangTu &hoangTu) = 0;
    virtual void hienThiThongTinCong() const = 0;
};

class congGiaoThuong : public cong {
private:
    int donGia;
    int soHang;
    int tongChiPhi;

public:
    congGiaoThuong(int dg = 0, int sh = 0) {
        donGia = dg;
        soHang = sh;
        tongChiPhi = 0;
    }

    void nhap() {
        cout << "   Nhap don gia cua cong Giao Thuong: ";
        cin >> donGia;
        cout << "   Nhap so luong hang can mua: ";
        cin >> soHang;
        tongChiPhi = donGia * soHang;
    }

    bool quaCong(HoangTu &hoangTu) {
        if (hoangTu.soTien >= tongChiPhi) {
            hoangTu.soTien -= tongChiPhi;
            cout << "    Hoang Tu da qua cong Giao Thuong thanh cong!" << endl;
            return true;
        } else {
            cout << "    Hoang Tu KHONG du tien de qua cong Giao Thuong (can " << tongChiPhi << ")." << endl;
            return false;
        }
    }

    void hienThiThongTinCong() const {
        cout << "Cong Giao Thuong (Can " << tongChiPhi << " tien)";
    }
};

class congHocThuat : public cong {
private:
    int triTueYeuCau;
public:
    congHocThuat(int ttyc = 0) {
        triTueYeuCau = ttyc;
    }
    void nhap() {
        cout << "   Nhap chi so tri tue can thiet cho cong Hoc Thuat: ";
        cin >> triTueYeuCau;
    }
    bool quaCong(HoangTu &hoangTu) {
        if (hoangTu.triTue >= triTueYeuCau) {
            hoangTu.triTue -= triTueYeuCau;
            cout << "    Hoang Tu da qua cong Hoc Thuat thanh cong!" << endl;
            return true;
        } else {
            cout << "    Hoang Tu khong du tri tue de qua cong Hoc Thuat (can " << triTueYeuCau << ")." << endl;
            return false;
        }
    }
    void hienThiThongTinCong() const {
        cout << "Cong Hoc Thuat (Can " << triTueYeuCau << " tri tue)";
    }
};
class congSucManh : public cong {
private:
    int sucManhDungSy;
public:
    congSucManh(int smds = 0) {
        sucManhDungSy = smds;
    }
    void nhap() {
        cout << "   Nhap chi so suc manh cua Dung Sy (cong Suc Manh): ";
        cin >> sucManhDungSy;
    }
    bool quaCong(HoangTu &hoangTu) {
        if (hoangTu.sucManh >= sucManhDungSy) {
            hoangTu.sucManh -= sucManhDungSy;
            cout << "    Hoang Tu da qua cong Suc Manh thanh cong!" << endl;
            return true;
        } else {
            cout << "    Hoang Tu KHONG du suc manh de qua cong Suc Manh (can " << sucManhDungSy << ")." << endl;
            return false;
        }
    }
    void hienThiThongTinCong() const {
        cout << "Cong Suc Manh (Can " << sucManhDungSy << " suc manh)";
    }
};
int main() {
    HoangTu hoangTu;
    hoangTu.nhapThongTin();
    hoangTu.hienThiThongTin();
    int n;
    cin >> n;
    cong** danhSachCong = new cong*[n];
    int soLuongCongThucTe = 0;

    for (int i = 0; i < n; ++i) {
        int loaiCong;
        cout << "\nCong thu " << i + 1 << ":" << endl;
        cout << "   Chon loai cong (1: Giao Thuong, 2: Hoc Thuat, 3: Suc Manh): ";
        cin >> loaiCong;
        cong* currentCong = nullptr;
        switch (loaiCong) {
            case 1:
                currentCong = new congGiaoThuong();
                break;
            case 2:
                currentCong = new congHocThuat();
                break;
            case 3:
                currentCong = new congSucManh();
                break;
            default:
                cout << "   Loai cong khong hop le! Vui long nhap lai.\n";
                i--;
                continue;
        }
        currentCong->nhap();
        danhSachCong[soLuongCongThucTe] = currentCong;
        soLuongCongThucTe++;
    }
    bool daCuuDuocCongChua = true;
    for (int i = 0; i < soLuongCongThucTe; ++i) {
        cout << "\nVuot qua cong thu " << i + 1 << ": ";
        danhSachCong[i]->hienThiThongTinCong();
        cout << endl;

        if (!danhSachCong[i]->quaCong(hoangTu)) {
            daCuuDuocCongChua = false;
            cout << "Hoang Tu khong the cuu Cong Chua vi khong vuot qua duoc cong nay." << endl;
            break;
        }
        hoangTu.hienThiThongTin();
    }

    if (daCuuDuocCongChua) {
        cout << "Hoang Tu da vuot qua tat ca cac cong va cuu duoc Cong Chua" << endl;
        cout << "Chi so cuoi cung cua Hoang Tu: ";
        hoangTu.hienThiThongTin();
    } else {
        cout << "Hoang Tu khong the cuu Cong Chua." << endl;
    }
    for (int i = 0; i < soLuongCongThucTe; ++i) {
        delete danhSachCong[i];
    }
    delete[] danhSachCong;
    return 0;
}