#include <iostream>
#include <string>
#include <limits>
#include <map>

using namespace std;

#define MAX_ITEMS 100 // Kích thước tối đa cho mảng sản phẩm và hóa đơn

// Lớp cha cho tất cả sản phẩm
class sanpham {
protected:
    int maso;
    string tieude;
    double gia;

public:
    sanpham() : maso(0), gia(0.0) {}
    virtual ~sanpham() {}

    double getGia() {
        return gia;
    }

    virtual void nhap() {
        cout << "  - Nhap ma so: ";
        cin >> maso;
        cout << "  - Nhap tieu de: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, tieude);
        cout << "  - Nhap gia ban: ";
        cin >> gia;
    }

    virtual void xuat() {
        cout << "Ma so: " << maso << ", Tieu de: " << tieude << ", Gia: " << gia;
    }
};

// Lớp Tranh kế thừa từ sanpham
class Tranh : public sanpham {
private:
    int rong;
    int cao;
    string artist;

public:
    void nhap() override {
        cout << "--- Nhap Thong Tin Tranh Anh ---" << endl;
        sanpham::nhap();
        cout << "  - Nhap chieu rong (cm): ";
        cin >> rong;
        cout << "  - Nhap chieu cao (cm): ";
        cin >> cao;
        cout << "  - Nhap ten hoa si: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, artist);
    }

    void xuat() override {
        cout << "Loai: Tranh, ";
        sanpham::xuat();
        cout << ", Kich thuoc: " << rong << "x" << cao << " cm, Hoa si: " << artist << endl;
    }
};

// Lớp CD kế thừa từ sanpham
class CD : public sanpham {
private:
    string singer;
    string publisher;

public:
    void nhap() override {
        cout << "--- Nhap Thong Tin CD ---" << endl;
        sanpham::nhap();
        cout << "  - Nhap ten ca si: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, singer);
        cout << "  - Nhap ten nha san xuat: ";
        getline(cin, publisher);
    }

    void xuat() override {
        cout << "Loai: CD, ";
        sanpham::xuat();
        cout << ", Ca si: " << singer << ", Nha san xuat: " << publisher << endl;
    }
};

// Lớp Khachhang
class Khachhang {
private:
    int makhachhang;
    string tenkhachhang;
    string sodienthoai;

public:
    Khachhang() : makhachhang(0) {}

    int getMaKhachHang() const { return makhachhang; }
    string getTenKhachHang() const { return tenkhachhang; }

    void nhap() {
        cout << "--- Nhap Thong Tin Khach Hang ---" << endl;
        cout << "  - Nhap ma khach hang: ";
        cin >> makhachhang;
        cout << "  - Nhap ten khach hang: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, tenkhachhang);
        cout << "  - Nhap so dien thoai: ";
        getline(cin, sodienthoai);
    }

    void xuat() {
        cout << "Ma KH: " << makhachhang << ", Ten: " << tenkhachhang << ", SDT: " << sodienthoai << endl;
    }
};

// Lớp hoadon
class hoadon {
private:
    int mahoadon;
    string ngaylaphoadon;
    Khachhang kh;
    sanpham* danhSachSP[MAX_ITEMS]; // THAY ĐỔI: Dùng mảng con trỏ C-style
    int soLuongSP;                   // THAY ĐỔI: Biến đếm số lượng sản phẩm hiện tại
    double tonggiatien;

public:
    // Constructor
    hoadon() : soLuongSP(0), tonggiatien(0.0) {
        // Khởi tạo mảng là con trỏ rỗng
        for (int i = 0; i < MAX_ITEMS; ++i) {
            danhSachSP[i] = nullptr;
        }
    }

    // Destructor để giải phóng bộ nhớ
    ~hoadon() {
        for (int i = 0; i < soLuongSP; ++i) {
            delete danhSachSP[i];
        }
    }
    
    Khachhang getKhachHang() const { return kh; }
    double getTongGiaTien() const { return tonggiatien; }

    void nhap() {
        cout << "\n===== NHAP HOA DON MOI =====\n";
        cout << "Nhap ma hoa don: ";
        cin >> mahoadon;
        cout << "Nhap ngay lap (dd/mm/yyyy): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, ngaylaphoadon);

        kh.nhap();

        int n;
        cout << "Nhap so luong loai san pham trong hoa don: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            // Kiểm tra xem mảng còn chỗ không
            if (soLuongSP >= MAX_ITEMS) {
                cout << "Loi: Hoa don da day, khong the them san pham!" << endl;
                break;
            }
            int loai;
            cout << "\nChon loai san pham thu " << i+1 << " (1: Tranh, 2: CD): ";
            cin >> loai;
            sanpham* sp = nullptr;
            if (loai == 1) {
                sp = new Tranh();
            } else {
                sp = new CD();
            }
            sp->nhap();
            // Thêm sản phẩm vào mảng và tăng biến đếm
            danhSachSP[soLuongSP] = sp;
            soLuongSP++;
        }
        tinhTongTien();
    }

    void tinhTongTien() {
        tonggiatien = 0;
        for (int i = 0; i < soLuongSP; ++i) {
            tonggiatien += danhSachSP[i]->getGia();
        }
    }

    void xuat() {
        cout << "\n--------------------------------------------\n";
        cout << "HOA DON - Ma HD: " << mahoadon << " | Ngay lap: " << ngaylaphoadon << endl;
        cout << "Thong tin khach hang: ";
        kh.xuat();
        cout << "Chi tiet san pham:" << endl;
        for (int i = 0; i < soLuongSP; ++i) {
            cout << "  - ";
            danhSachSP[i]->xuat();
        }
        cout << "==> TONG GIA TRI HOA DON: " << tonggiatien << " VND" << endl;
        cout << "--------------------------------------------\n";
    }
};

// Lớp quản lý cửa hàng
class cuahang {
private:
    hoadon* danhSachHD[MAX_ITEMS];
    int soLuongHD;

public:
    cuahang() : soLuongHD(0) {
        for (int i = 0; i < MAX_ITEMS; ++i) {
            danhSachHD[i] = nullptr;
        }
    }
    ~cuahang() {
        for (int i = 0; i < soLuongHD; ++i) {
            delete danhSachHD[i];
        }
    }

    void nhapDanhSachHoaDon() {
        int n;
        cout << "Nhap so luong hoa don can them: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            if (soLuongHD >= MAX_ITEMS) {
                cout << "Loi: Cua hang da het dung luong luu tru hoa don!" << endl;
                break;
            }
            hoadon* hd = new hoadon();
            hd->nhap();
            danhSachHD[soLuongHD] = hd;
            soLuongHD++;
        }
    }

    void xuatDanhSachHoaDon() {
        if (soLuongHD == 0) {
            cout << "Chua co hoa don nao trong cua hang." << endl;
            return;
        }
        cout << "\n\n========= DANH SACH TAT CA HOA DON =========\n";
        for (int i = 0; i < soLuongHD; ++i) {
            danhSachHD[i]->xuat();
        }
    }
    
    void tinhTongThuNhap() {
        double tong = 0;
        for (int i = 0; i < soLuongHD; ++i) {
            tong += danhSachHD[i]->getTongGiaTien();
        }
        cout << "\n==> TONG THU NHAP CUA CUA HANG: " << tong << " VND" << endl;
    }
    
    void timKhachHangMuaNhieuNhat() {
        if (soLuongHD == 0) {
            cout << "Chua co du lieu de phan tich." << endl;
            return;
        }

        map<int, double> chiTieuKhachHang;
        map<int, string> tenKhachHang;

        for (int i = 0; i < soLuongHD; ++i) {
            int maKH = danhSachHD[i]->getKhachHang().getMaKhachHang();
            chiTieuKhachHang[maKH] += danhSachHD[i]->getTongGiaTien();
            if (tenKhachHang.find(maKH) == tenKhachHang.end()) {
                tenKhachHang[maKH] = danhSachHD[i]->getKhachHang().getTenKhachHang();
            }
        }
        
        double maxChiTieu = 0;
        for (auto const& [maKH, tongTien] : chiTieuKhachHang) {
            if (tongTien > maxChiTieu) {
                maxChiTieu = tongTien;
            }
        }

        cout << "\n========= KHACH HANG MUA NHIEU NHAT (Chi tieu: " << maxChiTieu << " VND) =========\n";
        for (auto const& [maKH, tongTien] : chiTieuKhachHang) {
            if (tongTien == maxChiTieu) {
                cout << "- Ma KH: " << maKH << ", Ten: " << tenKhachHang[maKH] << endl;
            }
        }
    }
};

void showMenu() {
    cout << "\n\n===== MENU QUAN LY CUA HANG =====\n";
    cout << "1. Nhap danh sach hoa don\n";
    cout << "2. Xuat danh sach hoa don\n";
    cout << "3. Tinh tong thu nhap cua hang\n";
    cout << "4. Tim khach hang mua nhieu nhat\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "===================================\n";
    cout << "Lua chon cua ban: ";
}

int main() {
    cuahang myStore;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                myStore.nhapDanhSachHoaDon();
                break;
            case 2:
                myStore.xuatDanhSachHoaDon();
                break;
            case 3:
                myStore.tinhTongThuNhap();
                break;
            case 4:
                myStore.timKhachHangMuaNhieuNhat();
                break;
            case 0:
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}