#include <iostream>
#include <numeric>
#include <cmath>   

struct PhanSo {
    int tuSo;
    int mauSo;
};

int UCLN(int a, int b) {
     while (b != 0) {
         int temp = b;
         b = a % b;
         a = temp;
     }
     return a;
}

void rutGonPhanSo(PhanSo& ps) { 
    if (ps.tuSo == 0) {
        ps.mauSo = 1;
        return;
    }

    int absTuSo = std::abs(ps.tuSo);
    int absMauSo = std::abs(ps.mauSo);

    int uocChungLonNhat = UCLN(absTuSo, absMauSo);

    ps.tuSo /= uocChungLonNhat;
    ps.mauSo /= uocChungLonNhat;

    if (ps.mauSo < 0) {
        ps.tuSo *= -1;
        ps.mauSo *= -1;
    }
}
PhanSo congPhanSo(const PhanSo& ps1, const PhanSo& ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    rutGonPhanSo(ketQua); 
    return ketQua;
}

PhanSo truPhanSo(const PhanSo& ps1, const PhanSo& ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    rutGonPhanSo(ketQua);
    return ketQua;
}

PhanSo nhanPhanSo(const PhanSo& ps1, const PhanSo& ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.tuSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    rutGonPhanSo(ketQua);
    return ketQua;
}


PhanSo chiaPhanSo(const PhanSo& ps1, const PhanSo& ps2) {
    PhanSo ketQua;
     if (ps2.tuSo == 0) {

        std::cerr << "Loi: Khong the chia cho 0." << std::endl;
        ketQua.tuSo = 0;
        ketQua.mauSo = 0;
        return ketQua;
    }

    ketQua.tuSo = ps1.tuSo * ps2.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.tuSo;
    rutGonPhanSo(ketQua); 
    return ketQua;
}
int main() {
    PhanSo ps1, ps2;

    std::cout << "Nhap tu so 1: ";
    std::cin >> ps1.tuSo;
    std::cout << "Nhap mau so 1: ";
    std::cin >> ps1.mauSo;

    if (ps1.mauSo == 0) {
        std::cout << "Loi: Mau so khong the bang 0" << std::endl;
        return 1;
    }
    rutGonPhanSo(ps1);

    std::cout << "Nhap tu so 2: ";
    std::cin >> ps2.tuSo;
    std::cout << "Nhap mau so 2: ";
    std::cin >> ps2.mauSo;

    if (ps2.mauSo == 0) {
        std::cout << "Loi: Mau so khong the bang 0" << std::endl;
        return 1;
    }
    rutGonPhanSo(ps2);

    PhanSo tong = congPhanSo(ps1, ps2);
    std::cout << "Tong: " << ps1.tuSo << "/" << ps1.mauSo << " + " << ps2.tuSo << "/" << ps2.mauSo << " = " << tong.tuSo << "/" << tong.mauSo << std::endl;

    PhanSo hieu = truPhanSo(ps1, ps2);
    std::cout << "Hieu: " << ps1.tuSo << "/" << ps1.mauSo << " - " << ps2.tuSo << "/" << ps2.mauSo << " = " << hieu.tuSo << "/" << hieu.mauSo << std::endl;


    PhanSo tich = nhanPhanSo(ps1, ps2);
    std::cout << "Tich: " << ps1.tuSo << "/" << ps1.mauSo << " * " << ps2.tuSo << "/" << ps2.mauSo << " = " << tich.tuSo << "/" << tich.mauSo << std::endl;

    PhanSo thuong = chiaPhanSo(ps1, ps2);
    if (thuong.mauSo != 0) { 
        std::cout << "Thuong: " << ps1.tuSo << "/" << ps1.mauSo << " / " << ps2.tuSo << "/" << ps2.mauSo << " = " << thuong.tuSo << "/" << thuong.mauSo << std::endl;
    }
    else {
        std::cout << "Thuong: Khong the thuc hien phep chia." << std::endl;
    }

    return 0;
}