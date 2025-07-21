#include <iostream>

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

int soSanhPhanSo(const PhanSo& ps1, const PhanSo& ps2) {

    long long val1 = (long long)ps1.tuSo * ps2.mauSo;
    long long val2 = (long long)ps2.tuSo * ps1.mauSo;

    if (val1 > val2) {
        return 1;
    }
    else if (val1 < val2) {
        return -1;
    }
    else {
        return 0;
    }
}

int main() {
    PhanSo ps1, ps2;


    std::cout << "Nhap tu cua phan so 1: ";
    std::cin >> ps1.tuSo;
    std::cout << "Nhap mau cua phan so 1: ";
    std::cin >> ps1.mauSo;

    if (ps1.mauSo == 0) {
        std::cout << "Loi: Mau so khong the bang 0" << std::endl;
        return 1;
    }

    std::cout << "Nhap tu cua phan so 2: ";
    std::cin >> ps2.tuSo;
    std::cout << "Nhap mau cua phan so 2: ";
    std::cin >> ps2.mauSo;


    if (ps2.mauSo == 0) {
        std::cout << "Loi: Mau so khong the bang 0" << std::endl;
        return 1;
    }


    int Sosanh = soSanhPhanSo(ps1, ps2);



    if (Sosanh == 1) {
        std::cout << "Phan so lon nhat la: " << ps1.tuSo << "/" << ps1.mauSo << std::endl;
    }
    else if (Sosanh == -1) {
        std::cout << "Phan so lon nhat la: " << ps2.tuSo << "/" << ps2.mauSo << std::endl;
    }
    else {
        std::cout << "Hai phan so bang nhau: " << ps1.tuSo << "/" << ps1.mauSo << std::endl;
    }

    return 0;
}