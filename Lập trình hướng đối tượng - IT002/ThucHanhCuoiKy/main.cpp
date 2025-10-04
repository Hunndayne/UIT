#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define MAX 100

class xe {
protected:
    int soKhung;
    int soMay;
    int dungTich;
    string mau;
    string hang;
    int soChongoi;
    int namSanxuat;
    string xuatxu;
    double giaxenhapkhau;
    double thuenhapkhau;

    double thuetieuthudacbiet;
    double bienloinhuan;
    double giaxe;
    double thueVAT;
    double giaBan;
    double chiphidangky;

public:
    double getGiaban() { return giaBan; }
    double getLanBanh() { return giaBan + chiphidangky; }

    xe() {
        soKhung = 0;
        soMay = 0;
        dungTich = 0;
        mau = "";
        hang = "";
        soChongoi = 0;
        namSanxuat = 0;
        xuatxu = "";
        giaxenhapkhau = 0;
        thuenhapkhau = 0;
        thuetieuthudacbiet = 0;
        bienloinhuan = 0;
        giaxe = 0;
        thueVAT = 0;
        giaBan = 0;
        chiphidangky = 0;
    }

    xe(int sk, int sm, int dt, string m, string h, int scn, int nsx, string xx, double gx) {
        soKhung = sk;
        soMay = sm;
        dungTich = dt;
        mau = m;
        hang = h;
        soChongoi = scn;
        namSanxuat = nsx;
        xuatxu = xx;
        giaxenhapkhau = gx;
        tinhThuenk();
    }

    virtual void nhap() {
        cout << "Nhap so khung: ";
        cin >> soKhung;
        cout << "Nhap so may: ";
        cin >> soMay;
        cout << "Nhap dung tich: ";
        cin >> dungTich;
        cout << "Nhap mau: ";
        cin >> mau;
        cout << "Nhap hang: ";
        cin >> hang;
        cout << "Nhap so Cho ngoi: ";
        cin >> soChongoi;
        cout << "Nhap nam San xuat: ";
        cin >> namSanxuat;
        cout << "Nhap noi xuat xu: ";
        cin >> xuatxu;
        cout << "Nhap gia xe: ";
        cin >> giaxenhapkhau;
    }

    void tinhThuenk() { thuenhapkhau = giaxenhapkhau * 0.7; }

    virtual void xuat() {
        cout << fixed << setprecision(0);
        cout << "So khung xe: " << soKhung << endl;
        cout << "So may: " << soMay << endl;
        cout << "Dung tich: " << dungTich << endl;
        cout << "Mau: " << mau << endl;
        cout << "Hang: " << hang << endl;
        cout << "SoChongoi: " << soChongoi << endl;
        cout << "NamSanxuat: " << namSanxuat << endl;
        cout << "Noi xuat xu: " << xuatxu << endl;
        cout << "Gia xe nhap khau: " << giaxenhapkhau << endl;
        cout << "Thue nhap khau: " << thuenhapkhau << endl;
        cout << "Thue tieu thu dac biet: " << thuetieuthudacbiet << endl;
        cout << "Bien loi nhuan: " << bienloinhuan << endl;
        cout << "Gia xe: " << giaxe << endl;
        cout << "VAT: " << thueVAT << endl;
        cout << "Gia ban: " << giaBan << endl;
        cout << "Chi phi dang ky: " << chiphidangky << endl;
        cout << "Gia lan banh: " << (giaBan + chiphidangky) << endl;
    }

    // ĐỔI int -> double để tránh tràn số
    virtual double tinhVAT(double gx) { return gx * 0.1; }

    virtual void tinhThuetieuthudacbiet() = 0;

    virtual void bienLoiNhuan() = 0;

    virtual void tinhGiaxe() = 0;

    virtual void tinhGiaban() = 0;

    // 2% * giaxe (đề bài)
    virtual void tinhChiphidangky() { chiphidangky = 0.02 * giaxe; }

    void tinhToan() {
        tinhThuenk();
        tinhThuetieuthudacbiet();
        bienLoiNhuan();
        tinhGiaxe();
        thueVAT = tinhVAT(giaxe);
        tinhGiaban();
        tinhChiphidangky();
    }

    virtual ~xe() {
    }
};

class xeXang : public xe {
public:
    void tinhThuetieuthudacbiet() override {
        thuetieuthudacbiet = 0.6 * (giaxenhapkhau + thuenhapkhau);
    }

    void bienLoiNhuan() override {
        bienloinhuan = 0.2 * (giaxenhapkhau + thuenhapkhau + thuetieuthudacbiet);
    }

    void tinhGiaxe() override {
        giaxe = giaxenhapkhau + thuenhapkhau + thuetieuthudacbiet + bienloinhuan;
    }

    double tinhVAT(double gx) override {
        thueVAT = gx * 0.1;
        return thueVAT;
    }

    void tinhGiaban() override { giaBan = giaxe + thueVAT; }

    void tinhChiphidangky() override { xe::tinhChiphidangky(); }

    void xuat() override {
        cout << "Loai xe: xe xang" << endl;
        xe::xuat();
    }
};

class xeDien : public xe {
public:
    void tinhThuetieuthudacbiet() override {
        thuetieuthudacbiet = 0.5 * (giaxenhapkhau + thuenhapkhau);
    }

    void bienLoiNhuan() override {
        bienloinhuan = 0.2 * (giaxenhapkhau + thuenhapkhau + thuetieuthudacbiet);
    }

    void tinhGiaxe() override {
        giaxe = giaxenhapkhau + thuenhapkhau + thuetieuthudacbiet + bienloinhuan;
    }

    double tinhVAT(double gx) override {
        thueVAT = gx * 0.1;
        return thueVAT;
    }

    void tinhGiaban() override { giaBan = giaxe + thueVAT; }

    void tinhChiphidangky() override { xe::tinhChiphidangky(); }

    void xuat() override {
        cout << "Loai xe: xe dien" << endl;
        xe::xuat();
    }
};

class xeLai : public xe {
public:
    void tinhThuetieuthudacbiet() override {
        thuetieuthudacbiet = 0.55 * (giaxenhapkhau + thuenhapkhau);
    }

    void bienLoiNhuan() override {
        bienloinhuan = 0.2 * (giaxenhapkhau + thuenhapkhau + thuetieuthudacbiet);
    }

    void tinhGiaxe() override {
        giaxe = giaxenhapkhau + thuenhapkhau + thuetieuthudacbiet + bienloinhuan;
    }

    double tinhVAT(double gx) override {
        thueVAT = gx * 0.1;
        return thueVAT;
    }

    void tinhGiaban() override { giaBan = giaxe + thueVAT; }

    void tinhChiphidangky() override { xe::tinhChiphidangky(); }

    void xuat() override {
        cout << "Loai xe: xe lai" << endl;
        xe::xuat();
    }
};

class quanlyXe {
private:
    xe *x[MAX];
    int soluongxe;

public:
    quanlyXe() { soluongxe = 0; }

    ~quanlyXe() {
        for (int i = 0; i < soluongxe; ++i) delete x[i];
    }

    void nhap() {
        int n;
        cout << "Nhap so luong xe can nhap: ";
        cin >> n;
        if (n <= 3 || n >= 100) {
            cout << "n phai thoa 3 < n < 100\n";
            return;
        }

        double tong = 0;
        for (int i = 0; i < n; ++i) {
            int loai;
            cout << "\nChon loai xe (1: xang, 2: dien, 3: lai): ";
            cin >> loai;

            if (loai == 1) x[soluongxe] = new xeXang();
            else if (loai == 2) x[soluongxe] = new xeDien();
            else x[soluongxe] = new xeLai();

            x[soluongxe]->nhap();
            x[soluongxe]->tinhToan();
            tong += x[soluongxe]->getGiaban();
            ++soluongxe;
        }
        cout << fixed << setprecision(0);
        cout << "\nTong so tien cho lo xe o to vua nhap (khong bao gom chi phi dang ky): " << tong << endl;
    }

    int highestPrice() {
        if (soluongxe == 0) return -1;
        int idx = 0;
        double best = x[0]->getLanBanh();
        for (int i = 1; i < soluongxe; ++i) {
            double cur = x[i]->getLanBanh();
            if (cur > best) {
                best = cur;
                idx = i;
            }
        }
        return idx;
    }

    void xuat() {
        int idx = highestPrice();
        if (idx < 0) {
            cout << "Chua co du lieu.\n";
            return;
        }
        cout << "\nThong tin xe co gia lan banh cao nhat\n";
        x[idx]->xuat();
    }
};

int main() {
    quanlyXe ql;
    ql.nhap();
    ql.xuat();
    return 0;
}
