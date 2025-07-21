#include "Diem.h"
#include <iostream>
using namespace std;

int main() {
    cout << "====== CHUONG TRINH MINH HOA LOP POINT ======" << endl;

    // Tạo các điểm
    Point a, b, c;

    cout << "\n1. Tao diem mac dinh:" << endl;
    cout << "Diem a: " << a << endl;
    cout << "Diem b: " << b << endl;

    cout << "\n2. Nhap diem a:" << endl;
    cin >> a;

    cout << "\n3. Nhap diem b:" << endl;
    cin >> b;

    cout << "\n4. Hien thi cac diem vua nhap:" << endl;
    cout << "Diem a: " << a << endl;
    cout << "Diem b: " << b << endl;

    cout << "\n5. Tinh tien diem a bang diem b (a + b):" << endl;
    c = a + b;
    cout << "Ket qua: " << c << endl;

    cout << "\n6. Hieu hai diem (a - b):" << endl;
    c = a - b;
    cout << "Ket qua: " << c << endl;

    cout << "\n7. Thay doi toa do diem a:" << endl;
    a.setX(10.5);
    a.setY(20.3);
    cout << "Diem a sau khi thay doi: " << a << endl;
    cout << "Hoanh do cua a: " << a.getX() << endl;
    cout << "Tung do cua a: " << a.getY() << endl;

    cout << "\n8. Tinh tien diem a theo vector (5, -3):" << endl;
    a.TinhTien(5, -3);
    cout << "Diem a sau khi tinh tien: " << a << endl;

    cout << "\n9. So sanh hai diem:" << endl;
    if (a == b) {
        cout << "Diem a va b trung nhau" << endl;
    }
    else {
        cout << "Diem a va b khac nhau" << endl;
    }

    cout << "\n10. Tao diem c bang constructor co tham so:" << endl;
    Point d(1.5, 2.7);
    cout << "Diem d: " << d << endl;

    cout << "\n11. Gan diem:" << endl;
    c = d;
    cout << "Gan c = d, diem c: " << c << endl;

    cout << "\n12. Su dung phuong thuc Nhap() va Xuat():" << endl;
    Point e;
    cout << "Nhap diem e:" << endl;
    e.Nhap();
    cout << "Diem e: ";
    e.Xuat();
    cout << endl;

    return 0;
}