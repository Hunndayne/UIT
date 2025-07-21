#include <iostream>
#include <cmath>   

// Hàm tìm ước số chung lớn nhất (USCLN)
int UCLN(int a, int b) {
     while (b != 0) {
         int temp = b;
         b = a % b;
         a = temp;
     }
     return a;

}

void rutGonPhanSo(int* tuSo, int* mauSo) {

    if (*tuSo == 0) {
        *mauSo = 1;
        return;
    }
    int absTuSo = std::abs(*tuSo);
    int absMauSo = std::abs(*mauSo);

    int uocChungLonNhat = UCLN(absTuSo, absMauSo);

    *tuSo /= uocChungLonNhat;
    *mauSo /= uocChungLonNhat;

    if (*mauSo < 0) {
        *tuSo *= -1;
        *mauSo *= -1;
    }
}

int main() {
    int tuSo, mauSo;

    std::cout << "Nhap tu so: ";
    std::cin >> tuSo;

    std::cout << "Nhap mau so: ";
    std::cin >> mauSo;

    if (mauSo == 0) {
        std::cout << "Loi: Mau so khong the bang 0." << std::endl;
        return 1;
    }

    rutGonPhanSo(&tuSo, &mauSo);
    if (mauSo == 1) {
        std::cout << "Phan so: " << tuSo;
    }
    else {
        std::cout << "Phan so: " << tuSo << "/" << mauSo << std::endl;
    }


    return 0;
}