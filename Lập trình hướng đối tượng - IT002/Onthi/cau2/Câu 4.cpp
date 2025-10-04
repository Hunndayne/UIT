#include <iostream>

using namespace std;

class cNgay {
private:
    int d, m, y;

    bool laNgayHopLe() const {
        if (y <= 0 || m < 1 || m > 12 || d < 1 || d > 31) {
            return false;
        }
        if (m == 2) {
            bool laNamNhuan = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
            if (laNamNhuan) {
                return d <= 29;
            } else {
                return d <= 28;
            }
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return d <= 30;
        }
        return true;
    }

public:
    cNgay(int d, int m, int y) {
        this->d = d;
        this->m = m;
        this->y = y;
    }

    cNgay() {
        this->d = 1;
        this->m = 1;
        this->y = 1;
    }

    cNgay(int y, int m) {
        this->y = y;
        this->m = m;
        this->d = 1;
    }

    friend ostream& operator<<(ostream& os, const cNgay& obj) {
        os << obj.d << "/" << obj.m << "/" << obj.y;
        return os;
    }

    friend istream& operator>>(istream& is, cNgay& obj) {
        do {
            cout << "Nhap ngay: ";
            is >> obj.d;
            cout << "Nhap thang: ";
            is >> obj.m;
            cout << "Nhap nam: ";
            is >> obj.y;
            if (!obj.laNgayHopLe()) {
                cout << "Ngay khong hop le. Vui long nhap lai!" << endl;
            }
        } while (!obj.laNgayHopLe());
        return is;
    }

    bool operator<(const cNgay& obj) const {
        if (this->y < obj.y) return true;
        if (this->y == obj.y && this->m < obj.m) return true;
        if (this->y == obj.y && this->m == obj.m && this->d < obj.d) return true;
        return false;
    }
};
void main()
{
    cNgay ng1;
    cNgay ng2(2017, 1);
    cNgay ng3(2017, 1, 7);
    cin>>ng1;
    cout<<ng1;
    if(ng1 < ng2)
        cout << "Ngay 1 truoc ngay 2" << endl;
    else
        cout << "Ngay 1 khong truoc ngay 2" << endl;
}
