#include <iostream>

using namespace std;

class cDate {
private:
    int dd;
    int mm;
    int yy;

public:

    cDate(int d = 1, int m = 1, int y = 2000) : dd(d), mm(m), yy(y) {}

    bool laNamNhuan() const {
        return (yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0);
    }

    bool laNgayHopLe() const {
        if (yy <= 0 || mm < 1 || mm > 12 || dd < 1 || dd > 31) {
            return false;
        }
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (laNamNhuan()) {
            daysInMonth[2] = 29;
        }
        if (dd > daysInMonth[mm]) {
            return false;
        }

        return true;
    }

    friend istream &operator>>(istream &is, cDate &d) {
        do {
            is >> d.dd >> d.mm >> d.yy;
        } while (!d.laNgayHopLe());
        return is;
    }

    friend ostream &operator<<(ostream &os, const cDate &d) {
        os << d.dd << "/" << d.mm << "/" << d.yy;
        return os;
    }

    // Toán tử ++ dạng prefix (++a)
    cDate& operator++() {
        dd++;
        if (!laNgayHopLe()) {
            dd = 1;
            mm++;
            if (mm > 12) {
                mm = 1;
                yy++;
            }
        }
        return *this;
    }

    // Toán tử ++ dạng postfix (a++)
    cDate operator++(int) {
        cDate temp = *this;
        ++(*this);
        return temp;
    }
};


int main() {
    cDate ngay1;

    cin >> ngay1;

   cout << ngay1 << endl;

    cDate ngay2 = ++ngay1;
    cout << ngay1 << endl;
    cout << ngay2 << endl;
    cDate ngay3 = ngay1++;
    cout << ngay1 << endl;
    cout << ngay3 << endl;

    return 0;
}