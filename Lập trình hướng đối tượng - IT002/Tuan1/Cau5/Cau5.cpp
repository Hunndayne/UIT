// Cau5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
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
int main()
{
    hocsinh hs;
    cout << "Nhap ho va ten hoc sinh: ";
    getline(cin, hs.hoten);

    cout << "Nhap diem toan: ";
    cin >> hs.toan;

    cout << "Nhap diem van: ";
    cin>> hs.van;

    hs.dtb = tinhtb(hs.toan, hs.van);
    cout << hs.hoten <<"\n";
    cout << hs.dtb;
}

