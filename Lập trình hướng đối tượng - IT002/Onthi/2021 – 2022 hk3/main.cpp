#include <iostream>
#include <string>
#include <limits>
using namespace std;

#define MAX 100

class SIM {
protected:
    string nhaMang;
    int serial{};
    int maNhaMang{};
    string soDienThoai;
    bool trangThai{};
    double khuyenMai{};

public:
    virtual ~SIM() {}

    string getNhaMang() {
        return nhaMang;
    }

    double getKhuyenMai() {
        return khuyenMai;
    }

    // Trả về -1 cho các loại không có ghi nợ (trả trước)
    virtual double getSoGhiNo() const {
        return -1.0;
    }

    virtual void nhap() {
        int nm = 0;
        cout << "Nhap nha mang (1: Verizon, 2: AT&T, 3: Sprint): ";
        cin >> nm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (nm == 1) {
            nhaMang = "Verizon";
        } else if (nm == 2) {
            nhaMang = "AT&T";
        } else if (nm == 3) {
            nhaMang = "Sprint";
        } else {
            nhaMang = "Unknown";
        }

        cout << "Nhap serial (int): ";
        cin >> serial;

        cout << "Nhap ma nha mang (int): ";
        cin >> maNhaMang;

        int tt = 0;
        cout << "Trang thai (1: hoat dong, 0: khoa): ";
        cin >> tt;
        trangThai = (tt != 0);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nhap so dien thoai: ";
        getline(cin, soDienThoai);
    }

    virtual void xuat() {
        cout << "Nha mang: " << nhaMang << '\n';
        cout << "Serial: " << serial << '\n';
        cout << "Ma nha mang: " << maNhaMang << '\n';
        cout << "Trang thai: " << (trangThai ? "Hoat dong" : "Khoa") << '\n';
        cout << "So dien thoai: " << soDienThoai << '\n';
        cout << "Khuyen mai: " << khuyenMai << '\n';
    }

    virtual void tinhKhuyenMai() = 0;
};

class SIMtratruoc : public SIM {
private:
    double soDu{};
    int soLanNap{};
    double tienNapThe{};

public:
    void nhap() override {
        SIM::nhap();

        cout << "Nhap so du hien tai: ";
        cin >> soDu;

        cout << "Nhap so lan nap: ";
        cin >> soLanNap;

        cout << "Nhap menh gia lan nap gan nhat: ";
        cin >> tienNapThe;

        tinhKhuyenMai();
    }

    void tinhKhuyenMai() override {
        double rate = 0.0;
        if (soLanNap <= 5) {
            rate = 0.05;
        } else if (soLanNap <= 10) {
            rate = 0.20;
        } else {
            rate = 0.50;
        }
        khuyenMai = tienNapThe * rate;
        soDu += khuyenMai + tienNapThe;
    }

    void xuat() override {
        SIM::xuat();
        cout << "Loai: Tra truoc\n";
    }
};

class SIMtrasau : public SIM {
private:
    string goiCuoc;
    double soGhiNo{};

public:
    double getSoGhiNo() const override {
        return soGhiNo;
    }

    void nhap() override {
        SIM::nhap();

        cout << "Nhap goi cuoc (LCAP/MCAP/HCAP): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, goiCuoc);

        cout << "Nhap so ghi no: ";
        cin >> soGhiNo;

        tinhKhuyenMai();
    }

    void tinhKhuyenMai() override {
        double rate = 0.0;
        if (goiCuoc == "LCAP") {
            rate = 0.05;
        } else if (goiCuoc == "MCAP") {
            rate = 0.10;
        } else if (goiCuoc == "HCAP") {
            rate = 0.15;
        }
        khuyenMai = soGhiNo * rate;
        soGhiNo -= khuyenMai;
    }

    void xuat() override {
        SIM::xuat();
        cout << "Loai: Tra sau\n";
        cout << "Goi cuoc: " << goiCuoc << '\n';
        cout << "So ghi no (sau KM): " << soGhiNo << '\n';
    }
};

class QuanLyKhoSIM {
private:
    SIM *DS[MAX]{};
    int SL{};
    double tongTienKhuyenMaiATT{};
    int idxHighestGhiNo{-1};
    double maxGhiNo{-1.0};

public:
    ~QuanLyKhoSIM() {
        for (int i = 0; i < SL; ++i) {
            delete DS[i];
        }
    }

    void Nhap() {
        cout << "Nhap so luong SIM: ";
        cin >> SL;
        if (SL < 0) SL = 0;
        if (SL > MAX) SL = MAX;

        for (int i = 0; i < SL; i++) {
            int loai = 0;
            cout << "\nSIM #" << (i + 1) << " - Nhap loai (1: Tra truoc, 2: Tra sau): ";
            cin >> loai;

            if (loai == 1) {
                DS[i] = new SIMtratruoc();
            } else {
                DS[i] = new SIMtrasau();
            }

            DS[i]->nhap();

            // Cộng dồn khuyến mãi của AT&T
            if (DS[i]->getNhaMang() == "AT&T") {
                tongTienKhuyenMaiATT += DS[i]->getKhuyenMai();
            }

            // Lấy ghi nợ lớn nhất bằng so sánh cơ bản
            double gn = DS[i]->getSoGhiNo();   // trả trước sẽ cho -1
            if (gn >= 0.0 && gn > maxGhiNo) {
                maxGhiNo = gn;
                idxHighestGhiNo = i;
            }
        }
    }

    void xuat() {
        int luachon = 0;
        cout << "\nLua chon (1: Tong KM AT&T, 2: SIM tra sau ghi no lon nhat, 3: Xuat tat ca): ";
        cin >> luachon;

        if (luachon == 1) {
            cout << "Tong tien khuyen mai cua AT&T: " << tongTienKhuyenMaiATT << '\n';
        } else if (luachon == 2) {
            if (idxHighestGhiNo == -1) {
                cout << "Khong co SIM tra sau nao.\n";
            } else {
                cout << "SIM tra sau co so ghi no lon nhat:\n";
                DS[idxHighestGhiNo]->xuat();
            }
        } else if (luachon == 3) {
            for (int i = 0; i < SL; ++i) {
                cout << "\n--- SIM #" << (i + 1) << " ---\n";
                DS[i]->xuat();
            }
        }
    }
};

int main() {
    QuanLyKhoSIM kho;
    kho.Nhap();
    kho.xuat();
    return 0;
}
