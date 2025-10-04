#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Thêm thư viện này để định dạng output

using namespace std;

// --- Lớp cơ sở (trừu tượng) cho tất cả các loại cây nông sản ---
class CayNongSan {
protected:
    float DienTich; // Diện tích canh tác (ha)
    float MatDo;    // Mật độ cây/ha

public:
    // Phương thức nhập thông tin chung cho mọi loại cây
    virtual void nhap() {
        cout << "Nhap dien tich canh tac (ha): ";
        cin >> DienTich;
        cout << "Nhap mat do cay/ha: ";
        cin >> MatDo;
    }

    // Phương thức hiển thị thông tin chung
    virtual void hienthi() const {
        cout << "Dien tich: " << DienTich << " ha" << endl;
        cout << "Mat do: " << MatDo << " cay/ha" << endl;
    }

    // Phương thức ảo thuần túy để tính tổng chi phí.
    // Các lớp con bắt buộc phải cài đặt phương thức này.
    virtual double TongChiPhi() const = 0;

    // Phương thức ảo để tính doanh thu (chỉ áp dụng cho Ot)
    // Các lớp không có doanh thu có thể trả về 0.
    virtual double DoanhThu() const { return 0; }

    // Phương thức ảo để in chi phí và doanh thu.
    virtual void inChiPhiVaDoanhThu() const = 0;
};

// --- Lớp Bơ Sáp ---
class BoSap : public CayNongSan {
private:
    int namTrong;         // Số năm trồng cho đến khi thu hoạch
    double ChiPhiChamSoc; // Chi phí chăm sóc 1 cây/1 năm

public:
    void nhap() override {
        CayNongSan::nhap(); // Gọi phương thức nhập của lớp cha
        cout << "Nhap so nam trong den khi thu hoach: ";
        cin >> namTrong;
        cout << "Nhap chi phi cham soc 1 cay/1 nam: ";
        cin >> ChiPhiChamSoc;
    }

    // Cài đặt phương thức tính tổng chi phí theo công thức
    double TongChiPhi() const override {
        return DienTich * MatDo * ChiPhiChamSoc * namTrong;
    }

    void inChiPhiVaDoanhThu() const override {
        cout<<"Cay bo sap\n";
        cout << fixed << setprecision(2); // Định dạng số thập phân
        hienthi();
        cout << "Tong chi phi: " << TongChiPhi() << " VND" << endl;
    }
};

// --- Lớp Lê Ki Ma ---
class LeKiMa : public CayNongSan {
private:
    int namTrong;
    double ChiPhiChamSoc; // Chi phí chăm sóc 1 cây/1 năm
    double ChiPhiChuyenGia; // Chi phí thuê chuyên gia/1 năm

public:
    void nhap() override {
        CayNongSan::nhap();
        cout << "Nhap so nam trong den khi thu hoach: ";
        cin >> namTrong;
        cout << "Nhap chi phi cham soc 1 cay/1 nam: ";
        cin >> ChiPhiChamSoc;
        cout << "Nhap chi phi thue chuyen gia/1 nam: ";
        cin >> ChiPhiChuyenGia;
    }

    // Cài đặt phương thức tính tổng chi phí
    double TongChiPhi() const override {
        return ((DienTich * MatDo * ChiPhiChamSoc) + ChiPhiChuyenGia) * namTrong;
    }

    void inChiPhiVaDoanhThu() const override {
        cout<<"Cay Le Ki Ma\n";
        cout << fixed << setprecision(2);
        hienthi();
        cout << "Tong chi phi: " << TongChiPhi() << " VND" << endl;
    }
};

// --- Lớp Ớt ---
class Ot : public CayNongSan {
private:
    int thangTrong;          // Số tháng trồng đến khi thu hoạch
    double ChiPhiTheoHa;     // Chi phí/1 ha/1 năm
    double SanLuong;         // Sản lượng tấn/ha/1 năm
    double GiaBan;           // Giá bán/1kg

public:
    void nhap() override {
        CayNongSan::nhap();
        cout << "Nhap so thang trong den khi cho trai: ";
        cin >> thangTrong;
        cout << "Nhap chi phi 1 ha/1 nam: ";
        cin >> ChiPhiTheoHa;
        cout << "Nhap san luong (tan/ha/1 nam): ";
        cin >> SanLuong;
        cout << "Nhap gia ban (VND/kg): ";
        cin >> GiaBan;
    }

    // Cài đặt phương thức tính tổng chi phí
    double TongChiPhi() const override {
        return DienTich * ChiPhiTheoHa;
    }

    // Cài đặt phương thức tính doanh thu
    double DoanhThu() const override {
        // Chú ý: Đổi tấn sang kg (nhân 1000)
        return (DienTich * SanLuong * 1000 * GiaBan) * (12.0 - thangTrong) / 12.0;
    }

    void inChiPhiVaDoanhThu() const override {
        cout<<"Cay Ot\n";
        cout << fixed << setprecision(2);
        hienthi();
        cout << "Tong chi phi: " << TongChiPhi() << " VND" << endl;
        cout << "Tong doanh thu: " << DoanhThu() << " VND" << endl;
    }
};

// --- Lớp Nông Trại để quản lý danh sách cây trồng ---
class NongTrai {
private:
    vector<CayNongSan*> danhSachCay; // Sử dụng vector con trỏ để lưu các đối tượng con
public:
    // Phương thức thêm cây trồng vào nông trại
    void themCay() {
        int loai;
        cout << "Chon loai cay muon them:" << endl;
        cout << "1. Bo Sap" << endl;
        cout << "2. Le Ki Ma" << endl;
        cout << "3. Ot" << endl;
        cout << ">>";
        cin >> loai;

        CayNongSan* cay = nullptr;
        switch (loai) {
            case 1:
                cay = new BoSap();
                break;
            case 2:
                cay = new LeKiMa();
                break;
            case 3:
                cay = new Ot();
                break;
            default:
                cout << "Lua chon khong hop le" << endl;
                return;
        }

        if (cay) {
            cay->nhap();
            danhSachCay.push_back(cay);
        }
    }

    void hienThiDanhSach() const {
        if (danhSachCay.empty()) {
            cout << "Danh sach cay trong trong nong trai rong." << endl;
            return;
        }
        cout << "Danh sach cay trong trong nong trai" << endl;
        for (const auto& cay : danhSachCay) {
            cay->inChiPhiVaDoanhThu();
        }
    }

    double tinhTongChiPhiNongTrai() const {
        double tong = 0;
        for (const auto& cay : danhSachCay) {
            tong += cay->TongChiPhi();
        }
        return tong;
    }
    ~NongTrai() {
        for (auto& cay : danhSachCay) {
            delete cay;
        }
    }
};

int main() {
    NongTrai nongTrai;
    int luaChon;

    do {
        cout << "1. Them mot loai cay moi" << endl;
        cout << "2. Hien thi danh sach cay trong va du toan" << endl;
        cout << "3. Tinh tong chi phi toan bo nong trai" << endl;
        cout << "0. Thoat" << endl;
        cout << ">>";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                nongTrai.themCay();
                break;
            case 2:
                nongTrai.hienThiDanhSach();
                break;
            case 3:
                cout << fixed << setprecision(2);
                cout << "Tong chi phi toan bo nong trai la: " << nongTrai.tinhTongChiPhiNongTrai() << " VND" << endl;
                break;
            case 0:
                cout << "Ket thuc chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
        }
    } while (luaChon != 0);

    return 0;
}