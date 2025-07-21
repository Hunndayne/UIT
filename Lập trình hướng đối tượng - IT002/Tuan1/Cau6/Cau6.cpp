// Cau5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#define MAX 300
using namespace std;
struct hocsinh {
    string hoten;
    float toan;
    float van;
    float dtb;
};
float tinhtb(float a, float b) {
    return (a + b) / 2;
}
int findmax(vector<hocsinh> hs, int n) {
    int temp=0;
    for (int i = 0; i < n; i++) {
        if (hs[i].dtb > hs[temp].dtb) {
            temp = i;
        }
    }
    return temp;
}
int findmin(vector<hocsinh> hs, int n) {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        if (hs[i].dtb < hs[temp].dtb) {
            temp = i;
        }
    }
    return temp;
}
int main()
{
    vector<hocsinh> hs(MAX);

    int n;
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Nhap ho va ten hoc sinh: ";
        getline(cin, hs[i].hoten);
        cout << "Nhap diem toan: ";
        cin >> hs[i].toan;
        cout << "Nhap diem van: ";
        cin >> hs[i].van;
        cin.ignore();
        hs[i].dtb = tinhtb(hs[i].toan, hs[i].van);
    }
    int max = findmax(hs, n);
    int min = findmin(hs,n);

    cout << "Hoc sinh co diem trung binh cao nhat: \n"
        << "Ho ten: " << hs[max].hoten
        << "\nToan: " << hs[max].toan
        << "\nVan: " << hs[max].van
        << "\nDiem trung binh: " << hs[max].dtb;
    cout << "\nHoc sinh co diem trung binh thap nhat: \n"
        << "Ho ten: " << hs[min].hoten
        << "\nToan: " << hs[min].toan
        << "\nVan: " << hs[min].van
        << "\nDiem trung binh: " << hs[min].dtb;
}

