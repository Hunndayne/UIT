#include <iostream>
#include <vector>
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


bool soSanhPhanSo(const PhanSo& ps1, const PhanSo& ps2) {

    return (ps1.tuSo * ps2.mauSo) > (ps2.tuSo * ps1.mauSo);
}

int compareFractions(const PhanSo& ps1, const PhanSo& ps2) {
    long long product1 = (long long)ps1.tuSo * ps2.mauSo;
    long long product2 = (long long)ps2.tuSo * ps1.mauSo;

    if (product1 < product2) return -1;
    if (product1 > product2) return 1;
    return 0;
}

void swap(PhanSo& ps1, PhanSo& ps2) {
    PhanSo temp = ps1;
    ps1 = ps2;
    ps2 = temp;
}

int partitionAscending(std::vector<PhanSo>& arr, int low, int high) {
    PhanSo pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compareFractions(arr[j], pivot) <= 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


int partitionDescending(std::vector<PhanSo>& arr, int low, int high) {
    PhanSo pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (compareFractions(arr[j], pivot) >= 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortAscending(std::vector<PhanSo>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionAscending(arr, low, high);
        quickSortAscending(arr, low, pi - 1);
        quickSortAscending(arr, pi + 1, high);
    }
}

void quickSortDescending(std::vector<PhanSo>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionDescending(arr, low, high);
        quickSortDescending(arr, low, pi - 1);
        quickSortDescending(arr, pi + 1, high);
    }
}


void inPhanSo(const PhanSo& ps) {
    if (ps.mauSo == 1) {
        std::cout << ps.tuSo;
    }
    else {
        std::cout << ps.tuSo << "/" << ps.mauSo;
    }
}

void inDanhSachPhanSo(const std::vector<PhanSo>& danhSach) {
    for (int i = 0; i < danhSach.size(); i++) {
        inPhanSo(danhSach[i]);
        if (i < danhSach.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "So luong phan so: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "So luong phan so phai lon hon 0" << std::endl;
        return 1;
    }

    std::vector<PhanSo> danhSachPhanSo(n);


    for (int i = 0; i < n; i++) {
        std::cout << "Nhap phan so thu " << (i + 1) << ":" << std::endl;
        std::cout << "  Tu so: ";
        std::cin >> danhSachPhanSo[i].tuSo;
        std::cout << "  Mau so: ";
        std::cin >> danhSachPhanSo[i].mauSo;

        if (danhSachPhanSo[i].mauSo == 0) {
            std::cout << "Mau so khong the bang 0." << std::endl;
            i--;
            continue;
        }

        rutGonPhanSo(danhSachPhanSo[i]);
    }

    std::vector<PhanSo> danhSachSapXep = danhSachPhanSo; // Tạo bản sao để sắp xếp

        std::cout << "\nPhan so lon nhat la: ";
        inPhanSo(danhSachSapXep[0]);
        std::cout << std::endl;

        quickSortAscending(danhSachSapXep, 0, n - 1);
        std::cout << "\nPhan so sau khi sap xep tang dan: ";
        inDanhSachPhanSo(danhSachSapXep);

        quickSortDescending(danhSachSapXep, 0, n - 1);
        std::cout << "\nPhan so sau khi sap xep giam dan: ";
        inDanhSachPhanSo(danhSachSapXep);
    return 0;
}